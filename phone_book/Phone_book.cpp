#include<phonebook.h>
#include<algorithm>
#include<iostream>

void Phonebook::sorting(){
    sort(people.begin(), people.end());
}

void Phonebook::addPerson(const Person& p){
    people.push_back(p);
    sorting();
}

void Phonebook::removePerson(const Person& p){
    int i = 0;
    vector<Person>::iterator it;
    for(it = people.begin();it != people.end(); it++){
        if(strcmp(*it.name,p.name) && strcmp(*it.phone_num,p.phone_num) && strcmp(*it.group, p.group) && strcmp(*it.memo, p.memo))
            break;
        i++
    }
    people.erase(people.begin()+i);
}

void Phonebook::readFile(const string& file){
    ifstream file_in(file.c_str());
    Person p;
    while(file_in.is_open()){
        file_in >> p;
        people.push_back(p);
    }
}

void Phonebook::saveFile(const string& file){
    ofstream file_out(file.c_str());
    vector<Person>::iterator it;
    for(it = people.begin();it != people.end();it++)
        file_out << *it;  
}

void showPhoneBook(){
    vector<Person>::iterator it;
    for(it = people.begin();it != people.end();it++){
        count <<"Name : " << *it.name << endl;
        count <<"Phonenum : " << *it.phone_num << endl;
        count <<"Group : " << *it.group << endl;
        count <<"memo : "<< *it.memo << endl;
    }
}

int numofPerson(){
    return people.size();
}

Person findName(const string& f_name){
    PhoneBook target_names;
    vector<Person>::iterator it;
    int i, j;
    if(it=people.begin();it!=people;it++){
        if(*it.name = f_name)
            target_names.pushback(*it);
    }
    //케이스 정리
    //해당 이름이 없을 경우
    if(target_names.size() == 0){
        return Person("NULL","NULL","NULL","NULL")
    }
    else if(target_names.size() == 1){  //해당이름을 가진사람이 한명일 경우
        return target_names[1];
    } 
    else{  //해당이름을 가진 사람이 여러명인 경우 번호까지보여줘서 선택하게 함
       cout <<"찾기를 원하는 사람을 고르세요.";
       for(i = 0; i < target_names.size()-1 ; i++){
           cout << i+1 << " " << endl;
           cout << target_names[i];
       }
       cin >> j;
       return target_names[j-1]; 
    }

}

Person findPhone(const string& f_phone_num){
    vector<Person>::iterator it;
    for(it = people.begin();it != people.end(); it++){
        if(*it.phone == f_phone_num){  //해당번호가 존재할 경우
            return *it;
        }
        else if(it == people.end()){
            return Person("NULL","NULL","NULL","NULL"); //해당번호가 존재하지 않을경우
        }
    }
    //return Person("NULL","NULL","NULL","NULL"); //해당번호가 존재하지 않을경우
}

Person findGroup(const string& f_group){
    //어케 구현할까 그룹만 나오게 할까? 아니면 그룹을 통해서 한명을 선택할 수 있게할까? 
    //최준영이랑 상의
}



