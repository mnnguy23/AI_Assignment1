#include "Genetic.h"
#include "Mutation.h"

int main()
{
	Genetic population;
	Mutation mutation;
	std::vector < std::vector <int> > p;

	population.createInitialPopulation(p);
	population.printPopulation(p);

	p = mutation.generateMutation(p);
	population.printPopulation(p);

	return (0); 
}
