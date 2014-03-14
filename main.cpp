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
    void visit(visited) {d=low=visited;}
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
  Push(L, u);
  for each v ∈Adj[u]
  do if (d[v] = ∞ || v ∈ L)
  // Ignora vértices de SCCs já identiﬁcados
  then if d[v] = ∞
  then Tarjan_Visit(v)
  low[u] = min(low[u], low[v])
  if d[u] = low[u] ✄ Raiz do SCC
  then repeat
  v = Pop(L)
  // Vértices retirados deﬁnem SCC
until u = v
}
