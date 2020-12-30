#ifndef NEURAL_NETWORK_FULLYCONNECTED_H
#define NEURAL_NETWORK_FULLYCONNECTED_H
#include "Layer.h"
/// Класс полносвязного слоя нейронной сети. Используется для создания перцептронов разной топологии
class FullyConnected:public Layer {
public:
	/// Конструктор принимает количество нейронов в слое и функцию активации
	FullyConnected(int neuronsAmountVal, double (*activationMethodLink)(double x, bool derivative) = sigmoid);
	void setRandomWeights(Layer *nextLayer);
	Matrix forward(Matrix input);
	Matrix back(Matrix delta, Matrix activatedLayer);
	void update(Matrix delta, Matrix activatedLayer, Matrix, double learningRate);
};


#endif //NEURAL_NETWORK_FULLYCONNECTED_H
