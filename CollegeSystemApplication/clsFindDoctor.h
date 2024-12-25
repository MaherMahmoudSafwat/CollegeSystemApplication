#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsDoctorBusinessLogic.h"

using namespace std;

class clsFindDoctor
{
public:
	clsDoctorBusinessLogic Doctors = clsDoctorBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", "");
	vector<clsDoctorBusinessLogic>AllDoctorsData = Doctors.GetAllAvaliableData();
	void GetDoctorIdToFind(clsDoctorBusinessLogic*& Doctor, string State = "Find")
	{
		bool IsID_AlreadyExists = true;
		string ID = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter the DoctorID you want to " + State + "\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			getline(cin >> ws, ID);
			if (!clsUtil<bool>::IsChoiceCorrect(ID))
			{
				IsID_AlreadyExists = false;
				cout << clsUtil<string>::NumberOfTabs(5) << "The ID Number is not valid, Please try again.\n";
				system("pause > 0");
				continue;
			}
			IsID_AlreadyExists = clsDoctorBusinessLogic::CheckDoctor_ID_AlreadyExists(stoi(ID), AllDoctorsData);
			if (!IsID_AlreadyExists)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "The Doctor ID Doesn't Exists :-(, Please try again later.\n";
				system("pause > 0");
			}
		} while (!IsID_AlreadyExists);
		*Doctor = clsDoctorBusinessLogic::GetDoctorData(stoi(ID), AllDoctorsData);
	}
};



