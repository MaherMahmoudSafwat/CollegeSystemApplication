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

using namespace std;

class clsUpdateStudentScreen :protected clsDrawScreenHeader<void>
{
private:
	static void _UpdateStudent(clsStudent* Student)
	{
		clsUpdateStudent UpdateInfo;
		clsUpdatePersonalInfo<clsStudent>* UpdateStudentInfo = &UpdateInfo;
		UpdateInfo.GetStudentIdToUpdate(Student);
		UpdateStudentInfo->UpdatePassword(Student);
		UpdateStudentInfo->UpdateEmail(Student);
		UpdateStudentInfo->UpdatePhoneNumber(Student);
		UpdateStudentInfo->UpdateAddress(Student);
		UpdateInfo.UpdateGPA(Student);
		UpdateInfo.UpdateNumberOfCoursesEnrolled(Student);
		UpdateInfo.UpdateIsGraduated(Student);
		UpdateInfo.UpdateField(Student);
		cout << clsUtil<string>::NumberOfTabs(5) << "----------------------------------------------------------------\n";
	}
public:
	static void UpdateStudentScreen()
	{
		clsStudentBusinessLogic Student = clsStudentBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", 0,0,0,0,"");
		char Answer = 'Y';
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Update Student Information Screen", "Please Fill The Following Information", 6);
			_UpdateStudent(&Student);
			Student.UpdateStudentData();
			cout << clsUtil<string>::NumberOfTabs(5) << "Student Information has been Updated Successfully :-).\n\n\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to Update another Student ? Y/N.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};

