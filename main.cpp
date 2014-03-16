#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Person {
    int id;
    int d, low;
    vector<int> friends;
    bool imstacked=false;
    bool imstackedF=false;
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
    bool isOnStack(){return imstacked;}
    void enterStack(){imstacked=true;}
    void exitStack(){imstacked=false;}

    bool isOnStackF(){return imstackedF;}
    void enterStackF(){imstackedF=true;}
    void exitStackF(){imstackedF=false;}
};

vector<Person*> people;
vector<int> stack;
int n,p;
int visited = 0, L = 0;
int numberOfSCCs = 0;
int maxSCCSize = 0;
int privateSCCs = 0;

bool isPrivate(int n){
	int l = people[n]->getLow();
    for(int i = 0; i < people[n]->getFriends(); i++){
    	if(l != people[people[n]->getFriend(i)-1]->getLow()){return false;}
    }
    return true;
}

void tarjanVisit(int u) {
  //cout << "Visiting " << u+1 << "\n";
  people[u]->visit(visited);
  people[u]->enterStack();
  visited = visited + 1;
  stack.push_back(u+1);

  for(int i=0; i < people[u]->getFriends(); i++) {
    int v = people[u]->getFriend(i)-1;
    if (people[v]->isUnvisited() || people[v]->isOnStack() /*std::find(stack.begin(), stack.end(), (v+1))!=stack.end()*/) {
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
    int SCCSize = 0;
    //bool envy = false;
    int v = -1;

    while(u != v) {
      // Vértices retirados deﬁnem SCC
      v = stack.back();
      stack.pop_back();
      people[v-1]->exitStack();
      //if(isPrivate(v-1)) envy = true;
      //cout << v << " ";
      SCCSize=SCCSize+1;

      for(int i = 0; i< people[v-1]->getFriends();i++){
      	if(!people[people[v-1]->getFriend(i)-1]->isOnStackF()){
      		friends.push_back(v-1); 
      		people[people[v-1]->getFriend(i)-1]->enterStackF();
      	}
      }
    }

	for(int i = 0; i< friends.size();i++){
		if(people[friends[i]]->isOnStackF()){
			people[friends[i]]->exitStackF();
		}
	}
    if(SCCSize=friends.size()) privateSCCs = privateSCCs + 1;
       //cout << "\n";
    //if(envy) privateSCCs = privateSCCs+1;
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
  cout << privateSCCs << "\n";


  return 0;
}
