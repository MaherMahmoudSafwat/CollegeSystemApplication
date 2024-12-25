#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include "clsUtil.h"
#include "clsDoctor.h"

using namespace std;

class clsDoctorBusinessLogic :public clsDoctor
{
private:
	static string _ConvertDoctorObjectToLine(clsDoctor Doctor, string Separator = "#//#")
	{
		string Line = "";
		Line += Doctor.GetFullName() + Separator;
		Line += to_string(Doctor.GetID()) + Separator;
		Line += clsUtil<string>::EncryptData(Doctor.GetPassword()) + Separator;
		Line += Doctor.GetEmail() + Separator;
		Line += Doctor.GetPhoneNumber() + Separator;
		Line += Doctor.GetAddress() + Separator;
		Line += Doctor.GetSpecialization() + Separator;
		Line += Doctor.GetMartialStatus();
		return Line;
	}
	static clsDoctorBusinessLogic _ConvertDoctorLineToObject(string Line)
	{
		vector <string> Doctor;
		Doctor = clsUtil<vector<string>>::Spilt(Line);
		return clsDoctorBusinessLogic("", Doctor[0], stoi(Doctor[1]), clsUtil<string>::DecryptData(Doctor[2]),
			Doctor[3], Doctor[4], Doctor[5], 0, 0, "", Doctor[6], Doctor[7]);
	}
public:
	clsDoctorBusinessLogic(string FirstName, string LastName, int ID, string Password, string Email, string PhoneNumber, string Address,
		int NumberOfCourses, int CourseID, string CourseName, string Specialization, string MartialStatus) :
		clsDoctor(FirstName, LastName, ID, Password, Email, PhoneNumber, Address, NumberOfCourses, CourseID, CourseName,
			Specialization, MartialStatus) {};
	void AddNewDoctor()
	{
		fstream NewFile;
		NewFile.open("DoctorsData.txt", ios::out | ios::app);
		if (NewFile.is_open())
		{
			NewFile << _ConvertDoctorObjectToLine(*this) << endl;
		}
	}
	static vector<clsDoctorBusinessLogic> GetAllData()
	{
		vector <clsDoctorBusinessLogic> GetAllAvaliableData;
		fstream NewFile;
		string Line;
		NewFile.open("DoctorsData.txt", ios::in);
		if (NewFile.is_open())
		{
			while (getline(NewFile, Line))
			{
				if (Line != "")
					GetAllAvaliableData.push_back(_ConvertDoctorLineToObject(Line));
			}
		}
		return GetAllAvaliableData;
	}
	static vector<clsDoctorBusinessLogic> GetAllAvaliableData()
	{
		return GetAllData();
	}
	static bool CheckDoctor_ID_AlreadyExists(short ID, vector <clsDoctorBusinessLogic> AllDoctorData)
	{
		for (clsDoctorBusinessLogic& DoctorID : AllDoctorData)
		{
			if (DoctorID.ID == ID)
				return true;
		}
		return false;
	}
	static clsDoctorBusinessLogic GetDoctorData(short ID, vector <clsDoctorBusinessLogic> AllDoctorData)
	{
		for (clsDoctorBusinessLogic& Doctor : AllDoctorData)
		{
			if (Doctor.ID == ID)
				return Doctor;
		}
		return clsDoctorBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", "");
	}
	static bool CheckDoctorEmailAlreadyExists(string Email, vector <clsDoctorBusinessLogic> AllDoctorData)
	{
		for (clsDoctorBusinessLogic& DoctorEmail : AllDoctorData)
		{
			if (DoctorEmail.Email == Email)
				return true;
		}
		return false;
	}
	static bool CheckDoctorPhoneNumberAlreadyExists(string PhoneNumber, vector <clsDoctorBusinessLogic> AllDoctorData)
	{
		for (clsDoctorBusinessLogic& DoctorPhoneNumber : AllDoctorData)
		{
			if (DoctorPhoneNumber.PhoneNumber == PhoneNumber)
				return true;
		}
		return false;
	}
	void UpdateDoctorInfo()
	{
		vector<clsDoctorBusinessLogic>GetAllDoctorsData = clsDoctorBusinessLogic::GetAllData();
		clsDoctor Doctor = *this;
		fstream NewFile;
		NewFile.open("DoctorsData.txt", ios::out);
		if (NewFile.is_open())
		{
			for (clsDoctorBusinessLogic& DoctorsData : GetAllDoctorsData)
			{
				if (Doctor.ID == DoctorsData.ID)
				{
					NewFile << _ConvertDoctorObjectToLine(Doctor) << endl;
					continue;
				}
				NewFile << _ConvertDoctorObjectToLine(DoctorsData) << endl;
			}
		}
		NewFile.close();
	}
	static void DeleteDoctorInfo(short ID)
	{
		fstream NewFile;
		vector <clsDoctorBusinessLogic> GetAllDoctorsData = clsDoctorBusinessLogic::GetAllData();
		NewFile.open("DoctorsData.txt", ios::out);
		if (NewFile.is_open())
		{
			for (clsDoctorBusinessLogic& DoctorsData : GetAllDoctorsData)
			{
				if (DoctorsData.ID == ID)
					continue;
				NewFile << _ConvertDoctorObjectToLine(DoctorsData) << endl;
			}
			NewFile.close();
		}
	}
};
