#pragma once
#include "clsDrawScreen.h"
#include "clsLoginManagement.h"
#include "clsLogin.h"
#include "clsCurrentDoctorLogin.h"
#include "clsDoctorMainMenuScreen.h"

using namespace std;


class clsDoctorLoginScreen :protected clsDrawScreenHeader <void>, public clsLogin
{
public:
	void Login()
	{
		string Password = "";
		short ID = 0;
		bool IsPasswordValid = true;
		bool IsID_Exists = true;
		do
		{
			system("cls");
			DrawHeaderScreen("Doctor Login Screen", "", 6);
			cout << "Please enter your ID.\n";
			cin >> ID;
			IsID_Exists = !clsLoginManagement<bool>::ManageDoctorID(ID);
			if (IsID_Exists)
			{
				cout << "Invalid ID, Please try Again :-( .\n";
				system("pause > 0");
				continue;
			}
			cout << "Please enter your Password.\n";
			getline(cin >> ws, Password);
			IsPasswordValid = !clsLoginManagement<bool>::ManageDoctorPassword(ID,Password);
			if (IsPasswordValid)
			{
				cout << "Invalid Password, Please try Again :-( .\n";
				system("pause > 0");
				continue;
			}
		} while (IsPasswordValid || IsID_Exists);
		vector<clsDoctorBusinessLogic>AllDoctorsData = clsDoctorBusinessLogic::GetAllData();
		CurrentDoctorUser = clsDoctorBusinessLogic::GetDoctorData(ID, AllDoctorsData);
		clsDoctorMainMenuScreen::ShowDoctorMainMenuScreen();
	}
};

