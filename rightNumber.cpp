#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	bool rightNumber = true;
	do {
		if (!rightNumber) {
			cout << "ERROR! Incorrect value!" << endl;
			rightNumber = !rightNumber;
		}
		
		cout << "Enter number: ";
		string number = "\0";
		cin >> number;
		
		bool minus = false;
		if (number[0] == 45) {
			minus = true;
			for (int i = 1; i < number.length(); i++) {
				if (number[0] == number[i]) {
					rightNumber = false;
					cout << "ERROR! Недопустимо использовать больше одного знака в числе!\n";
					break;
				}
			}
			if (!rightNumber)
				continue;
		}
		
		bool point = false;
		int pointNumber;
		for (int i = 0; i < number.length(); i++) {
			if (number[i] == 46) {
				point = true;
				pointNumber = i;
				number[pointNumber] = '0';
				break;
			}
		}
		
		//я пытался как мог избежать тупого сравнения и хотел оптимизировать код, но пока не получается. я посмотрю в разборе. вполне вероятно, что уровень знаний достаточный, просто я дурак.
		
		if (minus && point && number.length() < 3) {
			rightNumber = false;
			cout << "ERROR! Введите хотя бы одну цифру!\n";
			continue;
		} 
		
		if (point && number.length() < 2) {
			rightNumber = false;
			cout << "ERROR! Введите хотя бы одну цифру!\n";
			continue;
		}
		
		if (minus && number.length() < 2) {
			rightNumber = false;
			cout << "ERROR! Введите хотя бы одну цифру!\n";
			continue;
		}
		
		if (point) {
			for (int i = pointNumber + 1; i < number.length(); i++) {
				if (number[i] == 46) {
					rightNumber = false;
					cout << "ERROR! Недопустимо использовать больше двух точек в числе!\n";
					break;
				}
			}	
			if (!rightNumber)
				continue;
		}
		
		int index = 0;
		if (minus) { 
			++index;
		}
		for (; index < number.length(); index++) {
			if (number[index] >= 48 && number[index] <= 57) {
					rightNumber = true;
			} else {
				rightNumber = false;
				cout << "ERROR! Недопустимый ввод данных!\n";
				break;
			}
		}
		if (!rightNumber)
			continue;
			
		
		cout << "Value is accepted!\n";
						
	} while (true);
	return 0;
}