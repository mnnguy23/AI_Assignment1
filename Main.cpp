#include "Genetic/Genetic.h"
#include "CrossOver/CrossOver.h"

using namespace std;

int main() {
  Genetic population;
  CrossOver crossoverPopulation;
  std::vector <std::vector<int> > initialPopulation = population.createInitialPopulation();
  std::vector<int> parentSelection = crossoverPopulation.crossoverSelection(7);
  crossoverPopulation.crossOver(initialPopulation, parentSelection);
  return (0); 
}