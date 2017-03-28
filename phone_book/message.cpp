#include "message.h"
#include "person.h"
#include "people.h"
#include <iostream>

using namespace std;

//Message class ������ �Ҹ��� method
Message::Message(const string& newsender, const string& newreceiver, const string& newcontent, const string& newdate) {
	sender = new string(newsender);
	receiver = new string(newreceiver);
	content = new string(newcontent);
	date = new string(newdate);
}

Message::Message(const Message& newmsg) {
	sender = new string(*newmsg.sender);
	receiver = new string(*newmsg.receiver);
	content = new string(*newmsg.content);
	date = new string(*newmsg.date);
}

Message::~Message() {
	delete sender;
	delete receiver;
	delete content;
	delete date;
}

//Message attribute ������ �޾ƿ������� getter
// message�� sender�� �����ϴ� method
string Message::getSender() const {
	return *sender;
}

// message�� receiver�� �����ϴ� merhod
string Message::getReceiver() const {
	return *receiver;
}

// message�� content�� �����ϴ� method
string Message::getContent() const {
	return *content;
}

// message�� date�� �����ϴ� method
string Message::getDate() const {
	return *date;
}

//�޼��� ��� sort�� ���� ������ �����ε� 
//message���� date�� �̿��� �� method
bool operator<(const Message& firstMsg, const Message& secondMsg) {
	if (*firstMsg.date != *secondMsg.date)
		return *firstMsg.date < *secondMsg.date;
	return true;
}
// Message class���� �� method
bool Message::operator==(const Message& msg) const {
	bool comp = (*sender == *msg.sender) & (*receiver == *msg.receiver) & (*content == *msg.content) & (*date == *msg.date);
	return comp;
}

// ���Ͽ��� data�� �о�� Message class�� �����ϴ� ������ �����ε�
ifstream& operator >> (ifstream& fin, Message& msg) {
	(fin >> *msg.sender).get();
	(fin >> *msg.receiver).get();
	(fin >> *msg.content).get();
	(fin >> *msg.date).get();
	return fin;
}

// ���Ͽ� Message class�� ������ �����ϴ� ������ �����ε�
ofstream& operator<<(ofstream& fout, const Message& msg) {
	fout << *msg.sender << endl;
	fout << *msg.receiver << endl;
	fout << *msg.content << endl;
	fout << *msg.date << endl;
	return fout;
}

//�޼��� ����� ����ϴ� method
//���� �߽��� �����ڹ�ȣ�� ��ȭ��ȣ�ο� ������� �̸������� ���� ǥ����
void showMessage(const Message& msg, const People book) {
	cout << "-------------�޼�����----------------" << endl;
	cout << "�߽��� : " << book.findNameFromNum(msg.getSender()) << " " << msg.getSender() << endl;
	cout << "������ : " << book.findNameFromNum(msg.getReceiver()) << " " << msg.getReceiver() << endl;
	cout << "���� : " << msg.getContent() << endl;
	cout << "�ð� : " << msg.getDate() << endl;
	cout << "-------------------------------------" << endl;
}
