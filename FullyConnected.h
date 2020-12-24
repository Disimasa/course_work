#ifndef NEURAL_NETWORK_FULLYCONNECTED_H
#define NEURAL_NETWORK_FULLYCONNECTED_H
#include "Layer.h"

class FullyConnected:public Layer {
public:
	FullyConnected(int neuronsAmountVal);
	Matrix forward(Matrix input);
};


#endif //NEURAL_NETWORK_FULLYCONNECTED_H
