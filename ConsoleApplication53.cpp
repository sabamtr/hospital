// ConsoleApplication53.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#include<map>
#include<fstream>
using namespace std;

multimap<string, string>savedPatient;

class Person
{
private:
	string name, family, phoneNumber,code;
	float age;
public:
	Person() {}
	Person(string c,string n,string f,float a,string phone):code(c),name(n),family(f),age(a), phoneNumber(phone){}
	void setCode(string code) { this->code = code; }
	void setName(string name) { this->name = name; }
	void setFamily(string family) { this->family = family; }
	void setAge(float age) { this->age = age; }
	void setPhone(string phone) {phoneNumber=phone; }
	string getCode() { return code; }
	string getName() const { return name; }
	string getFamily() const { return family; }
	float getAge() const { return age; }
	string getPhone() const { return phoneNumber; }
	void print()
	{
		cout <<" "<<code<<"    "<< name << "          " << family << "          " << age << "         " << phoneNumber<<"          ";
	}
};
class Patient:public Person
{
private:
	string type,DrName;
	static int count;
public:
	Patient() { count++; }
	Patient(string c,string n, string f, float a, string phone,string t,string d):Person(c,n,f,a,phone),type(t),DrName(d){}
	void setType(string type) { (*this).type = type; }
	void setDrName(string dr) { DrName = dr; }
	string getDrName() { return DrName; }
	string getType() { return type; }
	static int getNumber() { return count; }
	static void setNumber() { count--; }
	void print()
	{
		Person::print();
		cout << type <<"          " <<DrName<<endl;
	}
};
int Patient::count = 0;
class Doctor :public Person
{
private:
	string specialty;
	static int count;
public:
	Doctor() { count++; }
	Doctor(string c,string n, string f, float a, string phone,string s):Person(c,n,f,a,phone),specialty(s){}
	void setSpecialty(string specialty) { this->specialty = specialty; }
	string getSpecialty() {	return specialty;}
	static int getNumber() { return count; }
	static void setNumber() { count--; }
	void print()
	{
		Person::print();
		cout << specialty << endl;
	}
};
int Doctor::count = 0;

//######################### PATIENT ##########################

vector<Patient>p1,p2;
vector<string>p3;
fstream file1;
void first1()
{
	string code,name, family, phone,type,drName;
	float age;
	Patient p;
	cout << "\nEnter the patient's code:";
	cin >> code;
	cout << "\nEnter the patient's name:";
	cin >> name;
	cout << "\nEnter the patient's family:";
	cin >> family;
	cout << "\nEnter the patient's age:";
	cin >> age;
	cout << "\nEnter the patient's phone number:";
	cin >> phone;
	cout << "\nEnter the patient's illness:";
	cin >> type;
	cout << "\nEnter the name of the patient's doctor :";
	cin >> drName;
	savedPatient.insert(pair<string , string>(drName, name +" "+family+ "     " + type));
	p1.push_back(Patient(code,name, family, age, phone, type,drName));
	file1.open("patient.csv", ios::app);
	file1 << code+","+name + "," + family + "," + to_string(age) + "," + phone + "," + type +","+drName<< endl;
}
void displayAllPantients()
{
	cout << "\n\n\t\t All PATIENTS \n\n";
	cout << "====================================================================================================\n";
	cout << "  CODE      NAME         FAMILY        AGE          PHONE             ILNESS        DOCTOR'S NAME" << endl;
	cout << "====================================================================================================\n";
	for (int i = 0; i < p1.size(); i++)
	{
			p1[i].print();
	}
	cout << "\n\n\nNUMBER OF THE PATIENTS:" << Patient::getNumber();

}
void displayPatient(string c)
{
	cout << "\n\n\t\t All PATIENTS \n\n";
	cout << "====================================================================================================\n";
	cout << "  CODE      NAME         FAMILY        AGE          PHONE             ILNESS        DOCTOR'S NAME" << endl;
	cout << "====================================================================================================\n";
	for (int i = 0; i < p1.size(); i++)
	{
		if(p1[i].getCode() == c)
		p1[i].print();
	}
}
void modify1(string c)
{
	string a,name,family, phone, type,code,drName;
	float age;
	for (int i = 0; i < p1.size(); i++)
	{
		if (p1[i].getCode() == c)
		{
			cout << "which information do you want to modify?(code|name|family|age|phone|illness|Dr)";
			cin >> a;
			if (a == "code")
			{
				cout << "\nNew code:";
				cin >> code;
				p1[i].setCode(code);
			}
			else if (a == "name")
			{
				cout << "\nNew name:";
				cin >> name;
				p1[i].setName(name);
			}
			else if (a == "family")
			{
				cout << "\nNew family:";
				cin >> family;
				p1[i].setFamily(family);
			}
			else if (a == "age")
			{
				cout << "\nNew age:";
				cin >> age;
				p1[i].setAge(age);
			}
			else if (a == "phone")
			{
				cout << "\nNew phone number:";
				cin >> phone;
				p1[i].setPhone(phone);
			}
			else if (a == "illness")
			{
				cout << "\nNew type of illness:";
				cin >> type;
				p1[i].setType(type);
			}
			else
			{
				cout << "\nNew doctor's name:";
				cin >> drName;
				p1[i].setDrName(drName);
			}
		}
	}
}
void deleteAllPatients()
{
	p1.clear();
	cout << "    ALL INFORMATION DELETED!\n";
}
void deletePantient(string c)
{
	for (int i = 0; i < p1.size(); i++)
	{
		if (p1[i].getCode() != c)
		{
			p2.push_back(p1[i]);
			p1[i].setNumber();
		}
	}
	p1 = p2;
	cout << "   INFORMATION DELETED\n";
	vector<Patient>().swap(p2);
}
multimap<string, string>getSavedPatient()
{
	return savedPatient;
}

//######################### DOCTOR ##########################

vector<Doctor>d1, d2;
fstream file2;
void first2()
{
	string code, name, family, phone, specialty;
	float age;
	Doctor d;
	cout << "\nEnter the doctor's code:";
	cin >> code;
	cout << "\nEnter the doctor's name:";
	cin >> name;
	cout << "\nEnter the doctor's family:";
	cin >> family;
	cout << "\nEnter the doctor's age:";
	cin >> age;
	cout << "\nEnter the doctor's phone number:";
	cin >> phone;
	cout << "\nEnter the doctor's specialty:";
	cin >> specialty;
	d1.push_back(Doctor(code, name, family, age, phone, specialty));
	file2.open("doctor.csv", ios::app);
	file2 << code + "," + name + "," + family + "," + to_string(age) + "," + phone + "," + specialty << endl;
}
void displayAllDoctors()
{
	cout << "\n\n\t\t All DOCTORS \n\n";
	cout << "=================================================================================================\n";
	cout << "  CODE      NAME         FAMILY        AGE          PHONE           SPECIALTY    " << endl;
	cout << "=================================================================================================\n";
	for (int i = 0; i < d1.size(); i++)
	{
		d1[i].print();
	}
	cout << "\n\n\nNUMBER OF THE DOCTORS:" << Doctor::getNumber();

}
void displayDoctor(string c)
{
	cout << "\n\n\t\t All DOCTORS \n\n";
	cout << "=================================================================================================\n";
	cout << "  CODE      NAME         FAMILY        AGE          PHONE           SPECIALTY    " << endl;
	cout << "=================================================================================================\n";
	for (int i = 0; i < d1.size(); i++)
	{
		if (d1[i].getCode ()== c)
			d1[i].print();
	}
}
void modify2(string c)
{
	string a, name, family, phone, specialty, code;
	float age;
	for (int i = 0; i < d1.size(); i++)
	{
		if (d1[i].getCode() == c)
		{
			cout << "which information do you want to modify?(code|name|family|age|phone|specialty)";
			cin >> a;
			if (a == "code")
			{
				cout << "\nNew code:";
				cin >> code;
				d1[i].setCode(code);
			}
			else if (a == "name")
			{
				cout << "\nNew name:";
				cin >> name;
				d1[i].setName(name);
			}
			else if (a == "family")
			{
				cout << "\nNew family:";
				cin >> family;
				d1[i].setFamily(family);
			}
			else if (a == "age")
			{
				cout << "\nNew age:";
				cin >> age;
				d1[i].setAge(age);
			}
			else if (a == "phone")
			{
				cout << "\nNew phone number:";
				cin >> phone;
				d1[i].setPhone(phone);
			}
			else
				cout << "\nNew specialty:";
			cin >> specialty;
			d1[i].setSpecialty(specialty);
		}
	}
}
void deleteAllDoctors()
{
	d1.clear();
	cout << "    ALL INFORMATION DELETED!\n";
}
void deleteDoctor(string c)
{
	for (int i = 0; i < d1.size(); i++)
	{
		if (d1[i].getCode() != c)
		{
			d2.push_back(d1[i]);
			d1[i].setNumber();
		}

	}
	d1 = d2;
	cout << "   INFORMATION DELETED\n";
	vector<Doctor>().swap(d2);
}
void displaySavedPatient(string c)
{
	multimap<string, string>saved=getSavedPatient();
	cout << "=========================================\n";
	cout << "  NAME             ILNESS" << endl;
	cout << "=========================================\n";
	for (multimap<string, string>::iterator i = saved.begin(); i != saved.end();i++)
	{
		if (c == i->first)
			cout << i->second << endl;
	}
}

//######################### MENU ##########################

void reportMenu()
{
	system("cls");
	int a;
	string b;
	cout << "\n\n\n\tREPORT MENU";
	cout << "\n\n\t1.ALL PATIENT'S REPORTS";
	cout << "\n\n\t2.ALL DOCTORS's REPORTS";
	cout << "\n\n\t3.PATIENT REPORT";
	cout << "\n\n\t4.DOCTOR REPORT";
	cout << "\n\n\t5.ALL DOCTOR'S PATIENT";
	cout << "\n\n\t6.BACK TO MAIN MENU";
	cout << "\n\n\tENTER YOUR CHOICE (1-6)";
	cin >> a;
	system("cls");
	switch (a)
	{
	case 1:
		displayAllPantients();
		break;
	case 2:
		displayAllDoctors();
		break;
	case 3:
		cout << "enter patient's code:";
		cin >> b;
		displayPatient(b);
		break;
	case 4:
		cout << "enter doctor's code:";
		cin >> b;
		displayDoctor(b);
		break;
	case 5:
		cout << "enter doctor's name:";
		cin >> b;
		displaySavedPatient(b);
	case 6:
		break;
	}
}
void entryMenu()
{
	int a;
	string b;
	system("cls");
	cout << "\n\n\n\t1.PATIENTS";
	cout << "\n\n\t2.DOCTORS";
	cin >> a;
	if (a == 1)
	{
		system("cls");
		cout << "\n\n\n\tENTRY MENU";
		cout << "\n\n\t1.ADD PATIENT";
		cout << "\n\n\t2.MODIFY PATIENT INFO";
		cout << "\n\n\t3.DELETE all PATIENTS";
		cout << "\n\n\t4.DELETE a PATIENT";
		cout << "\n\n\t5.BACK TO MAIN MENU";
		cout << "\n\n\tENTER YOUR CHOICE (1-5)";
		cin >> a;
		system("cls");
		char choice;
		switch (a)
		{
		case 1:
			do
			{
				first1();
				system("cls");
				cout << "do you want to add new student? Y|N";
				cin >> choice;
				system("cls");
			} while (choice == 'Y' || choice == 'y');
			break;
		case 2:
			cout << "enter patient code:";
			cin >> b;
			modify1(b);
			break;
		case 3:
			deleteAllPatients();
			break;
		case 4:
			cout << "enter patient code:";
			cin >> b;
			deletePantient(b);
			break;
		case 5:
			break;
		}
	}
	if (a == 2)
	{
		system("cls");
		cout << "\n\n\n\tENTRY MENU";
		cout << "\n\n\t1.ADD DOCTOR";
		cout << "\n\n\t2.MODIFY DOCTOR INFO";
		cout << "\n\n\t3.DELETE all DOCTORS";
		cout << "\n\n\t4.DELETE a DOCTOR";
		cout << "\n\n\t5.BACK TO MAIN MENU";
		cout << "\n\n\tENTER YOUR CHOICE (1-5)";
		cin >> a;
		system("cls");
		char choice;
		switch (a)
		{
		case 1:
			do
			{
				first2();
				system("cls");
				cout << "do you want to add new student? Y|N";
				cin >> choice;
				system("cls");
			} while (choice == 'Y' || choice == 'y');
			break;
		case 2:
			cout << "enter doctor code:";
			cin >> b;
			modify2(b);
			break;
		case 3:
			deleteAllDoctors();
			break;
		case 4:
			cout << "enter doctor code:";
			cin >> b;
			deleteDoctor(b);
			break;
		case 5:
			break;
		}
	}
}

int main()
{
	int a;
	do
	{
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t1.REPORT MENU";
		cout << "\n\n\t2.EDIT/ENTRY MENU";
		cout << "\n\n\t3.EXIT";
		cout << "\n\n\tENTER YOUR CHOICE (1|2|3)";
		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:
			reportMenu();
			break;
		case 2:
			entryMenu();
			break;
		case 3:
			break;
		}
	} while (a != 3);
	_getch();
    return 0;
}

