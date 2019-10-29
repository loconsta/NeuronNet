#include "random.h"
#include <random>

RandomNumbers::RandomNumbers(unsigned long int s){
	if (s == 0){
		std::random_device rd;
		seed = rd();
		}
		rng = std::mt19937(seed);
	}

void RandomNumbers::uniform_double(std::vector<double>& vec, double lower, double upper){
	std::uniform_real_distribution<> u(lower, upper);
	for (auto& val : vec) val = u(rng);
	}

double RandomNumbers::uniform_double(double lower, double upper){
	std::uniform_real_distribution<> u(lower, upper);
	return u(rng);
	}
	
void RandomNumbers::normal(std::vector<double>& vec, double mean, double sd){
	std::normal_distribution<> n(mean, sd);
	for (auto& val : vec) val = n(rng);
	}

double RandomNumbers::normal(double mean, double sd){
	std::normal_distribution<> n(mean, sd);
	return n(rng);
	}


void RandomNumbers::poisson(std::vector<int>& vec, double mean){
	std::poisson_distribution<> p(mean);
	for (auto& val : vec) val = p(rng);
	}

int RandomNumbers::poisson(double mean){
	std::poisson_distribution<> p(mean);
	return p(rng);
	}


