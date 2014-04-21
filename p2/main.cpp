#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*----------- Classes ------------*/
class Point {
    vector<int> connects;
    vector<int> flux;
    int color; // 0 is white; 1 is black; 2 is gray;
    int time;
    int father;
    int fatherPosition;
  public:
    Point () {color = 0; time = -1; father = -1;};
    void newConnect (int i) {connects.push_back(i); flux.push_back(0);}
    int getConnectsSize(){return connects.size();}
    int getConnect(int i){return connects[i];}
    int getColor(){return color;}
    int getTime(){return time;}
    int getFather(){return father;}
    int getFatherPos(){return fatherPosition;}
    int getFlux(int i){return flux[i];}
    void setColor(int c){color = c;}
    void setFather(int i, int pos){father = i; fatherPosition = pos;}
    void setTime(int i){time = i;}
    void setFlux(int i){flux[i]=1;}
    void reset(){color = 0; time = -1; father = -1;}
    void totalReset(){reset(); flux = vector<int>(flux.size(), 0); }
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
int minResult, count;
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
  		for(int i = 0; i < points[u]->getConnectsSize(); i++){
  			
  			if(points[points[u]->getConnect(i)]->getColor()==0 && points[u]->getFlux(i) == 0){
  				//printf("%i-%i: %i\n", u, points[u]->getConnect(i), points[points[u]->getConnect(i)]->getFlux(i));
  				points[points[u]->getConnect(i)]->setColor(2);
  				points[points[u]->getConnect(i)]->setTime(points[u]->getTime()+1);
  				points[points[u]->getConnect(i)]->setFather(u, i);
  				stack.push(points[u]->getConnect(i));
  			}
  		}
  		points[u]->setColor(1);
  	}
  }

  void FordFulkerson(int s,int t){
    BFS(s);
    int u;
  	while(points[t]->getTime()!=-1){
  		u=t;
        while(u != s){
          points[points[u]->getFather()]->setFlux(points[u]->getFatherPos());
          u=points[u]->getFather();
        }
        for(int i =0; (unsigned)i < points.size();i++){
        	points[i]->reset();
        }
        BFS(s);
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
  /*for(int i=0;i<n;i++) {
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

*/
  // OUTPUT

  for(int i = 0; (unsigned)i < problems.size(); i++){
  	for(int j=0; j < problems[i]->getPointsSize(); j++){
  		for(int k=j+1; k < problems[i]->getPointsSize();k++){
  			FordFulkerson(problems[i]->getPoint(j),problems[i]->getPoint(k));
  			count = 0;
			for (int o =0; o<n; o++){
			   if(points[o]->getTime()!=-1){
			   		for(int b = 0; b < points[o]->getConnectsSize(); b++){
			   			int u = points[o]->getConnect(b);
			   			if(points[u]->getTime() == -1) count++;
			   		}
				}
			}
			if(k== j+1) minResult = count;
			if(minResult > count) minResult = count;
  		}
  		
  	}
  	printf("%i\n", minResult);
  	for(int i =0; (unsigned)i < points.size();i++){
        	points[i]->totalReset();
    }

  }
  


  //FordFulkerson(0,1);
  /*for (int i =0; i<5; i++){
    for(int j = 0; j < points[i]->getConnectsSize(); j++){
  	 printf("%i: %i\n", i, points[i]->getFlux(j));
  }
	}
int count = 0;
for (int i =0; i<n; i++){
   if(points[i]->getTime()!=-1){
   		for(int j = 0; j < points[i]->getConnectsSize(); j++){
   			int u = points[i]->getConnect(j);
   			if(points[u]->getTime() == -1) count++;
   		}
   }
 }*/
 //printf("%i\n", minResult);
  return 0;
}
