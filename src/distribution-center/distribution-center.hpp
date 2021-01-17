#include <iostream>
#include <stdio.h>
#include <vector>
#ifndef __TP1_ALG___
#define __TP1_ALG__

using namespace std;

class DistributionCenter {
  private:
    int id;
    vector<int> adjacency;
 
  public:
    DistributionCenter(int id);
    
    void addAdjacentNode(int node);
    vector<int> getAdjacency();
};

#endif