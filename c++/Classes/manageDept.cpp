#include <iostream>
#include <string>

using namespace std;
string n;
int i;
string d;
string p;


class Employee {
private:
	string name;
	int idNumber;
	string Department;
	string position;
public:
	Employee() {
		name = "";
		idNumber = 0;
		Department = "";
		position = "";
	}
	Employee(string n, int i, string D, string p)
	{
		name = n;
		idNumber = i;
		Department = D;
		position = p;

	}
	void setname(string name) {
		this->name = name;
	}

	void setidNumber(int idNumber) {
		this->idNumber = idNumber;
	}

	void setDepartment(string Department) {
		this->Department = Department;
	}
	void setposition(string position) {
		this->position = position;
	}


	string getname() {
		return name;
	}
	int getidNumber() {
		return idNumber;
	}
	string getDepartment() {
		return Department;
	}
	string getposition() {
		return position;
	}

	void input() {
		cout << "Enter Your Name: ";
		getline(cin, name);
		cout << "Enter Your Id Number: ";
		cin >> idNumber;
		cout << "Enter Your Department: ";
		cin.ignore();
		getline(cin, Department);
		cout << "Enter Your Position: ";
		getline(cin, position);

	}


	void output() {
		cout << "\n";
		cout << name <<"\t\t\t"<< idNumber<<"\t\t\t" << Department <<"\t\t\t"<< position << endl;
	
	}
};


int main() {

	Employee E, E1, E2("Fahad",302, "BSCS", "Programar");
	E.input();
	

	E1.setname("Haris");
	E1.setidNumber(394);
	E1.setDepartment("BSCS");
	E1.setposition("CEO");
	cout << "\n";
	cout << "\n";
	cout << "\t\t\t\t " << "	Display Data: \n";
	cout << "\n";
	cout << "\n";
	cout << "   NAME " << "          \tidNumber" << "      \t     Department " << "       \t     Position " << endl;
	cout << "\n";
	cout << E1.getname()  << "\t\t\t"<<E1.getidNumber() <<"\t\t\t"<< E1.getDepartment() <<"\t\t\t"<<E1.getposition() << endl;
	
	E.output();


	E2.output();


	system("pause");


}
