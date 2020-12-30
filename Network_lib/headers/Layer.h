#ifndef NEURAL_NETWORK_LAYER_H
#define NEURAL_NETWORK_LAYER_H
#include <Eigen/Dense>
typedef Eigen::MatrixXd Matrix;
#include "ActivationMethods.h"

/// Абстрактный класс слоев нейронной сети
class Layer {
public:
	Layer(int neuronsAmountVal, double (*activationMethod)(double x, bool derivative) = sigmoid);
	/// Устанавливает значение весов для этого слоя
	void setWeights(Matrix weightsVal);
	/// Устанавливает случайные значения весов для этого слоя
	virtual void setRandomWeights(Layer *nextLayer) = 0;
	/// Функция отвечает за активацию слоя и возвращает вычисленные значения нейронов след. слоя
	virtual Matrix forward(Matrix) = 0;
	/// Функция отвечает за расчет дельты при обратном распостранении ошибки
	virtual Matrix back(Matrix, Matrix) = 0;
	/// Функция обновляет значения весов этого слоя
	virtual void update(Matrix, Matrix, Matrix, double) = 0;
	/// Возвращает количество нейронов этого слоя
	int getNeuronsAmount();
	/// Метод активации, используемый в данном слое
	double (*activationMethod)(double x, bool derivative);
	/// Возвращает матрицу весов этого слоя
	Matrix getWeights();
protected:
	Matrix weights;
	int neuronsAmount{0};
};

#endif //NEURAL_NETWORK_LAYER_H
