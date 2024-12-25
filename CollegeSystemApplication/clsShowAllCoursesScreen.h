#pragma once
#include <iostream>
#include "clsCourseBusinessLogic.h"
#include "clsDrawScreen.h"
#include "clsUtil.h"

using namespace std;
class clsShowAllCoursesScreen:protected clsDrawScreenHeader<void>
{
private:
	static void _ShowAllCoursesDataInfo(vector <clsCourseBusinessLogic> AllCoursesData)
	{
		short i = 1;
		if (AllCoursesData.size() == 0)
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "There are no Courses Data Found or Avaliable :-(.\n";
			return;
		}
		for (clsCourseBusinessLogic& CoursesData : AllCoursesData)
		{
			cout << "----------------------------------- Course " + to_string(i) + "-----------------------------------\n";
			cout << "Course ID   :- " << CoursesData.Courses.GetCourseID() << endl;
			cout << "Course Name :- " << CoursesData.Courses.GetCourseName() << endl;
			i++;
		}
		cout << "-------------------------------------------------------------------------------------------------------\n";
	}
public:
	static void ShowAllCoursesDatasScreen()
	{
		vector <clsCourseBusinessLogic> AllCoursesData = clsCourseBusinessLogic::GetAllCourses();
		string Subtitle = "Number of Courses Avaliable are " + to_string(AllCoursesData.size());
		system("cls");
		DrawHeaderScreen("Welcome to Show All Courses Screen", Subtitle, 6);
		_ShowAllCoursesDataInfo(AllCoursesData);
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to Courses main menu.\n";
	}
};

