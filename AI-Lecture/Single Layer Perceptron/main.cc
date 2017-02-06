#include <iostream>

#include "Perceptron.h"

int main()
{
	Perceptron* and_perceptron = new Perceptron({ 0.5, 0.5 }, 0.6);

	std::cout << "1 AND 0 = " << and_perceptron->Compute({ 1, 0 }) << std::endl
		<< "0 AND 0 = " << and_perceptron->Compute({ 0, 0 }) << std::endl
		<< "1 AND 1 = " << and_perceptron->Compute({ 1, 1 }) << std::endl;

	Perceptron* or_perceptron = new Perceptron({ 0.5, 0.5 }, 0.5);

	std::cout << "1 OR 0 = " << or_perceptron->Compute({ 1, 0 }) << std::endl
		<< "0 OR 0 = " << or_perceptron->Compute({ 0, 0 }) << std::endl
		<< "1 OR 1 = " << or_perceptron->Compute({ 1, 1 });

	delete and_perceptron;
	delete or_perceptron;
}