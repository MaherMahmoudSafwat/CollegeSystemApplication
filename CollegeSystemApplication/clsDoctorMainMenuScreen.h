#pragma once
#include <iostream>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsDoctorManagementScreenMenu.h"
#include "clsStudentManagementScreen.h"
#include "clsCourseManagementScreenMenu.h"
#include "clsCurrentDoctorLogin.h"
#include "clsShowAllDoctorPersonalInfoScreen.h"
#include "clsDoctorUpdateDataScreen.h"
#include "clsAssignGradesToStudentsScreen.h"

using namespace std;

class clsDoctorMainMenuScreen :protected clsDrawScreenHeader<void>
{
private:
	enum DoctorRole { Show = 1, Update = 2, Assign = 3, Exit = 4 };
	static void _ShowAllDoctorPersonalInfoScreen()
	{
		clsShowAllDoctorPersonalInfoScreen::ShowAllDoctorPersonalData();
		system("pause > 0");
	}
	static void _UpdateDoctorPersonalInfoScreen()
	{
		clsDoctorUpdateDataScreen::UpdateDoctorScreen();
		system("pause > 0");
	}
	static void _AssignGradesToStudentsScreen()
	{
		clsAssignGradesToStudentsScreen::AssignGradesToStudentsScreen();
		system("pause > 0");
	}
	static void _PerformDoctorMenuOperations(DoctorRole Role)
	{
		switch (Role)
		{
		case DoctorRole::Show:
			_ShowAllDoctorPersonalInfoScreen();
			ShowDoctorMainMenuScreen();
			break;
		case DoctorRole::Update:
			_UpdateDoctorPersonalInfoScreen();
			ShowDoctorMainMenuScreen();
			break;
		case DoctorRole::Assign:
			_AssignGradesToStudentsScreen();
			ShowDoctorMainMenuScreen();
			break;
		case DoctorRole::Exit:
			break;
		}
	}
public:
	static void ShowDoctorMainMenuScreen()
	{
		string Choice;
		short IsChoiceValid = 0;
		do
		{
			system("cls");
			string Title = "Welcome " + CurrentDoctorUser.GetLastName() + " To Doctor Main Screen.";
			DrawHeaderScreen(Title, "Please Choose one of the Following", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Show Personal Information.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Update Personal Information.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-Assign Grades to Students.\n";
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
		_PerformDoctorMenuOperations(DoctorRole(stoi(Choice)));
	}
};
