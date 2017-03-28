#include "callhistory.h"

//파일에서 통화목록을 읽어와 callhistory vector에 저장하는 method
bool CallHistory::readTextFile(const string& fileName) {
	// 파일 이름을 받아와 파일에서 call의 정보를 받아오는 함수
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
	// 파일 이름을 받아와 파일에 call을 저장하는 함수
	ofstream fout(fileName.c_str(), ios_base::out | ios_base::binary | ios_base::trunc);
	fout << callhistory.size() << "\n";
	for (auto it = callhistory.begin(); it != callhistory.end(); it++) {
		fout << *it;
	}
	return true;
}
