#include <functional>
#include <vector>

template <typename T, typename S>
T hillClimb(const S initial_value, std::function<T(S)> calcFitness, std::function<std::vector<S>(S)> calcNeighborhoods, std::function<bool(S)> terminateCondition){
  S state = initial_value;
  T best_fitness = calcFitness(state);
  while(terminateCondition(state) == false){
    std::vector<S> neighborhoods = calcNeighborhoods(state);
    for(const auto& neighbor: neighborhoods){
      T fitness = calcFitness(neighbor);
      if(fitness < best_fitness){
        best_fitness = fitness;
        state = neighbor;
      }
    }
  }
  return best_fitness;
}
