#pragma once
#include <iostream>
#include <string>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsDoctor.h"
#include "clsFindDoctorScreen.h"
#include "clsDoctorBusinessLogic.h"

using namespace std;

class clsDeleteUsersScreen :protected clsDrawScreenHeader<void>, clsFindDoctorScreen
{
private:
	static void _DeleteDoctor(clsDoctorBusinessLogic* Doctor)
	{
		_ShowDoctorInfo(Doctor, "Delete");
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to delete this Doctor Information ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			clsDoctorBusinessLogic::DeleteDoctorInfo(Doctor->ID);
		}
	}
public:
	static void DeleteUsersScreen()
	{
		clsDoctorBusinessLogic Doctor = clsDoctorBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", "");
		char Answer = 'Y';
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Delete Doctor Information Screen", "Please Fill The Following Information", 6);
			_DeleteDoctor(&Doctor);
			cout << clsUtil<string>::NumberOfTabs(5) << "Doctor Information has been Deleted Successfully.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to Delete another Doctor ? Y/N.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};
