#include "Perceptron.h"

#include <assert.h>

Perceptron::Perceptron(const std::vector<double>& weights, double threshold)
	: weights_(weights), threshold_(threshold)
{
}

double Perceptron::Compute(const std::vector<double>& inputs)
{
	assert(inputs.size() == weights_.size());

	double sum = 0;

	for (size_t i = 0; i < weights_.size(); ++i)
	{
		sum += inputs[i] * weights_[i];
	}

	if (sum >= threshold_)
		return 1;
	else
		return 0;
}