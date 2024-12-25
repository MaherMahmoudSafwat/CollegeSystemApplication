#pragma once
#include "clsPerson.h"

class clsStudent :public clsPerson
{
private:
	string _CourseNameEnrolled;
	short _Grades;
	float _GPA;
	short _NumberOfCoursesEnrolled;
	bool _IsGraduated;
	string _Field;
public:
	clsStudent(string FirstName, string LastName, int ID, string Password, string Email, string PhoneNumber, string Address,
		short NumberOfCourses, short CourseID, string CourseName, string CourseNameEnrolled, short Grades, float GPA,
		short NumberOfCoursesEnrolled, bool IsGraduated, string Field) :
		clsPerson(FirstName, LastName, ID, Password, Email, PhoneNumber, Address, NumberOfCourses, CourseID, CourseName)
	{
		_CourseNameEnrolled = CourseNameEnrolled;
		_Grades = Grades;
		_GPA = GPA;
		_NumberOfCoursesEnrolled = NumberOfCoursesEnrolled;
		_IsGraduated = IsGraduated;
		_Field = Field;
	}
	void SetCourseNameEnrolled(string CourseNameEnrolled)
	{
		_CourseNameEnrolled = CourseNameEnrolled;
	}
	string GetCourseNameEnrolled()
	{
		return _CourseNameEnrolled;
	}
	_declspec(property(get = GetCourseNameEnrolled, put = SetCourseNameEnrolled))string CourseNameEnrolled;
	void SetGrades(short Grades)
	{
		_Grades = Grades;
	}
	short GetGrades()
	{
		return _Grades;
	}
	_declspec(property(get = GetGrades, put = SetGrades))short Grades;
	void SetGPA(float GPA)
	{
		_GPA = GPA;
	}
	float GetGPA()
	{
		return _GPA;
	}
	_declspec(property(get = GetGPA, put = SetGPA))float GPA;
	void SetNumberOfCoursesEnrolled(short NumberOfCoursesEnrolled)
	{
		_NumberOfCoursesEnrolled = NumberOfCoursesEnrolled;
	}
	short GetNumberOfCoursesEnrolled()
	{
		return _NumberOfCoursesEnrolled;
	}
	_declspec(property(get = GetNumberOfCoursesEnrolled, put = SetNumberOfCoursesEnrolled))short NumberOfCoursesEnrolled;
	void SetIsGraduated(bool IsGraduated)
	{
		_IsGraduated = IsGraduated;
	}
	bool GetIsGraduated()
	{
		return _IsGraduated;
	}
	_declspec(property(get = GetIsGraduated, put = SetIsGraduated))bool IsGraduated;
	void SetField(string Field)
	{
		_Field = Field;
	}
	string GetField()
	{
		return _Field;
	}
	_declspec(property(get = GetField, put = SetField))string Field;
};

