#pragma once
#ifndef SMS_H
#define SMS_H

#include <string>
#include <ostream>
#include <fstream>
#include <vector>
#include "message.h"
#include "person.h"
#include "people.h"
#include <algorithm>
using namespace std;

//message���� datas�� �����ϴ� Sms class
class Sms {
public:
	//��� Message���� �����ϴ� vector
	vector<Message> sms;
	
	//Message�������� ���Ͽ��� �а� �������� method
	bool readTextFile(const string&);
	bool saveTextFile(const string&);

	//Message���� �����ϱ����� method
	void sortingMessage();
	void addMessage(const Message&);
	vector<Message> findMessage(const string&);
};

#endif
