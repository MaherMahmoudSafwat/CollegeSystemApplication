#pragma once
#include <iostream>
#include <string>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsStudent.h"
#include "clsPersonalInfo.h"
#include "clsStudentBusinessLogic.h"
#include "clsAddStudent.h"

using namespace std;

class clsAddStudentScreen :protected clsDrawScreenHeader<void>
{
private:
	static void _AddNewStudent(clsStudent* Student)
	{
		clsAddStudent Students;
		clsPersonalInfo <clsStudent>* Person = &Students;
		Person->AddFirstName(Student);
		Person->AddLastName(Student);
		Person->AddID(Student);
		Person->AddPassword(Student);
		Person->AddEmail(Student);
		Person->AddPhoneNumber(Student);
		Person->AddAddress(Student);
		Students.AddField(Student);
		cout << clsUtil<string>::NumberOfTabs(5) << "----------------------------------------------------------------\n";
	}
public:
	static void AddNewStudentsScreen()
	{
		clsStudentBusinessLogic Student = clsStudentBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", 0, 0, 0, 0, "");
		char Answer = 'Y';
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Add New Student Screen", "Please Fill The Following Information", 6);
			_AddNewStudent(&Student);
			Student.AddNewStudentsData();
			cout << clsUtil<string>::NumberOfTabs(5) << "Student Information has been added Successfully :-).\n\n\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to add another Student ? Y/N.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};


