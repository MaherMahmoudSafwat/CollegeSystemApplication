#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "clsDrawScreen.h"
#include "clsUtil.h"
#include "clsStudentBusinessLogic.h"
#include "clsCourseBusinessLogic.h"
#include "clsCurrentStudentLogin.h"

using namespace std;

class clsShowAllStudentGradesScreen:protected clsDrawScreenHeader<void>
{
private:
	static void _ShowGradesInTable (clsStudentBusinessLogic StudentGrades)
	{
		cout << "| " << setw(10) << left << StudentGrades.Courses.GetCourseID();
		cout << "| " << setw(77) << left << StudentGrades.Courses.GetCourseName();
		cout << "| " << setw(6) << left << StudentGrades.GetGrades();
		cout << "| " << setw(18) << left << clsStudentBusinessLogic::GradesInLetters(StudentGrades.GetGrades());
		cout << "|";
	}
	static void _ShowAllGrades(vector <clsStudentBusinessLogic> StudentGrades)
	{
		cout << "Student Name :- " << CurrentStudentUser.GetFullName() << clsUtil<string>::NumberOfTabs(9)
			<< "GPA :- " << CurrentStudentUser.GetGPA() << endl;
		cout << "Student ID :- " << CurrentStudentUser.GetID() << clsUtil<string>::NumberOfTabs(8) << "Graduation Status :- "
			<< ((CurrentStudentUser.GetIsGraduated()==1)?"Graduated":"Not Graduated") << endl;
		if (StudentGrades.size() < 1)
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "You haven't registered for any coure yet :-(.\n";
			return;
		}
		else
		{
			cout << "--------------------------------------------------------------------------------------------------------";
			cout << "----------------\n";
			cout << "| " << setw(10) << left << "Course ID " << "| " << setw(77) << left << "Course Name "
				<< "| " << setw(6) << left << "Grade " << "| " << setw(18) << left << "Grade in Letters | ";
			for (clsStudentBusinessLogic& StudentData : StudentGrades)
			{
				cout << "--------------------------------------------------------------------------------------------------------";
				cout << "----------------\n";
				_ShowGradesInTable(StudentData);
				cout << endl; 
			}
			cout << "--------------------------------------------------------------------------------------------------------";
			cout << "----------------\n";
		}
	}
public:
	static void ShowAllStudentGrades()
	{
		vector <clsStudentBusinessLogic> GetAllStudentCourses = clsStudentBusinessLogic::
			GetAllStudentCourses(CurrentStudentUser.GetID());
		string SubTtile = "Number of Courses the student registered are " + to_string(GetAllStudentCourses.size()) + " Course.";
		system("cls");
		DrawHeaderScreen("Welcome to the Show All Student Grades", SubTtile, 5);
		_ShowAllGrades(GetAllStudentCourses);
		cout << "Press Any Key, to go back to student main menu.\n";
	}
};

