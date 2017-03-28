#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ostream>
#include <fstream>
#include <vector>
#include "people.h"
#include "person.h"

using namespace std;

class Message {  //Message Class
private:
    //한번보낸 Message의 attribute에 접근이 불가능 하게 private로 정의
	string* sender;
	string* receiver;
	string* content;
	string* date;
public:
	//생성자, 소멸자
	Message(const string&, const string&, const string&, const string&);
	Message(const Message&);
	~Message();
    //private attribute에 접근하기위한 getter
	string getSender() const;
	string getReceiver() const;
	string getContent() const;
	string getDate() const;
	//message 객체간 비교를 위한 연산자 오버로딩
	bool operator==(const Message&) const;
	friend bool operator<(const Message&, const Message&);
	//message정보를 파일 입출력하기 위한 연산자 오버로딩
	friend ifstream& operator>>(ifstream&, Message&);
	friend ofstream& operator<<(ofstream&, const Message&);

};
//메세지 주고받은 목록 전체를 보여주는 method
void showMessage(const Message&, const People);

#endif
