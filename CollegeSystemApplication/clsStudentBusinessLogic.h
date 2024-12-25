#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "clsUtil.h"
#include "clsStudent.h"

using namespace std;

class clsStudentBusinessLogic:public clsStudent
{
private:
	static string _ConvertStudentsObjectToLine(clsStudentBusinessLogic StudentData, string Separator = "#//#")
	{
		string Line = "";
		Line += StudentData.GetFullName() + Separator;
		Line += to_string(StudentData.GetID()) + Separator;
		Line += clsUtil<string>::EncryptData(StudentData.GetPassword()) + Separator;
		Line += StudentData.GetEmail() + Separator;
		Line += StudentData.GetPhoneNumber() + Separator;
		Line += StudentData.GetAddress() + Separator;
		Line += to_string(StudentData.GetGPA()) + Separator;
		Line += to_string(StudentData.GetNumberOfCoursesEnrolled()) + Separator;
		Line += (StudentData.GetIsGraduated()) ? "Graduated" : "Not Graduated" + Separator;
		Line += StudentData.GetField();
		return Line;
	}
	static clsStudentBusinessLogic _ConvertStudentLineToObject(string Line)
	{
		vector<string>StudentsData;
		StudentsData = clsUtil<string>::Spilt(Line);
		return clsStudentBusinessLogic("", StudentsData[0], stoi(StudentsData[1]), clsUtil<string>::DecryptData(StudentsData[2]),
			StudentsData[3], StudentsData[4], StudentsData[5],0,0, "","", 0, stoi(StudentsData[6]), stoi(StudentsData[7]),
			(StudentsData[8] == "Graduated") ? 1 : 0, StudentsData[9]);
	}
	static int GetStudentSpecifiID(string Line,string Separator="#//#")
	{
		int ID = 0;
		short Position = 0;
		if ((Position = Line.find(Separator))&&(Position!=Line.npos))
		{
			ID = stoi(Line.substr(0, Position));
			return ID;
		}
		return ID;
	}
	static string _ConvertStudentCoursesObjectToLine(clsStudentBusinessLogic StudentData, string Separator = "#//#")
	{
		string Line = "";
		Line += to_string(StudentData.GetID()) + Separator;
		Line += to_string(StudentData.Courses.GetCourseID()) + Separator;
		Line += StudentData.Courses.GetCourseName() + Separator;
		Line += to_string(StudentData.GetGrades());
		return Line;
	}
	static clsStudentBusinessLogic _ConvertStudentCourseLineToObject(string Line)
	{
		vector<string>StudentCourses;
		StudentCourses = clsUtil<string>::Spilt(Line);
		return clsStudentBusinessLogic("", "", stoi(StudentCourses[0]), "", "", "", "", 0,stoi(StudentCourses[1]),
			StudentCourses[2],"",stoi(StudentCourses[3]), 0, 0, 0, "");
	}
public:
	clsStudentBusinessLogic(string FirstName, string SecondName, int ID, string Password, string Email, string PhoneNumber,
		string Address, short NumberOfCourses, short CourseID, string CourseName, string CourseNameEnrolled, short Grades,
		float GPA, short NumberOfCoursesEnrolled, bool IsGraduated, string Field) :
		clsStudent(FirstName, SecondName, ID, Password, Email, PhoneNumber, Address, NumberOfCourses, CourseID, CourseName,
			CourseNameEnrolled, Grades, GPA, NumberOfCoursesEnrolled, IsGraduated, Field) {};

	void AddNewStudentsData()
	{
		fstream NewFile;
		NewFile.open("StudentsData.txt", ios::out | ios::app);
		if (NewFile.is_open())
		{
			NewFile << _ConvertStudentsObjectToLine(*this) << endl;
		}
		NewFile.close();
	}
	static vector<clsStudentBusinessLogic>GetAllStudentsData()
	{
		fstream NewFile;
		vector<clsStudentBusinessLogic>GetAllStudentsPersonalInfo;
		NewFile.open("StudentsData.txt", ios::in);
		string Line = "";
		if (NewFile.is_open())
		{
			while (getline(NewFile, Line))
			{
				GetAllStudentsPersonalInfo.push_back(_ConvertStudentLineToObject(Line));
			}
			NewFile.close();
		}
		return GetAllStudentsPersonalInfo;
	}
	static bool IsStudentID_AlreadyExists(int ID,vector<clsStudentBusinessLogic>GetAllStudentInfo)
	{
		for (clsStudentBusinessLogic& StudentData : GetAllStudentInfo)
		{
			if (StudentData.ID == ID)
				return true;
		}
		return false;
	}
	static bool IsStudentEmailAlreadyExists(string Email, vector<clsStudentBusinessLogic>GetAllStudentInfo)
	{
		for (clsStudentBusinessLogic& StudentData : GetAllStudentInfo)
		{
			if (StudentData.GetEmail() == Email)
				return true;
		}
		return false;
	}
	static clsStudentBusinessLogic FindStudent(int ID, vector<clsStudentBusinessLogic>GetAllStudentInfo)
	{
		for (clsStudentBusinessLogic& StudentData : GetAllStudentInfo)
		{
			if (StudentData.GetID() == ID)
				return StudentData;
		}
		return clsStudentBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", 0, 0, 0, 0, "");
	}
	void UpdateStudentData()
	{
		vector<clsStudentBusinessLogic>AllStudentsInfo = clsStudentBusinessLogic::GetAllStudentsData();
		clsStudentBusinessLogic StudentData = *this;
		fstream NewFile;
		NewFile.open("StudentsData.txt", ios::out);
		if (NewFile.is_open())
		{
			for (clsStudentBusinessLogic& AllStudentsData : AllStudentsInfo)
			{
				if (StudentData.GetID() == AllStudentsData.GetID())
				{
					NewFile << _ConvertStudentsObjectToLine(StudentData) << endl;
					continue;
				}
				NewFile << _ConvertStudentsObjectToLine(AllStudentsData) << endl;
			}
			NewFile.close();
		}
	}
	static vector<clsStudentBusinessLogic> GetAllStudentCourses(int ID)
	{
		fstream NewFile;
		vector<clsStudentBusinessLogic>GetAllStudentCourses;
		NewFile.open("StudentsCoursesData.txt", ios::in);
		string Line = "";
		if (NewFile.is_open())
		{
			while (getline(NewFile, Line))
			{
				if (ID == GetStudentSpecifiID(Line))
				{
					GetAllStudentCourses.push_back(_ConvertStudentCourseLineToObject(Line));
				}
			}
			NewFile.close();
		}
		return GetAllStudentCourses;
	}
	static float CalculateStudentGPA(int ID)
	{
		float GPA = 0;
		vector<clsStudentBusinessLogic>GetAllStudentCoursesGrades = clsStudentBusinessLogic::GetAllStudentCourses(ID);
		for (clsStudentBusinessLogic& StudentCoursesGrades : GetAllStudentCoursesGrades)
		{
			if (StudentCoursesGrades.GetGrades() >= 90)
				GPA += 4.0;
			else if (StudentCoursesGrades.GetGrades() >= 80)
				GPA += 3.5;
			else if (StudentCoursesGrades.GetGrades() >= 70)
				GPA += 3.0;
			else if (StudentCoursesGrades.GetGrades() >= 60)
				GPA += 2.5;
			else if (StudentCoursesGrades.GetGrades() >= 50)
				GPA += 2.0;
		}
		if (GetAllStudentCoursesGrades.size() == 0)
			return 0;
		else
		{
			GPA = (GPA / (GetAllStudentCoursesGrades.size() * 3));
		}
		return GPA;
	}
	void DeleteStudentInfo()
	{
		clsStudentBusinessLogic StudentData = *this;
		vector<clsStudentBusinessLogic>GetAllStudentsData = clsStudentBusinessLogic::GetAllStudentsData();
		fstream NewFile;
		string Line = "";
		NewFile.open("StudentsData.txt", ios::out);
		if (NewFile.is_open())
		{
			for (clsStudentBusinessLogic& StudentInfo : GetAllStudentsData)
			{
				if (StudentInfo.GetID() == StudentData.GetID())
					continue;
				NewFile << _ConvertStudentsObjectToLine(StudentInfo) << endl;
			}
			NewFile.close();
		}
	}
	void AddNewCourseForStudent()
	{
		fstream NewFile;
		NewFile.open("StudentsCoursesData.txt", ios::out | ios::app);
		if (NewFile.is_open())
		{
			NewFile << _ConvertStudentCoursesObjectToLine(*this) << endl;
		}
		NewFile.close();
	}
	static vector<clsStudentBusinessLogic>GetAllStudentsCourses()
	{
		vector <clsStudentBusinessLogic> GetAllAvaliableData;
		fstream NewFile;
		string Line;
		NewFile.open("StudentsCoursesData.txt", ios::in);
		if (NewFile.is_open())
		{
			while (getline(NewFile, Line))
			{
				if (Line != "")
					GetAllAvaliableData.push_back(_ConvertStudentCourseLineToObject(Line));
			}
		}
		return GetAllAvaliableData;
	}
	static bool CheckIfStudentAlreadyRegisteredForThisCourse(int StudentID, short CourseID)
	{
		vector<clsStudentBusinessLogic> GetAllStudentsRegisteredCourses = clsStudentBusinessLogic::GetAllStudentsCourses();
		for (clsStudentBusinessLogic& AllCoursesData : GetAllStudentsRegisteredCourses)
		{
			if (AllCoursesData.GetID() == StudentID && AllCoursesData.Courses.GetCourseID() == CourseID)
				return true;
		}
		return false;
	}
	void UpdateStudentCoursesDataGrades()
	{
		vector<clsStudentBusinessLogic>AllStudentsInfo = clsStudentBusinessLogic::GetAllStudentsCourses();
		clsStudentBusinessLogic StudentData = *this;
		fstream NewFile;
		NewFile.open("StudentsCoursesData.txt", ios::out);
		if (NewFile.is_open())
		{
			for (clsStudentBusinessLogic& AllStudentsData : AllStudentsInfo)
			{
				if (StudentData.GetID() == AllStudentsData.GetID() && 
					StudentData.Courses.GetCourseID() == AllStudentsData.Courses.GetCourseID())
				{
					NewFile << _ConvertStudentCoursesObjectToLine(StudentData) << endl;
					continue;
				}
				NewFile << _ConvertStudentCoursesObjectToLine(AllStudentsData)<< endl;
			}
			NewFile.close();
		}
	}
	static string GradesInLetters(short Grades)
	{
		if (Grades >= 90)
			return "A";
		else if (Grades >= 80)
			return "B";
		else if (Grades >= 70)
			return "C";
		else if (Grades >= 60)
			return "D+";
		else if (Grades >= 50)
			return "D";
		else
			return "F";
	}
};

