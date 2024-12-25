#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsDoctor.h"
#include "clsPersonalInfo.h"
#include "clsDoctorBusinessLogic.h"

using namespace std;

class clsShowAllDoctorsScreen : protected clsDrawScreenHeader<void>
{
private:
	static void _ShowAllDoctorsDataInfo(vector <clsDoctorBusinessLogic> AllDoctorsData)
	{
		short i = 1;
		if (AllDoctorsData.size() == 0)
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "There are no Doctors Data Found or Avaliable :-(.\n";
			return;
		}
		for (clsDoctorBusinessLogic& DoctorsData : AllDoctorsData)
		{
			cout << "----------------------------------- Doctor " + to_string(i) + "-----------------------------------\n";
			cout << "ID             :- " << DoctorsData.ID << endl;
			cout << "Full Name      :- " << DoctorsData.GetFullName() << endl;
			cout << "Password       :- " << DoctorsData.GetPassword() << endl;
			cout << "Email          :- " << DoctorsData.GetEmail() << endl;
			cout << "Phone Number   :- " << DoctorsData.GetPhoneNumber() << endl;
			cout << "Address        :- " << DoctorsData.GetAddress() << endl;
			cout << "Specialization :- " << DoctorsData.GetSpecialization() << endl;
			cout << "Martial Status :- " << DoctorsData.GetMartialStatus() << endl;
			i++;
		}
		cout << "-------------------------------------------------------------------------------------------------------\n";
	}
public:
	static void ShowAllDoctorsScreen()
	{
		clsDoctorBusinessLogic Doctor = clsDoctorBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", "");
		vector <clsDoctorBusinessLogic> AllDoctorsData = clsDoctorBusinessLogic::GetAllAvaliableData();
		string Subtitle = "Number of Doctors Avaliable are " + to_string(AllDoctorsData.size());
		system("cls");
		DrawHeaderScreen("Welcome to Show All Doctor Screen", Subtitle, 6);
		_ShowAllDoctorsDataInfo(AllDoctorsData);
		cout << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Any Key, to go back to admin main menu.\n";
	}
};

