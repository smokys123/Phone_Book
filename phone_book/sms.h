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

//message들의 datas를 관리하는 Sms class
class Sms {
public:
	//모든 Message들을 저장하는 vector
	vector<Message> sms;
	
	//Message정보들을 파일에서 읽고 쓰기위한 method
	bool readTextFile(const string&);
	bool saveTextFile(const string&);

	//Message들을 관리하기위한 method
	void sortingMessage();
	void addMessage(const Message&);
	vector<Message> findMessage(const string&);
};

#endif
