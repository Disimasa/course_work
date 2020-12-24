#include "FullyConnected.h"

FullyConnected::FullyConnected(int neuronsAmountVal):
Layer(neuronsAmountVal) {}

Matrix FullyConnected::forward(Matrix input) {
	return input * weights;
}
