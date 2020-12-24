#include "Layer.h"

Layer::Layer(int neuronsAmountVal, double (*activationMethodLink)(double x, bool derivative)):
neuronsAmount(neuronsAmountVal), activationMethod(activationMethodLink) {};

void Layer::setWeights(Matrix weightsVal) {
	weights = weightsVal;
}

int Layer::getNeuronsAmount() {
	return neuronsAmount;
}


