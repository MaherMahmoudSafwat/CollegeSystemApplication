#pragma once
#include <iostream>
#include "clsCourseBusinessLogic.h"
#include "clsDrawScreen.h"
#include "clsUtil.h"

using namespace std;

class clsAddNewCourseScreen:protected clsDrawScreenHeader<void>
{
private:
	static int _AddNewCourseID()
	{
		int RandomNumber = 0;
		vector <clsCourseBusinessLogic> AllCoursesData = clsCourseBusinessLogic::GetAllCourses();
		bool IsID_AlreadyExists = true;
		do
		{
			RandomNumber = clsUtil<int>::GetRandomNumber(1, 1000);
			IsID_AlreadyExists = clsCourseBusinessLogic::CheckCourse_ID_AlreadyExists(RandomNumber, AllCoursesData);
		} while (IsID_AlreadyExists);
		return RandomNumber;
	}
	static string _AddNewCourseName()
	{
		string CourseName = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Course Name.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, CourseName);
		return CourseName;
	}
	static void _AddNewCourse(clsCourseBusinessLogic* Course)
	{
		Course->Courses.SetCourseID(_AddNewCourseID());
		Course->Courses.SetCourseName(_AddNewCourseName());
	}
public:
	static void AddNewCoursesScreen()
	{
		clsCourseBusinessLogic Course = clsCourseBusinessLogic("", "", 0, "", "", "", "", 0, 0, "");
		char Answer = 'Y';
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Add New Course Screen", "Please Fill The Following Information", 6);
			_AddNewCourse(&Course);
			Course.AddNewCourse();
			cout << clsUtil<string>::NumberOfTabs(5) << "Course Information has been added Successfully :-).\n\n\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to add another Course ? Y/N.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to Courses main menu.\n";
	}
};

