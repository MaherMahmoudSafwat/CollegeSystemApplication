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

using namespace std;

class clsUpdateDoctorScreen :protected clsDrawScreenHeader<void>
{
private:
	static void _UpdateDoctor(clsDoctor* Doctor)
	{
		clsUpdateDoctor UpdateInfo;
		clsUpdatePersonalInfo<clsDoctor>* UpdateDoctorInfo = &UpdateInfo;
		UpdateInfo.GetDoctorIdToUpdate(Doctor);
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
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Update Doctor Information Screen", "Please Fill The Following Information", 6);
			_UpdateDoctor(&Doctor);
			Doctor.UpdateDoctorInfo();
			cout << clsUtil<string>::NumberOfTabs(5) << "Doctor Information has been Updated Successfully :-).\n\n\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to Update another Doctor ? Y/N.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};
