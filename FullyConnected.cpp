#include "FullyConnected.h"
#include <iostream>

FullyConnected::FullyConnected(int neuronsAmountVal):
Layer(neuronsAmountVal) {}

Matrix FullyConnected::forward(Matrix input) {
	return (input * weights).unaryExpr([this] (double x) {return activationMethod(x, false);});
}

Matrix FullyConnected::back(Matrix delta, Matrix activatedLayer) {
	Matrix error = delta * weights.transpose();
//	std::cout<<activatedLayer.unaryExpr([this](double x) {return activationMethod(x, true);}).rows()<<' '<<activatedLayer.unaryExpr([this](double x) {return activationMethod(x, true);}).cols()<<std::endl;
//	std::cout<<error.array() * activatedLayer.unaryExpr([this](double x) {return activationMethod(x, true);}).array();
	Matrix newDelta =  error.array() * activatedLayer.unaryExpr([this](double x) {return activationMethod(x, true);}).array();
	return newDelta;
}

void FullyConnected::update(Matrix delta, Matrix activatedLayer, double learningRate) {
	std::cout<<'d';
	weights += (delta.transpose() * activatedLayer * learningRate).transpose();
}
