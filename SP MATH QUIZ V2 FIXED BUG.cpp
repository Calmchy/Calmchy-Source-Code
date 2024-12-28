#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

// noob code fr XD
int main();
int func = 1;
int score1 = 0;
int score2 = 0;
int score3 = 0;
int score4 = 0;
string cc1; 
string cc2 = "hello";
string cc3 = "calm";
string cc4 = "Mind";
string cc5 = "Chy";

void score(int& score1, int& score2, int& score3, int& score4) {
	string stat = " ";
	
	if (cc1 == cc2) {
		stat = "\t\t   Cheat true! -_-";
	}
	else {
		stat = "\t\t   Cheat false! ^∆^";
	}
	
	int total = score1 + score2 + score3 + score4;
	double percentage = total*2;
	
	string rate;
	if (total >= 1 && total <= 7) { 
		rate = "★☆☆☆☆    \t     ";
	}
	else if (total >= 8 && total <= 12) {
		rate = "★★☆☆☆    \t     ";
	}
	else if (total >= 13 && total <= 22) {
		rate = "★★★☆☆    \t     ";
	}
	else if (total >= 23 && total <= 28) {
		rate = "★★★★☆    \t     ";
	}
	else if (total >= 29 && total <= 30) {
		rate = "★★★★★    \t     ";
	}
	else {
		rate = "☆☆☆☆☆    \t     ";
	}
	
	system("cls");
	cout << fixed << setprecision(2);
	textcolor(6);
	cout << "#=================================================#\n#";
	textcolor(3);
	cout << "\t\t     MATH: QUIZ\t\t\t";
	textcolor(6);
	cout << "  #\n#=================================================#\n"; /////
	cout << "#     ";
	textcolor(2);
	cout << "    Easy: " << score1 << "/5";
	textcolor(1);
	cout << "\t    Medium: " << score2 << "/10";
	textcolor(6);
	cout << "\t  #\n#     ";
	textcolor(4);
	cout << "    Hard: " << score3 << "/15";
	textcolor(6);
	cout << "\t";
	textcolor(12);
	cout << "    IMPOSSIBLE: " << score4 << "/20";
	textcolor(6);
	cout << "\t\t#\n#=================================================#\n#";	
	textcolor(13);
	cout << "\t\tTotal scores: " << total << "/50";
	textcolor(6);
	cout << "\t\t  #\n#\t";
	textcolor(13);
	cout << "\tPercentage: " << percentage << "%";
	textcolor(6);
	cout << "\t\t\t#\n#";
	textcolor(13);
	cout << "\t\tRating: " << rate;
	textcolor(6);
	cout << "\t\t\t#\n";
	cout << "#=================================================#\n";
	cout << stat << endl;
	system("pause");
	main();
}

void cheat() {
	
	cout << "\n#=================================================#\n";
	cout << "#\tMATH QUIZ\t\tCHEAT CODE\t  #\n";
	cout << "#=================================================#\n";
	cout << "\n\n\tEnter cheat code: ";
	cin >> cc1;
	
	if (cc1 == cc2) {
		score1 = 5, score2 = 10, score3 = 15, score4 = 20;
		cout << "\n\tCheat code activate!\n\tAuto correct answer\'s✓\n\tAuto perfect score\'s√\n";
	}
	else {
		score1 = 0, score2 = 0, score3 = 0, score4 = 0;
		cout << "\n\tCheat code incorrect!\n\tScore\'s change to default\n";
	}
	
	cout << "\n" << system("pause") << endl;
	system("cls");
	main();
}

void easy(int& score1) {
	
	srand(time(NULL));
	
	int num[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int input[5] = {0, 0, 0, 0, 0};
	int data[10] = {10, 10, 10, 10, 15, 10, 15, 10, 15, 10};
	int data2[10] = {1, 1, 1, 1, 1, 2, 1, 2, 1, 2};
	string op[10] = {" + ", " - ", " * ", " / ", " % "};
	string stat = " ";
	
    for (int i = 0; i < 10; ++i) {
    	num[i] = (rand() % data[i]) + data2[i];
    }
	
	system("cls");
		
	//DISPLAY
	textcolor(2);
	cout << "#=================================================#\n";
	cout << "#\t";
	cout << "MATH QUIZ\t\tMODE: EASY😇 ";
	cout << "\t  #\n";
	cout << "#=================================================#\n";	
	
	int j[5] = {0, 2, 4, 6, 8};
	int k[5] = {1, 3, 5, 7, 9};
	
	for (int i = 0; i < 5; ++i) {
		cout << "\t" << i + 1 << ". " << num[j[i]] << op[i] << num[k[i]] << " = ?\t\tInput: ";
		while(!(cin >> input[i])) {	
			cout << "Error:  " << i + 1 << ". " << num[j[i]] << op[i] << num[k[i]] << " = ?\t\tInput: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	system("pause");
	
	system("cls");
	
	int t1[5] = {0, 0, 0, 0, 0};
	
	t1[0] = num[0] + num[1];
	t1[1] = num[2] - num[3];
	t1[2] = num[4] * num[5];
	t1[3] = num[6] / num[7];
	t1[4] = num[8] % num[9];
	
	if (cc1 == cc2) {
		for (int i = 0; i < 5; ++i) {
			input[i] = t1[i];
		}
		stat = "\t\t   Cheat true! -_-";
	}
	else {
		stat = "\t\t   Cheat false! ^∆^";
	}
	
	cout << "#=================================================#\n";
	cout << "#\t";
	cout << "MATH QUIZ\t\tMODE: EASY😇 ";
	cout << "\t #\n";
	cout << "#=================================================#\n";
	cout << "#\t\t";
	cout << "     RESULTS";
	cout << "\t\t\t  #\n";
	cout << "#=================================================#\n";
	
	for (int i = 0; i < 5; ++i) {
		(input[i] == t1[i])? cout << " " << i + 1  << ". " << num[j[i]] << op[i] << num[k[i]] << " = " << input[i] << " is Correct\n": cout << " " << i + 1  << ". " << num[j[i]] << op[i] << num[k[i]] << " = " << input[i] << " is Wrong➥Correct answer is " << t1[i] << endl;
	}
		
	int cm1[5] = {0, 0, 0, 0, 0};
	
	for (int i = 0; i < 5; ++i) {
		if (input[i] == t1[i]) {
			cm1[i] = 1;
		}
		else cm1[i] = 0;
	}
	
	int total = cm1[0] + cm1[1] + cm1[2] + cm1[3] + cm1[4];
	
	score1 = total;
	
	int average = total*20;
	
	string rate;
	if (average == 20) {
		rate = "★☆☆☆☆    \t     ";
	}
	else if (average == 40) {
		rate = "★★☆☆☆    \t     ";
	}
	else if (average == 60) {
		rate = "★★★☆☆    \t     ";
	}
	else if (average == 80) {
		rate = "★★★★☆    \t     ";
	}
	else if (average == 100) {
		rate = "★★★★★    \t     ";
	}
	else {
		rate = "☆☆☆☆☆    \t     ";
	}
	
	cout << "#=================================================#\n";
	cout << "$\t\t";
	cout << "Total score: " << total << "/5";
	cout << "\t\t  $\n$\t\t";
	cout << "Average: " << average << "% " << rate;
	cout << "  $\n";
	cout << "#=================================================#\n";	
	cout << stat << endl;
	system("pause");
	main();
}

void medium(int& score2) {
	
	srand(time(NULL));
	
	int num[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int input[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int data[20] = {25, 25, 25, 25, 25, 25, 25, 25, 25, 17, 25, 17, 25, 17, 25, 17, 25, 17, 25, 17};
	int data2[20] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 2, 10, 2, 10, 2, 10, 2, 10, 2, 10, 2};
	string op[10] = {" + ", " + ", " - ", " - ", " * ", " * ", " / ", " / ", " % ", " % " };
	string stat = " ";
	
    for (int i = 0; i < 20; ++i) {
    	num[i] = (rand() % data[i]) + data2[i];
    }
	
	system("cls");
	//DISPLAY
	textcolor(1);
	cout << "#=================================================#\n";
	cout << "$\t";
	cout << "MATH QUIZ\t\tMODE: MEDIUM😐 ";
	cout << "\t  $\n";
	cout << "#=================================================#\n";	
	
	int j[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
	int k[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	
	for (int i = 0; i < 10; ++i) {
		cout << "\t" << i + 1 << ". " << num[j[i]] << op[i] << num[k[i]] << " = ?\t\tInput: ";
		while(!(cin >> input[i])) {	
			cout << "Error:  " << i + 1 << ". " << num[j[i]] << op[i] << num[k[i]] << " = ?\t\tInput: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	system("pause");
	
	system("cls");
	
	int t1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	t1[0] = num[0] + num[1];
	t1[1] = num[2] + num[3];
	t1[2] = num[4] - num[5];
	t1[3] = num[6] - num[7];
	t1[4] = num[8] * num[9];
	t1[5] = num[10] * num[11];
	t1[6] = num[12] / num[13];
	t1[7] = num[14] / num[15];
	t1[8] = num[16] % num[17];
	t1[9] = num[18] % num[19];
	
	if (cc1 == cc2) {
		for (int i = 0; i < 10; ++i) {
			input[i] = t1[i];
		}
		stat = "\t\t   Cheat true! -_-";
	}
	else {
		stat = "\t\t   Cheat false! ^∆^";
	}
	
	cout << "#=================================================#\n";
	cout << "$\t";
	cout << "MATH QUIZ\t\tMODE: MEDIUM😐 ";
	cout << "\t $\n";
	cout << "#=================================================#\n";
	cout << "$\t\t";
	cout << "     RESULTS";
	cout << "\t\t\t  $\n";
	cout << "#=================================================#\n";
	
	for (int i = 0; i < 10; ++i) {
		(input[i] == t1[i])? cout << " " << i + 1  << ". " << num[j[i]] << op[i] << num[k[i]] << " = " << input[i] << " is Correct\n": cout << " " << i + 1  << ". " << num[j[i]] << op[i] << num[k[i]] << " = " << input[i] << " is Wrong➥Correct answer is " << t1[i] << endl;
	}
		
	int cm1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	for (int i = 0; i < 10; ++i) {
		if (input[i] == t1[i]) {
			cm1[i] = 1;
		}
		else cm1[i] = 0;
	}
	
	int total = cm1[0] + cm1[1] + cm1[2] + cm1[3] + cm1[4] + cm1[5] + cm1[6] + cm1[7] + cm1[8] + cm1[9];
	
	score2 = total;
	
	int average = total*10;
	
	string rate;
	if (average == 20) {
		rate = "★☆☆☆☆\t     ";
	}
	else if (average == 40) {
		rate = "★★☆☆☆\t     ";
	}
	else if (average == 60) {
		rate = "★★★☆☆\t     ";
	}
	else if (average == 80) {
		rate = "★★★★☆\t     ";
	}
	else if (average == 100) {
		rate = "★★★★★\t     ";
	}
	else {
		rate = "☆☆☆☆☆\t     ";
	}
	
	cout << "#=================================================#\n";
	cout << "$\t\t";
	cout << "Total score: " << total << "/10";
	cout << "\t\t  $\n$\t\t";
	cout << "Average: " << average << "% " << rate;
	cout << "  $\n";
	cout << "#=================================================#\n";	
	cout << stat << endl;
	system("pause");
	main();
}

void hard(int& score3) {
	
	srand(time(NULL));
	
	int num[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int input[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int data[30] = {35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 15, 35, 15, 35, 15, 35, 15, 35, 15, 35, 15, 35, 15, 35, 15, 35, 15};
	int data2[30] = {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 3, 15, 3, 15, 3, 15, 3, 15, 3, 15, 3, 15, 3, 15, 3, 15, 3};
	string op[15] = {" + ", " + ", " + ", " - ", " - ", " - ", " * ", " * ", " * ", " / ", " / ", " / ", " % ", " % ", " % "};
	int j[15] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28};
	int k[15] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29};
	int t1[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int cm1[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int cm = 1;
	string stat = " ";
	
    for (int i = 0; i < 30; ++i) {
    	num[i] = (rand() % data[i]) + data2[i];
    }
	
	system("cls");
	for (int w = 1; w <= 2; ++w) {
	//DISPLAY
		textcolor(4);
		cout << "#=================================================#\n";
		cout << "$\t";
		cout << "MATH QUIZ\t\tMODE:  HARD😡 ";
		cout << "\t  $\n#\t\t\tPAGE " << w << "\t\t\t  #\n";
		cout << "#=================================================#\n";	
	
	
		if (cm == 1) {
			for (int i = 0; i < 8; ++i) {
				cout << "\t" << i + 1 << ". " << num[j[i]] << op[i] << num[k[i]] << " = ?\t\tInput: ";
				while(!(cin >> input[i])) {	
					cout << "Error:  " << i + 1 << ". " << num[j[i]] << op[i] << num[k[i]] << " = ?\t\tInput: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	
				}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		else {
			for (int i = 8; i < 15; ++i) {
				cout << "\t" << i + 1 << ". " << num[j[i]] << op[i] << num[k[i]] << " = ?\t\tInput: ";
				while(!(cin >> input[i])) {	
					cout << "Error:  " << i + 1 << ". " << num[j[i]] << op[i] << num[k[i]] << " = ?\t\tInput: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	
				}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		system("pause");
		cm = 0;
		system("cls");
	}
	cm = 1;
	
	for (int i = 0; i < 3; ++i)
		{	t1[i] = num[j[i]] + num[k[i]];	}
	for (int i = 3; i < 6; ++i)
		{	t1[i] = num[j[i]] - num[k[i]];	}
	for (int i = 6; i < 9; ++i)
		{	t1[i] = num[j[i]] * num[k[i]];	}
	for (int i = 9; i < 12; ++i)
		{	t1[i] = num[j[i]] / num[k[i]];	}
	for (int i = 12; i < 15; ++i) 
		{	t1[i] = num[j[i]] % num[k[i]];	}
		
	if (cc1 == cc2) {
		for (int i = 0; i < 15; ++i) {
			input[i] = t1[i];
		}
	 stat = "\t\t   Cheat true! -_-";
	}
	else {
		stat = "\t\t   Cheat false! ^∆^";
	}
	
	for (int w = 1; w <= 2; ++w) {
		cout << "#=================================================#\n";
		cout << "$\t";
		cout << "MATH QUIZ\t\tMODE: HARD😡 ";
		cout << "\t $\n";
		cout << "#=================================================#\n";
		cout << "$\t";
		cout << "        RESULTS    PAGE " << w;
		cout << "\t\t\t$\n";
		cout << "#=================================================#\n";
	
		if (cm == 1) {
			for (int i = 0; i < 8; ++i) {
				(input[i] == t1[i])? cout << " " << i + 1  << ". " << num[j[i]] << op[i] << num[k[i]] << " = " << input[i] << " is Correct\n": cout << " " << i + 1  << ". " << num[j[i]] << op[i] << num[k[i]] << " = " << input[i] << " is Wrong➥Correct answer is " << t1[i] << endl;
			}
		}
		
		else {
			for (int i = 8; i < 15; ++i) {
				(input[i] == t1[i])? cout << " " << i + 1  << ". " << num[j[i]] << op[i] << num[k[i]] << " = " << input[i] << " is Correct\n": cout << " " << i + 1  << ". " << num[j[i]] << op[i] << num[k[i]] << " = " << input[i] << " is Wrong➥Correct answer is " << t1[i] << endl;
			}
		}
		
		for (int i = 0; i < 15; ++i) {
			if (input[i] == t1[i]) {
				cm1[i] = 1;
			}
			else cm1[i] = 0;
		}
	
		int total = cm1[0] + cm1[1] + cm1[2] + cm1[3] + cm1[4] + cm1[5] + cm1[6] + cm1[7] + cm1[8] + cm1[9] + cm1[10] + cm1[11] + cm1[12] + cm1[13] + cm1[14];
	
		score3 = total;
	
		int average = total*6.6666666667;
	
		string rate;
		if (average == 20) {
			rate = "★☆☆☆☆\t     ";
		}
		else if (average == 40) {
			rate = "★★☆☆☆\t     ";
		}
		else if (average == 60) {
			rate = "★★★☆☆\t     ";
		}
		else if (average == 80) {
			rate = "★★★★☆\t     ";
		}
		else if (average == 100) {
			rate = "★★★★★\t     ";
		}
		else {
			rate = "☆☆☆☆☆\t     ";
		}
	
		cout << "#=================================================#\n";
		cout << "$\t\t";
		cout << "Total score: " << total << "/15";
		cout << "\t\t  $\n$\t\t";
		cout << "Average: " << average << "% " << rate;
		cout << "  $\n";
		cout << "#=================================================#\n";	
		cout << stat << endl;
		system("pause");
		cm = 0;
		system("cls");
	}
	main();
}

void creator() {
	
	system("cls");
	textcolor(11);
	cout << "#=================================================#\n";
	cout << "#\tMATH QUIZ\tCREATED BY CALMCHY69\t  #\n";
	cout << "#=================================================#\n";
	cout << "\n It take\'s 9 days to finish this code\n";
	cout << " by adjusting and debugging and use of new stuff\n";
	cout << " like arrays, color text, clear screen,\n calling function to function and more\n";
	cout << "\n\n Sarang aho code ayaw pag judge dira\n 1st year IT palang ko fr;-; LOL XD\n\t\t       ʕ•ᴥ•ʔ\n";
	system("pause");
	
	main();
}

void impossible(int& score4) {
	
	srand(time(NULL));
	
	int num[40] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //  😆
	int input[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int data[40] = {49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 13, 49, 13, 49, 13, 49, 13, 49, 13, 49, 13, 49, 13, 49, 13, 49, 13, 49, 13, 49, 13, 49, 13};
	int data2[40] = {29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 21, 11, 21, 11, 21, 11, 21, 11, 13, 4, 13, 4, 13, 4, 13, 4, 13, 4, 13, 4, 13, 4, 13, 4};
	string op[20] = {" + ", " + ", " + ", " + ", " - ", " - ", " - ", " - ", " * ", " * ", " * ", " * ", " / ", " / ", " / ", " / ", " % ", " % ", " % ", " % " };
	int j[20] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38};
	int k[20] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
	int cm = 1;
	string stat = " ";
	
    for (int i = 0; i < 40; ++i) {
    	num[i] = (rand() % data[i]) + data2[i];
    }
	
	for (int b = 1; b <= 2; ++b) {
		system("cls");
		//DISPLAY
		textcolor(4);
		cout << "#=================================================#\n";
		cout << "#\t";
		cout << "MATH QUIZ\t     MODE: IMPOSSIBLE💀 ";
		cout << "\t  #\n#\t\t\tPAGE " << b << "\t\t\t  #\n";
		cout << "#=================================================#\n";	
		
		if (cm == 1) {
			for (int i = 0; i < 10; ++i) {
				cout << "\t" << i + 1 << ". " << num[j[i]] << op[i] << num[k[i]] << " = ?\t\tInput: ";
				while(!(cin >> input[i])) {	
					cout << "Error:  " << i + 1 << ". " << num[j[i]] << op[i] << num[k[i]] << " = ?\t\tInput: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	
				}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			system("pause");
			cm = 0;
		}
		else {
			for (int i = 10; i < 20; ++i) {
				cout << "\t" << i + 1 << ". " << num[j[i]] << op[i] << num[k[i]] << " = ?\t\tInput: ";
				while(!(cin >> input[i])) {	
					cout << "Error:  " << i + 1 << ". " << num[j[i]] << op[i] << num[k[i]] << " = ?\t\tInput: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');	
				}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}
	system("pause");
	system("cls");
	
	int t1[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	// -_-
	for (int i = 0; i < 4; ++i) 
		{	t1[i] = num[j[i]] + num[k[i]];	}
	for (int i = 4; i < 8; ++i)
		{	t1[i] = num[j[i]] - num[k[i]];	}
	for (int i = 8; i < 12; ++i)
		{	t1[i] = num[j[i]] * num[k[i]];	}
	for (int i = 12; i < 16; ++i)
		{	t1[i] = num[j[i]] / num[k[i]];	}
	for (int i = 16; i < 20; ++i)
		{	t1[i] = num[j[i]] % num[k[i]];	}
		
	if (cc1 == cc2) {
		for (int i = 0; i < 20; ++i) {
			input[i] = t1[i];
		}
	 stat = "\t\t   Cheat true! -_-";
	}
	else {
		stat = "\t\t   Cheat false! ^∆^";
	}
	
	cm = 1;
	
	int cm1[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int total;
	
	for (int w = 1; w <= 2; ++w) {
		cout << "#=================================================#\n";
		cout << "$\t";
		cout << "MATH QUIZ\t     MODE: IMPOSSIBLE💀 ";
		cout << "\t $\n";
		cout << "#=================================================#\n";
		cout << "$\t\t";
		cout << "  RESULTS  PAGE " << w;
		cout << "\t\t\t$\n";
		cout << "#=================================================#\n";
		
		if (cm == 1) {
			for (int i = 0; i < 10; ++i) {
				(input[i] == t1[i])? cout << " " << i + 1  << ". " << num[j[i]] << op[i] << num[k[i]] << " = " << input[i] << " is Correct\n": cout << " " << i + 1  << ". " << num[j[i]] << op[i] << num[k[i]] << " = " << input[i] << " is Wrong➥Correct answer is " << t1[i] << endl;
			}
		}
		else {
			for (int i = 10; i < 20; ++i) {
				(input[i] == t1[i])? cout << " " << i + 1  << ". " << num[j[i]] << op[i] << num[k[i]] << " = " << input[i] << " is Correct\n": cout << " " << i + 1  << ". " << num[j[i]] << op[i] << num[k[i]] << " = " << input[i] << " is Wrong➥Correct answer is " << t1[i] << endl;
			}
		}
	
		for (int i = 0; i < 20; ++i) {
			if (input[i] == t1[i]) {
				cm1[i] = 1;
			}
			else cm1[i] = 0;
		}
		
		total = cm1[0] + cm1[1] + cm1[2] + cm1[3] + cm1[4] + cm1[5] + cm1[6] + cm1[7] + cm1[8] + cm1[9] + cm1[10] + cm1[11] + cm1[12] + cm1[13] + cm1[14] + cm1[15] + cm1[16] + cm1[17] + cm1[18] + cm1[19];
		
		score4 = total;
	
		int average = total*5;
	
		string rate;
		if (average == 20) {
			rate = "★☆☆☆☆\t     ";
		}
		else if (average == 40) {
			rate = "★★☆☆☆\t     ";
		}
		else if (average == 60) {
			rate = "★★★☆☆\t     ";
		}
		else if (average == 80) {
			rate = "★★★★☆\t     ";
		}
		else if (average == 100) {
			rate = "★★★★★\t     ";
		}
		else {
			rate = "☆☆☆☆☆\t     ";
		}
	
		cout << "#=================================================#\n";
		cout << "$\t\t";
		cout << "Total score: " << total << "/20";
		cout << "\t\t  $\n$\t\t";
		cout << "Average: " << average << "% " << rate;
		cout << "  $\n";
		cout << "#=================================================#\n";	
		cout << stat << endl;
		system("pause");
		cm = 0;
		system("cls");
	}
	main();
}

void starting() {
	system("cls");
	textcolor(6);
	cout << "#<<\t\t      Cxxdroid\t\t\t>>#";
	textcolor(12);
	cout << "\n\n\t\t==>>> WARNING <<<==\n";
	textcolor(11);
	cout << "\n\tIf this (#<<) and (>>#) are not in\n";
	cout << "\tthe upper corner of your android";
	cout << "\n\tscreen. Please follow this steps\n";
	cout << "\tjust click the 3 dots > Preference\n";
	cout << "\t> Font size and change to 12 and\n";
	cout << "\trerun the code to avoid error\n";
	cout << "\t\t    thank you :)\n";
	textcolor(2);
	cout << "\n\t\t  App use Cxxdroid\n\n\n";
	textcolor(5);
	cout << "\tTab _ ⠸ <- 3 dots\n";
	textcolor(7);
	system("pause");
	main();
	system("cls");
}

int main()  {
	char a;
	string cc6, cc7, tt1, tt2, tt3, stat;
	
	if (func == 1) {
		func = 0;
		starting();
	}
	
	system("cls");
	// DISPLAY
	textcolor(6);
	cout << "#=================================================#\n";
	cout << "#\t\t";
	textcolor(11);
	cout << "     MATH QUIZ";
	textcolor(6);
	cout << "\t\t\t  #\n";
	cout << "#\t";
	textcolor(2);
	cout << "     1. EASY😇 ";
	textcolor(6);
	cout << "\t";
	textcolor(1);
	cout << "     2. MEDIUM😐 ";
	textcolor(6);
	cout << "\t\t#\n#\t";
	textcolor(4);
	cout << "     3. HARD😡 ";
	textcolor(12);
	cout << "\t";
	cout << "     4. IMPOSSIBLE💀 ";
	textcolor(6);
	cout << "\t\t#\n#\t";
	textcolor(13);
	cout << "     5. SCORE📊 ";
	textcolor(3);
	cc6 = "-_-";
	cout << "\t";
	cout << "     6. CREATOR😎 ";
	textcolor(6);
	cout << "\t\t\t#\n#";
	tt2 = cc3 + cc4;
	textcolor(14);
	cout << "\t     7. CHEAT🤫 ";
	textcolor(7);
	cc7 = "69";
	cout << "\t     8. EXIT👻 ";
	textcolor(6);
	cout << "\t\t\t#\n";
	cout << "#=================================================#\n";
	textcolor(7);
	tt3 = cc7 + cc6;
	cout << "\n\t\t     INPUT: ";
	cin >> a;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	tt1 = cc2 + cc5;
	
	textcolor(6);
	switch(a) {
	case '1':
		sleep(1);
		system("cls");
		easy(score1);
		break;
			
	case '2':
		sleep(1);
		system("cls");
		medium(score2);
		break;
			
	case '3':
		sleep(1);
		system("cls");
		hard(score3);
		break;
			
	case '4':
		sleep(1);
		system("cls");
		impossible(score4);
		break;
			
	case '5':
		sleep(1);
		system("cls");
		score(score1, score2, score3, score4);
		break;
			
	case '6':
		sleep(1);
		system("cls");
		creator();
		break;
		
	case '7':
		sleep(1);
		system("cls");
		cc2 = tt1 + tt2 + tt3;
		cheat();
		break;
			
	case '8':
		break;
		
	default:
		cout << "\n\tIvalid input :(\n\tPlease enter 1 to 7 only!\n";
		cout << "\n\t" << system("pause") << endl; // this line and the system("pause") cannot attached in c++adroid
		system("cls");
		main();
		break;
	}
	system("cls");
	return 0;
}