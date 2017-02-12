#pragma once

#include <vector>

using Vector = std::vector<double>;

class Perceptron
{
public:
	Perceptron(int input_size);

	void RandomizeWeights();

	void Train(double learning_rate, const std::vector<Vector>& inputs, const std::vector<double>& outputs);

	double Compute(const Vector& inputs);

	void Print();

private:
	std::vector<double> weights_;
	double threshold_;
};