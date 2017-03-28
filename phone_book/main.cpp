
#include "people.h"
#include "sms.h"
#include "message.h"
#include "call.h"
#include "callList.h"
#include <iostream>
#include <vector>

using namespace std;

//전화번호부 API
void main() {
    //지정된 파일들을 읽어옴
	People PhoneBook;
	Sms mms;
	CallHistory his;
	PhoneBook.readTextFile("phone_book.txt");
	PhoneBook.readFileGroups("group_box.txt");
	mms.readTextFile("message_box.txt");
	his.readTextFile("call_history.txt");

	while (true) {
		int menu;
		cout << "----------------------Menu----------------------" << endl;
		cout << "1. 전화번호부  2.  메세지함  3. 통화기록 4. 종료" << endl;
		cout << "> ";
		cin >> menu;
		//전화번호기능에 대한 접근
		if (menu == 1) {
			cout << "전화번호부 - 메뉴를 입력하세요" << endl;
			cout << "1. 전화 번호 목록 | 2. 전화번호 검색 | 3. 전화번호 추가/제거" << endl;
			cout << "4. 즐겨찾기 추가 / 제거 | 5.그룹 추가 / 제거" << endl;
			cout << "> ";
			int menu_1;
			cin >> menu_1;
			if (menu_1 == 1) {  //전화번호부 목록 show
				PhoneBook.show();
			}
			else if (menu_1 == 2) { //전화번호 검색
				cout << "검색 방법을 선택하세요" << endl;
				cout << "1. 전화번호 | 2. 이름 | 3. 그룹" << endl;
				cout << "> ";
				int select;
				cin >> select;
				if (select == 1) {  //번호를 통한 검색
					cout << "전화번호를 입력하세요." << endl;
					cout << "> ";
					string number;
					cin >> number;
					cout << "-----------------------------" << endl;
					if (PhoneBook.findPersonFromNum(number).getName() == "None") {
						cout << "해당번호가 없습니다." << endl;
						cout << "-----------------------------" << endl;
					}
					else {
						cout << PhoneBook.findPersonFromNum(number);
						cout << "-----------------------------" << endl;
					}
				}
				else if (select == 2) {  //이름을 통한 검색
					cout << "이름을 입력하세요." << endl;
					cout << "> ";
					string name;
					cin >> name;
					cout << "-----------------------------" << endl;
					if (PhoneBook.findNameFromName(name).getName() == "None") {
						cout << "해당이름이 없습니다." << endl;
						cout << "-----------------------------" << endl;
					}
					else {
						cout << PhoneBook.findNameFromName(name);
						cout << "-----------------------------" << endl;
					}
				}
				else if (select == 3) {  //그룹을 통한 검색
					for (int i = 0; i < PhoneBook.groups.size(); i++)
						cout << i + 1 << "." << PhoneBook.groups[i] << " ";
					cout << endl;
					cout << "그룹 이름을 입력하세요." << endl;
					cout << "> ";
					string group_name;
					cin >> group_name;
					cout << "-----------------------------" << endl;
					int j = 0;
					int check = 0;
					for (auto it = PhoneBook.people.begin(); it != PhoneBook.people.end(); it++, j++)
						if (PhoneBook.people.at(j).getGroup() == group_name) {
							cout << *it << endl;
							check++;
						}
					if (check == 0) {
						cout << "해당하는 그룹이 없습니다." << endl;
					}
					cout << "-----------------------------" << endl;
				}
			}
			else if (menu_1 == 3) {  //전화번호 추가 삭제
				int num;
				cout << "1.추가 2. 제거" << endl;
				cout << "> ";
				cin >> num;
				if (num == 1) {  //전화번호 추가 관련 기능
					cout << "전화번호부 입력 수단을 선택하세요" << endl;
					cout << "1. 직접 2. 파일" << endl;
					cout << "> ";
					int select;
					cin >> select;
					if (select == 1) {  //직접입력을 통한 전화번호 추가
						cout << "-----------------------------" << endl;
						int check = 0;
						string name, group, number;
						cout << "이름 : ";
						cin >> name;
						cout << "번호 : ";
						cin >> number;
						cout << "현재 그룹 목록 " << endl;
						for (int i = 0; i < PhoneBook.groups.size(); i++)
							cout << i + 1 << "." << PhoneBook.groups[i] << " ";
						cout << endl;
						cout << "그룹 : ";
						cin >> group;
						for (int order = 0; order < PhoneBook.groups.size(); order++) {
							if (PhoneBook.groups.at(order) == group) {
								check = 1;
								Person newPerson(name, number, group, false);
								PhoneBook.add(newPerson);
							}
						}
						cout << "-----------------------------" << endl;
						//그룹이 존재하지 않을경우를 위한 예외처리
						if (check == 0) {
							cout << "해당하는 그룹은 존재하지 않습니다. " << endl;
							cout << "그룹추가 메뉴에서 추가해주세요." << endl;
							cout << "-----------------------------" << endl;
						}
					}
					else if (select == 2) { //파일을 통한 전화번호 추가
						string fileName;
						cout << "파일 이름을 입력하세요. : ";
						cin >> fileName;
						PhoneBook.readTextFile(fileName);
					}
				}
				if (num == 2) {  //전화번호부 제거 기능
					string name;
					cout << "제거할 이름 입력하세요. : ";
					cin >> name;
					cout << "-----------------------------" << endl;
					if (PhoneBook.findNameFromName(name).getName() == "None") {
						cout << "해당하는 이름이 없습니다." << endl;
						cout << "-----------------------------" << endl;
					}
					else {
						PhoneBook.remove(PhoneBook.findNameFromName(name));
						cout << "해당 이름을 제거했습니다." << endl;
						cout << "-----------------------------" << endl;
					}
				}
			}
			else if (menu_1 == 4) {  //즐겨찾기 추가 제거 기능
				int select;
				cout << "즐겨찾기" << endl;
				cout << "1. 추가 2. 제거" << endl;
				cout << "> ";
				cin >> select;
				while (1) {
					cout << "-----------------------------" << endl;
					if (select == 1) {  //즐겨찾기 추가
						cout << "이름을 입력하세요" << endl;
						cout << "> ";
						string name_1, name_2, number, group;
						bool favorite;
						cin >> name_1;
						//해당 이름이 없을 경우를 위한 예외처리
						if (PhoneBook.findNameFromName(name_1).getName() == "None") {
							cout << "해당하는 이름이 전화번호 목록에 없습니다.";
							break;
						}
						name_2 = PhoneBook.findNameFromName(name_1).getName();
						number = PhoneBook.findNameFromName(name_1).getNumber();
						group = PhoneBook.findNameFromName(name_1).getGroup();

						PhoneBook.remove(PhoneBook.findNameFromName(name_1));
						Person newPerson(name_2, group, number, true);
						PhoneBook.add(newPerson);
						cout << "즐겨찾기 목록에 추가했습니다." << endl;
						break;
					}
					else if (select == 2) { //즐겨찾기 제거
						cout << "이름을 입력하세요" << endl;
						cout << "> ";
						string name_1, name_2, number, group;
						bool favorite;
						cin >> name_1;
						//해당이름이 없을 경우를 위한 예외처리
						if (PhoneBook.findNameFromName(name_1).getName() == "None") {
							cout << "해당하는 이름이 전화번호 목록에 없습니다." << endl;
							break;
						}
						name_2 = PhoneBook.findNameFromName(name_1).getName();
						number = PhoneBook.findNameFromName(name_1).getNumber();
						group = PhoneBook.findNameFromName(name_1).getGroup();

						PhoneBook.remove(PhoneBook.findNameFromName(name_1));
						Person newPerson(name_2, group, number, false);
						PhoneBook.add(newPerson);
						cout << "즐겨찾기 목록에서 제거했습니다." << endl;
						break;
					}
				}
				cout << "-----------------------------" << endl;
			}
			else if (menu_1 == 5) { //그룹 추가 제거
				int select;
				cout << "-----------------------------" << endl;
				cout << "현재 그룹 목록 " << endl;
				for (int i = 0; i < PhoneBook.groups.size(); i++)
					cout << i + 1 << "." << PhoneBook.groups[i] << " ";
				cout << endl;
				cout << "1. 추가 2. 제거" << endl;
				cout << "> ";
				cin >> select;
				cout << "-----------------------------" << endl;
				if (select == 1) { //그룹 추가 기능
					string name;
					int check = 0;
					cout << "추가할 그룹 이름을 입력하세요" << endl;
					cout << "> ";
					cin >> name;
					//그룹이 이미 존재 할경우를 위한 예외처리
					for (int i = 0; i < PhoneBook.groups.size(); i++) {
						if (PhoneBook.groups[i] == name) {
							cout << "해당하는 그룹이 이미 존재합니다." << endl;
							check++;
						}
					}
					if (check == 0) {
						cout << "그룹을 추가했습니다." << endl;
						PhoneBook.groups.push_back(name);
					}
				}
				else if (select == 2) { //그룹 삭제 기능
					string name;
					int check = 0;
					cout << "삭제할 그룹 이름을 입력하세요" << endl;
					cout << "> ";
					cin >> name;
					vector<string>::iterator it = PhoneBook.groups.begin();
					for (int i = 0; i < (signed)PhoneBook.groups.size(); i++) {
						if (PhoneBook.groups[i] == name) {
							PhoneBook.groups.erase(it + i);
							cout << "그룹을 삭제했습니다." << endl;
							check++;
						}
					}
					//해당 그룹이 존재하지 않을 경우를 위한 예외처리
					if (check == 0) {
						cout << "해당하는 그룹이 존재하지 않습니다." << endl;
					}
				}
				cout << "-----------------------------" << endl;
			}
		}
		//메세지함 기능
		else if (menu == 2) {  
			cout << "메세지함 - 원하는 메뉴를 입력하세요" << endl;
			cout << "1. 메세지 출력 | 2. 메세지 입력 | 3. 메세지 검색 | 4. 메세지 삭제" << endl;
			cout << "> ";
			int menu_2;
			cin >> menu_2;
			if (menu_2 == 1) {  //메시지 출력
				for (int i = 0; i<mms.sms.size(); i++) {
					showMessage(mms.sms[i], PhoneBook);
				}
			}
			else if (menu_2 == 2) {  //메세지 입력
				cout << "-----------------------------" << endl;
				string sender, receiver, content, date;
				cout << "보내는 사람 : ";
				cin >> sender;
				cout << "받는 사람 : ";
				cin >> receiver;
				cout << "내용 : ";
				cin >> content;
				cout << "시간 : ";
				cin >> date;
				Message msg(sender, receiver, content, date);
				mms.addMessage(msg);
				cout << "-----------------------------" << endl;
			}
			else if (menu_2 == 3) { //메시지 검색
				string index;
				cout << "-----------------------------" << endl;
				cout << "검색할 대상을 번호로 입력하세요" << endl;
				cout << "> ";
				cin >> index;
				int i;
				//해단 번호가 수신자, 발신자 상관없이  전부 출력
				for (i = 0; i < mms.findMessage((PhoneBook.findPersonFromNum(index)).getNumber()).size(); i++) {
					showMessage(mms.findMessage((PhoneBook.findPersonFromNum(index)).getNumber())[i], PhoneBook);
				}
				if (i == 0) {
					cout << "해당 사람이 없습니다." << endl;
				}
				cout << "-----------------------------" << endl;
			}
		}
		//통화기록 출력
		else if (menu == 3) {  
			cout << "통화기록" << endl;
			for (int i = 0; i < his.callhistory.size(); i++) {
				cout << "-----------------------------" << endl;
				showCallList(his.callhistory[i], PhoneBook);
				cout << "-----------------------------" << endl;
			}
		}
		else break;
	}

	//전화번호부 data들을 해당파일에 저장
	PhoneBook.saveFileGroups("group_box.txt");
	PhoneBook.saveTextFile("phone_book.txt");
	his.saveTextFile("call_history.txt");
	mms.saveTextFile("message_box.txt");
	cout << "프로그램 종료" << endl;
}
