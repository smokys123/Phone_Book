#pragma once
#ifndef PEOPLE_H
#define PEOPLE_H

#include <vector>
using namespace std;
#include "person.h"
#include <ostream>
#include <fstream>

//Person class의 datas를 관리하는 People class
class People {
public:
	//전화번호부의 person 객체들를 저장
	vector<Person> people;
	//전화번호부의 그룹들을 저장
	vector<string> groups;

	//파일 입출력을 위한 method
	bool readTextFile(const string&);
	bool readFileGroups(const string&);
	bool saveTextFile(const string&) const;
	bool saveFileGroups(const string&) const;

	//Person 객체들을 관리하기위한 method
	void sorting();
	void add(const Person&);
	void remove(const Person&);
	void remove(const string&);
	void show();
	int size() const;
	Person get(int) const;
	
	//전화번호부에서 검색을 위한 method
	int findPerson(const Person&, const int START = 0) const;
	int findPerson(const string&, const int START = 0) const;
	string findNameFromNum(const string&) const;
	Person findNameFromName(const string& fPhone);
	Person findPersonFromNum(const string& fName);
	Person findFavorite();
};

#endif
