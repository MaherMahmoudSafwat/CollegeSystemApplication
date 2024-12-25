#pragma once
#include <iostream>
#include "clsCourseBusinessLogic.h"
#include "clsDrawScreen.h"
#include "clsUtil.h"

using namespace std;

class clsFindCourseScreen:protected clsDrawScreenHeader<void>
{
private:
	static void _GetCourseIdToFind(clsCourseBusinessLogic* Course)
	{
		vector <clsCourseBusinessLogic> Courses = clsCourseBusinessLogic::GetAllCourses();
		bool IsID_AlreadyExists = true;
		string ID = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter the CourseID you want to Find.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			getline(cin >> ws, ID);
			if (!clsUtil<bool>::IsChoiceCorrect(ID))
			{
				IsID_AlreadyExists = false;
				cout << clsUtil<string>::NumberOfTabs(5) << "The ID Number is not valid, Please try again.\n";
				system("pause > 0");
				continue;
			}
			IsID_AlreadyExists = clsCourseBusinessLogic::CheckCourse_ID_AlreadyExists(stoi(ID), Courses);
			if (!IsID_AlreadyExists)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "The Course ID Doesn't Exists :-(, Please try again later.\n";
				system("pause > 0");
			}
		} while (!IsID_AlreadyExists);
		*Course = clsCourseBusinessLogic::GetCourseData(stoi(ID), Courses);
	}
	static void _ShowCourseInfo()
	{
		clsCourseBusinessLogic Course = clsCourseBusinessLogic("", "", 0, "", "", "", "", 0, 0, "");
		_GetCourseIdToFind(&Course);
		system("cls");
		DrawHeaderScreen("Welcome to Find Course Information Screen", "The Following is Course Data", 6);
		cout << "-----------------------------------------------------------------\n";
		cout << "Course ID    :- " << Course.Courses.GetCourseID() << endl;
		cout << "Course Name  :- " << Course.Courses.GetCourseName() << endl;
		cout << "-----------------------------------------------------------------\n";
	}
public:
	static void FindCourseScreen()
	{
		char Answer = 'Y';
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Find Course Information Screen", "Please Fill The Following Information", 6);
			_ShowCourseInfo();
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to Find another Course ? Y/N.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to Courses main menu.\n";
	}
};

