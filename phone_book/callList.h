#pragma once
#include "call.h"


class CallHistory {
public:
	//CallHistory의 attribute
	vector<Call> callhistory;
	
	//통화목록을 파일에서 읽고 쓰기위한 method
	bool readTextFile(const string&);
	bool saveTextFile(const string&);
};
