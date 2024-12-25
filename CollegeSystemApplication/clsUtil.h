#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

template <class T>

class clsUtil
{
public:
	static T NumberOfTabs(int TabsNumber)
	{
		string Tabs = "";
		for (int i = 0; i < TabsNumber; i++)
		{
			Tabs += "\t";
		}
		return Tabs;
	}
	static T NumberOfSpaces(int SpacesNumber)
	{
		string Spaces = "";
		for (int i = 0; i < SpacesNumber; i++)
		{
			Spaces += " ";
		}
		return Spaces;
	}
	static bool IsChoiceInBetween(short Choice, short Start, short End)
	{
		return (Choice >= Start && Choice <= End) ? true : false;
	}
	static bool IsChoiceCorrect(string Choice)
	{
		for (int i = 0; i < Choice.length(); i++)
		{
			if (int(Choice[i]) < 48 || int(Choice[i]) > 57)
				return false;
		}
		return true;
	}
	static short IsChoiceValid(string Choice, short Start, short End)
	{
		if (IsChoiceCorrect(Choice))
		{
			if (IsChoiceInBetween(short(stoi(Choice)), Start, End))
				return 1;
			return -1;
		}
		return 0;
	}
	static int GetRandomNumber(int Start, int End)
	{
		srand((unsigned)time(NULL));
		int RandomNumber = rand() % (End - Start + 1) + Start;
		return RandomNumber;
	}
	static string EncryptData(string Password)
	{
		string EncryptedPassword = "";
		for (int i = 0; i < Password.length(); i++)
		{
			EncryptedPassword += (char)(((int)Password[i]) + 3);
		}
		return EncryptedPassword;
	}
	static string DecryptData(string Password)
	{
		string DecryptedPassword = "";
		for (int i = 0; i < Password.length(); i++)
		{
			DecryptedPassword += (char)(((int)Password[i]) - 3);
		}
		return DecryptedPassword;
	}
	static vector<string>Spilt(string Line, string Separator = "#//#")
	{
		vector <string> Spliter;
		string Word = "";
		short Position = 0;
		while ((Position = Line.find(Separator)) && (Position != Line.npos))
		{
			Word = Line.substr(0, Position);
			if (Word != "")
			{
				Spliter.push_back(Word);
			}
			Line.erase(0, Position + Separator.length());
		}
		if (Line != "")
		{
			Spliter.push_back(Line);
		}
		return Spliter;
	}

};

