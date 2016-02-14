#include "Genetic.h"

void Genetic::createInitialPopulation(std::vector< std::vector<int> > &chromosomePopulation)
{
	int m = 20, n = 10;
	srand(time(0));

	chromosomePopulation.resize(m);

	for(int i =0; i < m; i++)
	{
		chromosomePopulation[i].resize(n);
	}

	for( int i = 0; i < m; i++)
	{
		//std::cout<<i<<": ";
		for( int j = 0; j < n; j++) 
	{
		int dna = rand() % 2;
		//std::cout<<dna;
		chromosomePopulation[i][j] = dna;
	}
		//std::cout<<"\n";
	}

}

void Genetic::printPopulation(std::vector< std::vector<int> > &chromosomePopulation)
{
	int m = 20, n = 10;
	
	for( int i = 0; i < m; i++)
	{
		std::cout<<i<<": ";
		for (int j = 0; j <10; j++)
		{
			std::cout<<chromosomePopulation[i][j];
		}
		std::cout<<"\n";
	}
}
