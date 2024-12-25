#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsStudent.h"
#include "clsStudentBusinessLogic.h"
#include "clsUpdatePersonalInfo.h"

using namespace std;


class clsUpdateStudent :public clsUpdatePersonalInfo<clsStudent>
{
public:
	clsStudentBusinessLogic Student = clsStudentBusinessLogic("", "", 0, "", "", "", "", 0, 0, "", "", 0, 0, 0, 0, "");
	vector<clsStudentBusinessLogic>AllStudentsData = Student.GetAllStudentsData();
	void GetStudentIdToUpdate(clsStudent*& Student)
	{
		bool IsID_AlreadyExists = true;
		string ID = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter the StudentID you want to update.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			getline(cin >> ws, ID);
			if (!clsUtil<bool>::IsChoiceCorrect(ID))
			{
				IsID_AlreadyExists = false;
				cout << clsUtil<string>::NumberOfTabs(5) << "The ID Number is not valid, Please try again.\n";
				system("pause > 0");
				continue;
			}
			IsID_AlreadyExists = clsStudentBusinessLogic::IsStudentID_AlreadyExists(stoi(ID), AllStudentsData);
			if (!IsID_AlreadyExists)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "The Student ID Doesn't Exists :-(, Please try again later.\n";
				system("pause > 0");
			}
		} while (!IsID_AlreadyExists);
		*Student = clsStudentBusinessLogic::FindStudent(stoi(ID), AllStudentsData);
	}
	void UpdatePassword(clsStudent*& Student)
	{
		string StudentPassword = "";
		string ConfirmPassword = "";
		bool IsPasswordAndConfirmPasswordsAreTheSame = true;
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to update the Student Password ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			do
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Student Password.\n";
				cout << clsUtil<string>::NumberOfTabs(5);
				getline(cin >> ws, StudentPassword);
				Student->SetPassword(StudentPassword);
				cout << clsUtil<string>::NumberOfTabs(5) << "Please Confirm Password.\n";
				cout << clsUtil<string>::NumberOfTabs(5);
				getline(cin >> ws, ConfirmPassword);
				IsPasswordAndConfirmPasswordsAreTheSame = (Student->GetPassword() == ConfirmPassword);
				if (!IsPasswordAndConfirmPasswordsAreTheSame)
				{
					cout << clsUtil<string>::NumberOfTabs(5) << "Passwords aren't the same, Please try again.\n";
					system("pause > 0");
				}
			} while (!IsPasswordAndConfirmPasswordsAreTheSame);
		}
	}
	void UpdateEmail(clsStudent*& Student)
	{
		bool IsEmailAlreadyExists = true;
		string StudentEmail = "";
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to update the Student Email ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			do
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Student Email.\n";
				cout << clsUtil<string>::NumberOfTabs(5);
				getline(cin >> ws, StudentEmail);
				Student->SetEmail(StudentEmail);
				IsEmailAlreadyExists = clsStudentBusinessLogic::IsStudentEmailAlreadyExists(Student->GetEmail(), AllStudentsData);
				if (IsEmailAlreadyExists)
				{
					cout << clsUtil<string>::NumberOfTabs(5) << "This Email Already Exists :-(, Please try another one.\n";
					system("pause > 0");
				}
			} while (IsEmailAlreadyExists);
		}
	}
	void UpdatePhoneNumber(clsStudent*& Student)
	{
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to update the Student PhoneNumber ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			string StudentPhoneNumber = "";
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Student PhoneNumber.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			getline(cin >> ws, StudentPhoneNumber);
			Student->SetPhoneNumber(StudentPhoneNumber);
		}
	}
	void UpdateAddress(clsStudent*& Student)
	{
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to update the Student Address ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			string StudentAddress = "";
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Student Address.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			getline(cin >> ws, StudentAddress);
			Student->SetAddress(StudentAddress);
		}
	}
	void UpdateGPA(clsStudent*& Student)
	{
		Student->SetGPA(clsStudentBusinessLogic::CalculateStudentGPA(Student->GetID()));
	}
	void UpdateNumberOfCoursesEnrolled(clsStudent*& Student)
	{
		Student->SetNumberOfCoursesEnrolled(clsStudentBusinessLogic::GetAllStudentCourses(Student->GetID()).size());
	}
	void UpdateIsGraduated(clsStudent*& Student)
	{
		Student->SetIsGraduated((Student->GetNumberOfCoursesEnrolled() < 15 || Student->GetGPA() < 2.0) ? 0 : 1);
	}
	void UpdateField(clsStudent*& Student)
	{
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Would you like to update the Student Field ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			string StudentField = "";
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Student Field.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			getline(cin >> ws, StudentField);
			Student->SetField(StudentField);
		}
	}
};


