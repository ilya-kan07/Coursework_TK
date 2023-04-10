#include<iostream>
#include<string>
#include <sstream>
using namespace std;

bool Flag = false;

struct object_table {					// ��������� ������� 										
	int table_number;					// ����� �������
	int number;							// ����� ��������
	string name;						// ������

	object_table() {					// ����������� ������
		table_number = 0;
		number = 0;
		name = "none";
	}
};

void putdata(object_table* object, int a, int b, string n) {	// ������� ����� ������ � �������
	object->table_number = b;
	object->number = a;
	object->name = n;
}

void getdata(object_table* object) {			// ������� ������ ������ �� ������
	cout << object->table_number << "\t";
	cout << object->number << "\t";
	cout << object->name << endl;
}

void SplitStr(string str, string str1[])	// ������� ���������� ������ �� �����
{
	string s = "";

	int i = 0;

	for (auto x : str)
	{
		if (x == ' ')
		{
			str1[i] = s;
			i += 1;
			s = "";
		}
		else {
			s = s + x;
		}
	}
	str1[i] = s;
}

void func(string str, object_table* tab1) {		// ������� �������� �����
	if (str == tab1->name) {
		Flag = true;
		cout << str << "\t";
		cout << tab1->table_number << "\t";
		cout << tab1->number << endl;
	}
}

void func1(string str, object_table* tab1, int count) {  // ������� �������� ����� ��� 3 �������
	tab1->table_number = 3;
	tab1->number = count;
	tab1->name = str;

	cout << str << "\t";
	cout << tab1->table_number << "\t";
	cout << count << endl;



}



int main()
{
	object_table* keywords = new object_table[16];						// ������ �������� ��� �������� ����(������� 1)
	object_table* separators = new object_table[10];					// ������ �������� ��� ������������(������� 2)
	object_table* names = new object_table[7];							// ������ �������� ��� ����(������� 3)

	string keyword[]{
		"integer", "real", "boolean",
		"ass", "if", "then", "else", "for", "to",								// ������ �������� ���� ��� ������� � �������
		"do", "while", "read", "write", "or", "and", "not"
	};

	string separator[]{ "<>", "=", "<", "<=", ">", ">=", "+", "-", "*", "/" };	// ������ ������������ ��� ������� � �������


	cout << "Enter the string: ";
	string str1;						// ������, �������� �������������
	getline(cin, str1);
	string arr[7];						// ������, � ������� ����� ������������ ����� �� ������
	SplitStr(str1, arr);


	cout << "table\t" << "number\t" << "name" << endl;		// ������� ������� 1 � 2

	for (int i = 0; i < 16; i++) {							// ���� ������ � ������� 1
		putdata(&keywords[i], i + 1, 1, keyword[i]);
	}

	for (int i = 0; i < 16; i++) {
		getdata(&keywords[i]);
	}

	cout << endl;

	for (int i = 0; i < 10; i++) {							// ���� ������ � ������� 2
		putdata(&separators[i], i + 1, 2, separator[i]);
	}

	for (int i = 0; i < 10; i++) {
		getdata(&separators[i]);
	}

	cout << endl;
	cout << endl;
	cout << "entered string: " << endl;					//����� �������� ����
	cout << "word\t" << "table\t" << "number" << endl;
	cout << "----------------------" << endl;

	int count = 1;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 16; j++) {
			func(arr[i], &keywords[j]);
		}
		if (Flag != true) {
			for (int j = 0; j < 10; j++) {
				func(arr[i], &separators[j]);
			}
		}

		if (Flag != true) {
			func1(arr[i], &names[i], count);
			count += 1;
		}
		Flag = false;
	}



	delete[] keywords;		// ������� ������ 
	delete[] separators;

	return 0;
}

