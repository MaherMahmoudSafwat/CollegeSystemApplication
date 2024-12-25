#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsDoctor.h"
#include "clsPersonalInfo.h"
#include "clsDoctorBusinessLogic.h"

using namespace std;


class clsAddDoctor :public clsPersonalInfo<clsDoctor>
{
public:
	clsDoctorBusinessLogic Doctors = clsDoctorBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", "");
	vector<clsDoctorBusinessLogic>AllDoctorsData = Doctors.GetAllAvaliableData();
	void AddFirstName(clsDoctor*& Doctor)
	{
		string DoctorFirstName = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Doctor FirstName.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, DoctorFirstName);
		Doctor->SetFirstName(DoctorFirstName);
	}
	void AddLastName(clsDoctor*& Doctor)
	{
		string DoctorLastName = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Doctor LastName.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, DoctorLastName);
		Doctor->SetLastName(DoctorLastName);
	}
	void AddID(clsDoctor*& Doctor)
	{
		bool IsID_AlreadyExists = true;
		do
		{
			int RandomNumber = clsUtil<int>::GetRandomNumber(1, 1000);
			Doctor->SetID(RandomNumber);
			IsID_AlreadyExists = clsDoctorBusinessLogic::CheckDoctor_ID_AlreadyExists(Doctor->GetID(), AllDoctorsData);
		} while (IsID_AlreadyExists);
	}
	void AddPassword(clsDoctor*& Doctor)
	{
		string DoctorPassword = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Doctor Password.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, DoctorPassword);
		Doctor->SetPassword(DoctorPassword);
	}
	void AddEmail(clsDoctor*& Doctor)
	{
		bool IsEmailAlreadyExists = true;
		string DoctorEmail = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Doctor Email.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			getline(cin >> ws, DoctorEmail);
			Doctor->SetEmail(DoctorEmail);
			IsEmailAlreadyExists = clsDoctorBusinessLogic::CheckDoctorEmailAlreadyExists(Doctor->GetEmail(), AllDoctorsData);
			if (IsEmailAlreadyExists)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "This Email Already Exists :-(, Please try another one.\n";
				system("pause > 0");
			}
		} while (IsEmailAlreadyExists);
	}
	void AddPhoneNumber(clsDoctor*& Doctor)
	{
		string DoctorPhoneNumber = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Doctor PhoneNumber.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, DoctorPhoneNumber);
		Doctor->SetPhoneNumber(DoctorPhoneNumber);
	}
	void AddAddress(clsDoctor*& Doctor)
	{
		string DoctorAddress = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Doctor Address.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, DoctorAddress);
		Doctor->SetAddress(DoctorAddress);
	}
	void AddSpecializiation(clsDoctor*& Doctor)
	{
		string DoctorSpecializiation = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Doctor Specializiation.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, DoctorSpecializiation);
		Doctor->SetSpecialization(DoctorSpecializiation);
	}
	void AddMartialStatus(clsDoctor*& Doctor)
	{
		string DoctorMartialStatus = "";
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Doctor MartialStatus.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		getline(cin >> ws, DoctorMartialStatus);
		Doctor->SetMartialStatus(DoctorMartialStatus);
	}
};

