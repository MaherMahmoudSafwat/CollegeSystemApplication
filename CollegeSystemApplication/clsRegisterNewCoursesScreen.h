#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "clsStudentBusinessLogic.h"
#include "clsUtil.h"
#include "clsDrawScreen.h"
#include "clsCurrentstudentlogin.h"
#include "clsCourseBusinessLogic.h"

using namespace std;

class clsRegisterNewCoursesScreen:protected clsDrawScreenHeader <void>
{
private:
	static void _ShowAllCoursesAvaliable(vector <clsCourseBusinessLogic> GetAllAvaliableCourses)
	{
		int i = 1;
		cout << clsUtil<string>::NumberOfTabs(5) << "The following is all the courses avaliable right now. \n";
		for (clsCourseBusinessLogic& CourseData : GetAllAvaliableCourses)
		{
			cout << " --------------------------- Course " + to_string(i) + " ---------------------------------\n";
			cout << "Course ID    :- " << CourseData.Courses.GetCourseID() << endl;
			cout << "Course Name  :- " << CourseData.Courses.GetCourseName() << endl;
			i++;
		}
		cout << "--------------------------------------------------------------------------------------\n";
	}
	static queue<string> _RegisterNewCourse()
	{
		int ID = 0;
		bool IsID_NotExists = true;
		bool IsCourseDataAlreadyRegistered = true;
		queue <string> CourseData;
		vector<clsCourseBusinessLogic>GetAllCourses = clsCourseBusinessLogic::GetAllCourses();
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Register New Courses Screen", "Please fill the following Data", 6);
			_ShowAllCoursesAvaliable(GetAllCourses);
			cout << "Please enter the ID of the course You Want to Register.\n";
			cin >> ID;
			IsID_NotExists = !(clsCourseBusinessLogic::CheckCourse_ID_AlreadyExists(ID, GetAllCourses));
			if (IsID_NotExists)
			{
				cout << "This Course ID Doesn't Exists.\n";
				system("pause > 0");
				continue;
			}
			IsCourseDataAlreadyRegistered = clsStudentBusinessLogic::CheckIfStudentAlreadyRegisteredForThisCourse
			(CurrentStudentUser.GetID(), ID);
			if (IsCourseDataAlreadyRegistered)
			{
				cout << "You have Already Registered For these Course please choose another one.\n";
				system("pause > 0");
			}
		} while (IsID_NotExists || IsCourseDataAlreadyRegistered);
		CourseData.push(to_string(ID));
		CourseData.push(clsCourseBusinessLogic::GetCourseNameOnly(ID, GetAllCourses));
		return CourseData;
	}
public:
	static void RegisterNewCoursesScreen()
	{
		char Answer = 'Y';
		queue <string> CourseData;
		clsStudentBusinessLogic StudentRegisterCourse = clsStudentBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", 0, 0, 0, 0, "");
		do
		{
			StudentRegisterCourse.SetID(CurrentStudentUser.GetID());
			CourseData = _RegisterNewCourse();
			StudentRegisterCourse.Courses.SetCourseID(stoi(CourseData.front()));
			CourseData.pop();
			StudentRegisterCourse.Courses.SetCourseName(CourseData.front());
			CourseData.pop();
			StudentRegisterCourse.AddNewCourseForStudent();
			cout << "Course has been registered successfully :-).\n";
			cout << "Would you like to register to another course ? Y/N ? \n";
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key to go back to student main menu.\n";
	}
};

