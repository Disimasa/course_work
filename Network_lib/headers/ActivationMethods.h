#ifndef NEURAL_NETWORK_ACTIVATIONMETHODS_H
#define NEURAL_NETWORK_ACTIVATIONMETHODS_H
#include <iostream>

static double sigmoid(double x, bool derivative) {
	return derivative ? x*(1-x) : 1/(1+exp(-x));
}

static double relu(double x, bool derivative) {
	if (x == 0) return 0;
	else return derivative ? 1 : x;
}

#endif //NEURAL_NETWORK_ACTIVATIONMETHODS_H
