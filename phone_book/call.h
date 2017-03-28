#pragma once
#ifndef CALL_H
#define CALL_H

#include <string>
#include <vector>
#include <ostream>
#include <fstream>
#include "people.h"

using namespace std;

using namespace std;
 
class Call { 
public:
	//생성자, 소멸자 
	Call(const string&, const string&, const string&);
	Call(const Call&);
	~Call();
	//Call class의 attribute 
	string* caller;
	string* receiver;
	string* time;
	//Call class의 method , 연산자 오버로딩
	friend bool operator<(const Call&, const Call&);
	friend ifstream& operator >> (ifstream&, Call&);
	friend ofstream& operator<<(ofstream&, const Call&);
};
//현재 통화 목록을 보여주는 method
void showCallList(const Call&, const People);

#endif
