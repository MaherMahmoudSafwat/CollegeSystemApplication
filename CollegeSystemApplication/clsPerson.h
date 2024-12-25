#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	int _ID;
	string _Password;
	string _Email;
	string _PhoneNumber;
	string _Address;
	class clsCourses
	{
	private:
		int _NumberOfCourses;
		int _CourseID;
		string _CourseName;
	public:
		clsCourses(int NumberOfCourses, int CourseID, string CourseName)
		{
			_NumberOfCourses = NumberOfCourses;
			_CourseID = CourseID;
			_CourseName = CourseName;
		}
		void SetNumberOfCourses(int _NumberOfCourses)
		{
			this->_NumberOfCourses = _NumberOfCourses;
		}
		int GetNumberOfCourses()
		{
			return _NumberOfCourses;
		}
		_declspec(property(get = GetNumberOfCourses, put = SetNumberOfCourses))int NumberOfCourses;
		void SetCourseID(int _CourseID)
		{
			this->_CourseID = _CourseID;
		}
		int GetCourseID()
		{
			return _CourseID;
		}
		_declspec(property(get = GetCourseID, put = SetCourseID))int CourseID;
		void SetCourseName(string _CourseName)
		{
			this->_CourseName = _CourseName;
		}
		string GetCourseName()
		{
			return _CourseName;
		}
		_declspec(property(get = GetCourseName, put = SetCourseName))string CourseName;
	};
public:
	clsCourses Courses = clsCourses(0, 0, "");
	clsPerson(string FirstName, string LastName, int ID, string Password, string Email, string PhoneNumber, string Address,
		int NumberOfCourses, int CourseID, string CourseName)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_ID = ID;
		_Password = Password;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
		_Address = Address;
		Courses = clsCourses(NumberOfCourses, CourseID, CourseName);
	}
	void SetFirstName(string _FirstName)
	{
		this->_FirstName = _FirstName;
	}
	string GetFirstName()
	{
		return _FirstName;
	}
	_declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;
	void SetLastName(string _LastName)
	{
		this->_LastName = _LastName;
	}
	string GetLastName()
	{
		return _LastName;
	}
	_declspec(property(get = GetLastName, put = SetLastName))string LastName;
	string GetFullName()
	{
		return _FirstName + "" + _LastName;
	}
	void SetID(int _ID)
	{
		this->_ID = _ID;
	}
	int GetID()
	{
		return _ID;
	}
	_declspec(property(get = GetID, put = SetID))int ID;
	void SetPassword(string _Password)
	{
		this->_Password = _Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	_declspec(property(get = GetPassword, put = SetPassword))string Password;
	void SetEmail(string _Email)
	{
		this->_Email = _Email;
	}
	string GetEmail()
	{
		return _Email;
	}
	_declspec(property(get = GetEmail, put = SetEmail))string Email;
	void SetPhoneNumber(string _PhoneNumber)
	{
		this->_PhoneNumber = _PhoneNumber;
	}
	string GetPhoneNumber()
	{
		return _PhoneNumber;
	}
	_declspec(property(get = GetPhoneNumber, put = SetPhoneNumber))string PhoneNumber;
	void SetAddress(string _Address)
	{
		this->_Address = _Address;
	}
	string GetAddress()
	{
		return _Address;
	}
	_declspec(property(get = GetAddress, put = SetAddress))string Address;
};

