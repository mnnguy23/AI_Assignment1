#include "Genetic/Genetic.h"
#include "CrossOver/CrossOver.h"

using namespace std;

int main() {
  Genetic population;
  CrossOver crossoverPopulation;
  std::vector <std::vector<int> > initialPopulation = population.createInitialPopulation();
  crossoverPopulation.crossOver(initialPopulation, 7);
  
  return (0); 
}