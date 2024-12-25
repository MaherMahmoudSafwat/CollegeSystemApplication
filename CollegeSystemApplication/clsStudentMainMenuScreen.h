#pragma once
#include <iostream>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsStudentManagementScreen.h"
#include "clsCourseManagementScreenMenu.h"
#include "clsCurrentStudentLogin.h"
#include "clsShowStudentPersonalInfo.h"
#include "clsUpdateStudentPersonalInfoScreen.h"
#include "clsRegisterNewCoursesScreen.h"
#include "clsShowAllStudentGradesScreen.h"

using namespace std;

class clsStudentMainMenuScreen :protected clsDrawScreenHeader<void>
{
private:
	enum StudentRole { Show = 1, Update = 2, Register = 3, ShowAllGrades = 4, Exit = 5 };
	static void _ShowAllStudentPersonalInfoScreen()
	{
		clsShowAllStudentPersonalInfoScreen::ShowAllStudentPersonalData();
		system("pause > 0");
	}
	static void _UpdateStudentPersonalInfoScreen()
	{
		clsUpdateStudentPersonalInfoScreen::UpdateStudentScreen();
		system("pause > 0");
	}
	static void _RegisterToCoursesScreen()
	{
		clsRegisterNewCoursesScreen::RegisterNewCoursesScreen();
		system("pause > 0");
	}
	static void _ShowAllStudentGradesScreen()
	{
		clsShowAllStudentGradesScreen::ShowAllStudentGrades();
		system("pause > 0");
	}
	static void _PerformStudentMenuOperations(StudentRole Role)
	{
		switch (Role)
		{
		case StudentRole::Show:
			_ShowAllStudentPersonalInfoScreen();
			ShowStudentMainMenuScreen();
			break;
		case StudentRole::Update:
			_UpdateStudentPersonalInfoScreen();
			ShowStudentMainMenuScreen();
			break;
		case StudentRole::Register:
			_RegisterToCoursesScreen();
			ShowStudentMainMenuScreen();
			break;
		case StudentRole::ShowAllGrades:
			_ShowAllStudentGradesScreen();
			ShowStudentMainMenuScreen();
		case StudentRole::Exit:
			break;
		}
	}
public:
	static void ShowStudentMainMenuScreen()
	{
		string Choice;
		short IsChoiceValid = 0;
		do
		{
			system("cls");
			string Title = "Welcome " + CurrentStudentUser.GetLastName() + " To Student Main Screen.";
			DrawHeaderScreen(Title, "Please Choose one of the Following", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Show Personal Information.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Update Personal Information.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-Register To Courses.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "4-Show All Grades." << endl;
			cout << clsUtil<string>::NumberOfTabs(5) << "5-Exit." << endl;
			cout << clsUtil<string>::NumberOfTabs(5) << "--------------------------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Your Choice :- ";
			cin >> Choice;
			IsChoiceValid = clsUtil<short>::IsChoiceValid(Choice, 1, 5);
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
		_PerformStudentMenuOperations(StudentRole(stoi(Choice)));
	}
};
