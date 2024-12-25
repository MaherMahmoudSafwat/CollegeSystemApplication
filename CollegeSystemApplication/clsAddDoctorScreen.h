#pragma once
#include <iostream>
#include <string>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsDoctor.h"
#include "clsPersonalInfo.h"
#include "clsDoctorBusinessLogic.h"
#include "clsAddDoctor.h"

using namespace std;

class clsAddDoctorScreen:protected clsDrawScreenHeader<void>
{
private:
	static void _AddNewDoctor(clsDoctor* Doctor)
	{
		clsAddDoctor Doctors;
		clsPersonalInfo <clsDoctor>* Person = &Doctors;
		Person->AddFirstName(Doctor);
		Person->AddLastName(Doctor);
		Person->AddID(Doctor);
		Person->AddPassword(Doctor);
		Person->AddEmail(Doctor);
		Person->AddPhoneNumber(Doctor);
		Person->AddAddress(Doctor);
		Doctors.AddSpecializiation(Doctor);
		Doctors.AddMartialStatus(Doctor);
		cout << clsUtil<string>::NumberOfTabs(5) << "----------------------------------------------------------------\n";
	}
public:
	static void AddNewDoctorsScreen()
	{
		clsDoctorBusinessLogic Doctor = clsDoctorBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", "");
		char Answer = 'Y';
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Add New Doctor Screen", "Please Fill The Following Information", 6);
			_AddNewDoctor(&Doctor);
			Doctor.AddNewDoctor();
			cout << clsUtil<string>::NumberOfTabs(5) << "Doctor Information has been added Successfully :-).\n\n\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to add another Doctor ? Y/N.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};


