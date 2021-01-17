#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
#ifndef __TP1_ALG___
#define __TP1_ALG__

using namespace std;

class Graph {
  private:
    int vertex;
    vector<int> temperature;
    list<int>* adjacency;
    int increase;
  
    void DFSRecursive(int vertex, bool visited[]);
 
  public:
    Graph(int vertex, int increase);
    
    void addAdjacentNode(int source, int destination);
    void DFS(int vertex);
};

#endif