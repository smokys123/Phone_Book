#include "call.h"

#include <iostream>

using namespace std;

//������ �Ҹ��� method
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

//sorting�� ���� ��ȭ �ð� ������ �����ε�
bool operator<(const Call& first_Call, const Call& second_Call) {
	return *first_Call.time < *second_Call.time;
}

//call�� attributes�� ���Ͽ��� �о���� ���� ������ �����ε�
ifstream& operator >> (ifstream& fin, Call& call) {
	(fin >> *call.caller).get();
	(fin >> *call.receiver).get();
	(fin >> *call.time).get();
	return fin;
}

//call�� attributes�� ���Ͽ� �����ϱ� ���� ������ �����ε�
ofstream& operator<<(ofstream& fout, const Call& call) {
	fout << *call.caller << endl;
	fout << *call.receiver << endl;
	fout << *call.time << endl;
	return fout;
}

//call�� ��� attributes�� �����ִ� method
void showCallList(const Call& call, const People Per) {
	cout << "�߽��� : " << Per.findNameFromNum(*call.caller) << " " << *call.caller << endl;
	cout << "������ : " << Per.findNameFromNum(*call.receiver) << " " << *call.receiver << endl;
	cout << "�ð�   : " << *call.time << endl;
}
