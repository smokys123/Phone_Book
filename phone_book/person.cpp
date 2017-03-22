#include <person.h>
#include <iostream>

using namespace std;

Person::Person(const string& new_Name, const string& new_Phonenum, const string &new_Group, const string& new_Memo){
    name = new string(new_Name);
    phone_num = new string(new_Phonenum);
    group = new string(new_Group);
    memo = new string(new_Memo);
}

Person::Person(const Person& new_Person){
    name = new string(*new_Person.name);
    phone_num = new string(*new_Person.phone_num);                                      
    group = new string(*new_Person.group);
    memo = new string(*new_Person.memo);
}

Person::Person(){
    delete name;
    delete phone_num;
    delete group;
    delete memo;
}

Person::ShowInfo(){
    cout << "Name : " << name << endl;
    cout << "Phone Number : " << phone_num << endl;
    cout << "Group name : " << group << endl;
    cout << "Memo : " << memo << endl;
}

void Person::setName(const string& new_Name){
    delete neme;
    name = new string(new_Name);
}

void Person::setPhone_num(const string& new_Phonenum){
    delete phone_num;
    phone_num = new string(new_Phonenum);
}

void Person::setGroup(const string& new_Group){
    delete group;
    group = new string(new_Group);
}

void Person::setMemo(const string& new_Memo){
    delete memo;
    memo = new string(new_memo);
}

Person& Person::operator=(const Person& p){
    delete this->name;
    delete this->phone_num;
    delete this->group;
    delete this->memo;
    this->name = new string(*p.name);
    this->phone_num = new string(*p.phone_num);
    this->group = new string(*p.group);
    this->memo = new string(*p.memo);
}

bool Person::operator==(const Person& p){
    return (*name==*p.name) & (*phone_num==*p.phone_num) & (*group==*p.group) & (*memo==*p.memo);
}

bool Person::operator<(const Person& p1, const Person& p2){
    if(*p1.name != *p2.name)
        return *p1.name < *p2.name;
    if(*p1.phone_num != *p2.phone_num)
        return *p1.phone_num < *p2.phone_num;
    else 
       return true; 
}

ifstream& Person::operator>>(ifstream& file_in, Person& p){
    file_in >> *p.name;
    file_in >> *p.phoe_num;
    file_in >> *p.group;
    file_in >> *p.memo;
    return file_in;
}

ofstream& Person::operator<<(ofstream& file_out, Person& p){
    file_out << *p.name << "\n";
    file_out << *p.phone_num << "\n";
    file_out << *p.group << "\n";
    file_out << *p.memo << "\n";
    return file_out
}














