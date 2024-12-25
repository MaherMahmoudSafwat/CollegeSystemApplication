#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsStudent.h"
#include "clsPersonalInfo.h"
#include "clsStudentBusinessLogic.h"

using namespace std;


class clsAddStudent :public clsPersonalInfo<clsStudent>
{
public:
	clsStudentBusinessLogic Students = clsStudentBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", 0, 0, 0, 0, "");
	vector<clsStudentBusinessLogic>AllStudentsData = Students.GetAllStudentsData();
	void AddFirstName(clsStudent*& Student)
	{
		string StudentFirstName = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Student FirstName.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, StudentFirstName);
		Student->SetFirstName(StudentFirstName);
	}
	void AddLastName(clsStudent*& Student)
	{
		string StudentLastName = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Student LastName.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, StudentLastName);
		Student->SetLastName(StudentLastName);
	}
	void AddID(clsStudent*& Student)
	{
		bool IsID_AlreadyExists = true;
		do
		{
			int RandomNumber = clsUtil<int>::GetRandomNumber(1000000, 2000000);
			Student->SetID(RandomNumber);
			IsID_AlreadyExists = clsStudentBusinessLogic::IsStudentID_AlreadyExists(Student->GetID(), AllStudentsData);
		} while (IsID_AlreadyExists);
	}
	void AddPassword(clsStudent*& Student)
	{
		string StudentPassword = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Student Password.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, StudentPassword);
		Student->SetPassword(StudentPassword);
	}
	void AddEmail(clsStudent*& Student)
	{
		bool IsEmailAlreadyExists = true;
		string StudentEmail = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Student Email.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			getline(cin >> ws, StudentEmail);
			Student->SetEmail(StudentEmail);
			IsEmailAlreadyExists = clsStudentBusinessLogic::IsStudentEmailAlreadyExists(Student->GetEmail(), AllStudentsData);
			if (IsEmailAlreadyExists)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "This Email Already Exists :-(, Please try another one.\n";
				system("pause > 0");
			}
		} while (IsEmailAlreadyExists);
	}
	void AddPhoneNumber(clsStudent*& Student)
	{
		string StudentPhoneNumber = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Student PhoneNumber.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, StudentPhoneNumber);
		Student->SetPhoneNumber(StudentPhoneNumber);
	}
	void AddAddress(clsStudent*& Student)
	{
		string StudentAddress = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Student Address.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, StudentAddress);
		Student->SetAddress(StudentAddress);
	}
	void AddField(clsStudent*& Student)
	{
		string StudentField = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Student Field.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, StudentField);
		Student->SetField(StudentField);
	}
};

