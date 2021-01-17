#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
#include <set>
#ifndef __TP1_ALG___
#define __TP1_ALG__

using namespace std;

const int initialTemperature = -90;
const int limitTemperature = -60;

class Graph {
  private:
    int vertex;
    vector<int> temperature;
    vector<int> result;
    list<int>* adjacency;
    int increase;
    bool cycle;
  
    void DFSRecursive(int vertex, bool visited[]);
 
  public:
    Graph(int vertex, int increase);
    
    void addAdjacentNode(int source, int destination);
    vector<int> getResult();
    bool getCycle();
    void DFS(int vertex);
};

#endif