#pragma once
#include <iostream>
#include <string>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsStudent.h"
#include "clsFindStudent.h"
#include "clsStudentBusinessLogic.h"

using namespace std;

class clsFindStudentScreen :protected clsDrawScreenHeader<void>
{
protected:
	static void _ShowStudentInfo(clsStudentBusinessLogic* Student, string State = "Find")
	{
		clsFindStudent FindStudent;
		FindStudent.GetStudentIdToFind(Student, State);
		system("cls");
		DrawHeaderScreen("Welcome to Find Student Information Screen", "The Following is all Student Information", 6);
		cout << "-----------------------------------------------------\n\n\n";
		cout << "ID                         :- " << Student->ID << endl;
		cout << "Full Name                  :- " << Student->GetFullName() << endl;
		cout << "Password                   :- " << Student->GetPassword() << endl;
		cout << "Email                      :- " << Student->GetEmail() << endl;
		cout << "Phone Number               :- " << Student->GetPhoneNumber() << endl;
		cout << "Address                    :- " << Student->GetAddress() << endl;
		cout << "Number Of Courses Enrolled :- " << Student->GetNumberOfCoursesEnrolled() << endl;
		cout << "GPA                        :- " << Student->GetGPA() << endl;
		cout << "Student Graduation Status  :- " << ((Student->GetIsGraduated() == 1) ? "Graduated" : "Not Graduated");
		cout << endl;
		cout << "Field                      :- " << Student->GetField() << endl;
		cout << "\n\n\n-----------------------------------------------------\n";
	}
public:
	static void FindStudentScreen()
	{
		clsStudentBusinessLogic Student = clsStudentBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", 0, 0, 0, 0, "");
		char Answer = 'Y';
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Find Student Information Screen", "Please Fill The Following Information", 6);
			_ShowStudentInfo(&Student);
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to Find another Student ? Y/N.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};

