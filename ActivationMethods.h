#ifndef NEURAL_NETWORK_ACTIVATIONMETHODS_H
#define NEURAL_NETWORK_ACTIVATIONMETHODS_H

static double sigmoid(double x, bool derivative) {
	return derivative ? sigmoid(x, false)*(1-sigmoid(x, false)) : 1/(1+exp(-x));
}

#endif //NEURAL_NETWORK_ACTIVATIONMETHODS_H
