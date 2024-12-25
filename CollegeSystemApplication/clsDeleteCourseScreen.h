#pragma once
#include <iostream>
#include "clsCourseBusinessLogic.h"
#include "clsDrawScreen.h"
#include "clsUtil.h"

using namespace std;

class clsDeleteCourseScreen:protected clsDrawScreenHeader<void>
{
private:
	static void _GetCourseIdToDelete(clsCourseBusinessLogic* Course)
	{
		vector <clsCourseBusinessLogic> Courses = clsCourseBusinessLogic::GetAllCourses();
		bool IsID_AlreadyExists = true;
		string ID = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter the CourseID you want to Delete.\n";
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
	static void _ShowCourseInfo(clsCourseBusinessLogic * Course)
	{
		cout << "The following is Course Information :- \n";
	    cout << "-----------------------------------------------------------------\n";
		cout << "Course ID    :- " << Course->Courses.GetCourseID() << endl;
		cout << "Course Name  :- " << Course->Courses.GetCourseName() << endl;
		cout << "-----------------------------------------------------------------\n";
	}
	static void _DeleteCourseInfo()
	{
		clsCourseBusinessLogic Course = clsCourseBusinessLogic("", "", 0, "", "", "", "", 0, 0, "");
		_GetCourseIdToDelete(&Course);
		_ShowCourseInfo(&Course);
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to delete this course ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Course.DeleteCourseInfo();
			cout << clsUtil<string>::NumberOfTabs(5) << "Course Has been Deleted Successfully.\n";
		}
		else
		{
			return;
		}
	}
public:
	static void DeleteCourseScreen()
	{
		char Answer = 'Y';
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Delete Course Information Screen", "Please Fill The Following Information", 6);
			_DeleteCourseInfo();
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to Delete another Course ? Y/N.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to Courses main menu.\n";
	}
};

