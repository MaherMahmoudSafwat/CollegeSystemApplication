#pragma once
#include <iostream>
#include <vector>
#include "clsDoctorBusinessLogic.h"
#include "clsFindDoctorScreen.h"
#include "clsUtil.h"
#include "clsDrawScreen.h"
#include "clsCurrentDoctorLogin.h"
#include "clsCourseBusinessLogic.h"

using namespace std;

class clsShowAllDoctorPersonalInfoScreen:protected clsDrawScreenHeader<void>
{
private:
	static void _ShowAllDoctorInfo()
	{
		vector <clsCourseBusinessLogic> Courses = clsCourseBusinessLogic::GetAllCoursesAssignedToDoctors();
		vector <string> AllCoursesToDoctor = clsCourseBusinessLogic::GetCoursesNamesAssignedToSpecificUser(CurrentDoctorUser.GetID(),
			Courses);
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "ID                     :- " << CurrentDoctorUser.GetID() << endl;
		cout << "FullName               :- " << CurrentDoctorUser.GetFullName() << endl;
		cout << "Password               :- " << CurrentDoctorUser.GetPassword() << endl;
		cout << "Email                  :- " << CurrentDoctorUser.GetEmail() << endl;
		cout << "PhoneNumber            :- " << CurrentDoctorUser.GetPhoneNumber() << endl;
		cout << "Address                :- " << CurrentDoctorUser.GetAddress() << endl;
		cout << "Specilization          :- " << CurrentDoctorUser.GetSpecialization() << endl;
		cout << "Martial Status         :- " << CurrentDoctorUser.GetMartialStatus() << endl;
		cout << "The following is the All Courses Assigned to these doctor \n";
		int i = 0;
		for (string& CourseName : AllCoursesToDoctor)
		{
			cout << "Course " << i << " :- " << CourseName << endl;
			i++;
		}
		cout << "-----------------------------------------------------------------------------------------------------\n";
	}
public:
	static void ShowAllDoctorPersonalData()
	{
		system("cls");
		DrawHeaderScreen("Welcome to the Doctor Personal Info", "The Following is All Doctor Info", 6);
		_ShowAllDoctorInfo();
		cout << "Press Any Key to go back to doctor main menu.\n";
	}
};

