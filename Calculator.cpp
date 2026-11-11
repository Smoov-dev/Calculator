#include <iostream>
#include <string>
#include <fstream>

constexpr double PI = 3.14159265;


double divide(double n1, double n2)
{
	if (n2 != 0) {
		return n1 / n2;
	}
	else {
		std::cout << "You can't divide by ";
		return 0;
	}
}

int factorial(int n)
{
	if (n < 0) {
		std::cout << "You can't calculate the factorial of a negative number";
		return 0;
	}
	else if (n == 0) {
		return 1;
	}
	else {
		int fact{ 1 };
		for (int i = 1; i <= n; ++i) {
			fact *= i;
		}
		return fact;
	}
}

std::string history[100];

void saveHistory(int i, std::string operation)
{
	history[i] = operation;
}



void printHistory(int i)
{
	for (int j = 0; j < i; j++) {
		std::cout <<"[" << j+1  << "] " << history[j] << '\n';
	}
	char option{};


	std::cout << "Do you want to [c]lear or [s]ave history?";
	std::cin >> option;

	if (option == 'c') {
		for (int k = 0; k < i; k++) {
			history[k] = "";
		}
		std::ofstream MyFile("history.txt", std::ofstream::out | std::ofstream::trunc);
		std::cout << "History cleared.\n";
	}
	else if (option == 's') {
		std::ofstream MyFile("history.txt");
		for (int k = 0; k < i; k++) {
			MyFile << history[k] << '\n';
		}
		MyFile.close();
		std::cout << "History saved.\n";
	}
}

void recoverHistory(int& i)
{
	std::ifstream MyFile("history.txt");
	std::string line;
	while (std::getline(MyFile, line)) {
		history[i] = line;
		i++;
	}
	MyFile.close();
}

double calculate( int i, double n1, char op, double n2 = 0)
{
	/*int n1{};
	double e { 2.718281828 };
	if (sn1 != 'e') {
		n1 = static_cast<int>(sn1);
	}
	else n1 = 2.718281828;*/

	std::string operation;

	switch (op)
	{
		case '+':
			operation = std::to_string(n1) + " + " + std::to_string(n2) + " = " + std::to_string(n1 + n2);
			saveHistory(i, operation);
			return n1 + n2;
			break;
		case '-':
			operation = std::to_string(n1) + " - " + std::to_string(n2) + " = " + std::to_string(n1 - n2);
			saveHistory(i, operation);
			return n1 - n2;
			break;
		case '*':
			operation = std::to_string(n1) + " * " + std::to_string(n2) + " = " + std::to_string(n1 * n2);
			saveHistory(i, operation);
			return n1 * n2;
			break;
		case '/':
			operation = std::to_string(n1) + " / " + std::to_string(n2) + " = " + std::to_string(n1 / n2);
			saveHistory(i, operation);
			return divide(n1, n2);
			break;
		case '%':
		{
			int in1;
			int in2;
			in1 = static_cast<int>(n1);
			in2 = static_cast<int>(n2);
			
			if (in2 != 0) {
				operation = std::to_string(in1) + " % " + std::to_string(in2) + " = " + std::to_string(in1 % in2);
				saveHistory(i, operation);
				return in1 % in2;
			}
			else std::cout << "You can't divide by 0";
		}	
			break;
		case '^':
			if (n1 == 0 && n2 <= 0) {
				std::cout << "You can't calculate 0 raised to a non-positive number";
				return 0;
			}
			operation = std::to_string(n1) + " ^ " + std::to_string(n2) + " = " + std::to_string(pow(n1, n2));
			saveHistory(i, operation);
			return pow(n1, n2);
			break;
		case 's':
			if (n1 < 0) {
				std::cout << "You can't calculate the square root of a negative number";
				return 0;
			}
			operation = std::to_string(n1) + " = " + std::to_string(sqrt(n1));
			saveHistory(i, operation);
			return sqrt(n1);
			break;
		case 'c':
			operation = std::to_string(n1) + " = " + std::to_string(cbrt(n1));
			saveHistory(i, operation);
			return cbrt(n1);
			break;
		case 'a':
			operation = std::to_string(n1) + " = " + std::to_string(abs(n1));
			saveHistory(i, operation);
			return abs(n1);
			break;
		case 'f':
		{
			int in1 = static_cast<int>(n1);
			int result = factorial(in1);
			operation = std::to_string(n1) + "!  = " + std::to_string(result);
			saveHistory(i, operation);
			return result;
			break;
		}
				
		case 'l':
			if (n1 <= 0) {
				std::cout << "You can't calculate the logarithm of a non-positive number";
				return 0;
			}
			operation = "ln(" + std::to_string(n1) + ") = " + std::to_string(log(n1));
			saveHistory(i, operation);
			return log(n1);
			break;
		case 'g':
			if (n1 <= 0) {
				std::cout << "You can't calculate the logarithm of a non-positive number";
				return 0;
			}
			operation = "log10(" + std::to_string(n1) + ") = " + std::to_string(log10(n1));
			saveHistory(i, operation);
			return log10(n1);
			break;
		case 'i':
			operation = "sin(" + std::to_string(n1) + ") = " + std::to_string(sin(n1));
			saveHistory(i, operation);
			return sin(n1);
			break;
		case 'o':
			operation = "cos(" + std::to_string(n1) + ") = " + std::to_string(cos(n1));
			saveHistory(i, operation);
			return cos(n1);
			break;
		case 't':
			operation = "tan(" + std::to_string(n1) + ") = " + std::to_string(tan(n1));
			saveHistory(i, operation);
			return tan(n1);
			break;
		case 'e':
			exit(0);
			break;
	}
}

int main()
{
	double n1{};
	double n2{};
	char op{};
	bool cont{true};
	char answer{};
	int i{ 0 };
	recoverHistory(i);

    std::cout << "Calculator\n";
	while (cont) {
		std::cout << "Select operation (+, -, *, /, %, ^, [s]qrt, [c]brt, [a]bs, [f]actorial,[l]n, lo[g]10, s[i]n, c[o]s, [t]an), [h]istory, [e]xit: ";
		std::cin >> op;
		if (op == 'h') {
			if (i == 0) {
				std::cout << "No history yet\n";
			}
			else
			printHistory(i);
		} 
		else{
			std::cout << "Input number: ";
			std::cin >> n1;
			if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '^'){
				std::cout << "Input a 2nd number: ";
				std::cin >> n2;
			}
			else if (op == 'i' || op == 'o' || op == 't') {
				char radConf{};
				std::cout << "Do you want to use radians? (y/n): ";
				std::cin >> radConf;
				if (radConf == 'n') {
					n1 = n1 * (PI / 180);
				}
				else if (radConf != 'y') {
					std::cout << "Invalid input. Assuming radians.\n";
				}
				else {
					n1 = n1;
				}
			}
			
			
			std::cout <<"Result: " << calculate(i, n1, op, n2) << '\n';
			i++;
		}
		std::cout << "Continue? (y/n): ";
		std::cin >> answer;
		if (answer == 'n') {
			cont = false;
			break;
		}
	}
}

