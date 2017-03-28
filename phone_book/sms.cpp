#include <iostream>
#include <vector>
#include <algorithm>
#include "sms.h"
#include "message.h"

using namespace std;

// ���Ͽ��� message�� ������ �о� �޾ƿ��� method
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

// message class�� data�� ���Ͽ� �����ϴ� method
bool Sms::saveTextFile(const string& fileName) {
	ofstream fout(fileName.c_str(), ios_base::out | ios_base::binary | ios_base::trunc);
	fout << sms.size() << "\n";
	for (auto it = sms.begin(); it != sms.end(); it++) {
		fout << *it;
	}
	return true;
}

// message�� sort�ϴ� method 
void Sms::sortingMessage() {
	sort(sms.begin(), sms.end());
}

//�߰��� message�� vector�� �����ϴ� method
void Sms::addMessage(const Message& msg) {
	sms.push_back(msg);
	//msgSorting();
}

//��ȣ�� ���� Ư�� �޼��� �˻� method
vector<Message> Sms::findMessage(const string& num) {
	vector<Message>::iterator it;
	vector<Message> fResult;
	//�Է��ϴ� ��ȣ�� �߽���,�����ڷ� �Ǿ��ִ� ��� message�˻�
	for (it = sms.begin(); it != sms.end(); it++) {
		if ((*it).getSender() == num || (*it).getReceiver() == num)
			fResult.push_back(*it);
	}
	return fResult;
}
