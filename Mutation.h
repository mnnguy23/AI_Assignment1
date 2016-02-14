#ifndef Mutation_h
#define Mutation_h

#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

class Mutation
{
	public:
		void generateMutation(std::vector < std::vector <int> > &population);
		int getMutationX();
		int getMutationY();
	private:
		int mutationX;
		int mutationY;
};	
#endif
