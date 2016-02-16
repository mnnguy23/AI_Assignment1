#include "Genetic/Genetic.h"
#include "CrossOver/CrossOver.h"
#include "Mutation/Mutation.h"

using namespace std;

int main() {
  Genetic population;
  CrossOver crossoverPopulation;
  Mutation mutant;
  std::vector< std::vector<int> > generation;
  std::vector <std::vector<int> > initialPopulation = population.createInitialPopulation();
  std::vector<int> parentSelection = crossoverPopulation.crossoverSelection(7);
  generation = crossoverPopulation.crossOver(initialPopulation, parentSelection);
  generation = mutant.generateMutation(generation);
  return (0); 
}