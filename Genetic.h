#ifndef Genetic_h
#define Genetic_h

#include <ctime>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Genetic {

	public:
		void createInitialPopulation(std::vector< std::vector<int> > &chromosomePopulation);
		void printPopulation(std::vector< std::vector<int> > &chromosomePopulation);
    void printToFile(std::vector<std::vector<int> >&chromosomePopulation);
    void geneCount(std::vector< std:: vector<int> > chromosomePopulation);
    bool findChromosome(std::vector< std::vector<int> > chromosomePopulation);
	};
#endif
