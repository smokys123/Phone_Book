#pragma once
#include "call.h"


class CallHistory {
public:
	//CallHistory�� attribute
	vector<Call> callhistory;
	
	//��ȭ����� ���Ͽ��� �а� �������� method
	bool readTextFile(const string&);
	bool saveTextFile(const string&);
};
