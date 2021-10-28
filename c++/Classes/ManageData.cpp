
#include<iostream>
#include<string>
using namespace std;
class student
{
private:
	string id;
	string name;
	string dept;
public:

	student()
	{
		id = "";
		name = "";
		dept = "";
	}

	student(string x)
	{
		
		id = x;
	}
	student(string a, string b, string c)
	{
		
		id = a;
		
		name = b;

		dept = c;
	}

	student(string w, string h)
	{
		
			name = w;
			
		dept = h;
	}
	void input()
	{
		
		cout << " Enter name " << endl;

		cin >> this->name;
		cout << " Enter id no " << endl;
		cin >> this->id;
		cout << " Enter the department " << endl;
		cin >> this->dept;

	}
	void display()
	{
		
		cout << this->name << endl;
	
		cout << this->id << endl;

		cout << this->dept << endl;
	}

	~student(){
		cout << "Distructor is called\n";
	}

};
int main()
{
	student s;
	student s3;
	student s1("18f0181");
	student s2("18f0181", " Fahad ", " BSCS ");
	student s4(" Fahad ", " BSCS ");
	s3.input();
	s.display();
	s1.display();
	s2.display();
	s4.display();
	s3.display();
	system("pause");
}
