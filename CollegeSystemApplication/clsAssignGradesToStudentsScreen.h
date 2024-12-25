#pragma once
#include <iostream>
#include "clsDrawScreen.h"
#include "clsCourseBusinessLogic.h"
#include "clsStudentBusinessLogic.h"
#include "clsCurrentDoctorLogin.h"

using namespace std;

class clsAssignGradesToStudentsScreen:protected clsDrawScreenHeader<void>
{
private:
	static void _ShowAllStudentInfo(clsStudentBusinessLogic Student)
	{
		cout << "The following is the student personal info.\n";
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "ID                         :- " << Student.GetID() << endl;
		cout << "FullName                   :- " << Student.GetFullName() << endl;
		cout << "Email                      :- " << Student.GetEmail() << endl;
		cout << "PhoneNumber                :- " << Student.GetPhoneNumber() << endl;
		cout << "Address                    :- " << Student.GetAddress() << endl;
		cout << "Field                      :- " << Student.GetField() << endl;
		cout << "-----------------------------------------------------------------------------------------------------\n";
	}
	static void _AssignGradesToStudents(clsStudentBusinessLogic* StudentGrades)
	{
		bool IsCourseID_AlreadyExists = true;
		bool IsCourseAlreadyTaughtByTheDoctor = true;	
		bool IsStudentID_AlreadyExists = true;
		int CourseID = 0;
		int StudentID = 0;
		short Grades = 0;
		vector<clsCourseBusinessLogic> GetAllCoursesData = clsCourseBusinessLogic::GetAllCourses();
		vector<clsStudentBusinessLogic> AllStudentsData = clsStudentBusinessLogic::GetAllStudentsData();
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome To Assign Grades to students Screen", "Please fill in the following Boxes", 6);
			cout << "Please Enter the Course ID.\n";
			cin >> CourseID;
			IsCourseID_AlreadyExists = !(clsCourseBusinessLogic::CheckCourse_ID_AlreadyExists(CourseID, GetAllCoursesData));
			if (IsCourseID_AlreadyExists)
			{
				cout << "Course Doesn't Exist :-(, Please enter another one.\n";
				system("pause > 0");
				continue;
			}
			IsCourseAlreadyTaughtByTheDoctor = !(clsCourseBusinessLogic::IsCourseTaughtByDoctor(CurrentDoctorUser.GetID(), CourseID));
			if (IsCourseAlreadyTaughtByTheDoctor)
			{
				cout << "Course is not Taught by you, Please enter another one.\n";
				system("pause > 0");
				continue;
			}
			cout << "Please enter Student ID.\n";
			cin >> StudentID;
			IsStudentID_AlreadyExists = !(clsStudentBusinessLogic::IsStudentID_AlreadyExists(StudentID, AllStudentsData));
			if (IsStudentID_AlreadyExists)
			{
				cout << "Student ID Doesn't Exist, Please try Again.\n";
				system("pause > 0");
				continue;
			}
		} while (IsCourseID_AlreadyExists || IsCourseAlreadyTaughtByTheDoctor || IsStudentID_AlreadyExists);
		*StudentGrades = clsStudentBusinessLogic::FindStudent(StudentID, AllStudentsData);
		_ShowAllStudentInfo(*StudentGrades);
		string Course = clsCourseBusinessLogic::GetCourseNameOnly(CourseID, GetAllCoursesData);
		StudentGrades->Courses.SetCourseID(CourseID);
		StudentGrades->Courses.SetCourseName(Course);
		cout << "Please Enter the grades of the " << Course << " for this student.\n";
		cin >> Grades;
		StudentGrades->SetGrades(Grades);
	}
public:
	static void AssignGradesToStudentsScreen()
	{
		char Answer = 'Y';
		do
		{
			clsStudentBusinessLogic StudentGrades = clsStudentBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", 0, 0, 0, 0, "");
			_AssignGradesToStudents(&StudentGrades);
			StudentGrades.UpdateStudentCoursesDataGrades();
			cout << "Course Grades have been Updated Successfully.\n";
			cout << "Would you like to update another grades for this student ? Y/N ? \n";
			cin >> Answer;
		} while (Answer == 'Y' || Answer == 'y');
		cout << "Press Any Key, to go back to doctor main menu.\n";
	}
};

