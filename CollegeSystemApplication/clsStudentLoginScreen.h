#pragma once
#include <iostream>
#include <vector>
#include "clsDrawScreen.h"
#include "clsLoginManagement.h"
#include "clsLogin.h"
#include "clsCurrentStudentLogin.h"
#include "clsStudentMainMenuScreen.h"

using namespace std;


class clsStudentLoginScreen :protected clsDrawScreenHeader <void>, public clsLogin
{
public:
	void Login()
	{
		string Password = "";
		int ID = 0;
		bool IsPasswordValid = true;
		bool IsID_Exists = true;
		do
		{
			system("cls");
			DrawHeaderScreen("Student Login Screen", "", 6);
			cout << "Please enter your ID.\n";
			cin >> ID;
			IsID_Exists = !clsLoginManagement<bool>::ManageStudentID(ID);
			if (IsID_Exists)
			{
				cout << "Invalid ID, Please try Again :-( .\n";
				system("pause > 0");
				continue;
			}
			cout << "Please enter your Password.\n";
			getline(cin >> ws, Password);
			IsPasswordValid = !clsLoginManagement<bool>::ManageStudentPassword(ID, Password);
			if (IsPasswordValid)
			{
				cout << "Invalid Password, Please try Again :-( .\n";
				system("pause > 0");
				continue;
			}
		} while (IsPasswordValid || IsID_Exists);
		vector<clsStudentBusinessLogic>GetAllStudentsData = clsStudentBusinessLogic::GetAllStudentsData();
		CurrentStudentUser = clsStudentBusinessLogic::FindStudent(ID, GetAllStudentsData);
		CurrentStudentUser.SetGPA(clsStudentBusinessLogic::CalculateStudentGPA(CurrentStudentUser.GetID()));
		int NumberOfEnrolledCourses = clsStudentBusinessLogic::GetAllStudentCourses(CurrentStudentUser.GetID()).size();
		CurrentStudentUser.SetIsGraduated(((NumberOfEnrolledCourses >= 15 && CurrentStudentUser.GetGPA() >= 2.0) ? 1 : 0));
		CurrentStudentUser.SetNumberOfCoursesEnrolled(NumberOfEnrolledCourses);
		clsStudentMainMenuScreen::ShowStudentMainMenuScreen();
	}
};

