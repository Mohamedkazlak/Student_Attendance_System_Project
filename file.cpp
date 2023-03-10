#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class StudentAttendence
{//infromation save in class
private:
	string Name;
	int Lecture;
	string NameOfSubject;
public:
	StudentAttendence()//constructor
	{
		Name = "";
		Lecture = -1;
		NameOfSubject = "";
	}
//set data to all variable
	void SetData(string n, int l, string s)
	{
		Name = n;
		Lecture = l;
		NameOfSubject = s;

	}
	
//get all infromation
	
	string GetName()
	{
		return Name;
	}
	string GetNameOfSubject()
	{
		return NameOfSubject;
	}
	
	int GetLecture()
	{
		return 	Lecture;
	}
	
	
	//operator >> to input data

	friend istream& operator>>(istream  &cinn, StudentAttendence &x) {


		cout << "Enter student Name ";

		cinn >> x.Name;

		cout << "Enter subject Name ";

		cinn >> x.NameOfSubject;

		cout << "Enter Lecture number ";
		cinn >> x.Lecture;

		


		return cinn;
	}
//operator << to output data

	friend ostream& operator<<(ostream& coutt, StudentAttendence &x)
	{

		coutt << "************************************************" << endl;
		coutt << endl;
		coutt << "Student Name : " << x.Name << endl;
		coutt << "Name Of Subject : " << x.NameOfSubject << endl;
		coutt << "Lecture : " << x.Lecture << endl;
		coutt << "************************************************" << endl;

		return coutt;
	}

};
const int Size = 1000;
StudentAttendence *Attendences;

int NumberOfStudent;




int main()
{
	Attendences = new StudentAttendence[Size];
	
	char Sel;
	cout << "\t Student Attendance System \n";
	while (true) {//option menu of the program
		cout << "[T]ake Student Attendence" << endl;
		cout << "[D]elete Student Attendence" << endl;
		cout << "[S]earch Student Attendence" << endl;
		cout << "Dis[P]lay all Student Attendence" << endl;
		cout << "[E]xit" << endl;
		cout << "Select: ";
		cin >> Sel;
		if (Sel == 'T')
		{
			string y;
			StudentAttendence x;
			if (NumberOfStudent<Size)
			{
				
				cin >> x;
				
				Attendences[NumberOfStudent] = x;
				NumberOfStudent++;
			}
			else
				cout << "Not space";
		}
		else if (Sel == 'D')
		{
			int Num;
			cout << "Enter Student Number: ";
			cin >> Num;
			if (Num > NumberOfStudent)
				cout << "No attendence in this number" << endl;
			else
			{
				int m = Num;
				while (m < Num)
					Attendences[m] = Attendences[m++ + 1];
			}
			
		}
		else if (Sel == 'S')
		{
			string t,tt;
			
			cout << endl << "Enter Name of Student: " << endl;
			cin >> t;
			int Num;
			cout << endl << "Enter week Num: " << endl;
			cin >> Num;
			cout << endl << "Enter Name of Subject: " << endl;
			cin >> tt;
			int i = 0;
			for (i = 0; i<NumberOfStudent; i++)
			if (Attendences[i].GetName().compare(t) == 0 && Attendences[i].GetLecture() == Num && Attendences[i].GetNameOfSubject().compare(tt)==0)
				break;
			if (i == NumberOfStudent)
				cout << "Student Attendence Not found";
			else
			{
				cout << Attendences[i];
			}
		}
		else if (Sel == 'P')
		{
			int i = 0;
			do
			{
				cout << "Student Attendence Number " << i << endl;
				cout << Attendences[i++];
				
			}while (i < NumberOfStudent);

		}
		
		else if (Sel == 'e')
			exit(0);
		


	} 

	return 0;
}
