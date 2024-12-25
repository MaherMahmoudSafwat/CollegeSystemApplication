#pragma once
#include <iostream>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsAddDoctorScreen.h"
#include "clsUpdateDoctorScreen.h"
#include "clsFindDoctorScreen.h"
#include "clsDeleteDoctorScreen.h"
#include "clsShowAllDoctorsScreen.h"

using namespace std;

class clsDoctorManagementScreenMenu :protected clsDrawScreenHeader<void>
{
private:
	enum enDoctorManagementChoice { Add = 1, Update = 2, Find = 3, Delete = 4, Show = 5, Exit = 6 };
	static void _AddDoctors()
	{
		clsAddDoctorScreen::AddNewDoctorsScreen();
		system("pause > 0");
	}
	static void _UpdateDoctors()
	{
		clsUpdateDoctorScreen::UpdateDoctorScreen();
		system("pause > 0");
	}
	static void _FindDoctors()
	{
		clsFindDoctorScreen::FindDoctorScreen();
		system("pause > 0");
	}
	static void _DeleteDoctors()
	{
		clsDeleteUsersScreen::DeleteUsersScreen();
		system("pause > 0");
	}
	static void _ShowAllDoctors()
	{
		clsShowAllDoctorsScreen::ShowAllDoctorsScreen();
		system("pause > 0");
	}
	static void _PerformOperationsOnDoctors(enDoctorManagementChoice Choice)
	{
		switch (Choice)
		{
		case enDoctorManagementChoice::Add:
			_AddDoctors();
			ManagementDoctorScreen();
			break;
		case enDoctorManagementChoice::Update:
			_UpdateDoctors();
			ManagementDoctorScreen();
			break;
		case enDoctorManagementChoice::Find:
			_FindDoctors();
			ManagementDoctorScreen();
			break;
		case enDoctorManagementChoice::Delete:
			_DeleteDoctors();
			ManagementDoctorScreen();
			break;
		case enDoctorManagementChoice::Show:
			_ShowAllDoctors();
			ManagementDoctorScreen();
			break;
		case enDoctorManagementChoice::Exit:
			cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to the main menu.\n";
			break;
		}
	}
public:
	static void ManagementDoctorScreen()
	{
		string Choice;
		short IsChoiceValid = 0;
		do
		{
			system("cls");
			DrawHeaderScreen("Doctor Management Menu Screen", "Please choose one of the following", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Add Doctors.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Update Doctors.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-Find Doctors.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "4-Delete Doctors.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "5-Show all Doctors.\n";
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
		_PerformOperationsOnDoctors(enDoctorManagementChoice(stoi(Choice)));
	}
};

