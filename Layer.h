#ifndef NEURAL_NETWORK_LAYER_H
#define NEURAL_NETWORK_LAYER_H
#include <Eigen/Dense>
#include "ActivationMethods.h"
typedef Eigen::MatrixXd Matrix;

class Layer {
public:
	Layer(int neuronsAmountVal, double (*activationMethod)(double x, bool derivative) = sigmoid);
	void setWeights(Matrix weightsVal);
	virtual Matrix forward(Matrix input) = 0;
	virtual Matrix back(Matrix delta, Matrix activatedLayer) = 0;
	virtual void update(Matrix delta, Matrix activatedLayer, double learningRate) = 0;
	int getNeuronsAmount();
	double (*activationMethod)(double x, bool derivative);
protected:
	Matrix weights;
	int neuronsAmount{0};
};


#endif //NEURAL_NETWORK_LAYER_H
