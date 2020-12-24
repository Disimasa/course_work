#include "Layer.h"

Layer::Layer(int neuronsAmountVal):
neuronsAmount(neuronsAmountVal) {};

void Layer::setWeights(Matrix weightsVal) {
	weights = weightsVal;
}

int Layer::getNeuronsAmount() {
	return neuronsAmount;
}


