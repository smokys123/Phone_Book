#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ostream>
#include <fstream>
using namespace std;

class Person { //전화번호부에 저장되는 person class
private:
	//person 객체의 attribute를 다른 class에서접근이 불가능하게 하기위해 private로 선언 
	string* name;
	string* number;
	string* group;
	bool favorite;
public:
	//생성자, 소멸자
	Person(const string&, const string&, const string&, bool newFavorite);
	Person(const Person&);
	~Person();

	//Person 객체를 출력하기위한 오버로딩
	friend ostream& operator<<(ostream&, const Person&);
	
	//파일 입출력을 위한 연산자 오버로딩
	friend ofstream& operator<<(ofstream&, const Person&);
	friend ifstream& operator >> (ifstream&, Person&);
	
	//정렬과 대입을 위한 연산자 오버로딩
	friend bool operator<(const Person&, const Person&);
	Person& operator=(const Person&);
	bool operator==(const Person&) const;
	
	//Person attribute 접근, 수정을 위한 getter,setter
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
