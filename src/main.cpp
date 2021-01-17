#include <iostream> 
#include <string>
#include <sstream>
#include <cstdlib>
#include "graph/graph.hpp"

using namespace std;

vector<int> getAdjacency()
{
  string line;
  vector<int> adjacency;

  getline(cin, line);
  istringstream iss(line);

  for (string s; iss >> s;)
  {
    int value = atoi(s.c_str());

    if(value != 0)
      adjacency.push_back(value);
  }

  return adjacency;
}

void setAdjacencyCenterDistribution(int num_vaccination_center,
  vector<Graph> &graphs)
{
  // Ocorre um bug que na primeira entrada do getline()
  // ela não realiza o input das entradas. Dessa forma, adicionei essa
  // primeira entrada para evitar inconsistencia na lógica
  vector<int> adjacency = getAdjacency(); 
  for(int i = 0; i < num_vaccination_center; i++)
  {    
    adjacency = getAdjacency();

    vector<int>::iterator it;
    for(it = adjacency.begin(); it != adjacency.end(); ++it)
      graphs.at(i).addAdjacentNode(0, *it);
  }
}

void setAdjacencyVaccinationPost(int num_vaccination_post,
  int num_vaccination_center,
  vector<Graph> &graphs)
{
  for(int i = 1; i < num_vaccination_post; i++)
  {    
    vector<int> adjacency = getAdjacency();

    vector<int>::iterator it;
    for(it = adjacency.begin(); it != adjacency.end(); ++it)
    {
      if(*it != 0)
      {
        for (int j = 0; j < num_vaccination_center; j++)
          graphs.at(j).addAdjacentNode(i, *it);
      }
    }
  }
}
 
int main()
{
  int num_vaccination_center;
  int num_vaccination_post;
  int rate_incrase;
  
  scanf("%d %d %d", &num_vaccination_center,
    &num_vaccination_post,
    &rate_incrase);

  int num_nodes = 1 + num_vaccination_post;

  vector<Graph> graphs;
  
  for(int i = 0; i < num_vaccination_center; i++)
  {
    Graph graph = Graph(num_nodes, rate_incrase);
    graphs.push_back(graph);
  }
  
  setAdjacencyCenterDistribution(num_vaccination_center, graphs);
  setAdjacencyVaccinationPost(num_vaccination_post, num_vaccination_center, graphs);

  for(int i = 0; i < num_vaccination_center; i++)
  {
    graphs.at(i).DFS(0);
    printf("\n");
  }

  return 0;
}
