#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "people.h"
using namespace std;

//파일에서 Person객체의 data를 읽어오는 method
bool People::readTextFile(const string& fileName) {
	ifstream fin(fileName.c_str(), ios_base::in | ios_base::binary);
	if (fin.is_open()) {
		int size;
		int check;
		(fin >> size).get();
		Person per("", "", "", false);
		for (int i = 0; i < size; i++) {
			fin >> per;
			check = 0;
			//동일한 인물이 있을경우를 위한 예외처리
			for (int j = 0; j < people.size(); j++) {
				if (people[j] == per)
					check++;
			}
			if (check == 0)
				people.push_back(per);
		}
		sorting();
		return true;
	}
	else {
		return false;
	}
}

//파일에서 그룹정보를 읽어오기위한 method
bool People::readFileGroups(const string& fileName) {
	ifstream fin(fileName.c_str(), ios_base::in | ios_base::binary);
	if (fin.is_open()) {
		int size;
		string group;
		(fin >> size).get();
		for (int i = 0; i < size; i++) {
			fin >> group;
			groups.push_back(group);
		}
		return true;
	}
	else {
		return false;
	}

}

//전화번호부의 Person 객체들을 파일로 쓰기위한 method
bool People::saveTextFile(const string& fileName) const {
	ofstream fout(fileName.c_str(), ios_base::out | ios_base::binary | ios_base::trunc);
	fout << people.size() << "\n";
	for (auto it = people.begin(); it != people.end(); it++) {
		fout << *it;
	}
	if (fout.fail())
		return false;
	return true;
}

//전화번호부의 Group의 data를 파일로 쓰기위한 method
bool People::saveFileGroups(const string& fileName) const {
	ofstream fout(fileName.c_str(), ios_base::out | ios_base::binary | ios_base::trunc);
	fout << groups.size() << "\n";
	for (auto it = groups.begin(); it != groups.end(); it++) {
		fout << *it << "\n";
	}
	if (fout.fail())
		return false;
	return true;
}

// Person 추가을 추가하고 sort하는 method
void People::add(const Person& Person) {
	people.push_back(Person);
	sorting();
}

//현재 전화번호부에 해당하는 사람이 있는지  Person class로 찾는 method
int People::findPerson(const Person& Person, const int START) const {
	for (int order = START; order < (signed)people.size(); order++) {
		if (people.at(order) == Person)
			return order;
	}
	return -1;
}

//전화번호부에서 name으로 해당하는 Person 찾는 method
//같은 사람이 있을 경우 번호를 통해 선택
int People::findPerson(const string& name, const int START) const {
	int same[50];
	int i = 0;
	//같은 name인 Person들을 찾음
	for (int order = START; order < (signed)people.size(); order++) {
		if (people.at(order).getName() == name) {
			same[i] = order;
			i++;
		}
	}
	//같은 name이 없을경우
	if (i == 0) 
		return -1;
	else { //같은 name이 있는경우 번호로 탐색
		int j;
		std::cout << "해당하는 사람의 번호를 입력하세요" << endl;
		for (j = 0; j <= i; j++) {
			std::cout << j + 1 << "." << endl;
			std::cout << people.at(same[j]);
		}
		while (true) {
			std::cin >> j;
			if (j > 0 && j < i + 1) {
				return same[j - 1];
			}
			cout << "잘못 된 번호입니다. 다시 입력하세요" << endl;
		}
	}
}

//전화번호부에서 Person 객체를 이용해서 Person을 제거하는 method
void People::remove(const Person& Person) {
	people.erase(people.begin() + findPerson(Person));
}

//전화번호부에서 name을 이용하여 person을 제거하는 method
void People::remove(const string& name) {
	people.erase(people.begin() + findPerson(name));
}

//전화번호부 내의 모든 사람 출력하는 method
//즐겨찾기된 사람 먼저 위에 나오게 함
void People::show() {
	int i = 0;
	cout << "----- 즐겨찾기 목록 -----" << endl;
	for (auto it = people.begin(); it != people.end(); it++, i++) {
		if (people.at(i).getFavorite() == true) {
			cout << *it << endl;
		}
	}
	cout << "----- 전화번호 목록 -----" << endl;
	for (auto it = people.begin(); it != people.end(); it++) {
		cout << *it << endl;
	}
}

//전화번호부 사람 sort하는 method
void People::sorting() {
	sort(people.begin(), people.end());
}

//전화번호부의 Person의 숫자 반환하는 method
int People::size() const {
	return people.size();
}

//전화번호의 order에 있는 Person 반환하는 method
Person People::get(int order) const {
	return people.at(order);
}

//전화번호부에서 해당하는 번호에 해당하는 name을 반환하는 method
string People::findNameFromNum(const string& num) const {
	for (int order = 0; order < (signed)people.size(); order++) {
		if (people.at(order).getNumber() == num)
			return people.at(order).getName();
	}
	return "";
}

//전화번호부에서 이름으로 해당하는 Person을 찾는 method
Person People::findNameFromName(const string& fName) {
	vector<Person> sameName;
	//같은이름인 Person 객체를 찾음
	for (int order = 0; order < (signed)people.size(); order++) {
		if (people.at(order).getName() == fName) {
			sameName.push_back(people.at(order));
		}
	}
	//해당 이름을 가진 사람이 한 사람만 존재할 경우
	if (sameName.size() == 1) 
		return sameName[0];			
	//해당 이름을 가진 사람이 존재하지 않을 경우
	else if (sameName.size() == 0) {
		return Person("None", "None", "None", false);			
	}
	//이름이 같은 사람이 여럿 존재할 경우
	else {
		int i = sameName.size() - 1;
		cout << "찾고 있는 사람을 선택하세요";
		for (int j = 0; j <= i; j++) {
			cout << j + 1 << "." << endl;
			cout << sameName[j];
		}
		int k;
		cin >> k;
		return sameName[k - 1];			
	}

}

//전화번호부에서 번호를 통해 Person을 검색하는 method
Person People::findPersonFromNum(const string& fPhone) {
	vector<Person>::iterator it;
	for (int order = 0; order < (signed)people.size(); order++) {
		//해당 번호가 존재할 경우
		if (people.at(order).getNumber() == fPhone)
			return people.at(order);
	}
	//해당 번호가 존재하지 않을 경우
	return Person("None", fPhone, "None", false);			

}

//즐겨찾기로 지정된 Person을 찾는 method
Person People::findFavorite() {
	vector<Person>::iterator it;
	for (int i = 0; i < (signed)people.size(); i++) {
		cout << people.at(i).getFavorite() << endl;
		if (people.at(i).getFavorite() == true) 
			return people.at(i);
	}
	cout << "즐겨찾기목록이 비었습니다" << endl;
	return Person("None", "None", "None", false);
}
