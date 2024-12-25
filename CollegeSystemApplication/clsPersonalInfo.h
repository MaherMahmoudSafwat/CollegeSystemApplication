#pragma once
#include <iostream>

using namespace std;

template <class T>

class clsPersonalInfo
{
public:
	virtual void AddFirstName(T*& User) = 0;
	virtual void AddLastName(T*& User) = 0;
	virtual void AddID(T*& User) = 0;
	virtual void AddPassword(T*& User) = 0;
	virtual void AddEmail(T*& User) = 0;
	virtual void AddPhoneNumber(T*& User) = 0;
	virtual void AddAddress(T*& User) = 0;
};

