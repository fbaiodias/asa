#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Person {
    int id;
    vector<int> friends;
  public:
    Person (int);
    int getId () {return id;}
    void newFriend (int i) {friends.push_back(i);}
    int getShares(){return friends.size;}
    int getFriend(int i){return friends[i];}

};

Person::Person (int i) {
  id = i;
}

//vector<int> u,v;
vector<Person*> people;
int n,p;


int main () {

  scanf("%u %u", &n,&p);

  for(int i=0;i<n;i++) {
    people.push_back(new Person(i));
  }

  int pu, pv;

  for(int i=0;i<p;i++) {
    scanf("%u %u", &pu, &pv);

    people[pu]->newFriend(pv);
    //u.push_back(pu);
    //v.push_back(pv);
  }


  // DEBUG
  for(int i=0;i<n;i++) {
    cout << "Person " << people[i]->getId() << "\n" << "Partilhas ";
    for(int j = 0; j<people[i]->getShares(); j++){
      cout << people->getFriend(j) << " ";
    }
    cout << "\n";
  }

  for(int i=0;i<p;i++) {
    //cout << "Partilha " << u[i] << " " << v[i] << "\n";
  }

  return 0;
}