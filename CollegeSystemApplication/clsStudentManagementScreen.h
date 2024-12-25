#pragma once
#include <iostream>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsAddStudentScreen.h"
#include "clsFindStudentScreen.h"
#include "clsUpdateStudentScreen.h"
#include "clsDeleteStudentScreen.h"
#include "clsShowAllStudentsScreen.h"

using namespace std;

class clsStudentManagementScreen :protected clsDrawScreenHeader<void>
{
private:
	enum enStudentManagementScreen { Add = 1, Update = 2, Find = 3, Delete = 4, Show = 5, Exit = 6 };
	static void _AddStudents()
	{
		clsAddStudentScreen::AddNewStudentsScreen();
		system("pause > 0");
	}
	static void _UpdateStudents()
	{
		clsUpdateStudentScreen::UpdateStudentScreen();
		system("pause > 0");
	}
	static void _FindStudents()
	{
		clsFindStudentScreen::FindStudentScreen();
		system("pause > 0");
	}
	static void _DeleteStudents()
	{
		clsDeleteStudentScreen::DeleteUsersScreen();
		system("pause > 0");
	}
	static void _ShowAllStudents()
	{
		clsShowAllStudentsScreen::ShowAllStudentsDatasScreen();
		system("pause > 0");
	}
	static void _PerformOperationsOnStudents(enStudentManagementScreen Choice)
	{
		switch (Choice)
		{
		case enStudentManagementScreen::Add:
			_AddStudents();
			ManagementStudentScreen();
			break;
		case enStudentManagementScreen::Update:
			_UpdateStudents();
			ManagementStudentScreen();
			break;
		case enStudentManagementScreen::Find:
			_FindStudents();
			ManagementStudentScreen();
			break;
		case enStudentManagementScreen::Delete:
			_DeleteStudents();
			ManagementStudentScreen();
			break;
		case enStudentManagementScreen::Show:
			_ShowAllStudents();
			ManagementStudentScreen();
			break;
		case enStudentManagementScreen::Exit:
			cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to the main menu.\n";
			break;
		}
	}
public:
	static void ManagementStudentScreen()
	{
		string Choice;
		short IsChoiceValid = 0;
		do
		{
			system("cls");
			DrawHeaderScreen("Student Management Menu Screen", "Please choose one of the following", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Add Students.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Update Students.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-Find Students.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "4-Delete Students.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "5-Show all Students.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "6-Exit" << endl;
			cout << clsUtil<string>::NumberOfTabs(5) << "--------------------------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Your Choice :- ";
			cin >> Choice;
			IsChoiceValid = clsUtil<short>::IsChoiceValid(Choice, 1, 6);
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
		_PerformOperationsOnStudents(enStudentManagementScreen(stoi(Choice)));
	}
};

