#include "Genetic.h"
#include "Mutation.h"
#include "CrossOver.h"

int main()
{
	srand(time(0));
	
	int i = 0;
	int sMax = 0, zMax = 0;
	int crossOverRate[] =  {7, 3, 5, 9, 0};
	
	
	bool chromosomeFound = false;
	
	std::vector < std::vector <int> > p, initialP;
	std::vector < std::vector <int> > secondLastP;
	std::vector<int> rate;
	
	Genetic population;
	Mutation mutation;
	CrossOver cross;
	
	population.createInitialPopulation(p);
	initialP = p;
  double avgNumGenPerPCO[5];
	
	for(i = 0; i < 5; i++)
	{
    double avgNumGenPerPCO[5];
  	int sum = 0;
  	double numGen = 0;
    int numGenPerRun [20];
		for(int w = 0; w < 20; w++)
		{	

			rate = cross.crossoverSelection(p, crossOverRate[i]);
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
				
				secondLastP = p;
				
				p = cross.crossOver(p, rate);
				
				p = mutation.generateMutation(p);
        
				if(w == 0)
				{
					if(crossOverRate[0] == 7)
					{
						if(sMax < 1)
						{
              population.printToFile(secondLastP);
							population.printToFile(p);
						}
						sMax++;
					}
					if(crossOverRate[0] == 0)
					{
						if(zMax < 1)
						{
              population.printToFile(secondLastP);
							population.printToFile(p);
						}
						zMax++;
					}
				}
				
				chromosomeFound = population.findChromosome(p);
				numGen++;
				
			}
			
			if(w == 0 && (crossOverRate[i] == 7 || crossOverRate[i] == 0))
			{
				population.printToFile(secondLastP);
				population.printToFile(p);
			}
			
			std::cout<<"\nPerfect chromosome found!\n";
			population.printPopulation(p);
      std::cout << "Working" << std::endl;
			std::cout<<"Number of generations: "<<numGen++;
			numGenPerRun[w] = numGen;
			population.printNumberOfGeneration(numGen,crossOverRate[i]);

			cross.clearPopulation();
		}
		
		
		for(int k = 0; k < 20; k++)
		{
			std::cout<<"\nRun "<<k<<": "<<numGenPerRun[k];
			sum = numGenPerRun[k]+sum;
		}
		
		avgNumGenPerPCO[i] = sum / 20;
		std::cout<<"\nAverage number of generations per run at PCO "<<crossOverRate[i]<<" = "<<avgNumGenPerPCO[i];
    population.printData(avgNumGenPerPCO[i], crossOverRate[i]);
	}

	return (0); 
}













