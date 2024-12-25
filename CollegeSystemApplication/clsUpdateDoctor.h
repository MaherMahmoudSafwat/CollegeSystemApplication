#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsDoctor.h"
#include "clsDoctorBusinessLogic.h"
#include "clsUpdatePersonalInfo.h"

using namespace std;


class clsUpdateDoctor :public clsUpdatePersonalInfo<clsDoctor>
{
public:
	clsDoctorBusinessLogic Doctors = clsDoctorBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", "");
	vector<clsDoctorBusinessLogic>AllDoctorsData = Doctors.GetAllAvaliableData();
	void GetDoctorIdToUpdate(clsDoctor*& Doctor)
	{
		bool IsID_AlreadyExists = true;
		string ID = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter the DoctorID you want to update.\n";
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
	void UpdatePassword(clsDoctor*& Doctor)
	{
		string DoctorPassword = "";
		string ConfirmPassword = "";
		bool IsPasswordAndConfirmPasswordsAreTheSame = true;
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to update the Doctor Password ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			do
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Doctor Password.\n";
				cout << clsUtil<string>::NumberOfTabs(5);
				getline(cin >> ws, DoctorPassword);
				Doctor->SetPassword(DoctorPassword);
				cout << clsUtil<string>::NumberOfTabs(5) << "Please Confirm Password.\n";
				cout << clsUtil<string>::NumberOfTabs(5);
				getline(cin >> ws, ConfirmPassword);
				IsPasswordAndConfirmPasswordsAreTheSame = (Doctor->GetPassword() == ConfirmPassword);
				if (!IsPasswordAndConfirmPasswordsAreTheSame)
				{
					cout << clsUtil<string>::NumberOfTabs(5) << "Passwords aren't the same, Please try again.\n";
					system("pause > 0");
				}
			} while (!IsPasswordAndConfirmPasswordsAreTheSame);
		}
	}
	void UpdateEmail(clsDoctor*& Doctor)
	{
		bool IsEmailAlreadyExists = true;
		string DoctorEmail = "";
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to update the Doctor Email ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			do
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Doctor Email.\n";
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
	}
	void UpdatePhoneNumber(clsDoctor*& Doctor)
	{
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to update the Doctor PhoneNumber ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			string DoctorPhoneNumber = "";
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Doctor PhoneNumber.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			getline(cin >> ws, DoctorPhoneNumber);
			Doctor->SetPhoneNumber(DoctorPhoneNumber);
		}
	}
	void UpdateAddress(clsDoctor*& Doctor)
	{
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to update the Doctor Address ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			string DoctorAddress = "";
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Doctor Address.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			getline(cin >> ws, DoctorAddress);
			Doctor->SetAddress(DoctorAddress);
		}
	}
	void UpdateMartialStatus(clsDoctor*& Doctor)
	{
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to update the Doctor Martial Status? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			string DoctorMartialStatus = "";
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Doctor MartialStatus.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			getline(cin >> ws, DoctorMartialStatus);
			Doctor->SetMartialStatus(DoctorMartialStatus);
		}
	}
};


