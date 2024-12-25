#pragma once
#include <iostream>
#include <string>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsStudent.h"
#include "clsUpdateStudent.h"
#include "clsUpdatePersonalInfo.h"
#include "clsStudentBusinessLogic.h"
#include "clsCurrentStudentLogin.h"

using namespace std;

class clsUpdateStudentPersonalInfoScreen :protected clsDrawScreenHeader<void>
{
private:
	static void _UpdateStudent(clsStudent* Student)
	{
		clsUpdateStudent UpdateInfo;
		clsUpdatePersonalInfo<clsStudent>* UpdateStudentInfo = &UpdateInfo;
		UpdateStudentInfo->UpdatePassword(Student);
		UpdateStudentInfo->UpdateEmail(Student);
		UpdateStudentInfo->UpdatePhoneNumber(Student);
		UpdateStudentInfo->UpdateAddress(Student);
		UpdateInfo.UpdateGPA(Student);
		UpdateInfo.UpdateNumberOfCoursesEnrolled(Student);
		UpdateInfo.UpdateIsGraduated(Student);
		cout << clsUtil<string>::NumberOfTabs(5) << "----------------------------------------------------------------\n";
	}
public:
	static void UpdateStudentScreen()
	{
		system("cls");
		DrawHeaderScreen("Welcome to Update Student Information Screen", "Please Fill The Following Information", 6);
		char Answer = 'Y';
		_UpdateStudent(&CurrentStudentUser);
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to update your Student personal info ? Y/N ? \n"; 
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			CurrentStudentUser.UpdateStudentData();
			cout << clsUtil<string>::NumberOfTabs(5) << "Your Student Personal Data has been Updated Successfully.\n";
		}
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};