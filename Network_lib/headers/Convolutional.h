#ifndef NEURAL_NETWORK_CONVOLUTIONAL_H
#define NEURAL_NETWORK_CONVOLUTIONAL_H
#include "Layer.h"
/// Класс сверточного слоя нейронной сети
///
/// Чаще всего используется для обработки изображений, данная реализация использует valid метод для обработки изображения
class Convolutional: public Layer {
public:
	/// Конструктор принимает размер изображения, размер ядра и функцию активации
	Convolutional(int width, int height, int kernelSize = 3, double (*activationMethod)(double x, bool derivative) = sigmoid);
	void setRandomWeights(Layer *nextLayer);
	Matrix forward(Matrix input);
	Matrix back(Matrix delta, Matrix activatedLayer);
	void update(Matrix delta, Matrix, Matrix previousLayer, double learningRate);
private:
	int width = 0;
	int height = 0;
	int kernel = 0;
};


#endif //NEURAL_NETWORK_CONVOLUTIONAL_H
