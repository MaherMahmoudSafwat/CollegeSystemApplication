#pragma once
#include <iostream>
#include "clsDoctorBusinessLogic.h"
#include "clsCourseBusinessLogic.h"
#include "clsAssignCoursesToDoctorScreen.h"
#include "clsDrawScreen.h"
#include "clsUtil.h"

using namespace std;

class clsAssignCoursesToDoctorScreen:protected clsDrawScreenHeader<void>
{
private:
	static void _FindDoctorID(clsCourseBusinessLogic* DoctorID)
	{
		vector <clsDoctorBusinessLogic> Doctor = clsDoctorBusinessLogic::GetAllData();
		bool IsID_NotExists = true;
		string ID = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Doctor ID.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> ID;
			IsID_NotExists = !(clsDoctorBusinessLogic::CheckDoctor_ID_AlreadyExists(stoi(ID), Doctor));
			if (IsID_NotExists)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "Doctor ID Doesn't Exists Please try again.\n";
			}
		} while (IsID_NotExists);
		DoctorID->SetID(stoi(ID));
	}
	static void _GetCourseID(clsCourseBusinessLogic* CourseID)
	{
		vector <clsCourseBusinessLogic> Course = clsCourseBusinessLogic::GetAllCourses();
		bool IsID_NotExists = true;
		string ID = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Course ID.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> ID;
			IsID_NotExists = !(clsCourseBusinessLogic::CheckCourse_ID_AlreadyExists(stoi(ID), Course));
			if (IsID_NotExists)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "Course ID Doesn't Exists Please try again.\n";
			}
		} while (IsID_NotExists);
		CourseID->Courses.SetCourseID(stoi(ID));
		CourseID->Courses.SetCourseName(clsCourseBusinessLogic::GetCourseNameOnly(stoi(ID), Course));
	}
public:
	static void AssignCoursesToDoctorScreen()
	{
		clsCourseBusinessLogic CoursesOfDoctor = clsCourseBusinessLogic("", "", 0, "", "", "", "", 0, 0, "");
		system("cls");
		DrawHeaderScreen("Welcome to Assign Courses To Doctor Screen","Please Fill the Following Information",6);
		_FindDoctorID(&CoursesOfDoctor);
		char Answer = 'Y';
		do
		{
			_GetCourseID(&CoursesOfDoctor);
			CoursesOfDoctor.AssignCoursesToDoctor();
			cout << clsUtil<string>::NumberOfTabs(5) << "Course Assgned To Doctor Successfully :-).\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to Add Another Course to the doctor ?  Y/N ? \n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y')
			{
				system("cls");
				DrawHeaderScreen("Welcome to Assign Courses To Doctor Screen", "Please Fill the Following Information", 6);
			}

		} while (Answer == 'Y' || Answer == 'y');
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key To go back to Courses Main Menu.\n";
	}
};

