#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ostream>
#include <fstream>
using namespace std;

class Person { //��ȭ��ȣ�ο� ����Ǵ� person class
private:
	//person ��ü�� attribute�� �ٸ� class���������� �Ұ����ϰ� �ϱ����� private�� ���� 
	string* name;
	string* number;
	string* group;
	bool favorite;
public:
	//������, �Ҹ���
	Person(const string&, const string&, const string&, bool newFavorite);
	Person(const Person&);
	~Person();

	//Person ��ü�� ����ϱ����� �����ε�
	friend ostream& operator<<(ostream&, const Person&);
	
	//���� ������� ���� ������ �����ε�
	friend ofstream& operator<<(ofstream&, const Person&);
	friend ifstream& operator >> (ifstream&, Person&);
	
	//���İ� ������ ���� ������ �����ε�
	friend bool operator<(const Person&, const Person&);
	Person& operator=(const Person&);
	bool operator==(const Person&) const;
	
	//Person attribute ����, ������ ���� getter,setter
	void setName(const string& name);
	void setGroup(const string& email);
	void setNumber(const string& number);
	void setFavorite(const bool newFavorite);
	string getName() const;
	string getGroup() const;
	string getNumber() const;
	bool getFavorite() const;
};
#endif
