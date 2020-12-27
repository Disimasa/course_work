#include "Convolutional.h"

Convolutional::Convolutional(int neuronsAmountVal, double (*activationMethod)(double x, bool derivative), int kernelSize):
	Layer(neuronsAmountVal, activationMethod), kernel(kernelSize) {}

//Matrix Convolutional::forward(Matrix input) {
//	Matrix convLayer = Matrix::Zero();
//}