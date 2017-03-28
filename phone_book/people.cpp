#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "people.h"
using namespace std;

//���Ͽ��� Person��ü�� data�� �о���� method
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
			//������ �ι��� ������츦 ���� ����ó��
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

//���Ͽ��� �׷������� �о�������� method
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

//��ȭ��ȣ���� Person ��ü���� ���Ϸ� �������� method
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

//��ȭ��ȣ���� Group�� data�� ���Ϸ� �������� method
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

// Person �߰��� �߰��ϰ� sort�ϴ� method
void People::add(const Person& Person) {
	people.push_back(Person);
	sorting();
}

//���� ��ȭ��ȣ�ο� �ش��ϴ� ����� �ִ���  Person class�� ã�� method
int People::findPerson(const Person& Person, const int START) const {
	for (int order = START; order < (signed)people.size(); order++) {
		if (people.at(order) == Person)
			return order;
	}
	return -1;
}

//��ȭ��ȣ�ο��� name���� �ش��ϴ� Person ã�� method
//���� ����� ���� ��� ��ȣ�� ���� ����
int People::findPerson(const string& name, const int START) const {
	int same[50];
	int i = 0;
	//���� name�� Person���� ã��
	for (int order = START; order < (signed)people.size(); order++) {
		if (people.at(order).getName() == name) {
			same[i] = order;
			i++;
		}
	}
	//���� name�� �������
	if (i == 0) 
		return -1;
	else { //���� name�� �ִ°�� ��ȣ�� Ž��
		int j;
		std::cout << "�ش��ϴ� ����� ��ȣ�� �Է��ϼ���" << endl;
		for (j = 0; j <= i; j++) {
			std::cout << j + 1 << "." << endl;
			std::cout << people.at(same[j]);
		}
		while (true) {
			std::cin >> j;
			if (j > 0 && j < i + 1) {
				return same[j - 1];
			}
			cout << "�߸� �� ��ȣ�Դϴ�. �ٽ� �Է��ϼ���" << endl;
		}
	}
}

//��ȭ��ȣ�ο��� Person ��ü�� �̿��ؼ� Person�� �����ϴ� method
void People::remove(const Person& Person) {
	people.erase(people.begin() + findPerson(Person));
}

//��ȭ��ȣ�ο��� name�� �̿��Ͽ� person�� �����ϴ� method
void People::remove(const string& name) {
	people.erase(people.begin() + findPerson(name));
}

//��ȭ��ȣ�� ���� ��� ��� ����ϴ� method
//���ã��� ��� ���� ���� ������ ��
void People::show() {
	int i = 0;
	cout << "----- ���ã�� ��� -----" << endl;
	for (auto it = people.begin(); it != people.end(); it++, i++) {
		if (people.at(i).getFavorite() == true) {
			cout << *it << endl;
		}
	}
	cout << "----- ��ȭ��ȣ ��� -----" << endl;
	for (auto it = people.begin(); it != people.end(); it++) {
		cout << *it << endl;
	}
}

//��ȭ��ȣ�� ��� sort�ϴ� method
void People::sorting() {
	sort(people.begin(), people.end());
}

//��ȭ��ȣ���� Person�� ���� ��ȯ�ϴ� method
int People::size() const {
	return people.size();
}

//��ȭ��ȣ�� order�� �ִ� Person ��ȯ�ϴ� method
Person People::get(int order) const {
	return people.at(order);
}

//��ȭ��ȣ�ο��� �ش��ϴ� ��ȣ�� �ش��ϴ� name�� ��ȯ�ϴ� method
string People::findNameFromNum(const string& num) const {
	for (int order = 0; order < (signed)people.size(); order++) {
		if (people.at(order).getNumber() == num)
			return people.at(order).getName();
	}
	return "";
}

//��ȭ��ȣ�ο��� �̸����� �ش��ϴ� Person�� ã�� method
Person People::findNameFromName(const string& fName) {
	vector<Person> sameName;
	//�����̸��� Person ��ü�� ã��
	for (int order = 0; order < (signed)people.size(); order++) {
		if (people.at(order).getName() == fName) {
			sameName.push_back(people.at(order));
		}
	}
	//�ش� �̸��� ���� ����� �� ����� ������ ���
	if (sameName.size() == 1) 
		return sameName[0];			
	//�ش� �̸��� ���� ����� �������� ���� ���
	else if (sameName.size() == 0) {
		return Person("None", "None", "None", false);			
	}
	//�̸��� ���� ����� ���� ������ ���
	else {
		int i = sameName.size() - 1;
		cout << "ã�� �ִ� ����� �����ϼ���";
		for (int j = 0; j <= i; j++) {
			cout << j + 1 << "." << endl;
			cout << sameName[j];
		}
		int k;
		cin >> k;
		return sameName[k - 1];			
	}

}

//��ȭ��ȣ�ο��� ��ȣ�� ���� Person�� �˻��ϴ� method
Person People::findPersonFromNum(const string& fPhone) {
	vector<Person>::iterator it;
	for (int order = 0; order < (signed)people.size(); order++) {
		//�ش� ��ȣ�� ������ ���
		if (people.at(order).getNumber() == fPhone)
			return people.at(order);
	}
	//�ش� ��ȣ�� �������� ���� ���
	return Person("None", fPhone, "None", false);			

}

//���ã��� ������ Person�� ã�� method
Person People::findFavorite() {
	vector<Person>::iterator it;
	for (int i = 0; i < (signed)people.size(); i++) {
		cout << people.at(i).getFavorite() << endl;
		if (people.at(i).getFavorite() == true) 
			return people.at(i);
	}
	cout << "���ã������ ������ϴ�" << endl;
	return Person("None", "None", "None", false);
}
