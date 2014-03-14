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
    bool unvisited() {return (d == -1);}
    void visit(int visited) {d=low=visited;}
    int low() {return low;}
    void setLow(int newLow) {if(newLow < low) low = newLow;}
};

vector<Person*> people;
vector<Person*> stack;
int n,p;
int visited = 0, L = 0;



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
    if(people[i]->unvisited()){
      tarjanVisit(i);
    }
  }

  // DEBUG
  for(int i=0;i<n;i++) {
    cout << "Person " << people[i]->getId() << "\n" << "Shares with ";
    for(int o=0; o < people[i]->getFriends(); o++){
      cout << people[i]->getFriend(o) << " ";
    }
    cout << "\n\n";
  }

  return 0;
}

void tarjanVisit(int i) {
  people[i]->visit();

  visited = visited + 1
  stack.push_back(people[i]);

  for(int o=0; o<people[i]->getFriends(); o++) {
    if (people[people[i]->getFriend[o]]->unvisited()) {
      // Ignora vértices de SCCs já identiﬁcados
      tarjanVisit(o)
      people[i]->setLow(people[people[i]->getFriend[o]]->low())
    }
  }

  if d[u] = low[u] ✄ Raiz do SCC
  then repeat
  v = Pop(L)
  // Vértices retirados deﬁnem SCC
until u = v
}
