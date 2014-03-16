#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Person {
    int id;
    int d, low;
    vector<int> friends;
  public:
    Person (int i) {id = i; d=-1;};
    int getId () {return id;}
    void newFriend (int i) {friends.push_back(i);}
    int getFriends(){return friends.size();}
    int getFriend(int i){return friends[i];}
    bool isUnvisited() {return (d == -1);}
    bool isRoot() {return (d == low);}
    void visit(int visited) {d=low=visited;}
    int getLow() {return low;}
    void setLow(int newLow) {if(newLow < low) low = newLow;}
};

vector<Person*> people;
vector<int> stack;
int n,p;
int visited = 0, L = 0;
int numberOfSCCs = 0;
int maxSCCSize = 0;

void tarjanVisit(int u) {
  //cout << "Visiting " << u+1 << "\n";
  people[u]->visit(visited);

  visited = visited + 1;
  stack.push_back(u+1);

  for(int i=0; i < people[u]->getFriends(); i++) {
    int v = people[u]->getFriend(i)-1;
    if (people[v]->isUnvisited() || find(stack.begin(), stack.end(), v+1)!=stack.end()) {
      if (people[v]->isUnvisited()) {
        // Ignora vértices de SCCs já identiﬁcados
        tarjanVisit(v);
      }
      people[u]->setLow(people[v]->getLow());
    }

  }

  if(people[u]->isRoot()) {
    u=u+1;
    int SCCSize = 1;
    int v = stack.back();
    stack.pop_back();

    //cout << "SCC U: " << u << " V: " << v << " ";
    while(u != v) {
      // Vértices retirados deﬁnem SCC
      v = stack.back();
      stack.pop_back();
      //cout << v << " ";
      SCCSize=SCCSize+1;
    }
    //cout << "\n";

    numberOfSCCs = numberOfSCCs+1;
    if(SCCSize>maxSCCSize) maxSCCSize=SCCSize;
  }


}


int main () {

  scanf("%u %u", &n,&p);

  for(int i=0;i<n;i++) {
    people.push_back(new Person(i+1));
  }

  int pu, pv;
  for(int i=0;i<p;i++) {
    scanf("%u %u", &pu, &pv);

    people[pu-1]->newFriend(pv);
  }

  for(int i=0;i<n;i++) {
    if(people[i]->isUnvisited()){
      tarjanVisit(i);
    }
  }

  // DEBUG
  /*
  for(int i=0;i<n;i++) {
    cout << "Person " << people[i]->getId() << "\n" << "Shares with ";
    for(int o=0; o < people[i]->getFriends(); o++){
      cout << people[i]->getFriend(o) << " ";
    }
    cout << "\n\n";
  }
  */

  // OUTPUT
  cout << numberOfSCCs << "\n";
  cout << maxSCCSize << "\n";


  return 0;
}
