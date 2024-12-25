#pragma once
#include "clsPerson.h"

using namespace std;

class clsDoctor :public clsPerson
{
private:
	string _Specialization;
	string _MartialStatus;
public:
	clsDoctor(string FirstName, string LastName, int ID, string Password, string Email, string PhoneNumber, string Address,
		int NumberOfCourses, int CourseID, string CourseName, string Specialization, string MartialStatus) :
		clsPerson(FirstName, LastName, ID, Password, Email, PhoneNumber, Address, NumberOfCourses, CourseID, CourseName)
	{
		_Specialization = Specialization;
		_MartialStatus = MartialStatus;
	}
	void SetSpecialization(string Specialization)
	{
		_Specialization = Specialization;
	}
	string GetSpecialization()
	{
		return _Specialization;
	}
	_declspec(property(get = GetSpecialization, put = SetSpecialization))string Specialization;
	void SetMartialStatus(string MartialStatus)
	{
		_MartialStatus = MartialStatus;
	}
	string GetMartialStatus()
	{
		return _MartialStatus;
	}
	_declspec(property(get = GetMartialStatus, put = SetMartialStatus))string MartialStatus;
};

