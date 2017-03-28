#include "call.h"

#include <iostream>

using namespace std;

//생성자 소멸자 method
Call::Call(const string& newCaller, const string& newReceiver, const string& newTime) {
	caller = new string(newCaller);
	receiver = new string(newReceiver);
	time = new string(newTime);
}

Call::Call(const Call& newCall) {
	caller = new string(*newCall.caller);
	receiver = new string(*newCall.receiver);
	time = new string(*newCall.time);
}

Call::~Call() {
	delete caller;
	delete receiver;
	delete time;
}

//sorting을 위한 통화 시간 연산자 오버로딩
bool operator<(const Call& first_Call, const Call& second_Call) {
	return *first_Call.time < *second_Call.time;
}

//call의 attributes를 파일에서 읽어오기 위한 연산자 오버로딩
ifstream& operator >> (ifstream& fin, Call& call) {
	(fin >> *call.caller).get();
	(fin >> *call.receiver).get();
	(fin >> *call.time).get();
	return fin;
}

//call의 attributes를 파일에 저장하기 위한 연산자 오버로딩
ofstream& operator<<(ofstream& fout, const Call& call) {
	fout << *call.caller << endl;
	fout << *call.receiver << endl;
	fout << *call.time << endl;
	return fout;
}

//call의 모든 attributes를 보여주는 method
void showCallList(const Call& call, const People Per) {
	cout << "발신인 : " << Per.findNameFromNum(*call.caller) << " " << *call.caller << endl;
	cout << "수신인 : " << Per.findNameFromNum(*call.receiver) << " " << *call.receiver << endl;
	cout << "시간   : " << *call.time << endl;
}
