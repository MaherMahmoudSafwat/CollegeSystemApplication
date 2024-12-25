#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsStudentBusinessLogic.h"

using namespace std;

class clsFindStudent
{
public:
	clsStudentBusinessLogic Students = clsStudentBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", 0, 0, 0, 0, "");
	vector<clsStudentBusinessLogic>AllStudentsData = Students.GetAllStudentsData();
	void GetStudentIdToFind(clsStudentBusinessLogic*& Student, string State = "Find")
	{
		bool IsID_AlreadyExists = true;
		string ID = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter the StudentID you want to " + State + "\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			getline(cin >> ws, ID);
			if (!clsUtil<bool>::IsChoiceCorrect(ID))
			{
				IsID_AlreadyExists = false;
				cout << clsUtil<string>::NumberOfTabs(5) << "The ID Number is not valid, Please try again.\n";
				system("pause > 0");
				continue;
			}
			IsID_AlreadyExists = clsStudentBusinessLogic::IsStudentID_AlreadyExists(stoi(ID), AllStudentsData);
			if (!IsID_AlreadyExists)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "The Student ID Doesn't Exists :-(, Please try again later.\n";
				system("pause > 0");
			}
		} while (!IsID_AlreadyExists);
		*Student = clsStudentBusinessLogic::FindStudent(stoi(ID), AllStudentsData);
	}
};


