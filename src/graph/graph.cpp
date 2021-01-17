#include "graph.hpp"

Graph::Graph(int vertex, int increase)
{
  this->vertex = vertex;
  this->increase = increase;
  this->adjacency = new list<int>[vertex];
  vector<int> temperature(this->vertex);
  this->temperature = temperature;
}
 
void Graph::addAdjacentNode(int source, int destination)
{
  this->adjacency[source].push_back(destination);
}
 
void Graph::DFSRecursive(int vertex, bool visited[])
{
  if(temperature.at(vertex) <= limitTemperature)
  {
    int temperature = this->temperature[vertex] + increase;
  
    visited[vertex] = true;
    cout << vertex << " ";
    cout << this->temperature[vertex] << "; ";
  
    list<int>::iterator i;
    for (i = this->adjacency[vertex].begin();
      i != this->adjacency[vertex].end();
      ++i)
    {
      if (!visited[*i])
      {
        this->temperature[*i] = temperature;
        DFSRecursive(*i, visited);
      }
    }  
  }  
}

void Graph::DFS(int vertex)
{
  bool* visited = new bool[vertex];
  for (int i = 0; i < vertex; i++)
    visited[i] = false;
  
  printf("\n\n");
  this->temperature[vertex] = initialTemperature + increase;
  DFSRecursive(vertex, visited);
}