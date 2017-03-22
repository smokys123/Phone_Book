#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <person.h>
#include <string>
#include <vector>

using namespace std;

class PhoneBook{
private:
    vector<Person> people;

public:
    void sorting();
    void addPerson(const Person&);
    void removePerson(const Person&);

    void readFile(const string&);
    void saveFile(const string&);

    void showPhoneBook();
    int numofPerson();

    Person findName(const string& f_name);
    Person findPhone_num(const string& f_phone_num);
    Person findGroup(const string& f_group);
}

#endif
