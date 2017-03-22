#ifdef PERSON_H
#define PERSON_H

#include <string>
#include <ostream>
#include <fstream>

using namespace std;

class Person{

  private:
      string* name;
      string* phone_num;
      string* group;
      string* memo;
  
  public:
      Person(const string&, const string&, const string&, const string&);
      Person(const Person&);
      ~Person();
      Show_info();

      void setName(const string& name);
      void setPhone_num(const string& phone_num);
      void setGroup(const string& group);
      void setMemo(const string& memo);

      bool operator == (const Person&);
      bool operator < (const Person&, const Person&);
      friend Person operator = (const Person&);
      friend ifstream& operator >> (ifstream&, Person&);
      friend ofstream& operator << (ofstream&, const Person&);
      friend ostream& operator << (ostream&, const Person&);

}

#endif
