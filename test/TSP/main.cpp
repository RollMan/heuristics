#include "hill-climb.h"

struct calcFitness {
  int operator()(const vector< int > graph, const vector<vector<int>> domain){
    int res = 0;
    for(int i = 0; i < graph.size(); i++){
      int j = (i + 1) % graph.size();
      res += domain[i][j];
    }
  }
  return res;
};

struct calcNeighborhoods {
  std::mt19937 mt;
  calcNeighborhoods(){
    mt = std::mt19937{std::random_device{}()};
  }
  vector<int> operator()(const vector<int>& graph){
    std::uniform_int_distribution<int> rand(0, graph.size()-1);
    int a = rand(mt), b = rand(mt);
    swap(graph[a], graph[b]);
    return graph;
  }
};

struct terminateCondition {
  int number_of_iteration;
  int cnt;
  terminateCondition(int number_of_iteration): cnt(0), number_of_iteration(number_of_iteration) {}
  bool operator()(const vector<int>& graph){
    cnt++;
    if(cnt >= number_of_iteration) return true;
    return false;
  }
};

int main(void){
  cout 
}
