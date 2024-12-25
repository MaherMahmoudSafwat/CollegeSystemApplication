#pragma once
#include <iostream>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsAddNewCourseScreen.h"
#include "clsUpdateCourseScreen.h"
#include "clsFindCourseScreen.h"
#include "clsDeleteCourseScreen.h"
#include "clsShowAllCoursesScreen.h"
#include "clsAssignCoursesToDoctorScreen.h"

using namespace std;

class clsCourseManagementMenuScreen :protected clsDrawScreenHeader<void>
{
private:
	enum enCourseManagementChoice { Add = 1, Update = 2, Find = 3, Delete = 4, Show = 5, Assign = 6, Exit = 7 };
	static void _AddCourses()
	{
		clsAddNewCourseScreen::AddNewCoursesScreen();
		system("pause > 0");
	}
	static void _UpdateCourses()
	{
		clsUpdateCourseScreen::UpdateCourseScreen();
		system("pause > 0");
	}
	static void _FindCourses()
	{
		clsFindCourseScreen::FindCourseScreen();
		system("pause > 0");
	}
	static void _DeleteCourses()
	{
		clsDeleteCourseScreen::DeleteCourseScreen();
		system("pause > 0");
	}
	static void _ShowAllCourses()
	{
		clsShowAllCoursesScreen::ShowAllCoursesDatasScreen();
		system("pause > 0");
	}
	static void _AssignCoursesToDoctorScreen()
	{
		clsAssignCoursesToDoctorScreen::AssignCoursesToDoctorScreen();
		system("pause > 0");
	}
	static void _PerformOperationsOnCourses(enCourseManagementChoice Choice)
	{
		switch (Choice)
		{
		case enCourseManagementChoice::Add:
			_AddCourses();
			ManagementCoursescreen();
			break;
		case enCourseManagementChoice::Update:
			_UpdateCourses();
			ManagementCoursescreen();
			break;
		case enCourseManagementChoice::Find:
			_FindCourses();
			ManagementCoursescreen();
			break;
		case enCourseManagementChoice::Delete:
			_DeleteCourses();
			ManagementCoursescreen();
			break;
		case enCourseManagementChoice::Show:
			_ShowAllCourses();
			ManagementCoursescreen();
			break;
		case enCourseManagementChoice::Assign:
			_AssignCoursesToDoctorScreen();
			ManagementCoursescreen();
			break;
		case enCourseManagementChoice::Exit:
			cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to the main menu.\n";
			break;
		}
	}
public:
	static void ManagementCoursescreen()
	{
		string Choice;
		short IsChoiceValid = 0;
		do
		{
			system("cls");
			DrawHeaderScreen("Course Management Menu Screen", "Please choose one of the following", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Add Courses.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Update Courses.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-Find Courses.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "4-Delete Courses.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "5-Show all Courses.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "6-Assign Course to doctor" << endl;
			cout << clsUtil<string>::NumberOfTabs(5) << "7-Exit" << endl;
			cout << clsUtil<string>::NumberOfTabs(5) << "--------------------------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Your Choice :- ";
			cin >> Choice;
			IsChoiceValid = clsUtil<short>::IsChoiceValid(Choice, 1, 7);
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
		_PerformOperationsOnCourses(enCourseManagementChoice(stoi(Choice)));
	}
};

