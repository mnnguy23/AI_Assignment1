#ifndef CrossOver_h
#define CrossOver_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class CrossOver {
  public:
    std::vector<int> crossoverSelection(int crossOverRate);
    void crossOver (std::vector< std::vector<int> >, std::vector<int> crossOverselector);
};
#endif