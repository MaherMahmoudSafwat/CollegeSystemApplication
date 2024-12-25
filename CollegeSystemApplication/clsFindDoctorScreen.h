#pragma once
#include <iostream>
#include <string>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsDoctor.h"
#include "clsFindDoctor.h"
#include "clsDoctorBusinessLogic.h"

using namespace std;

class clsFindDoctorScreen :protected clsDrawScreenHeader<void>
{
protected:
	static void _ShowDoctorInfo(clsDoctorBusinessLogic* Doctor, string State = "Find")
	{
	    clsFindDoctor FindDoctor;
		FindDoctor.GetDoctorIdToFind(Doctor, State);
		system("cls");
		DrawHeaderScreen("Welcome to Find Doctor Information Screen", "The Following is all Doctor Information", 6);
		cout << "-----------------------------------------------------\n\n\n";
		cout << "ID             :- " << Doctor->ID << endl;
		cout << "Full Name      :- " << Doctor->GetFullName() << endl;
		cout << "Password       :- " << Doctor->GetPassword() << endl;
		cout << "Email          :- " << Doctor->GetEmail() << endl;
		cout << "Phone Number   :- " << Doctor->GetPhoneNumber() << endl;
		cout << "Address        :- " << Doctor->GetAddress() << endl;
		cout << "Specialization :- " << Doctor->GetSpecialization() << endl;
		cout << "Martial Status :- " << Doctor->GetMartialStatus() << endl;
		cout << "\n\n\n-----------------------------------------------------\n";
	}
public:
	static void FindDoctorScreen()
	{
		clsDoctorBusinessLogic Doctor = clsDoctorBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", "");
		char Answer = 'Y';
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome to Find Doctor Information Screen", "Please Fill The Following Information", 6);
			_ShowDoctorInfo(&Doctor);
			cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to Find another Doctor ? Y/N.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};

