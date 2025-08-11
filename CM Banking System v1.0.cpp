#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

struct userAccount { 
    string username;
    string pincode;
    double balance;
};

struct userTransHis { 
    userAccount* user;
    string date;
    string type;
    double amount;
    double balanceAfter;
};

class bank {
    private:
        vector<userAccount*> users;
        vector<userTransHis*> trans;
        userAccount* currentUser = nullptr;
        
    public:
        int size = 48;
        
        ~bank() {
            for (auto u : users) {
                delete u;
            }
        }
        
        void saveData() {
            ofstream saveUser("userAccount.txt");
            cout << "💾 Saving user data..." << flush;
            for (auto u : users) {
                saveUser << u->username << endl;
                saveUser << u->pincode << endl;
                saveUser << u->balance << endl;
            }
            this_thread::sleep_for(seconds(2));
            cout << " ✅ Done.";
            saveUser.close();
            ofstream saveTrans("transactionHistory.txt");
            cout << "\n\n💾 Saving transaction history..." << flush;
            for (auto ut : trans) {
                saveTrans << ut->user->username << endl;
                saveTrans << ut->date << endl;
                saveTrans << ut->type << endl;
                saveTrans << ut->amount << endl;
                saveTrans << ut->balanceAfter << endl;
            }
            this_thread::sleep_for(seconds(2));
            cout << " ✅ Done.";
            saveTrans.close();
            cout << "\n\n🔐 All data saved securely.\n";
        }
        
        void loadData() {
            bool load = true;
            string uName, date, type, pin;
            double amount, balanceAfter, bal;
            ifstream loadUser("userAccount.txt");
            cout << "📂 Loading user data..." << flush;
            this_thread::sleep_for(seconds(2));
            if (!loadUser) {
                cout << " ❌ Failed.";
                
                load = false;
            }
            else {
                while(loadUser >> uName >> pin >> bal) {
                    userAccount* newUser = new userAccount;
                    newUser->username = uName;
                    newUser->pincode = pin;
                    newUser->balance = bal;
                    users.push_back(newUser);
                }
                cout << " ✅ Done.";
            }
            loadUser.close();
            ifstream loadTrans("transactionHistory.txt");
            cout << "\n\n📂 Loading transaction history..." << flush;
            this_thread::sleep_for(seconds(2));
            if (!loadTrans) {
                cout << " ❌ Failed.";
                load = false;
            }
            else {
                while(loadTrans >> uName) {
                    loadTrans.ignore();
                    getline(loadTrans, date);
                    getline(loadTrans, type);
                    loadTrans >> amount;
                    loadTrans >> balanceAfter;
                    loadTrans.ignore();
                    userAccount* foundUser = nullptr;
                    for (auto u : users) {
                        if (u->username == uName) {
                            foundUser = u;
                            break;
                        }
                    }
                    if (foundUser) {
                        userTransHis* ut = new userTransHis;
                        ut->user = foundUser;
                        ut->date = date;
                        ut->type = type;
                        ut->amount = amount;
                        ut->balanceAfter = balanceAfter;
                        trans.push_back(ut);
                    }
                }
                cout << " ✅ Done";
            }
            if (!load) {
                cout << "\n\n⚠️ Some files were not found or corrupted.\n";
            }
            else {
                cout << "\n\n✅ Data loaded succesfully\n";
            }
            loadTrans.close();
        }
        
        void addNewAccount(string x, string y, double z = 0.0) {
            userAccount* newAccount = new userAccount;
            newAccount->username = x;
            newAccount->pincode = y;
            newAccount->balance = z;
            users.push_back(newAccount);
        }
        
        void updateBalance(double nBalance) {
            currentUser->balance = nBalance;
        }
        
        string transDate() {
            time_t n = time(0);
            n += 8 * 60 * 60;
            tm *pht = gmtime(&n);
            char buffer[40];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d %I:%M:%S %p", pht);
            return string(buffer);
        }
        
        void buffer() {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        void inputInt(int& x, string y = "Enter: ") {
            while(!(cin >> x)) {
                cout << "\n⚠️ Invalid input!\nPlease enter numbers only.\n\n" << y;
                cin.clear();
                buffer();
            }
        }
        
        void inputDouble(double& x, string y = "Enter: ") {
            while(!(cin >> x)) {
                cout << "\n⚠️ Invalid input!\nPlease enter numbers only.\n\n" << y;
                cin.clear();
                buffer();
            }
        }
        
        void addTransHis(string type, double amt, double bAfter, string date) {
            userTransHis* ut = new userTransHis;
            ut->user = currentUser;
            ut->type = type;
            ut->amount = amt;
            ut->balanceAfter = bAfter;
            ut->date = date;
            trans.push_back(ut);
        }
        
        string userLower(string& x) {
            transform(x.begin(), x.end(), x.begin(), ::tolower);
            return x;
        }
        
        bool accountFound(string x, string y) {
            for (auto u : users) {
                if (u->username == x && u->pincode == y) {
                    currentUser = u;
                    return true;
                }
            }
            cout << "\n⚠️ Incorrect username or pincode!\n";
            return false;
        }
        
        bool validUser(string x) {
            bool valid = true;
            if (x.length() < 6 || x.length() > 20) {
                cout << "\n⚠️ Username  must be 6-20 characters long!";
                valid = false;
            }
            for (char c : x) {
                if (isspace(c)) {
                    cout << "\n⚠️ Spaces are not allowed in username!";
                    valid = false;
                    break;
                }
            }
            for (auto u : users) {
                if (userLower(u->username) == userLower(x)) {
                    cout << "\n⚠️ Username already exists!\n   Please try another.";
                    valid = false;
                }
            }
            return valid;
        }
        
        bool validPin(string x) {
            bool valid = true;
            if (x.length() != 6) {
                cout << "\n⚠️ Pincode must be 6 digits!";
                valid = false;
            }
            for (char c : x) {
                if (!isdigit(c) && c != ' ') {
                    cout << "\n⚠️ Pincode must only contain numbers\n   (no letters or symbols)!";
                    valid = false;
                    break;
                }
            }
            for (char c : x) {
                if (isspace(c)) {
                    cout << "\n⚠️ Spaces are not allowed in pincode!";
                    valid = false;
                    break;
                }
            }
            return valid;
        }
        
        bool validDeposit(double x) {
            bool valid = true;
            if (x == 0) {
                cout << "\n⚠️ You cant deposit with ₱0!\n";
                valid = false;
            }
            if (x < 0) {
                cout << "\n⚠️ Invalid amount!\nPlease enter a positive value.\n";
                valid = false;
            }
            return valid;
        }
        
        bool validWithdraw(double x) {
            bool valid = true;
            if (x == 0) {
                cout << "\n⚠️ You cant withdraw with ₱0!\n";
                valid = false;
            }
            if (x < 0) {
                cout << "\n⚠️ Invalid amount!\nPlease enter a positive value.\n";
                valid = false;
            }
            if (x > currentUser->balance) {
                cout << "\n💸 Insufficient funds!\n";
                valid = false;
            }
            return valid;
        }
        
        void csd(int d = 1) {
            this_thread::sleep_for(seconds(d)); 
            system("clear");
        }
        
        void csp(string x = "⏎ Press Enter to continue...") {
            cout << x;
            cin.get();
            system("clear");
        }
        
        void printLine() {
            cout << endl << setw(size) << setfill('=') << "=" << "\n\n";
        }
        
        void printLine2() {
            cout << endl << setw(size) << setfill('-') << "-" << endl;
        }
        
        void printTitle(string x = "Null") {
            int pad = size - x.size();
            int lPad = pad / 2;
            int rPad = pad - lPad;
            cout << setw(size) << setfill('=') << "=" << endl;
            cout << setfill(' ') << setw(lPad + x.size()) << x;
            cout << setw(rPad) << "" << endl;
            cout << setw(size) << setfill('=') << "=" << "\n\n";
        }
        
        void printTitle2() {
            string x = "[1] ✅ Confrim\t[2] ❌ Cancel";
            int pad = size - x.size();
            int lPad = pad / 2;
            int rPad = pad - lPad;
            cout << endl << setw(size) << setfill('-') << "-" << endl;
            cout << setfill(' ') << setw(lPad + x.size()) << x;
            cout << setw(rPad) << "" << endl;
            cout << setw(size) << setfill('-') << "-" << endl;
        }
        
        void saveUserData() {
            printTitle("     📂 SAVING SYSTEM DATA 📂");
            saveData();
            printLine(); csd(2);
        }
        
        void loadUserData() {
            printTitle("     📂 LOADING SYSTEM DATA 📂");
            loadData();
            printLine(); csp("⏎ Press Enter to start the Banking System...");
        }
        
        void mainMenu(int& x) {
            printTitle("     🏦 BANKING SYSTEM 🏦");
            cout << "[1] 📝 Register\n\n[2] 🔐 Login\n\n[3] 📘 Help\n\n[4] 👤 Credits\n\n[5] 💾 Save & Exit\n\n";
            while(true) {
                cout << "Enter: "; inputInt(x); buffer();
                if (x >= 1 && x <= 5) {
                    break;
                }
                else {
                    cout << "\n⚠️ Invalid choice!\n   Please enter (1-5) only.\n\n"; 
                }
            }
            printLine(); csd();
        }
        
        void userRegister() {
            string uName, pin;
            int c = 0;
            bool isValid1, isValid2;
            while (c != 2) {
                printTitle("     📝 REGISTER ACCOUNT 📝");
                cout << "👤 Enter your username: "; getline(cin, uName);
                cout << "\n🔐 Enter your pincode: "; getline(cin, pin);
                printTitle2();
                while (c != 2) {
                    cout << "\nEnter: "; inputInt(c); buffer();
                    if (c == 1) {
                         isValid1 = validUser(uName);
                         isValid2 = validPin(pin);
                         if (isValid1 && isValid2) {
                             addNewAccount(uName, pin);
                             cout << "\n✅ Account registered successfully!\n";
                             c = 2;
                         }
                         else {
                             cout << endl;
                             printLine(); csp("⏎ Press Enter to try again...");
                             break;
                         }
                    }
                    else if (c == 2) {
                        cout << "\n❌ Register cancelled.\n";
                        c = 2;
                    }
                    else {
                        cout << "\n⚠️ Invalid choice!\n   Please enter (1-2) only.\n";
                    }
                }
            }
            printLine(); csp("⏎ Press Enter to return to the Banking System\n  Menu...");
        }
        
        void userLogin(bool& isLogin) {
            string uName, pin;
            int c = 0;
            while (c != 2) {
                c = 0;
                printTitle("     🔐 LOGIN ACCOUNT 🔐");
                cout << "👤 Username: "; getline(cin, uName);
                cout << "\n🔐 Pincode: "; getline(cin, pin);
                printTitle2();
                while (c != 2) {
                    cout << "\nEnter: "; inputInt(c); buffer();
                    if (c == 1) {
                         if (accountFound(uName, pin)) {
                             cout << "\n✅ Login successfully! Welcome " << currentUser->username << "\n";
                             isLogin = true;
                             c = 2;
                             printLine(); csp("⏎ Press Enter to continue to the Banking Menu...");
                         }
                         else {
                             printLine(); csp("⏎ Press Enter to try again...");
                             break;
                         }
                    }
                    else if (c == 2) {
                        cout << "\n❌ Login cancelled.\n";
                        printLine(); csp("⏎ Press Enter to return to the Banking System\n  Menu...");
                    }
                    else {
                        cout << "\n⚠️ Invalid Choice!\n   Please enter (1-2) only.\n";
                    }
                }
            }
        }
        
        void transRec(double x, double y, string z = "Deposit") {
            string e = z == "Deposit" ? "📥" : "📤";
            string s = z == "Deposit" ? "+" : "-";
            string t = z == "Deposit" ? "     🧾 DEPOSIT RECEIPT 🧾" : "     🧾 WITHDRAWAL RECEIPT 🧾";
            string date = transDate();
            cout << endl;
            printTitle(t);
            cout << (e + " Amount " + z + ": " + s + "₱") << fixed << setprecision(2) << x << "\n💰 New Balance: ₱" << y << "\n";
            cout << "✅ " << (z == "Withdraw" ? "Withdrawal" : "Deposit") << " Successful\n\n📅 ️Date & Time: " << date << endl;
            addTransHis(z , x, y, date);
            printLine(); csp("⏎ Press Enter to return to the Banking Menu...");
        }
        
        void loginMenu(int& x) {
            x = 0;
            printTitle("     🏦 BANKING MENU 🏦");
            cout << "👤 Username: " << currentUser->username << "\n\n💰 Balance: ₱" << currentUser->balance << endl;
            printLine2();
            cout << "\n[1] 📥 Deposit\n\n[2] 📤 Withdraw\n\n[3] 📜 Transaction History\n\n[4] 🚪 Logout\n"; 
            printLine2();
            while (true) {
                cout << "\nEnter: "; inputInt(x);
                if (x >= 1 && x <= 4) {
                    if (currentUser->balance == 0 && x == 2) {
                        cout << "\n💸 You cant withdraw with ₱0 balance!\n";
                    }
                    else {
                       break;
                    }
                }
                else {
                    cout << "\n⚠️ Invalid choice!\n   Please Enter (1-4) only.\n";
                }
            }
            printLine(); csd();
        }
        
        void userDeposit() {
            double deposit = 0;
            int c = 0;
            while (c != 2) {
                printTitle("     📥 DEPOSIT 📥");
                cout << "💰 Current Balance: ₱" << currentUser->balance << "\n\n📥 Enter amount to deposit: ₱";
                inputDouble(deposit, "Enter amount to deposit: ₱"); buffer(); 
                printTitle2();
                while (c != 2) {
                    cout << "\nEnter: "; inputInt(c); buffer();
                    if (validDeposit(deposit)) {
                        if (c == 1) {
                            printLine(); csd();
                            currentUser->balance += deposit;
                            transRec(deposit, currentUser->balance);
                            c = 2;
                        }
                        else if (c == 2) {
                            cout << "\n❌ Deposit cancelled.\n";
                            printLine(); csp("⏎ Press Enter to return to the Banking Menu...");
                        }
                        else {
                            cout << "\n⚠️ Invalid choice!\n   Please enter (1-2) only.\n";
                        }
                    }
                    else {
                        printLine(); csp("⏎ Press Enter to try again...");
                        break;
                    }
                }
            }
        }
        
        void userWithdraw() {
            double withdraw;
            int c = 0;
            while (c != 2) {
                printTitle("     📤 WITHDRAW 📤");
                cout << "💰 Current Balance: ₱" << currentUser->balance << "\n\n📤 Enter amount to withdraw: ₱";
                inputDouble(withdraw, "Enter amount to withdraw: ₱");
                buffer();
                printTitle2();
                while (c != 2) {
                    cout << "\nEnter: "; inputInt(c); buffer();
                    if (c == 1) {
                        if (validWithdraw(withdraw)) {
                            printLine(); csd();
                            currentUser->balance -= withdraw;
                            transRec(withdraw, currentUser->balance, "Withdraw");
                            c = 2;
                        }
                        else {
                            printLine(); csp("⏎ Press Enter to try again...");
                            break;
                        }
                    }
                    else if (c == 2) {
                        cout << "\n❌ Withdraw cancelled.\n";
                        printLine(); csp("⏎ Press Enter to return to the Banking Menu...");
                    }
                    else {
                        cout << "\n⚠️ Invalid choice!\n   Please enter (1-2) only.\n";
                    }
                }
            }
        }
        
        void transactionHistory(int &x) {
            x = 0;
            printTitle("     📜 TRANSACTION HISTORY 📜");
            cout << "[1] 📥 Deposit Transaction\n\n[2] 📤 Withdraw Transaction\n\n[3] 📜 All Transaction\n\n[4] 🔙 Back\n\n";
            while (true) {
                cout << "Select an option: "; inputInt(x); buffer(); cout << endl;
                if (x >= 1 && x <= 4) {
                    printLine(); csd();
                    break;
                }
                else {
                    cout << "\n⚠️ Invalid choice!\n   Please enter (1-4) only!\n\n";
                }
            }
        }
        
        void depositTrans() {
            int x = 0;
            double y = 0;
            printTitle("     📥 DEPOSIT TRANSACTION 📥");
            for (auto ut: trans) {
                if (ut->user == currentUser && ut->type == "Deposit") {
                    printLine2();
                    cout << "\n💰 Amount: +₱" << ut->amount << "\n💼 Balance After: ₱" << ut->balanceAfter << "\n📅 Date & Time: " << ut->date << endl;
                    y += ut->amount;
                    x++;
                }
            }
            printLine2();
            cout << "\n\n📥 Number of " << (x == 1 ? "Deposit: " : "Deposits: ") << x << "\n💰 Total Deposited: " << y << endl;
            printLine(); csp("⏎ Press Enter to return to the\n  Transaction History Menu...");
        }
        
        void withdrawTrans() {
            int x = 0;
            double y = 0;
            printTitle("     📤 WITHDRAW TRANSACTION 📤");
            for (auto ut: trans) {
                if (ut->user == currentUser && ut->type == "Withdraw") {
                    printLine2();
                    cout << "\n💰 Amount: -₱" << ut->amount << "\n💼 Balance After: ₱" << ut->balanceAfter << "\n📅 Date & Time: " << ut->date << endl;
                    y += ut->amount;
                    x++;
                }
            }
            printLine2();
            cout << "\n\n📤 Number of " << (x == 1 ? "Withdrawal: " : "Withdrawals: ") << x << "\n💸 Total Withdrawn: " << y << endl;
            printLine(); csp("⏎ Press Enter to return to the\n  Transaction History Menu...");
        }
        
        void allTrans() {
            int x = 0, y = 0;
            double a = 0, b = 0;
            printTitle("     📜 ALL TRANSACTION 📜");
            for (auto ut: trans) {
                if (ut->user == currentUser) {
                    string c = ut->type == "Deposit" ? "+" : "-";
                    printLine2();
                    cout << "\n🧾 Transaction Type: " << ut->type << "\n💰 Amount: " << (c + "₱") << ut->amount << "\n💼 Balance After: ₱" << ut->balanceAfter << "\n📅 Date & Time: " << ut->date << endl;
                    if (ut->type == "Deposit") { x++; } else { y++; }
                    (ut->type == "Deposit") ? a+=ut->amount : b+=ut->amount;
                }
            }
            printLine2();
            cout << "\n\n📥 Number of " << (x == 1 ? "Deposit: " : "Deposits: ") << x << "\n📤 Number of " << (y == 1 ? "Withdrawal: " : "Withdrawals: ")  << y << "\n\n";
            cout << "💰 Total deposited: " << a << "\n💸 Total withdrawn: " << b << endl;
            printLine(); csp("⏎ Press Enter to return to the Transaction\n  History Menu...");
        }
        
        void help() {
            printTitle("     📘 HELP 📘");
            cout << "📖 How to Use my Banking System\n\n1️⃣ Register:\n";
            cout << " 👤 Username: Must be unique, 6-20 characters\n    length and no spaces allowed.\n";
            cout << " 🔐 Pincode: Must be exactly 6 digits\n    (numbers only).\n";
            cout << " 💰 Starting balance is set to 0\n";
            printLine(); csp("⏎ Press Enter to go to the next page...");
            printTitle("     📘 HELP 📘");
            cout << "📖 How to Use my Banking System\n\n2️⃣ Login:\n 👤 Enter your exact username\n 🔐 Enter correct 6-digit pincode.\n";
            cout << " ✅ Once logged in, you can:\n    📥 Deposit money\n    📤 Withdraw money\n    💰 View current balance\n    🧾 View transaction history\n";
            printLine(); csp("⏎ Press Enter to go to the next page...");
            printTitle("     📘 HELP 📘");
            cout << "📖 How to Use my Banking System\n\n💾 Saving Your Data:\n 💡 Always select 5 (Save and Exit) before\n    closing the app.\n";
            cout << " ⚠️ Closing any other way, will NOT save your\n    data.\n\n";
            cout << "🔐 Security Tips:\n 🔒 Keep your pincode private.\n 🛑 Make sure to save before exiting to protect\n    your data.\n";
            printLine(); csp("⏎ Press Enter to return to the\n  Banking System Menu...");
        }
        
        void credits() {
            printTitle("    👤 CREDITS 👤");
            cout << "👤 Created by: CALMCHY\n🧪 Project: Banking System (Self Project)\n📅 Date: June 12 2025 - July 18 2025\n"; 
            cout << "💻 Programming Language used: C++\n🧠 Programming Concepts Applied:\n   ⚡ Input Validation\n   ⚡ Vectors\n   ⚡ Pointers\n   ⚡ Structures\n   ⚡ OOP\n   ⚡ File Handling\n   ⚡ Menu System\n";
            cout << "📦 Version: 1.0\n🙏 Special Thanks: Programiz\n";
            printLine(); csp("⏎ Press Enter to return to the\n  Banking System Menu...");
        }
};

int main() {
    bank b;
    int choice1, choice2, choice3;
    b.loadUserData();
    do {
        bool isLogin = false;
        b.mainMenu(choice1);
        switch (choice1) {
            case 1:
                b.userRegister();
                break;
            case 2:
                b.userLogin(isLogin);
                if (isLogin) {
                    do {
                        b.loginMenu(choice2);
                        switch (choice2) {
                            case 1:
                                b.userDeposit();
                                break;
                            case 2:
                                b.userWithdraw();
                                break;
                            case 3:
                                do {
                                b.transactionHistory(choice3);
                                    switch (choice3) {
                                        case 1:
                                            b.depositTrans();
                                            break;
                                        case 2:
                                            b.withdrawTrans();
                                            break;
                                        case 3:
                                            b.allTrans();
                                            break;
                                        case 4:
                                            break;
                                    }
                                }
                                while (choice3 != 4);
                                break;
                            case 4:
                                break;
                        }
                    }
                    while (choice2 != 4);
                }
                break;
            case 3:
                b.help();
                break;
            case 4:
                b.credits(); 
                break;
            case 5:
                b.saveUserData();
                break;
        }
    }
    while (choice1 != 5);
    return 0;
}