#ifndef NEURAL_NETWORK_FULLYCONNECTED_H
#define NEURAL_NETWORK_FULLYCONNECTED_H
#include "Layer.h"

class FullyConnected:public Layer {
public:
	FullyConnected(int neuronsAmountVal, double (*activationMethodLink)(double x, bool derivative) = sigmoid);
	void setRandomWeights(Layer *nextLayer);
	Matrix forward(Matrix input);
	Matrix back(Matrix delta, Matrix activatedLayer);
	void update(Matrix delta, Matrix activatedLayer, Matrix, double learningRate);
};


#endif //NEURAL_NETWORK_FULLYCONNECTED_H
