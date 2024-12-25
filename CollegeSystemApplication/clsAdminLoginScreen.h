#pragma once
#include "clsDrawScreen.h"
#include "clsAdminMainMenuScreen.h"
#include "clsLoginManagement.h"
#include "clsLogin.h"

using namespace std;

string FileName = "AdminPassword.txt";

class clsAdminLoginScreen :protected clsDrawScreenHeader <void>, public clsLogin
{
public:
	void Login()
	{
		string Password = "";
		bool IsPasswordValid = true;
		do
		{
			system("cls");
			DrawHeaderScreen("Admin Login Screen", "", 6);
			cout << "Please enter your Admin Password.\n";
			getline(cin >> ws, Password);
			IsPasswordValid = !clsLoginManagement<bool>::ManagePasswords(Password);
			if (IsPasswordValid)
			{
				cout << "Invalid Password, Please try Again :-( .\n";
				system("pause > 0");
			}
		} while (IsPasswordValid);
		clsAdminMainMenuScreen::ShowAdminMainMenuScreen();
	}
};

