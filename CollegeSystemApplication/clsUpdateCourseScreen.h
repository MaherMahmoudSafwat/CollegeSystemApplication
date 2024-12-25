#pragma once
#pragma once
#include <iostream>
#include "clsCourseBusinessLogic.h"
#include "clsDrawScreen.h"
#include "clsUtil.h"

using namespace std;

class clsUpdateCourseScreen:protected clsDrawScreenHeader<void>
{
private:
	static void _GetCourseIdToUpdate(clsCourseBusinessLogic* Course)
	{
		vector <clsCourseBusinessLogic> Courses = clsCourseBusinessLogic::GetAllCourses();
		bool IsID_AlreadyExists = true;
		string ID = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter the CourseID you want to update.\n";
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
	static void _UpdateCourseInfo(clsCourseBusinessLogic* UpdateCourse)
	{
		_GetCourseIdToUpdate(UpdateCourse);
		string CourseName = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please  enter the New Course Name of the Course you want to Update\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, CourseName);
		UpdateCourse->Courses.SetCourseName(CourseName);
	}
public:
	static void UpdateCourseScreen()
	{
		clsCourseBusinessLogic Course = clsCourseBusinessLogic("", "", 0, "", "", "", "", 0, 0, "");
		char Answer = 'Y';
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Update Course Information Screen", "Please Fill The Following Information", 6);
			_UpdateCourseInfo(&Course);
			Course.UpdateCourseInfo();
			cout << clsUtil<string>::NumberOfTabs(5) << "Course Information has been Updated Successfully :-).\n\n\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to Update another Course ? Y/N.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};

