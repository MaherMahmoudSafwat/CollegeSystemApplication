#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsStudentBusinessLogic.h"

using namespace std;

class clsCourseBusinessLogic :public clsPerson
{
private:
	static string _ConvertCourseObjectToLine(clsPerson Course, string Separator = "#//#")
	{
		string Line = "";
		Line += to_string(Course.Courses.GetCourseID()) + Separator;
		Line += Course.Courses.GetCourseName();
		return Line;
	}
	static clsCourseBusinessLogic _ConvertCourseLineToObject(string Line)
	{
		vector <string> Course;
		Course = clsUtil<vector<string>>::Spilt(Line);
		return clsCourseBusinessLogic("", "", 0, "", "", "", "", 0, stoi(Course[0]), Course[1]);
	}
	static string _ConvertDoctorCoursesObjectToLine(clsCourseBusinessLogic Course, string Separator = "#//#")
	{
		string Line = "";
		Line += to_string(Course.GetID()) + Separator;
		Line += to_string(Course.Courses.GetCourseID()) + Separator;
		Line += Course.Courses.GetCourseName();
		return Line;
	}
	static clsCourseBusinessLogic _ConvertDoctorCoursesLineToObject(string Line)
	{
		vector <string> Course;
		Course = clsUtil<vector<string>>::Spilt(Line);
		return clsCourseBusinessLogic("", "", stoi(Course[0]), "", "", "", "", 0, stoi(Course[1]), Course[2]);
	}
public:
	clsCourseBusinessLogic(string FirstName, string LastName, int ID, string Password, string Email, string PhoneNumber, string Address,
		int NumberOfCourses, int CourseID, string CourseName) :
		clsPerson(FirstName, LastName, ID, Password, Email, PhoneNumber, Address, NumberOfCourses, CourseID, CourseName) 
	{
	};
	void AddNewCourse()
	{
		fstream NewFile;
		NewFile.open("CoursesData.txt", ios::out | ios::app);
		if (NewFile.is_open())
		{
			NewFile << _ConvertCourseObjectToLine(*this) << endl;
		}
	}
	static vector<clsCourseBusinessLogic> GetAllCourses()
	{
		vector <clsCourseBusinessLogic> GetAllAvaliableData;
		fstream NewFile;
		string Line;
		NewFile.open("CoursesData.txt", ios::in);
		if (NewFile.is_open())
		{
			while (getline(NewFile, Line))
			{
				if (Line != "")
					GetAllAvaliableData.push_back(_ConvertCourseLineToObject(Line));
			}
		}
		return GetAllAvaliableData;
	}
	static bool CheckCourse_ID_AlreadyExists(short ID, vector <clsCourseBusinessLogic> AllCourseData)
	{
		for (clsCourseBusinessLogic& CourseID : AllCourseData)
		{
			if (CourseID.Courses.GetCourseID() == ID)
				return true;
		}
		return false;
	}
	static clsCourseBusinessLogic GetCourseData(short ID, vector <clsCourseBusinessLogic> AllCourseData)
	{
		for (clsCourseBusinessLogic& Course : AllCourseData)
		{
			if (Course.Courses.GetCourseID() == ID)
				return Course;
		}
		return clsCourseBusinessLogic("", "", 0, "", "", "", "", 0, 0, "");
	}
	static string GetCourseNameOnly(short ID, vector <clsCourseBusinessLogic> AllCourseData)
	{
		for (clsCourseBusinessLogic& CourseName : AllCourseData)
		{
			if (CourseName.Courses.GetCourseID() == ID)
				return CourseName.Courses.GetCourseName();
		}
		return "";
	}
	void UpdateCourseInfo()
	{
		vector<clsCourseBusinessLogic>GetAllCoursesData = clsCourseBusinessLogic::GetAllCourses();
		clsPerson Course = *this;
		fstream NewFile;
		NewFile.open("CoursesData.txt", ios::out);
		if (NewFile.is_open())
		{
			for (clsCourseBusinessLogic& CoursesData : GetAllCoursesData)
			{
				if (Course.Courses.GetCourseID() == CoursesData.Courses.GetCourseID())
				{
					NewFile << _ConvertCourseObjectToLine(Course) << endl;
					continue;
				}
				NewFile << _ConvertCourseObjectToLine(CoursesData) << endl;
			}
		}
		NewFile.close();
	}
	void DeleteCourseInfo()
	{
		fstream NewFile;
		clsCourseBusinessLogic Course = *this;
		vector <clsCourseBusinessLogic> GetAllCoursesData = clsCourseBusinessLogic::GetAllCourses();
		NewFile.open("CoursesData.txt", ios::out);
		if (NewFile.is_open())
		{
			for (clsCourseBusinessLogic& CoursesData : GetAllCoursesData)
			{
				if (CoursesData.Courses.GetCourseID() == Course.Courses.GetCourseID())
					continue;
				NewFile << _ConvertCourseObjectToLine(CoursesData) << endl;
			}
			NewFile.close();
		}
	}
	void AssignCoursesToDoctor()
	{
		fstream NewFile;
		clsCourseBusinessLogic CourseAssignment = clsCourseBusinessLogic("", "", 0, "", "", "", "", 0, 0, "");
		CourseAssignment = *this;
		NewFile.open("DoctorCoursesData.txt", ios::out|ios::app);
		if (NewFile.is_open())
		{
			NewFile << _ConvertDoctorCoursesObjectToLine(CourseAssignment) << endl;
		}
		NewFile.close();
	}
	static vector<clsCourseBusinessLogic>GetAllCoursesAssignedToDoctors()
	{
		vector <clsCourseBusinessLogic> GetAllAvaliableData;
		fstream NewFile;
		string Line;
		NewFile.open("DoctorCoursesData.txt", ios::in);
		if (NewFile.is_open())
		{
			while (getline(NewFile, Line))
			{
				if (Line != "")
					GetAllAvaliableData.push_back(_ConvertDoctorCoursesLineToObject(Line));
			}
		}
		return GetAllAvaliableData;
	}
	static vector <string> GetCoursesNamesAssignedToSpecificUser(short ID, vector<clsCourseBusinessLogic>GetAllCourses)
	{
		vector<string>AllCoursesRelatedToSpecificUser;
		for (clsCourseBusinessLogic& AllCoursesData : GetAllCourses)
		{
			if (ID == AllCoursesData.GetID())
				AllCoursesRelatedToSpecificUser.push_back(AllCoursesData.Courses.GetCourseName());
		}
		return AllCoursesRelatedToSpecificUser;
	}
	static bool IsCourseTaughtByDoctor(int DoctorID, int CourseID)
	{
		vector<clsCourseBusinessLogic>GetAllDoctorsCourses = clsCourseBusinessLogic::GetAllCoursesAssignedToDoctors();
		for (clsCourseBusinessLogic& DoctorsCourses : GetAllDoctorsCourses)
		{
			if (DoctorsCourses.GetID() == DoctorID && DoctorsCourses.Courses.GetCourseID() == CourseID)
				return true;
		}
		return false;
	}
};
