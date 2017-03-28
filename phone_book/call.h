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
	//������, �Ҹ��� 
	Call(const string&, const string&, const string&);
	Call(const Call&);
	~Call();
	//Call class�� attribute 
	string* caller;
	string* receiver;
	string* time;
	//Call class�� method , ������ �����ε�
	friend bool operator<(const Call&, const Call&);
	friend ifstream& operator >> (ifstream&, Call&);
	friend ofstream& operator<<(ofstream&, const Call&);
};
//���� ��ȭ ����� �����ִ� method
void showCallList(const Call&, const People);

#endif
