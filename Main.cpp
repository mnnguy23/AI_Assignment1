#include "Genetic.h"
#include "Mutation.h"
#include "CrossOver.h"

int main()
{
	//ofstream fout;
	//fout.open("Output.txt");
	
	int sMax = 0, zMax = 0;
	int i = 0;
	int sum = 0;
	int numGen = 0;
	int crossOverRate[] =  {7, 3, 5, 9, 0};
	int numGenPerRun [20];
	
	bool chromosomeFound = false;
	
	double avgNumGenPerPCO[5];
	
	std::vector < std::vector <int> > p, initialP;
	std::vector < std::vector <int> > secondLastP;
	std::vector<int> rate;
	
	Genetic population;
	Mutation mutation;
	CrossOver cross;
	
	population.createInitialPopulation(p);
	initialP = p;
	
	
	//Loop for # of trials
	for(int w = 0; w < 5; w++)
	{	
		rate = cross.crossoverSelection(7);
		numGen = 0;
		p = initialP;
		chromosomeFound = false;

		std::cout<<"\n"<<"\n=========================\n";
		std::cout<<"Trial #"<<w<<"\n";
		std::cout<<"=========================\n";
		
		while(chromosomeFound != true)
		{
			std::cout<<"Generation #"<<numGen<<"\n";
			population.printPopulation(p);
			if(w == 0)
			{
				if(crossOverRate[0] == 7)
				{
					if(sMax < 2)
					{
						//std::cout<<"Print to File\n";
						population.printToFile(p);
					}
					sMax++;
				}
				if(crossOverRate[0] == 0)
				{
					if(zMax < 2)
					{
						//std::cout<<"Print to File\n";
						population.printToFile(p);
					}
					zMax++;
				}
			}
			
			p = cross.crossOver(p, rate);
			//std::cout<<"Generation #"<<numGen<<" after crossover\n";
			
			p = mutation.generateMutation(p);
			//std::cout<<"Generation #"<<numGen<<" after mutation\n";
			
			//population.geneCount(p);
			chromosomeFound = population.findChromosome(p);
			numGen++;
		}
		
		std::cout<<"\nPerfect chromosome found!\n";
		population.printPopulation(p);
		std::cout<<"Number of generations: "<<numGen++;
		numGenPerRun[w] = numGen;
	}
	
	
	for(int k = 0; k < 5; k++)
	{
		sum = numGenPerRun[k] + sum;
	}
	
	avgNumGenPerPCO[i] = sum / 5;
	std::cout<<"\nAverage number of generations per run at PCO "<<crossOverRate[0]<<" = "<<avgNumGenPerPCO[0];
	
	
	
	
	
	//Loop for every PCO value
	/*for(i = 0; i< 5; i++)
	{
		rate = cross.crossoverSelection(crossOverRate[i]);
		
		//Loop for 20 runs at every PCO value
		for(int j = 0; j < 20; j++)
		{
			numGen = 0;
			population.createInitialPopulation(p);
			population.printPopulation(p);
			
			//Loop until string of ten 1s is found
			while(chromosomeFound != true)
			{
				
				//Prints first two population of run with pco = 0.7
				if(crossOverRate[i] == 7)
				{
					if(sMax < 2)
						population.printPopulation(p);
					sMax++
				}
				
				//Prints first two population of run with pco = 0.0
				if(crossOverRate[i] == 0)
				{
					if(zMax < 2)
						population.printPopulation(p);
					zMax++
				}
			
				p = cross.crossOver(p, rate);
				//std::cout<<"Generation #"<<numGen<<" after crossover\n";
				//population.printPopulation(p);
				
				p = mutation.generateMutation(p);
				//std::cout<<"Generation #"<<numGen<<" after mutation\n";
				population.printPopulation(p);
				
				//population.geneCount(p);
				chromosomeFound = population.findChromosome(p);
				
				if(chromosomeFound == false)
					secondLastP = p;
				numGen++;
			}
			
			std::cout<<"\nPerfect chromosome found!\n";
			population.printPopulation(p);
			std::cout<<"Number of generations: "<<numGen++;
			
			//Print to file
			if(crossOverRate[i] == 7)
			{
				std::cout<<"Second to last population for pco = .7\n";
				std::cout<<"=====================================\n";
				population.printPopulation(secondLastP);
				
				std::cout<<"Second to last population for pco = .7\n";
				std::cout<<"=====================================\n";
				population.printPopulation(p);
			}
			
			//Print to file
			if(crossOverRate[i] ==0)
			{
				std::cout<<"Second to last population for pco = 0\n";
				std::cout<<"=====================================\n";
				population.printPopulation(secondLastP);
				
				std::cout<<"Second to last population for pco = 0\n";
				std::cout<<"=====================================\n";
				population.printPopulation(p);
			}
			
			numGenPerRun[j] = numGen;
			numGen = 0;
			
		}
		
		for(int k = 0; k < 20; k++)
		{
			sum = numGenPerRun[k] + sum;
		}
		
		avgNumGenPerPCO[i] = sum / 20;
		
	}*/
	
	//Do something with avg values
	//avgNumGenPerRun[];
	//fout.close();

	return (0); 
}













