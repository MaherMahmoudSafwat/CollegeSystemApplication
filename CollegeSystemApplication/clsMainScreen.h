#pragma once
#include <iostream>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsAdminLoginScreen.h"
#include "clsDoctorLoginScreen.h"
#include "clsStudentLoginScreen.h"
#include "clsLogin.h"

using namespace std;

enum UserRole { Admin = 1, Student = 2, Doctor = 3 };
class clsMainScreen :protected clsDrawScreenHeader<void>
{
private:
	static void _AdminRole()
	{
		system("cls");
		clsAdminLoginScreen AdminLoginScreen;
		clsLogin* AdminLogin = &AdminLoginScreen;
		AdminLogin->Login();
		system("pause > 0");
	}
	static void _DoctorRole()
	{
		system("cls");
		clsDoctorLoginScreen DoctorLoginScreen;
		clsLogin* DoctorLogin = &DoctorLoginScreen;
		DoctorLogin->Login();
		system("pause > 0");
	}
	static void _StudentRole()
	{
		system("cls");
		clsStudentLoginScreen StudentLoginScreen;
		clsLogin* StudentLogin = &StudentLoginScreen;
		StudentLogin->Login();
		system("pause > 0");
	}
	static void _PerformMainScreenOperations(UserRole enRole)
	{
		switch (enRole)
		{
		case UserRole::Admin:
			_AdminRole();
			ShowMainScreen();
			break;
		case UserRole::Doctor:
			_DoctorRole();
			ShowMainScreen();
			break;
		case UserRole::Student:
			_StudentRole();
			ShowMainScreen();
			break;
		}
	}
public:
	static void ShowMainScreen()
	{
		string Choice;
		short IsChoiceValid = 0;
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to the college system", "Please choose your role", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Admin.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Student.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-Doctor." << endl;
			cout << clsUtil<string>::NumberOfTabs(5) << "--------------------------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Your Choice :- ";
			cin >> Choice;
			IsChoiceValid = clsUtil<short>::IsChoiceValid(Choice, 1, 3);
			if (IsChoiceValid == -1)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "The Choice is out of range, Please try again :-).\n";
				system("pause > 0");
			}
			else if (!IsChoiceValid)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "The Choice is InValid, Please try again :-).\n";
				system("pause > 0");
			}
		} while (IsChoiceValid != 1);
		_PerformMainScreenOperations(UserRole(stoi(Choice)));
	}
};
