#ifndef Genetic_h
#define Genetic_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Genetic {

  public:
    std::vector< std::vector<int> > createInitialPopulation();
    
  private:
    std::vector < std::vector <int> > chromosomePopulation;
  };
#endif