#include "Convolutional.h"

Convolutional::Convolutional(int width, int height, int kernelSize, double (*activationMethod)(double x, bool derivative)):
	Layer(width*height, activationMethod), kernel(kernelSize) {}

void Convolutional::setRandomWeights(Layer *nextLayer) {
	setWeights(Matrix::Random(kernel, kernel));
}
Matrix Convolutional::forward(Matrix input) {
	int newWidth = (width - kernel + 1);
	int newHeight = (height - kernel + 1);
	Matrix convLayer = Matrix::Zero(input.rows(), newHeight*newWidth);
	for (int img = 0; img < input.rows(); img++) {
		for (int row = 0; row < newHeight; row++) {
			for (int col = 0; col < newWidth; col++) {
				for (int i = 0; i < kernel - 1; i++) {
					for (int j = 0; j < kernel - 1; j++) {
						convLayer(img, row*newWidth + col) += input(img, (row+i)*width + col + j)*weights(i, j);
					}
				}
			}
		}
	}
}

	return convLayer;
}