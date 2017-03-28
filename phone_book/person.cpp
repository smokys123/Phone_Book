#include "person.h"
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

//Person class ������ �Ҹ���
//���ڸ� �޾Ƽ� Person ��ü �����ϴ� ������ method
Person::Person(const string& newName, const string& newNumber, const string& newGroup, bool newFavorite) {
	name = new string(newName);
	group = new string(newGroup);
	number = new string(newNumber);
	favorite = newFavorite;
}

//Person class�� �޾ƿ� ��ü�� �����ϴ� ������ method
Person::Person(const Person& per) {
	name = new string(*per.name);
	group = new string(*per.group);
	number = new string(*per.number);
	favorite = (per.favorite);
}
//Person ��ü �Ҹ���
Person::~Person() {
	delete name;
	delete group;
	delete number;
}

//Person ��ü�� ����ϱ� ���� ������ �����ε�
ostream& operator<<(ostream& os, const Person& per) {
	os << "�̸� : " << *per.name << endl;
	os << "��ȣ : " << *per.number << endl;
	os << "�׷� : " << *per.group << endl;
	os << "favorite: " << per.favorite << endl;
	return os;
}

//Person class�� ������ ���Ͽ� �����ϴ� ������ �����ε�
ofstream& operator<<(ofstream& fout, const Person& per) {
	fout << *per.name << endl;
	fout << *per.number << endl;
	fout << *per.group << endl;
	fout << per.favorite << endl;
	return fout;
}

//���Ͽ��� Person class�� ������ �о�ͼ� �����ϴ� ������ �����ε�
ifstream& operator >> (ifstream& fin, Person& per) {
	(fin >> *per.name).get();
	(fin >> *per.number).get();
	(fin >> *per.group).get();
	(fin >> per.favorite).get();
	return fin;
}

//Person class���� ������ ���� method
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

//Person class���� �񱳸� ���� method
bool Person::operator==(const Person& Person) const {
	return (*name == *Person.name) & (*group == *Person.group) & (*number == *Person.number) &(favorite == Person.favorite);
}

//Person class�� ������ ����
//class���� namedmf �� �� ���� �� number�� ���ϴ� method
bool operator<(const Person& firstPer, const Person& secondPer) {
	if (*firstPer.name != *secondPer.name)
		return *firstPer.name < *secondPer.name;
	if (*firstPer.number != *secondPer.number)
		return *firstPer.number < *secondPer.number;
	return true;
}

//Person class�� ���� setter
//class�� name�� �����ϴ� method 
void Person::setName(const string& newName) {
	delete name;
	name = new string(newName);
}

//class�� group ������ �����ϴ� method
void Person::setGroup(const string& newGroup) {
	delete group;
	group = new string(newGroup);
}

//class�� number ������ �����ϴ� method
void Person::setNumber(const string& newNumber) {
	delete number;
	number = new string(newNumber);
}

//class�� favorite ������ �����ϴ� method
void Person::setFavorite(bool newFavorite) {
	favorite = newFavorite;

}
 //Person ��ü�� attribute�� ��ȯ�ϴ� getter
//class�� name�� ��ȯ�ϴ� method
string Person::getName() const {
	return *name;
}

//class�� group�� ��ȯ�ϴ� method
string Person::getGroup() const {
	return *group;
}

//class�� number�� ��ȯ�ϴ� method
string Person::getNumber() const {

	return *number;
}

//class�� favorite�� ��ȯ�ϴ� method
bool Person::getFavorite() const {
	return favorite;
}
