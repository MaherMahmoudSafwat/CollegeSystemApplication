#pragma once
#include <iostream>

using namespace std;

template <typename T>

class clsUpdatePersonalInfo
{
public:
	virtual void UpdatePassword(T*& User) = 0;
	virtual void UpdateEmail(T*& User) = 0;
	virtual void UpdatePhoneNumber(T*& User) = 0;
	virtual void UpdateAddress(T*& User) = 0;
};

