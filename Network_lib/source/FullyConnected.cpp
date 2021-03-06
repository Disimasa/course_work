#include "../headers/FullyConnected.h"
#include <iostream>

FullyConnected::FullyConnected(int neuronsAmountVal, double (*activationMethodLink)(double x, bool derivative)):
Layer(neuronsAmountVal, activationMethodLink) {}

void FullyConnected::setRandomWeights(Layer *nextLayer) {
	setWeights(Matrix::Random(neuronsAmount, nextLayer->getNeuronsAmount()));
}

Matrix FullyConnected::forward(Matrix input) {
	return (input * weights).unaryExpr([this] (double x) {return activationMethod(x, false);});
}

Matrix FullyConnected::back(Matrix delta, Matrix activatedLayer) {
	Matrix error = delta * weights.transpose();
	Matrix newDelta =  error.array() * activatedLayer.unaryExpr([this](double x) {return activationMethod(x, true);}).array();
	return newDelta;
}

void FullyConnected::update(Matrix delta, Matrix activatedLayer, Matrix, double learningRate) {
	weights += (delta.transpose() * activatedLayer * learningRate).transpose();
}
