#ifndef NEURAL_NETWORK_CONVOLUTIONAL_H
#define NEURAL_NETWORK_CONVOLUTIONAL_H
#include "Layer.h"

class Convolutional: public Layer {
public:
	Convolutional(int neuronsAmountVal, int kernelSize = 3, double (*activationMethod)(double x, bool derivative) = sigmoid);
	void setRandomWeights(Layer *nextLayer);
//		Matrix forward(Matrix input);
//	Matrix back(Matrix delta, Matrix activatedLayer);
//	void update(Matrix delta, Matrix activatedLayer, double learningRate);
private:
	int kernel = 0;
};


#endif //NEURAL_NETWORK_CONVOLUTIONAL_H