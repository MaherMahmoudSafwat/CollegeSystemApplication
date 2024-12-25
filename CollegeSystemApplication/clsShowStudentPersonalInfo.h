#pragma once
#include <iostream>
#include <vector>
#include "clsStudentBusinessLogic.h"
#include "clsCourseBusinessLogic.h"
#include "clsUtil.h"
#include "clsDrawScreen.h"
#include "clsCurrentStudentLogin.h"
#include "clsCourseBusinessLogic.h"

using namespace std;

class clsShowAllStudentPersonalInfoScreen :protected clsDrawScreenHeader<void>
{
private:
	static void _ShowAllStudentInfo()
	{
		vector<clsCourseBusinessLogic>GetAllCourses = clsCourseBusinessLogic::GetAllCourses();
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "ID                         :- " << CurrentStudentUser.GetID() << endl;
		cout << "FullName                   :- " << CurrentStudentUser.GetFullName() << endl;
		cout << "Password                   :- " << CurrentStudentUser.GetPassword() << endl;
		cout << "Email                      :- " << CurrentStudentUser.GetEmail() << endl;
		cout << "PhoneNumber                :- " << CurrentStudentUser.GetPhoneNumber() << endl;
		cout << "Address                    :- " << CurrentStudentUser.GetAddress() << endl;
		cout << "GPA                        :- " << CurrentStudentUser.GetGPA() << endl;
		cout << "Number Of Courses Enrolled :- " << CurrentStudentUser.GetNumberOfCoursesEnrolled() << endl;
		cout << "Gradution Status           :- " << ((CurrentStudentUser.GetIsGraduated())?"Graduated":"Not Graduated") << endl;
		cout << "Field                      :- " << CurrentStudentUser.GetField() << endl;
		cout << "-----------------------------------------------------------------------------------------------------\n";
	}
public:
	static void ShowAllStudentPersonalData()
	{
		system("cls");
		DrawHeaderScreen("Welcome to the Student Personal Info", "The Following is All Student Info", 6);
		_ShowAllStudentInfo();
		cout << "Press Any Key to go back to Student main menu.\n";
	}
};

