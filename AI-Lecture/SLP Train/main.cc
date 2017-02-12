#include "Perceptron.h"

#include <iostream>

int main()
{
	Perceptron* perceptron = new Perceptron(2);

	perceptron->RandomizeWeights();

	std::vector<Vector> inputs = {
		{0, 0},
		{1, 0},
		{0, 1},
		{1, 1}
	};

	std::vector<double> outputs = {
		0,
		1,
		1,
		1
	};

	for (int i = 0; i < 1000; i++)
	{
		perceptron->Train(0.03, inputs, outputs);
	}

	perceptron->Print();

	std::cout << perceptron->Compute({ 1, 0 }) << std::endl
		<< perceptron->Compute({ 1, 1 });

	delete perceptron;
}