#pragma once
#ifndef PEOPLE_H
#define PEOPLE_H

#include <vector>
using namespace std;
#include "person.h"
#include <ostream>
#include <fstream>

//Person class�� datas�� �����ϴ� People class
class People {
public:
	//��ȭ��ȣ���� person ��ü�鸦 ����
	vector<Person> people;
	//��ȭ��ȣ���� �׷���� ����
	vector<string> groups;

	//���� ������� ���� method
	bool readTextFile(const string&);
	bool readFileGroups(const string&);
	bool saveTextFile(const string&) const;
	bool saveFileGroups(const string&) const;

	//Person ��ü���� �����ϱ����� method
	void sorting();
	void add(const Person&);
	void remove(const Person&);
	void remove(const string&);
	void show();
	int size() const;
	Person get(int) const;
	
	//��ȭ��ȣ�ο��� �˻��� ���� method
	int findPerson(const Person&, const int START = 0) const;
	int findPerson(const string&, const int START = 0) const;
	string findNameFromNum(const string&) const;
	Person findNameFromName(const string& fPhone);
	Person findPersonFromNum(const string& fName);
	Person findFavorite();
};

#endif
