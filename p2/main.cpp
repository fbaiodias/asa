#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

/*----------- Classes ------------*/
class Point {
    vector<int> connects;
  public:
    Point () {};
    void newConnect (int i) {connects.push_back(i);}
    int getConnectsSize(){return connects.size();}
    int getConnect(int i){return connects[i];}
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

/*----------- Functions ------------*/


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

  return 0;
}
