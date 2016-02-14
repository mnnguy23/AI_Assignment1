#ifndef CrossOver_h
#define CrossOver_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class CrossOver {
  public:
    std::vector<int> crossoverSelection(int crossOverRate);
    void crossOver (std::vector< std::vector<int> >population, std::vector<int> crossOverselector);
    std::vector< std::vector<int> > crossoverMask(std::vector< std::vector<int> > population, std::vector<int> parentSelection);
    int addToPopulationFromShuffler(int counter, std::vector< std::vector<int> > sibling);
    void addToPopulationFromRemaining(std::vector< std::vector<int> > population, int counter);
  private:
    std::vector< std::vector<int> > newPopulation;
    std::vector<int> remainingPopulation;
};
#endif