#pragma once
#include <fstream>
#include <string>
#include "clsUtil.h"
#include "clsDoctorBusinessLogic.h"
#include "clsStudentBusinessLogic.h"

using namespace std;

template <typename T>

class clsLoginManagement
{
public:
	vector<clsDoctorBusinessLogic> GetAllDoctorsData = clsDoctorBusinessLogic::GetAllData();
	static T ManagePasswords(string Password)
	{
		fstream File;
		File.open("AdminPassword.txt", ios::in);
		string Line = "";
		if (File.is_open())
		{
			while (getline(File, Line))
			{
				if (Line == clsUtil<string>::EncryptData(Password))
				{
					return true;
				}
			}
		}
		return false;
	}
	static bool ManageDoctorID(short ID)
	{
		vector<clsDoctorBusinessLogic> GetAllDoctorsData = clsDoctorBusinessLogic::GetAllData();
		if (clsDoctorBusinessLogic::CheckDoctor_ID_AlreadyExists(ID, GetAllDoctorsData))
			return true;
		return false;
	}
	static bool ManageDoctorPassword(short ID,string Password)
	{
		vector<clsDoctorBusinessLogic> GetAllDoctorsData = clsDoctorBusinessLogic::GetAllData();
		clsDoctorBusinessLogic Doctor = clsDoctorBusinessLogic::GetDoctorData(ID, GetAllDoctorsData);
		if (Doctor.GetPassword() == Password)
			return true;
		return false;
	}
	static bool ManageStudentID(int ID)
	{
		vector<clsStudentBusinessLogic> GetAllStudentsData = clsStudentBusinessLogic::GetAllStudentsData();
		if (clsStudentBusinessLogic::IsStudentID_AlreadyExists(ID, GetAllStudentsData))
			return true;
		return false;
	}
	static bool ManageStudentPassword(int ID, string Password)
	{
		vector<clsStudentBusinessLogic> GetAllStudentsData = clsStudentBusinessLogic::GetAllStudentsData();
		clsStudentBusinessLogic Student = clsStudentBusinessLogic::FindStudent(ID, GetAllStudentsData);
		if (Student.GetPassword() == Password)
			return true;
		return false;
	}
};

