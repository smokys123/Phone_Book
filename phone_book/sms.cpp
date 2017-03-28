#include <iostream>
#include <vector>
#include <algorithm>
#include "sms.h"
#include "message.h"

using namespace std;

// 파일에서 message의 정보를 읽어 받아오는 method
bool Sms::readTextFile(const string& fileName) {
	ifstream fin(fileName.c_str(), ios_base::in | ios_base::binary);
	if (fin.is_open()) {
		int size;
		string receiver;
		(fin >> size).get();
		Message msg("", "", "", "");
		for (int i = 0; i<size; i++) {
			fin >> msg;
			sms.push_back(msg);
		}
		return true;
	}
	else {
		return false;
	}
}

// message class의 data를 파일에 저장하는 method
bool Sms::saveTextFile(const string& fileName) {
	ofstream fout(fileName.c_str(), ios_base::out | ios_base::binary | ios_base::trunc);
	fout << sms.size() << "\n";
	for (auto it = sms.begin(); it != sms.end(); it++) {
		fout << *it;
	}
	return true;
}

// message를 sort하는 method 
void Sms::sortingMessage() {
	sort(sms.begin(), sms.end());
}

//추가된 message를 vector에 저장하는 method
void Sms::addMessage(const Message& msg) {
	sms.push_back(msg);
	//msgSorting();
}

//번호를 통한 특정 메세지 검색 method
vector<Message> Sms::findMessage(const string& num) {
	vector<Message>::iterator it;
	vector<Message> fResult;
	//입력하는 번호가 발신자,수신자로 되어있는 모든 message검색
	for (it = sms.begin(); it != sms.end(); it++) {
		if ((*it).getSender() == num || (*it).getReceiver() == num)
			fResult.push_back(*it);
	}
	return fResult;
}
