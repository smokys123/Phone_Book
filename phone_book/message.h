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
    //�ѹ����� Message�� attribute�� ������ �Ұ��� �ϰ� private�� ����
	string* sender;
	string* receiver;
	string* content;
	string* date;
public:
	//������, �Ҹ���
	Message(const string&, const string&, const string&, const string&);
	Message(const Message&);
	~Message();
    //private attribute�� �����ϱ����� getter
	string getSender() const;
	string getReceiver() const;
	string getContent() const;
	string getDate() const;
	//message ��ü�� �񱳸� ���� ������ �����ε�
	bool operator==(const Message&) const;
	friend bool operator<(const Message&, const Message&);
	//message������ ���� ������ϱ� ���� ������ �����ε�
	friend ifstream& operator>>(ifstream&, Message&);
	friend ofstream& operator<<(ofstream&, const Message&);

};
//�޼��� �ְ���� ��� ��ü�� �����ִ� method
void showMessage(const Message&, const People);

#endif
