#include <iostream> 
#include <string>
#include <sstream>
#include <cstdlib>
#include "graph/graph.hpp"
#include "distribution-center/distribution-center.hpp"

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
  vector<DistributionCenter> &centers)
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
      centers.at(i).addAdjacentNode(*it);
  }
}

void setAdjacencyVaccinationPost(int num_vaccination_post, Graph &graphs)
{
  for(int i = 1; i < num_vaccination_post; i++)
  {    
    vector<int> adjacency = getAdjacency();

    vector<int>::iterator it;
    for(it = adjacency.begin(); it != adjacency.end(); ++it)
    {
      if(*it != 0)
      {
        graphs.addAdjacentNode(i, *it);
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

  int num_node = num_vaccination_post + 1;

  Graph graph = Graph(num_node, rate_incrase);
  vector<DistributionCenter> centers;
  
  for(int i = 1; i <= num_vaccination_center; i++)
  {
    DistributionCenter center = DistributionCenter(i);
    centers.push_back(center);
  }
  
  setAdjacencyCenterDistribution(num_vaccination_center, centers);
  setAdjacencyVaccinationPost(num_node, graph);

  for(int i = 0; i < num_vaccination_center; i++)
  {
    vector<int> adjacency = centers.at(i).getAdjacency();

    vector<int>::iterator it;
    for(it = adjacency.begin(); it != adjacency.end(); ++it)
      graph.DFS(*it);
    }

  vector<int> result = graph.getResult();

  cout << result.size();
  printf("\n");

  if(result.size() == 0)
  {
    cout << "*";
  }
  else
  {
    for (vector<int>::iterator i = result.begin();
    i != result.end();
    ++i)
      cout << *i << " ";
  }  

  printf("\n");

  bool cycle = graph.getCycle();
  (cycle) ? cout << 1 : cout << 0;
  printf("\n");

  return 0;
}
