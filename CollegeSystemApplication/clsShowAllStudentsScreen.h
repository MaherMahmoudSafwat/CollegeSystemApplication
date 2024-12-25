#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsStudent.h"
#include "clsPersonalInfo.h"
#include "clsStudentBusinessLogic.h"

using namespace std;

class clsShowAllStudentsScreen : protected clsDrawScreenHeader<void>
{
private:
	static void _ShowAllStudentsDataInfo(vector <clsStudentBusinessLogic> AllStudentsData)
	{
		short i = 1;
		if (AllStudentsData.size() == 0)
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "There are no Students Data Found or Avaliable :-(.\n";
			return;
		}
		for (clsStudentBusinessLogic& StudentsData : AllStudentsData)
		{
			cout << "----------------------------------- Student " + to_string(i) + "-----------------------------------\n";
			cout << "ID                              :- " << StudentsData.ID << endl;
			cout << "Full Name                       :- " << StudentsData.GetFullName() << endl;
			cout << "Password                        :- " << StudentsData.GetPassword() << endl;
			cout << "Email                           :- " << StudentsData.GetEmail() << endl;
			cout << "Phone Number                    :- " << StudentsData.GetPhoneNumber() << endl;
			cout << "Address                         :- " << StudentsData.GetAddress() << endl;
			cout << "Number Of Courses Enrolled      :- " << StudentsData.GetNumberOfCoursesEnrolled() << endl;
			cout << "GPA                             :- " << float(StudentsData.GetGPA()) << endl;
			cout << "StudentsData Graduation Status  :- " << ((StudentsData.GetIsGraduated() == 1) ? "Graduated" : "Not Graduated");
			cout << endl;
			cout << "Field                           :- " << StudentsData.GetField() << endl;
			i++;
		}
		cout << "-------------------------------------------------------------------------------------------------------\n";
	}
public:
	static void ShowAllStudentsDatasScreen()
	{
		vector <clsStudentBusinessLogic> AllStudentsData = clsStudentBusinessLogic::GetAllStudentsData();
		string Subtitle = "Number of Students Avaliable are " + to_string(AllStudentsData.size());
		system("cls");
		DrawHeaderScreen("Welcome to Show All Students Screen", Subtitle, 6);
		_ShowAllStudentsDataInfo(AllStudentsData);
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};

