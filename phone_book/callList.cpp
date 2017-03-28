#include "callhistory.h"

//���Ͽ��� ��ȭ����� �о�� callhistory vector�� �����ϴ� method
bool CallHistory::readTextFile(const string& fileName) {
	// ���� �̸��� �޾ƿ� ���Ͽ��� call�� ������ �޾ƿ��� �Լ�
	ifstream fin(fileName.c_str(), ios_base::in | ios_base::binary);
	if (fin.is_open()) {
		int size;
		(fin >> size).get();
		Call chat("", "", "");
		for (int i = 0; i<size; i++) {
			fin >> chat;
			callhistory.push_back(chat);
		}
		return true;
	}
	else {
		return false;
	}
}

bool CallHistory::saveTextFile(const string& fileName) {
	// ���� �̸��� �޾ƿ� ���Ͽ� call�� �����ϴ� �Լ�
	ofstream fout(fileName.c_str(), ios_base::out | ios_base::binary | ios_base::trunc);
	fout << callhistory.size() << "\n";
	for (auto it = callhistory.begin(); it != callhistory.end(); it++) {
		fout << *it;
	}
	return true;
}
