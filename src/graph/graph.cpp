#include "graph.hpp"

Graph::Graph(int vertex, int increase)
{
  this->vertex = vertex;
  this->increase = increase;
  this->adjacency = new list<int>[vertex];
}
 
void Graph::addAdjacentNode(int source, int destination)
{
  this->adjacency[source].push_back(destination);
}
 
void Graph::DFSRecursive(int vertex, bool visited[])
{
  visited[vertex] = true;
  cout << vertex << " ";
 
  list<int>::iterator i;
  for (i = this->adjacency[vertex].begin();
    i != this->adjacency[vertex].end();
    ++i)
  {
    if (!visited[*i])
      DFSRecursive(*i, visited);
  }    
}

void Graph::DFS(int vertex)
{
  bool* visited = new bool[vertex];
  for (int i = 0; i < vertex; i++)
    visited[i] = false;

  DFSRecursive(vertex, visited);
}