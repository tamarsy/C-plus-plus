#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstring>
using namespace std;

class Family {
public:
	int codeOfFamily = 0;
	char nameOfFamily[20] = "";
	int numOfSouls = 0;
	int phone = 0;
	bool course[6] = {};

	Family(int codeOfFamily = 0,const char* nameOfFamily = {},
		int numOfSouls = 0, int phone = 0, bool course[6] = {}) :
		codeOfFamily(codeOfFamily), numOfSouls(numOfSouls), phone(phone)
	{
		if (nameOfFamily)
			strcpy_s((this->nameOfFamily), nameOfFamily);
		if (course)
			for (int i = 0; i < 6; ++i) {
				this->course[i] = course[i];
			}
	}
};