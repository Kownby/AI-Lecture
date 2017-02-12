#include "Perceptron.h"

#include <assert.h>
#include <time.h>
#include <random>
#include <iostream>

Perceptron::Perceptron(int input_size)
{
	weights_.resize(input_size);
	threshold_ = -1;
}

void Perceptron::RandomizeWeights()
{
	std::mt19937 gen((unsigned)time(NULL));
	std::uniform_real_distribution<double> distribution(0, 1);

	for (int i = 0; i < weights_.size(); i++)
	{
		weights_[i] = distribution(gen);
	}
}

void Perceptron::Train(double learning_rate, const std::vector<Vector>& inputs, const std::vector<double>& outputs)
{
	assert(inputs.size() == outputs.size());

	for (int i = 0; i < inputs.size(); i++)
	{
		double output = Compute(inputs[i]);

		for (int j = 0; j < weights_.size(); j++)
		{
			double dW = learning_rate * (outputs[i] - output) * inputs[i][j];

			weights_[j] += dW;
		}

		threshold_ += learning_rate * (outputs[i] - output);
	}
}

double Perceptron::Compute(const Vector& inputs)
{
	assert(inputs.size() == weights_.size());

	double sum = 0;

	for (size_t i = 0; i < weights_.size(); ++i)
	{
		sum += inputs[i] * weights_[i];
	}
	
	return (sum + threshold_) >= 0 ? 1 : 0;
}

void Perceptron::Print()
{
	std::cout << "weights: ";

	for (int i = 0; i < weights_.size() - 1; i++)
		std::cout << weights_[i] << " ";

	std::cout << weights_[weights_.size() - 1] << std::endl;

	std::cout << "threshold: " << threshold_ << std::endl;
}