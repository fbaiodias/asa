#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

/*----------- Person ------------*/
class Person {
    int d, low;
    vector<int> friends;
    bool imstacked;
    bool imstackedF;
  public:
    Person () {d=-1; imstacked=false; imstackedF=false;};
    void newFriend (int i) {friends.push_back(i);}
    int getFriends(){return friends.size();}
    int getFriend(int i){return friends[i];}
    bool isUnvisited() {return (d == -1);}
    bool isRoot() {return (d == low);}
    void visit(int visited) {d=low=visited;}
    int getLow() {return low;}
    void setLow(int newLow) {if(newLow < low) low = newLow;}
    bool isOnStack(){return imstacked;}
    void enterStack(){imstacked=true;}
    void exitStack(){imstacked=false;}
    bool isOnStackF(){return imstackedF;}
    void enterStackF(){imstackedF=true;}
    void exitStackF(){imstackedF=false;}
};

/*----------- Global Variables ------------*/
vector<Person*> people;
vector<int> stack;
int n,p;
int visited = 0;
int numberOfSCCs = 0;
int maxSCCSize = 0;
int privateSCCs = 0;
int garbage = 0;

/*----------- Functions ------------*/
void tarjanVisit(int u) {
  people[u]->visit(visited);
  people[u]->enterStack();
  visited = visited + 1;
  stack.push_back(u+1);

  for(int i=0; i < people[u]->getFriends(); i++) {
    int v = people[u]->getFriend(i)-1;
    if (people[v]->isUnvisited() || people[v]->isOnStack()) {
      if (people[v]->isUnvisited()) {
        // Ignora vértices de SCCs já identiﬁcados
        tarjanVisit(v);
      }
      people[u]->setLow(people[v]->getLow());
    }

  }

  if(people[u]->isRoot()) {
  	vector<int> friends;
    u=u+1;
    int SCCSize = 0, v = -1, tempPerson;

    while(u != v) {
      // Vértices retirados deﬁnem SCC
      v = stack.back();
      stack.pop_back();
      people[v-1]->exitStack();
      SCCSize=SCCSize+1;

      if(!people[v-1]->isOnStackF()){
      		friends.push_back(v-1); 
      		people[v-1]->enterStackF();
      }
      for(int i = 0; i< people[v-1]->getFriends();i++){
        tempPerson = people[v-1]->getFriend(i)-1;
      	if(!people[tempPerson]->isOnStackF()){
      		friends.push_back(tempPerson); 
      		people[tempPerson]->enterStackF();
      	}
      }
    }

    int friendSize = friends.size();
  	for(int i = 0; i< friendSize;i++){
  		people[friends[i]]->exitStackF();
  	}
    if(SCCSize==friendSize) privateSCCs = privateSCCs + 1;
    numberOfSCCs = numberOfSCCs+1;
    if(SCCSize>maxSCCSize) maxSCCSize=SCCSize;
  }
}

/*----------- Main ------------*/
int main () {
  garbage = scanf("%u %u", &n,&p);

  for(int i=0;i<n;i++) {
    people.push_back(new Person());
  }

  int pu, pv;
  for(int i=0;i<p;i++) {
    garbage = scanf("%u %u", &pu, &pv);

    people[pu-1]->newFriend(pv);
  }

  for(int i=0;i<n;i++) {
    if(people[i]->isUnvisited()){
      tarjanVisit(i);
    }
  }

  // OUTPUT
  cout << numberOfSCCs << "\n";
  cout << maxSCCSize << "\n";
  cout << privateSCCs << "\n";
  return 0;
}
