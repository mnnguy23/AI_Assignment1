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

	/* Counts the number of times "1" appears in a row */

void Genetic::geneCount(std::vector< std:: vector<int> > chromosomePopulation)
{
	int m = 20, n = 10;
	int b = 20;
	int count[20];

	for(int a = 0; a<b; a++)
	{
		count[a] = 0;
	}

	for(int i = 0; i < m; i++)
	{		
		for(int j =0; j<10; j++)
		{	
			if(chromosomePopulation[i][j] == 1)
			{
				count[i]++;
			}
		}
	}

	for(int c = 0; c < m; c++)
	{
		std::cout<<c<<": "<<count[c]<< "\n";
	}
}

void Genetic::findChromosome(std::vector< std::vector<int> > chromosomePopulation)	
{
	int m = 20, n = 10;
	int count = 0;

	for (int i =0; i <m; i++)
	{
		 count = 0;
		for(int j = 0; j<10; j++)
		{
			if(chromosomePopulation[i][j] == 1)
			{
				count ++;
				if(count==10 && j == 9)
				{
					std::cout<<"chromosome is present \n";
				}
			}
			else if(chromosomePopulation[i][j] != 0)
			{
				j = 20;
			}
		}
	}
}