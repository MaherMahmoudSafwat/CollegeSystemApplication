#pragma once
#include <iostream>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsDoctorManagementScreenMenu.h"
#include "clsStudentManagementScreen.h"
#include "clsCourseManagementScreenMenu.h"

using namespace std;

class clsAdminMainMenuScreen :protected clsDrawScreenHeader<void>
{
private:
	enum AdminRole { Doctors = 1, Students = 2, Courses = 3, Exit = 4 };
	static void _DoctorsManagementMenu()
	{
		clsDoctorManagementScreenMenu::ManagementDoctorScreen();
		system("pause > 0");
	}
	static void _StudentsManagementMenu()
	{
		clsStudentManagementScreen::ManagementStudentScreen();
		system("pause > 0");
	}
	static void _CoursesManagementMenu()
	{
		clsCourseManagementMenuScreen::ManagementCoursescreen();
		system("pause > 0");
	}
	static void _PerformAdminMenuOperations(AdminRole Role)
	{
		switch (Role)
		{
		case AdminRole::Doctors:
			_DoctorsManagementMenu();
			ShowAdminMainMenuScreen();
			break;
		case AdminRole::Students:
			_StudentsManagementMenu();
			ShowAdminMainMenuScreen();
			break;
		case AdminRole::Courses:
			_CoursesManagementMenu();
			ShowAdminMainMenuScreen();
			break;
		case AdminRole::Exit:
			break;
		}
	}
public:
	static void ShowAdminMainMenuScreen()
	{
		string Choice;
		short IsChoiceValid = 0;
		do
		{
			system("cls");
			DrawHeaderScreen("Admin Main Menu Screen", "Please Choose the Users to Manage", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Manage Doctors.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Manage Students.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-Manage Course.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "4-Exit." << endl;
			cout << clsUtil<string>::NumberOfTabs(5) << "--------------------------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Your Choice :- ";
			cin >> Choice;
			IsChoiceValid = clsUtil<short>::IsChoiceValid(Choice, 1, 4);
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
		_PerformAdminMenuOperations(AdminRole(stoi(Choice)));
	}
};
