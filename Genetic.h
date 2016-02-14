#ifndef Genetic_h
#define Genetic_h

#include <ctime>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Genetic {

	public:
		void createInitialPopulation(std::vector< std::vector<int> > &chromosomePopulation);
		void printPopulation(std::vector< std::vector<int> > &chromosomePopulation);
	};
#endif
