#include <iostream>
#include <string>

double addition(double x, double y) {
	return x + y;
}

double subtraction(double x, double y) {
	return x - y;
}

double multiplacation(double x, double y) {
	return x * y;
}

double devide(double x, double y) {
	return x / y;
}

int modulo(int x, int y) {
	return static_cast<int> (x % y);
}

int main() {
	double x, y;
	char op, again;

	do {
		std::cout << "Enter your first number: ";
		std::cin >> x;
		std::cout << "Enter your operator (+, -, *, /, %): ";
		std::cin >> op;
		std::cout << "Enter your second number: ";
		std::cin >> y;

		switch (op) {
			case '+':
				std::cout << addition(x, y);
				break;
			case '-':
				std::cout << subtraction(x, y);
				break;
			case '*':
				std::cout << multiplacation(x, y);
				break;
			case '/':
				if (y != 0) {
					std::cout << devide(x, y);
				}
				else {
					std::cout << "You cant devide by zero!";
				}
				break;
			case '%':
				std::cout << modulo(x, y);
				break;
			default:
				std::cout << "Invalid chooce!";
		}
		while (true) {
			std::cout << "\nDo you want to try again (Y/N): ";
			std::cin >> again;
			again = toupper(again);
			if (again != 'Y' || again != 'N') {
				break;
			}
			else {
				std::cout << "Invalid choice!" << std::endl;
			}
		}
	}
	while (again != 'N');
	return 0;
}
