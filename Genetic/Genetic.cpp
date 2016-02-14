#include "Genetic.h"

void Genetic::createInitialPopulation() {
  int m = 20, n = 10;
  
  chromosomePopulation.resize(m);
  for(int i =0; i < m; i++) {
    chromosomePopulation[i].resize(n);
  }
  
  for( int i = 0; i < m; i++) {
    for( int j = 0; j < n; j++) {
      int dna = rand() % 2;
      chromosomePopulation[i][j] = dna;
    }
  }
  
  for( int i = 0; i < m; i++) {
    for( int j = 0; j < n; j++) {
      std::cout << chromosomePopulation[i][j];
    }
    std::cout << std::endl;
  }
}