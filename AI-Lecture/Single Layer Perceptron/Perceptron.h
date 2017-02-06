#pragma once

#include <vector>

class Perceptron
{
public:
	Perceptron(const std::vector<double>& weights, double threshold);

	double Compute(const std::vector<double>& inputs);

private:
	std::vector<double> weights_;
	double threshold_;
};