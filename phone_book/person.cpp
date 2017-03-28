#include "person.h"
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

//Person class 생성자 소멸자
//인자를 받아서 Person 객체 생성하는 생성자 method
Person::Person(const string& newName, const string& newNumber, const string& newGroup, bool newFavorite) {
	name = new string(newName);
	group = new string(newGroup);
	number = new string(newNumber);
	favorite = newFavorite;
}

//Person class를 받아와 객체를 생성하는 생성자 method
Person::Person(const Person& per) {
	name = new string(*per.name);
	group = new string(*per.group);
	number = new string(*per.number);
	favorite = (per.favorite);
}
//Person 객체 소멸자
Person::~Person() {
	delete name;
	delete group;
	delete number;
}

//Person 객체를 출력하기 위한 연산자 오버로딩
ostream& operator<<(ostream& os, const Person& per) {
	os << "이름 : " << *per.name << endl;
	os << "번호 : " << *per.number << endl;
	os << "그룹 : " << *per.group << endl;
	os << "favorite: " << per.favorite << endl;
	return os;
}

//Person class의 내용을 파일에 저장하는 연산자 오버로딩
ofstream& operator<<(ofstream& fout, const Person& per) {
	fout << *per.name << endl;
	fout << *per.number << endl;
	fout << *per.group << endl;
	fout << per.favorite << endl;
	return fout;
}

//파일에서 Person class의 내용을 읽어와서 저장하는 연산자 오버로딩
ifstream& operator >> (ifstream& fin, Person& per) {
	(fin >> *per.name).get();
	(fin >> *per.number).get();
	(fin >> *per.group).get();
	(fin >> per.favorite).get();
	return fin;
}

//Person class간의 대입을 위한 method
Person& Person::operator=(const Person& per) {
	delete name;
	delete number;
	delete group;
	this->name = new string(*per.name);
	this->number = new string(*per.number);
	this->group = new string(*per.group);
	this->favorite = per.favorite;
	return *this;
}

//Person class간의 비교를 위한 method
bool Person::operator==(const Person& Person) const {
	return (*name == *Person.name) & (*group == *Person.group) & (*number == *Person.number) &(favorite == Person.favorite);
}

//Person class의 정렬을 위해
//class안의 namedmf 비교 후 같을 시 number로 비교하는 method
bool operator<(const Person& firstPer, const Person& secondPer) {
	if (*firstPer.name != *secondPer.name)
		return *firstPer.name < *secondPer.name;
	if (*firstPer.number != *secondPer.number)
		return *firstPer.number < *secondPer.number;
	return true;
}

//Person class에 대한 setter
//class의 name에 대입하는 method 
void Person::setName(const string& newName) {
	delete name;
	name = new string(newName);
}

//class의 group 변수에 대입하는 method
void Person::setGroup(const string& newGroup) {
	delete group;
	group = new string(newGroup);
}

//class의 number 변수에 대입하는 method
void Person::setNumber(const string& newNumber) {
	delete number;
	number = new string(newNumber);
}

//class의 favorite 변수에 대입하는 method
void Person::setFavorite(bool newFavorite) {
	favorite = newFavorite;

}
 //Person 객체의 attribute를 반환하는 getter
//class의 name을 반환하는 method
string Person::getName() const {
	return *name;
}

//class의 group을 반환하는 method
string Person::getGroup() const {
	return *group;
}

//class의 number를 반환하는 method
string Person::getNumber() const {

	return *number;
}

//class의 favorite를 반환하는 method
bool Person::getFavorite() const {
	return favorite;
}
