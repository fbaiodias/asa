#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main () {
  vector<int> u,v;
  int n,p;

  scanf("%u %u", &n,&p);

  int pu, pv;

  for(int i=0;i<p;i++) {
    scanf("%u %u", &pu, &pv);

    u.push_back(pu);
    v.push_back(pv);
  }

  return 0;
}