#pragma once
#include <iostream>
#include <string>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsStudent.h"
#include "clsFindStudentScreen.h"
#include "clsStudentBusinessLogic.h"

using namespace std;

class clsDeleteStudentScreen :protected clsDrawScreenHeader<void>, clsFindStudentScreen
{
private:
	static void _DeleteStudent(clsStudentBusinessLogic* Student)
	{
		_ShowStudentInfo(Student, "Delete");
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to delete this Student Information ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Student->DeleteStudentInfo();
		}
	}
public:
	static void DeleteUsersScreen()
	{
		clsStudentBusinessLogic Student = clsStudentBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", 0, 0, 0, 0, "");
		char Answer = 'Y';
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Delete Student Information Screen", "Please Fill The Following Information", 6);
			_DeleteStudent(&Student);
			cout << clsUtil<string>::NumberOfTabs(5) << "Student Information has been Deleted Successfully.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to Delete another Student ? Y/N.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};
