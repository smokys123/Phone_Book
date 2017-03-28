
#include "people.h"
#include "sms.h"
#include "message.h"
#include "call.h"
#include "callList.h"
#include <iostream>
#include <vector>

using namespace std;

//��ȭ��ȣ�� API
void main() {
    //������ ���ϵ��� �о��
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
		cout << "1. ��ȭ��ȣ��  2.  �޼�����  3. ��ȭ��� 4. ����" << endl;
		cout << "> ";
		cin >> menu;
		//��ȭ��ȣ��ɿ� ���� ����
		if (menu == 1) {
			cout << "��ȭ��ȣ�� - �޴��� �Է��ϼ���" << endl;
			cout << "1. ��ȭ ��ȣ ��� | 2. ��ȭ��ȣ �˻� | 3. ��ȭ��ȣ �߰�/����" << endl;
			cout << "4. ���ã�� �߰� / ���� | 5.�׷� �߰� / ����" << endl;
			cout << "> ";
			int menu_1;
			cin >> menu_1;
			if (menu_1 == 1) {  //��ȭ��ȣ�� ��� show
				PhoneBook.show();
			}
			else if (menu_1 == 2) { //��ȭ��ȣ �˻�
				cout << "�˻� ����� �����ϼ���" << endl;
				cout << "1. ��ȭ��ȣ | 2. �̸� | 3. �׷�" << endl;
				cout << "> ";
				int select;
				cin >> select;
				if (select == 1) {  //��ȣ�� ���� �˻�
					cout << "��ȭ��ȣ�� �Է��ϼ���." << endl;
					cout << "> ";
					string number;
					cin >> number;
					cout << "-----------------------------" << endl;
					if (PhoneBook.findPersonFromNum(number).getName() == "None") {
						cout << "�ش��ȣ�� �����ϴ�." << endl;
						cout << "-----------------------------" << endl;
					}
					else {
						cout << PhoneBook.findPersonFromNum(number);
						cout << "-----------------------------" << endl;
					}
				}
				else if (select == 2) {  //�̸��� ���� �˻�
					cout << "�̸��� �Է��ϼ���." << endl;
					cout << "> ";
					string name;
					cin >> name;
					cout << "-----------------------------" << endl;
					if (PhoneBook.findNameFromName(name).getName() == "None") {
						cout << "�ش��̸��� �����ϴ�." << endl;
						cout << "-----------------------------" << endl;
					}
					else {
						cout << PhoneBook.findNameFromName(name);
						cout << "-----------------------------" << endl;
					}
				}
				else if (select == 3) {  //�׷��� ���� �˻�
					for (int i = 0; i < PhoneBook.groups.size(); i++)
						cout << i + 1 << "." << PhoneBook.groups[i] << " ";
					cout << endl;
					cout << "�׷� �̸��� �Է��ϼ���." << endl;
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
						cout << "�ش��ϴ� �׷��� �����ϴ�." << endl;
					}
					cout << "-----------------------------" << endl;
				}
			}
			else if (menu_1 == 3) {  //��ȭ��ȣ �߰� ����
				int num;
				cout << "1.�߰� 2. ����" << endl;
				cout << "> ";
				cin >> num;
				if (num == 1) {  //��ȭ��ȣ �߰� ���� ���
					cout << "��ȭ��ȣ�� �Է� ������ �����ϼ���" << endl;
					cout << "1. ���� 2. ����" << endl;
					cout << "> ";
					int select;
					cin >> select;
					if (select == 1) {  //�����Է��� ���� ��ȭ��ȣ �߰�
						cout << "-----------------------------" << endl;
						int check = 0;
						string name, group, number;
						cout << "�̸� : ";
						cin >> name;
						cout << "��ȣ : ";
						cin >> number;
						cout << "���� �׷� ��� " << endl;
						for (int i = 0; i < PhoneBook.groups.size(); i++)
							cout << i + 1 << "." << PhoneBook.groups[i] << " ";
						cout << endl;
						cout << "�׷� : ";
						cin >> group;
						for (int order = 0; order < PhoneBook.groups.size(); order++) {
							if (PhoneBook.groups.at(order) == group) {
								check = 1;
								Person newPerson(name, number, group, false);
								PhoneBook.add(newPerson);
							}
						}
						cout << "-----------------------------" << endl;
						//�׷��� �������� ������츦 ���� ����ó��
						if (check == 0) {
							cout << "�ش��ϴ� �׷��� �������� �ʽ��ϴ�. " << endl;
							cout << "�׷��߰� �޴����� �߰����ּ���." << endl;
							cout << "-----------------------------" << endl;
						}
					}
					else if (select == 2) { //������ ���� ��ȭ��ȣ �߰�
						string fileName;
						cout << "���� �̸��� �Է��ϼ���. : ";
						cin >> fileName;
						PhoneBook.readTextFile(fileName);
					}
				}
				if (num == 2) {  //��ȭ��ȣ�� ���� ���
					string name;
					cout << "������ �̸� �Է��ϼ���. : ";
					cin >> name;
					cout << "-----------------------------" << endl;
					if (PhoneBook.findNameFromName(name).getName() == "None") {
						cout << "�ش��ϴ� �̸��� �����ϴ�." << endl;
						cout << "-----------------------------" << endl;
					}
					else {
						PhoneBook.remove(PhoneBook.findNameFromName(name));
						cout << "�ش� �̸��� �����߽��ϴ�." << endl;
						cout << "-----------------------------" << endl;
					}
				}
			}
			else if (menu_1 == 4) {  //���ã�� �߰� ���� ���
				int select;
				cout << "���ã��" << endl;
				cout << "1. �߰� 2. ����" << endl;
				cout << "> ";
				cin >> select;
				while (1) {
					cout << "-----------------------------" << endl;
					if (select == 1) {  //���ã�� �߰�
						cout << "�̸��� �Է��ϼ���" << endl;
						cout << "> ";
						string name_1, name_2, number, group;
						bool favorite;
						cin >> name_1;
						//�ش� �̸��� ���� ��츦 ���� ����ó��
						if (PhoneBook.findNameFromName(name_1).getName() == "None") {
							cout << "�ش��ϴ� �̸��� ��ȭ��ȣ ��Ͽ� �����ϴ�.";
							break;
						}
						name_2 = PhoneBook.findNameFromName(name_1).getName();
						number = PhoneBook.findNameFromName(name_1).getNumber();
						group = PhoneBook.findNameFromName(name_1).getGroup();

						PhoneBook.remove(PhoneBook.findNameFromName(name_1));
						Person newPerson(name_2, group, number, true);
						PhoneBook.add(newPerson);
						cout << "���ã�� ��Ͽ� �߰��߽��ϴ�." << endl;
						break;
					}
					else if (select == 2) { //���ã�� ����
						cout << "�̸��� �Է��ϼ���" << endl;
						cout << "> ";
						string name_1, name_2, number, group;
						bool favorite;
						cin >> name_1;
						//�ش��̸��� ���� ��츦 ���� ����ó��
						if (PhoneBook.findNameFromName(name_1).getName() == "None") {
							cout << "�ش��ϴ� �̸��� ��ȭ��ȣ ��Ͽ� �����ϴ�." << endl;
							break;
						}
						name_2 = PhoneBook.findNameFromName(name_1).getName();
						number = PhoneBook.findNameFromName(name_1).getNumber();
						group = PhoneBook.findNameFromName(name_1).getGroup();

						PhoneBook.remove(PhoneBook.findNameFromName(name_1));
						Person newPerson(name_2, group, number, false);
						PhoneBook.add(newPerson);
						cout << "���ã�� ��Ͽ��� �����߽��ϴ�." << endl;
						break;
					}
				}
				cout << "-----------------------------" << endl;
			}
			else if (menu_1 == 5) { //�׷� �߰� ����
				int select;
				cout << "-----------------------------" << endl;
				cout << "���� �׷� ��� " << endl;
				for (int i = 0; i < PhoneBook.groups.size(); i++)
					cout << i + 1 << "." << PhoneBook.groups[i] << " ";
				cout << endl;
				cout << "1. �߰� 2. ����" << endl;
				cout << "> ";
				cin >> select;
				cout << "-----------------------------" << endl;
				if (select == 1) { //�׷� �߰� ���
					string name;
					int check = 0;
					cout << "�߰��� �׷� �̸��� �Է��ϼ���" << endl;
					cout << "> ";
					cin >> name;
					//�׷��� �̹� ���� �Ұ�츦 ���� ����ó��
					for (int i = 0; i < PhoneBook.groups.size(); i++) {
						if (PhoneBook.groups[i] == name) {
							cout << "�ش��ϴ� �׷��� �̹� �����մϴ�." << endl;
							check++;
						}
					}
					if (check == 0) {
						cout << "�׷��� �߰��߽��ϴ�." << endl;
						PhoneBook.groups.push_back(name);
					}
				}
				else if (select == 2) { //�׷� ���� ���
					string name;
					int check = 0;
					cout << "������ �׷� �̸��� �Է��ϼ���" << endl;
					cout << "> ";
					cin >> name;
					vector<string>::iterator it = PhoneBook.groups.begin();
					for (int i = 0; i < (signed)PhoneBook.groups.size(); i++) {
						if (PhoneBook.groups[i] == name) {
							PhoneBook.groups.erase(it + i);
							cout << "�׷��� �����߽��ϴ�." << endl;
							check++;
						}
					}
					//�ش� �׷��� �������� ���� ��츦 ���� ����ó��
					if (check == 0) {
						cout << "�ش��ϴ� �׷��� �������� �ʽ��ϴ�." << endl;
					}
				}
				cout << "-----------------------------" << endl;
			}
		}
		//�޼����� ���
		else if (menu == 2) {  
			cout << "�޼����� - ���ϴ� �޴��� �Է��ϼ���" << endl;
			cout << "1. �޼��� ��� | 2. �޼��� �Է� | 3. �޼��� �˻� | 4. �޼��� ����" << endl;
			cout << "> ";
			int menu_2;
			cin >> menu_2;
			if (menu_2 == 1) {  //�޽��� ���
				for (int i = 0; i<mms.sms.size(); i++) {
					showMessage(mms.sms[i], PhoneBook);
				}
			}
			else if (menu_2 == 2) {  //�޼��� �Է�
				cout << "-----------------------------" << endl;
				string sender, receiver, content, date;
				cout << "������ ��� : ";
				cin >> sender;
				cout << "�޴� ��� : ";
				cin >> receiver;
				cout << "���� : ";
				cin >> content;
				cout << "�ð� : ";
				cin >> date;
				Message msg(sender, receiver, content, date);
				mms.addMessage(msg);
				cout << "-----------------------------" << endl;
			}
			else if (menu_2 == 3) { //�޽��� �˻�
				string index;
				cout << "-----------------------------" << endl;
				cout << "�˻��� ����� ��ȣ�� �Է��ϼ���" << endl;
				cout << "> ";
				cin >> index;
				int i;
				//�ش� ��ȣ�� ������, �߽��� �������  ���� ���
				for (i = 0; i < mms.findMessage((PhoneBook.findPersonFromNum(index)).getNumber()).size(); i++) {
					showMessage(mms.findMessage((PhoneBook.findPersonFromNum(index)).getNumber())[i], PhoneBook);
				}
				if (i == 0) {
					cout << "�ش� ����� �����ϴ�." << endl;
				}
				cout << "-----------------------------" << endl;
			}
		}
		//��ȭ��� ���
		else if (menu == 3) {  
			cout << "��ȭ���" << endl;
			for (int i = 0; i < his.callhistory.size(); i++) {
				cout << "-----------------------------" << endl;
				showCallList(his.callhistory[i], PhoneBook);
				cout << "-----------------------------" << endl;
			}
		}
		else break;
	}

	//��ȭ��ȣ�� data���� �ش����Ͽ� ����
	PhoneBook.saveFileGroups("group_box.txt");
	PhoneBook.saveTextFile("phone_book.txt");
	his.saveTextFile("call_history.txt");
	mms.saveTextFile("message_box.txt");
	cout << "���α׷� ����" << endl;
}
