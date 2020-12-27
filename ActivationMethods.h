#ifndef NEURAL_NETWORK_ACTIVATIONMETHODS_H
#define NEURAL_NETWORK_ACTIVATIONMETHODS_H
#include <iostream>

static double sigmoid(double x, bool derivative) {
	return derivative ? x*(1-x) : 1/(1+exp(-x));
}

#endif //NEURAL_NETWORK_ACTIVATIONMETHODS_H
