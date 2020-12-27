#include "Convolutional.h"

Convolutional::Convolutional(int neuronsAmountVal, int kernelSize, double (*activationMethod)(double x, bool derivative)):
	Layer(neuronsAmountVal, activationMethod), kernel(kernelSize) {}

void Convolutional::setRandomWeights(Layer *nextLayer) {
	setWeights(Matrix::Random(kernel, kernel));
}
//Matrix Convolutional::forward(Matrix input) {
//	Matrix convLayer = Matrix::Zero();
//}