#pragma once
#include <iostream>
#include <string>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsDoctor.h"
#include "clsUpdateDoctor.h"
#include "clsUpdatePersonalInfo.h"
#include "clsDoctorBusinessLogic.h"
#include "clsCurrentDoctorLogin.h"

using namespace std;

class clsDoctorUpdateDataScreen:protected clsDrawScreenHeader<void>
{
private:
	static void _UpdateDoctor(clsDoctor* Doctor)
	{
		clsUpdateDoctor UpdateInfo;
		clsUpdatePersonalInfo<clsDoctor>* UpdateDoctorInfo = &UpdateInfo;
		*Doctor = CurrentDoctorUser;
		UpdateDoctorInfo->UpdatePassword(Doctor);
		UpdateDoctorInfo->UpdateEmail(Doctor);
		UpdateDoctorInfo->UpdatePhoneNumber(Doctor);
		UpdateDoctorInfo->UpdateAddress(Doctor);
		UpdateInfo.UpdateMartialStatus(Doctor);
		cout << clsUtil<string>::NumberOfTabs(5) << "----------------------------------------------------------------\n";
	}
public:
	static void UpdateDoctorScreen()
	{
		clsDoctorBusinessLogic Doctor = clsDoctorBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", "");
		char Answer = 'Y';
		system("cls");
		DrawHeaderScreen("Welcome to Update Doctor Information Screen", "Please Fill The Following Information", 6);
		_UpdateDoctor(&Doctor);
		cout << clsUtil<string>::NumberOfTabs(5) << "Doctor Information has been Updated Successfully :-).\n\n\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to update your doctor data ? Y/N.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Doctor.UpdateDoctorInfo();
			CurrentDoctorUser = Doctor;
			cout << clsUtil<string>::NumberOfTabs(5) << "Your Personal Doctor Info has been Updated Successfully.\n";
		}
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};

