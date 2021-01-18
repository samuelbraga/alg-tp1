#include "graph.hpp"

Graph::Graph(int vertex, int increase)
{
  this->length = vertex;
  this->increase = increase;
  this->adjacency = new list<int>[ this->length];
  vector<int> temperature(this->length);
  this->temperature = temperature;
  this->cycle = false;
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
    this->result.push_back(vertex);
  
    list<int>::iterator i;
    for (i = this->adjacency[vertex].begin();
      i != this->adjacency[vertex].end();
      ++i)
    {
      if(visited[*i])
        this->cycle = true;
      else if (!visited[*i])
      {
        this->temperature[*i] = temperature;
        DFSRecursive(*i, visited);
      }
    }  
  }  
}

void Graph::DFS(int vertex)
{
  bool* visited = new bool[this->length];
  for (int i = 0; i < this->length; i++)
    visited[i] = false;

  this->temperature[vertex] = initialTemperature + increase;
  DFSRecursive(vertex, visited);
}

vector<int> Graph::getResult()
{
  set<int> adjacency(this->result.begin(), this->result.end());
  this->result.assign(adjacency.begin(), adjacency.end());
  return this->result;
}

bool Graph::getCycle()
{
  return this->cycle;
}