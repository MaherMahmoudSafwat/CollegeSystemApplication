#pragma once
#include <iostream>
#include <string>
#include "clsUtil.h"
#include <cmath>

using namespace std;

template <typename T>

class clsDrawScreenHeader
{
public:
	static void DrawHeaderScreen(string Title, string Subtitle = "", int NumberOfTabs = 0)
	{
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		if (Subtitle == "")
		{
			cout << clsUtil<string>::NumberOfTabs(NumberOfTabs) << Title << endl;
		}
		else
		{
			int FinalLength = Title.length() - Subtitle.length();
			FinalLength = abs(FinalLength);
			if (Title.length() == Subtitle.length() || (Title.length() + 1 == Subtitle.length())
				|| Title.length() == Subtitle.length())
			{
				cout << clsUtil<string>::NumberOfTabs(NumberOfTabs) << Title << endl;
				cout << clsUtil<string>::NumberOfTabs(NumberOfTabs) << Subtitle << endl;
			}
			else if (Title.length() > Subtitle.length())
			{
				cout << clsUtil<string>::NumberOfTabs(NumberOfTabs) << Title << endl;
				cout << clsUtil<string>::NumberOfTabs(NumberOfTabs) << clsUtil<string>::
					NumberOfSpaces(FinalLength / 2) << Subtitle << endl;
			}
			else if (Title.length() < Subtitle.length())
			{
				cout << clsUtil<string>::NumberOfTabs(NumberOfTabs) << clsUtil<string>::
					NumberOfSpaces(FinalLength / 2) << Title << endl;
				cout << clsUtil<string>::NumberOfTabs(NumberOfTabs) << Subtitle << endl;
			}
		}
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
	}
};
