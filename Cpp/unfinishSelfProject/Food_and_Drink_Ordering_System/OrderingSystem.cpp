#include <iostream>
#include <string>
#include <vector>
#include <limits>

class userAccount {
	protected:
		std::string username;
		std::string password;
		std::string role;

	public:
		userAccount(std::string usr, std::string pswd, std::string rl) : username(usr), password(pswd), role(rl) {}

		virtual void userRegister() = 0;

		virtual bool userLogin(const std::string& usr, const std::string& pswd) = 0;
		
		std::string getUsername() {
			return username;
		}
		
		std::string getRole() {
			return role;
		}	
};

std::vector<userAccount*> users;

class accountManager : public userAccount {
	public:
		accountManager(std::string usr, std::string pswd, std::string rl) : userAccount(usr, pswd, rl) {}
		
		void userRegister() override {
			users.push_back(new accountManager(username, password, role));
			//std::cout << "Registered as [" << role << "]" << std::endl;
		}

		bool userLogin(const std::string& usr, const std::string& pswd) override {
			return (usr == username && pswd == password);
		}
};

struct product {
	std::string name;
	double price;
};

struct orderItem {
	std::string foodName;
	std::string mailCourse;
	double price;
	int quantitiy;
	double totalPrice;

	orderItem(std::string fn, std::string mc, double prc, int qty) : foodName(fn), mailCourse(mc), price(prc), quantitiy(qty) {
		totalPrice = price * qty;
	}
};

class userOrder {
	private:
		userAccount* user;
		std::vector<orderItem> items;
		double finalTotal = 0;
		double cash = 0;
		double change = 0;
		std::string dateOrder;

	public:
		userOrder(userAccount* usr) : user(usr) {}

		void addItem(const orderItem& oi) {
			items.push_back(oi);
			finalTotal += oi.totalPrice;
		}

		void setPayment(double amount) {
			cash = amount;
			if (cash >= finalTotal) {
				change = cash - finalTotal;
			}
		}

		void showReceipt() {
			// coming soon
		}
};

std::vector<userOrder*> userAllOrder;

class productMenu {
	private:
		std::vector<product> appetizer = {
			{"Fried Spring Rolls", 55},
			{"Quail Egg Fritters (4 pcs)", 40},
			{"Tofu with Pork", 65},
			{"Crispy Pork Rinds", 75}
		};

		std::vector<product> salad = {
			{"Green Mango Salad", 50},
			{"Grilled Eggplant Salad", 45},
			{"Cucumber & Tomato Salad", 40},
			{"Pickled Papaya", 30}
		};

		std::vector<product> mainDish = {
			{"Chicken Adobo", 120},
			{"Pork Sour Soup", 130},
			{"Beef Tomato Stew", 140},
			{"Beef Steak", 125}
		};

		std::vector<product> drinks = {
			{"Bottled Water", 20},
			{"Coconut Juice", 35},
			{"Pineapple Juice", 25},
			{"Lemon Juice", 30}
		};

		std::vector<product> desserts = {
			{"Caramel", 45},
			{"Halo-Halo", 65},
			{"Fried Banana Roll", 30},
			{"Macaroni Salad", 60}
		};

		std::vector<product> hitDrinks = {
			{"Iced Barako Coffe", 65},
			{"Brown Sugar Milk Tea", 70},
			{"Green Tea", 50},
			{"Hot Chocolate", 40}
		};
		
	public:
		void buyOrder(userAccount* user, std::string fn, std::string mc, double prc, int qty, double cp) {
			userOrder* order = new userOrder(user);
			orderItem item(fn, mc, prc, qty);
			order->addItem(item);
			order->setPayment(cp);
			userAllOrder.push_back(order);
		}

		void printProducts(int mailCourseNum) {
			int i = 1;
			switch (mailCourseNum) {
				case 1:
					std::cout << "APPETIZERS" << std::endl;
					std::cout << " Name\t\tPrice" << std::endl;
					for (auto p : appetizer) {
						std::cout << "[" << i << "] " << p.name << "\t" << p.price << std::endl;
						i++;
					}
					break;
				case 2:
					std::cout << "SALAD" << std::endl;
					std::cout << " Name\t\tPrice" << std::endl;
					for (auto p : salad) {
						std::cout << "[" << i << "] " << p.name << "\t" << p.price << std::endl;
						i++;
					}
					break;
				case 3:
					std::cout << "MAIN DISH" << std::endl;
					std::cout << " Name\t\tPrice" << std::endl;
					for (auto p : appetizer) {
						std::cout << "[" << i << "] " << p.name << "\t" << p.price << std::endl;
						i++;
					}
					break;
				case 4:
					std::cout << "DRINKS" << std::endl;
					std::cout << " Name\t\tPrice" << std::endl;
					for (auto p : appetizer) {
						std::cout << "[" << i << "] " << p.name << "\t" << p.price << std::endl;
						i++;
					}
					break;
				case 5:
					std::cout << "DRINKS" << std::endl;
					std::cout << " Name\t\tPrice" << std::endl;
					for (auto p : appetizer) {
						std::cout << "[" << i << "] " << p.name << "\t" << p.price << std::endl;
						i++;
					}
					break;
				case 6:
					std::cout << "DRINKS" << std::endl;
					std::cout << " Name\t\tPrice" << std::endl;
					for (auto p : appetizer) {
						std::cout << "[" << i << "] " << p.name << "\t" << p.price << std::endl;
						i++;
					}
					break;
			}
		}
		
		std::string getProductName(int &mailCourse, int &mailChoice) {
			switch (mailCourse) {
				case 1:
					return appetizer.at(mailChoice - 1).name;   
					break;
				case 2:
					return salad.at(mailChoice - 1).name;
					break;
				case 3:
					return mainDish.at(mailChoice - 1).name;
					break;
				case 4:
					return drinks.at(mailChoice - 1).name; 
					break;
				case 5:
					return desserts.at(mailChoice - 1).name;    
					break;
				case 6:
					return hitDrinks.at(mailChoice - 1).name;   
					break;
				default:
					return ""; // to avoid errors
			}
		}

		double getPrice(int &mailCourse, int &mailChoice) {
			switch (mailCourse) {
				case 1:
					return appetizer.at(mailChoice - 1).price;
					break;
				case 2:
					return salad.at(mailChoice - 1).price;
					break;
				case 3:
					return mainDish.at(mailChoice - 1).price;
					break;
				case 4:
					return drinks.at(mailChoice - 1).price;
					break;
				case 5:
					return desserts.at(mailChoice - 1).price;
					break;
				case 6:
					return hitDrinks.at(mailChoice - 1).price;
					break;
				default:
					return 0; // to avoid errors
			}
		}
};

class Order : public productMenu {
	private:
		userAccount* currentUser = nullptr; 
		productMenu menu;

	public:

		bool validUsername(std::string usr) {
			bool valid = true;
			if (usr.length() < 6 || usr.length() > 20) {
				std::cout << "Username must be 6 to 20 characters length!" << std::endl;
				valid = false;
			}
			for (char c : usr) {
				if (isspace(c)) {
					std::cout << "Spaces in username is not allowed!" << std::endl;
					valid = false;
					break;
				}
			}
			for (auto u : users) {
				if (usr == u->getUsername()) {
					std::cout << "Username already exists!" << std::endl;
					valid = false;
					break;
				}
			}
			return valid;
		}

		bool validPassword(std::string pswd) {
			bool valid = true;
			if (pswd.length() < 8 || pswd.length() > 16) {
				std::cout << "Password must be 8 to 16 characters length!" << std::endl;
				valid = false;
			}
			for (char c : pswd) {
				if (isspace(c)) {
					std::cout << "Spaces in password is not allowed!" << std::endl;
					valid = false;
					break;
				}
			}
			return valid;
		}

		bool loginUser(std::string usr, std::string pswd) {
			for (auto u : users) {
				if (u->userLogin(usr, pswd)) {
					currentUser = u;
					return true;
				}
			}
			return false;
		}

		void buffer() {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		void inputInt(int &x, std::string y = "Enter: ") {
			while (!(std::cin >> x)) {
				std::cout << "Invalid input!\nPlease enter numbers only.\n" << y;
				std::cin.clear();
				buffer();
			}
			buffer();
		}

		void inputDouble(double &x, std::string y = "Enter: ") {
			while (!(std::cin >> x)) {
				std::cout << "Invalid input!\nPlease enter mumbers only.\n" << y;
				std::cin.clear();
				buffer();
			}
			buffer();
		}

		void orderingSystemMenu(int &choice) {
            std::cout << "ORDERING SYSTEM MENU" << std::endl;
            std::cout << "[1] Register\n[2] Login\n[3] Exit" << std::endl;
            while (true) {
            	std::cout << "Enter: ";
            	inputInt(choice);
            	if (choice < 1 || choice > 3) {
            		std::cout << "Invalid choice!" << std::endl;
            		std::cout << "Please enter 1 to 3 only." << std::endl;
            	}
            	else {
            		break;
            	}
            }
        }

		void registerUser() {
			std::string usr, pswd;
			int choice = 0;
			while (choice != 2) {
				std::cout << "REGISTER ACCOUNT" << std::endl;
				std::cout << "Enter your username: ";
				std::getline(std::cin, usr);
				std::cout << "Enter your password: ";
				std::getline(std::cin, pswd);
				std::cout << "[1] Confirm [2] Cancel" << std::endl;
				while (choice != 2) {
					std::cout << "Enter: ";
					inputInt(choice);

					if (choice == 1) {
						bool validUser = validUsername(usr);
						bool validPass = validPassword(pswd);
						if (validUser && validPass) {
							accountManager newUser(usr, pswd, "guest");
							newUser.userRegister();
							
							std::cout << "Register successfully!" << std::endl;
							choice = 2;
						} else {
							break;
						}
					} else if (choice == 2) {
						std::cout << "Register cancel!" << std::endl;
					} else {
						std::cout << "Invalid chocie!" << std::endl;
						std::cout << "Please enter 1 to 2 only." << std::endl;
					}
				}
				std::cout << std::endl;
			}
		}

		void loginUser(bool &isLogin) {
			std::string usr, pswd;
			int choice = 0;
			while (choice != 2) {
				std::cout << "LOGIN ACCOUNT" << std::endl;
				std::cout << "Username: ";
				std::getline(std::cin, usr);
				std::cout << "Password: ";
				std::getline(std::cin, pswd);
				std::cout << "[1] Confirm [2] Cancel" << std::endl;
				while (choice != 2) {
					std::cout << "Enter: ";
					inputInt(choice);

					if (choice == 1) {
						if (loginUser(usr, pswd)) {
							std::cout << "Login successfully!" << std::endl;
							isLogin = true;
							choice = 2;
						} else {
							std::cout << "Invalid username or password!" << std::endl;
							break;
						}
					} else if (choice == 2) {
						std::cout << "Login cancel!" << std::endl;
					} else {
						std::cout << "Invalid choice!" << std::endl;
						std::cout << "Please enter 1 to 2 only." << std::endl;
					}
				}
			}
			std::cout << std::endl;
		}

		void oderingMenu(int &choice) {
			std::cout << "Ordering Menu" << std::endl;
			std::cout << "[1] Take Order\n[2] Show Receipt History\n[3] Logout\n" << std::endl;
			while (true) {
				std::cout << "Enter: ";
				inputInt(choice);

				if (choice >= 1 && choice <= 3) {
					break;
				} else {
					std::cout << "Invalid choice!" << std::endl;
					std::cout << "Please enter 1 to 3 only." << std::endl;
				}
			}
			std::cout << std::endl;
		}

		void takingOrder(int &choice) {
			std::cout << "TAKING ORDER" << std::endl;
			std::cout << "[1] Order Foods\n[2] Buy Order Foods\n[3] Back" << std::endl;
			while (true) {
				std::cout << "Enter: ";
				inputInt(choice);

				if (choice >= 1 && choice <= 3) {
					break;
				} else {
					std::cout << "Invalid choice!" << std::endl;
					std::cout << "Please enter 1 to 3 only." << std::endl;
				}
			}
			std::cout << std::endl;
		}

		void chooseMealCourse(int &choice) {
			std::cout << "CHOOSE MEAL COURSE" << std::endl;
			std::cout << "[1] APPETIZERS\n[2] SALAD\n[3] MAIN DISH\n";
			std::cout << "[4] DRINKS\n[5] HIT DRINKS\n[6] DESSERTS\n";
			std::cout << "[7] BACK\n";

			while (true) {
				std::cout << "Enter: ";
				inputInt(choice);
				if (choice >= 1 && choice <= 7) {
					break;
				} else {
					std::cout << "Invalid choice!" << std::endl;
					std::cout << "Please enter 1 to 7 only." << std::endl;
				}
			}
			std::cout << std::endl;
		}

		void pickOrder(int &course, int &choice) {
			int qty = 0;
			
			printProducts(course);
			std::cout << "Enter: ";
			inputInt(choice);
			
			if (choice != 7) {
				std::cout << "Enter quantity: ";
				inputInt(qty);
				// later add the ordername and quantity in stock
			}
		}

		void buyOrderFoods() {
			
		}

};

int main() {
	int choice1 = 0, choice2 = 0, choice3 = 0, choice4 = 0;
	Order od;

	do {
		bool isLogin = false;
		od.orderingSystemMenu(choice1); // show the main menu
		switch (choice1) {
			case 1: // User Register Account
				od.registerUser(); // show|input the user register
				break;
			case 2: // User Login Account
				od.loginUser(isLogin); // show|input the user login
				if (isLogin) { // check if login 
					do {
						od.oderingMenu(choice2); // show the ordering menu
							if (choice2 == 1) { //  Taking Order
								do {
									od.takingOrder(choice3); // show choices for order foods, buy order foods and Back
									if (choice3 == 1) { // Order Foods
										do {
											od.chooseMealCourse(choice4); // show meal courses Appetizer to Hit drinks
											
										}
										while (choice4 != 7);
										
									}
									else if (choice3 == 2) { // Buy Order Foods
										
									}
									else if (choice3 == 3) { // back
										
									}
								}
								while (choice3 != 3);
							}
							else if (choice2 == 2) { // Show Receipt
								
							}
							else if (choice2 == 3) { // Logout
								
							}
					} while (choice2 != 3);
				} // if (isLogin)
				break;
			case 3: // Save and Exit
				break;
		}
	} while (choice1 != 3);
	return 0;
}
