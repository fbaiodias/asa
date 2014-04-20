#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*----------- Classes ------------*/
class Point {
    vector<int> connects;
    int color; // 0 is white; 1 is black; 2 is gray;
    int time;
    int father;
  public:
    Point () {};
    void newConnect (int i) {connects.push_back(i); color = 0; time = -1; father = -1;}
    int getConnectsSize(){return connects.size();}
    int getConnect(int i){return connects[i];}
    
    int getColor(){return color;}
    int getTime(){return time;}
    int getFather(){return father;}
    void setColor(int c){color = c;}
    void setFather(int i){father = i;}
    void setTime(int i){time = i;}
};

class Problem {
    vector<int> points;
  public:
    Problem () {};
    void newPoint (int i) {points.push_back(i);}
    int getPointsSize(){return points.size();}
    int getPoint(int i){return points[i];}

};

/*----------- Global Variables ------------*/
vector<Point*> points;
vector<Problem*> problems;
int n,m,h;
int garbage = 0;
queue<int> stack;
/*----------- Functions ------------*/
  void BFS(int s){
  	points[s]->setColor(2);
  	points[s]->setTime(0);
  	stack.push(s);
  	while (!stack.empty()){
  		int u = stack.front();
  		stack.pop();
  		for(int i = 0; i <= points[i]->getConnectsSize(); i++){
  			if(points[points[u]->getConnect(i)]->getColor()==0){
  				points[points[u]->getConnect(i)]->setColor(2);
  				points[points[u]->getConnect(i)]->setTime(points[u]->getTime()+1);
  				points[points[u]->getConnect(i)]->setFather(u);
  				stack.push(points[u]->getConnect(i));
  			}
  		}
  		points[u]->setColor(1);
  	}
  }
  std::vector<int> pathFinder(int s, int t){
  	std::vector<int> path;
  	int j=0;
  	BFS(s);
  	u=t;
  	while(u!=s){
	  	for(int i=0;i <= points[u]->getConnectsSize; i++){
	  		if (time > points[points[u]->getConnect[i]]->getTime()){
	  			path[j] = points[u]->getConnect[i];
	  		}
	  	}
	  	u=path[j++];
    }
    return path;

  }
  void FordFulkerson(int s,int t){
  	std::vector<int> path = pathFinder(s,t);
  	while(points[t]->getTime()!=-1){

  	}
  }

/*----------- Main ------------*/
int main () {
  garbage = scanf("%u %u", &n,&m);
  // n - number of points
  for(int i=0;i<n;i++) {
    points.push_back(new Point());
  }

  // m - number of connections
  int pu, pv;
  for(int i=0;i<m;i++) {
    garbage = scanf("%u %u", &pu, &pv);

    points[pu]->newConnect(pv);
    points[pv]->newConnect(pu);
  }

  garbage = scanf("%u", &h);
  // h - number of problems
  for(int i=0;i<h;i++) {
    int k;
    problems.push_back(new Problem());
    garbage = scanf("%u", &k);
    // k - number of points in problem
    for(int o=0;o<k;o++) {
      int p;
      garbage = scanf("%u", &p);
      problems[i]->newPoint(p);
    }
  }

  // DEBUG
  for(int i=0;i<n;i++) {
    cout << "Point " << i << "\n" << "Connects with ";
    for(int o=0; o < points[i]->getConnectsSize(); o++){
      cout << points[i]->getConnect(o) << " ";
    }
    cout << "\n\n";
  }

  for(int i=0;i<h;i++) {
    cout << "Problem " << i << "\n" << "Has points ";
    for(int o=0; o < problems[i]->getPointsSize(); o++){
      cout << problems[i]->getPoint(o) << " ";
    }
    cout << "\n\n";
  }


  // OUTPUT
  BFS(0);
  for (int i =0; i<5; i++){
  	printf("%i: %i\n", i, points[i]->getFather());
  	printf("   %i\n", points[i]->getTime());
  }
  return 0;
}
