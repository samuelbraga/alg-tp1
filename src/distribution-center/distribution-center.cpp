#include "distribution-center.hpp"

DistributionCenter::DistributionCenter(int id)
{
  this->id = id;
}
    
void DistributionCenter::addAdjacentNode(int node)
{
  this->adjacency.push_back(node);
}

vector<int> DistributionCenter::getAdjacency()
{
  return this->adjacency;
}