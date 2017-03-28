#include "message.h"
#include "person.h"
#include "people.h"
#include <iostream>

using namespace std;

//Message class 생성자 소멸자 method
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

//Message attribute 정보를 받아오기위한 getter
// message의 sender을 리턴하는 method
string Message::getSender() const {
	return *sender;
}

// message의 receiver을 리턴하는 merhod
string Message::getReceiver() const {
	return *receiver;
}

// message의 content를 리턴하는 method
string Message::getContent() const {
	return *content;
}

// message의 date를 리턴하는 method
string Message::getDate() const {
	return *date;
}

//메세지 목록 sort을 위한 연산자 오버로딩 
//message안의 date를 이용해 비교 method
bool operator<(const Message& firstMsg, const Message& secondMsg) {
	if (*firstMsg.date != *secondMsg.date)
		return *firstMsg.date < *secondMsg.date;
	return true;
}
// Message class간의 비교 method
bool Message::operator==(const Message& msg) const {
	bool comp = (*sender == *msg.sender) & (*receiver == *msg.receiver) & (*content == *msg.content) & (*date == *msg.date);
	return comp;
}

// 파일에서 data를 읽어와 Message class에 저장하는 연산자 오버로딩
ifstream& operator >> (ifstream& fin, Message& msg) {
	(fin >> *msg.sender).get();
	(fin >> *msg.receiver).get();
	(fin >> *msg.content).get();
	(fin >> *msg.date).get();
	return fin;
}

// 파일에 Message class의 내용을 저장하는 연산자 오버로딩
ofstream& operator<<(ofstream& fout, const Message& msg) {
	fout << *msg.sender << endl;
	fout << *msg.receiver << endl;
	fout << *msg.content << endl;
	fout << *msg.date << endl;
	return fout;
}

//메세지 목록을 출력하는 method
//만약 발신자 수신자번호가 전화번호부에 있을경우 이름정보도 같이 표시함
void showMessage(const Message& msg, const People book) {
	cout << "-------------메세지함----------------" << endl;
	cout << "발신자 : " << book.findNameFromNum(msg.getSender()) << " " << msg.getSender() << endl;
	cout << "수신자 : " << book.findNameFromNum(msg.getReceiver()) << " " << msg.getReceiver() << endl;
	cout << "내용 : " << msg.getContent() << endl;
	cout << "시간 : " << msg.getDate() << endl;
	cout << "-------------------------------------" << endl;
}
