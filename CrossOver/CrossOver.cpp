#include "CrossOver.h"

std::vector<int> CrossOver::crossoverSelection(int crossOverRate) {
  int rate = (20 - (20 - 2*crossOverRate ));
  std::vector<int> shuffler;
  
  for(int i = 0; i < rate; i++) {
    shuffler.push_back(i);
  }
  
  std::random_shuffle(shuffler.begin(), shuffler.end());
  
  return shuffler;
}

void CrossOver::crossOver (std::vector< std::vector<int> >, std::vector<int> crossOverselector) {}
