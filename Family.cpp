#include "Family.h"
#include <iostream>
#include <fstream>
#include <Queue>
using namespace std;

int const sizeOfFamily = sizeof(Family);

queue<Family> q;

void setFile(fstream& f) {
	for (int i = 0; i < 100; ++i){
		Family family;
		f.write(((char*)&family), sizeOfFamily);
	}
}

void add(fstream& f) {
	Family family;
	int temp = 0;
	cin >> family.codeOfFamily;
	gets_s(family.nameOfFamily);
	cin >> family.numOfSouls >> family.phone;
	f.seekg(double(family.codeOfFamily) * sizeOfFamily);
	f.read((char*)temp,sizeof(int));
	if (family.codeOfFamily > 100 || family.codeOfFamily < 1) {
		throw "ERROR: Invalid family number";}
	if (temp)
	{ throw "ERROR: Family is already in the file"; }
	f.seekp(double(family.codeOfFamily) * sizeOfFamily);
	f.write((char*)&family, sizeOfFamily);
}

void del(fstream& f, int num) {
	if (num > 100 || num < 1) { throw "ERROR: Invalid family number"; }
	f.seekp(num * sizeOfFamily);
	f.write(0, sizeof(int));
}

bool checkIfInFile(fstream& f, int num) {
	int codeOfFamily;
	f.seekg(num * sizeOfFamily);
	f.read((char*)&codeOfFamily, sizeof(int));
	if (codeOfFamily) {
		return true;
	}
	else {
		return false;
	}
}

void update(fstream& f, int num) {
	if (num > 100 || num < 1) {
		throw "ERROR: Invalid family number";
	}
	
	if (!checkIfInFile) {
		throw"ERROR: Family is not in the file";
	}
	Family family;
	f.seekg(num * sizeOfFamily);
	f.read((char*)&family, sizeOfFamily);
	int counterForCourse[6];
	for (int i = 0; i < sizeof(family.course); ++i) {
		cin >> family.course[i];
	}
	f.seekg(0, ios::beg);
	for (int i = 0; i < 100; ++i) {
		Family temp;
		f.read((char*)&temp, sizeOfFamily);
		if (temp.codeOfFamily) {
			for (int i = 0; i < sizeof(temp.course); ++i) {
				counterForCourse[i] += temp.course[i];
			}
		}
	}
	bool tempForWaitingQueue[6] = {false};
	for (int i = 0; i < sizeof(family.course); ++i) {
		if (counterForCourse[i] >= 10) {
			family.course[i] == true;
		}
		else{
			tempForWaitingQueue[i] = family.course[i];
			family.course[i] = false;
		}
	}

	q.push(family);
	for (int i = 0; i < sizeof(family.course); ++i) {
		family.course[i] = tempForWaitingQueue[i]; }
	f.seekp(num * sizeOfFamily);
	f.write((char*)&family, sizeOfFamily);
}

void waiting(fstream& f, queue<Family> q) {
	Family family = q.front();
	int counter[sizeof(family.course)] = {};
	for (int i = 0; i < 100; ++i) {
		Family familyTemp;
		f.read((char*)&familyTemp, sizeOfFamily);
		for (int i = 0; i < sizeof(familyTemp.course); ++i) {
			counter[i] += int(familyTemp.course[i]);
		}
	}
	for (int i = 0; i < sizeof(family.course); ++i) {
		bool isWaiting = false; char YorN;
		if (family.course[i]){
			if (counter[i] < 10) {
				puts(family.nameOfFamily); cout << family.phone;
				YorN = getchar();
				if (YorN == 'Y') {
					++counter[i]; Family tempForCouse;
					f.seekp(double(family.codeOfFamily) * sizeOfFamily);
					f.seekg(double(family.codeOfFamily) * sizeOfFamily);
					f.read((char*)&tempForCouse, sizeOfFamily);
					tempForCouse.course[i] = true;
					f.write((char*)&tempForCouse, sizeOfFamily);
				}
				family.course[i] = false;
			}
			else isWaiting = true;
		}
		if (!isWaiting) {
			q.pop();
		}
	}
	
}

bool rishum(fstream& f, int num, int numOfCourse) {
	if (num > 100 || num < 1) { throw "ERROR: Invalid family number"; }
	if (!checkIfInFile) { throw"ERROR: Family is not in the file"; }
	if (numOfCourse > 6 || numOfCourse < 1) { "ERROR: Invalid class number"; }
	bool course = false;
	f.seekp(double((num + 1) * sizeOfFamily) - sizeof(int));
	f.read((char*)course, sizeof(bool));
	return course;
}

void print(fstream& f, int num) {
	if (num > 100 || num < 1) {
		throw "ERROR: Invalid family number";
	}

	if (!checkIfInFile) {
		throw"ERROR: Family is not in the file";
	}
	Family family;
	f.seekg(num * sizeOfFamily);
	f.read((char*)&family, sizeOfFamily);
	puts(family.nameOfFamily);
	cout << "\t" << family.numOfSouls
		<< "\t" << family.phone;
	for (int i = 0; i < sizeof(family.course); ++i) {
		cout << '\t' << family.course[i]? 'Y':'N';
	}
}

void inClass(fstream& f, int numOfCourse) {
	if (numOfCourse > 6 || numOfCourse < 1) { "ERROR: Invalid class number"; }
	f.seekg(0, ios::beg);
	for (int i = 0; i < 100; ++i) {
		Family familyTemp;
		f.read((char*)&familyTemp, sizeOfFamily);
		if (familyTemp.course[numOfCourse]) {
			puts(familyTemp.nameOfFamily);
		}
	}
}