#include "Genetic.h"

void Genetic::createInitialPopulation(std::vector< std::vector<int> > &chromosomePopulation)
{
	int m = 20, n = 10;

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

bool Genetic::findChromosome(std::vector< std::vector<int> > chromosomePopulation)	
{
	int m = 20, n = 10;
	int count = 0;

	for (int i =0; i <m; i++)
	{
		count = 0;
		for(int j = 0; j<n; j++)
		{
			if(chromosomePopulation[i][j] == 1)
			{
				count ++;
				
				if(count==10 && j ==9)
				{
					return true;
				}
			}
			else if(chromosomePopulation[i][j] != 0)
			{
				j = 20;
			}
		}
	}
	return false;
}

void Genetic::printPopulation(std::vector< std::vector<int> > &chromosomePopulation)
{
	int m = 20, n = 10;
	int fitnessV = 0;
	
	for( int i = 0; i < m; i++)
	{
		fitnessV = 0;
		
		std::cout<<i<<": ";
		for (int j = 0; j <10; j++)
		{
			//std::cout<<chromosomePopulation[i][j];
			if(chromosomePopulation[i][j] == 1)
				fitnessV++;
		}
		std::cout<<" | Fitness Value: "<<fitnessV<<"\n";
	}
}

void Genetic::printToFile(std::vector<std::vector<int> > &chromosomePopulation) {
	int fitnessV = 0;
	
	std::ofstream outfile;
	outfile.open("test.txt", std::ios_base::app);
	for( int i = 0; i < 20; i++)
	{
		fitnessV = 0;
		
		outfile<<i<<": ";
		for(int j = 0; j < 10; j++)
		{
			outfile << chromosomePopulation[i][j];
			if(chromosomePopulation[i][j] == 1)
				fitnessV++;
		}
		outfile <<" | Fitness Value: "<<fitnessV<< std::endl;
	}
  outfile << std::endl;
	outfile.close() ;
}

void Genetic::printData(double avgNumGenPerPCO, int crossOverRate)
{
	std::ofstream outfile;
	outfile.open("AverageNumberOfGenerations.txt", std::ios_base::app);

		outfile<<"Average number of generations at PCO" <<crossOverRate<<": "<<avgNumGenPerPCO<< std::endl;

	outfile.close();
}

void Genetic::printNumberOfGeneration(int numberOfGeneration, int crossOverRate) {
  std::ofstream outfile;
  
  outfile.open("NumberOfGenerationPerPco.txt", std::ios_base::app);
  
  outfile <<"The number of generation: " << numberOfGeneration << " in pCo: " << crossOverRate << std::endl;
  
}














