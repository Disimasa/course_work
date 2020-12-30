#ifndef NEURAL_NETWORK_LAYER_H
#define NEURAL_NETWORK_LAYER_H
#include <Eigen/Dense>
#include "ActivationMethods.h"
typedef Eigen::MatrixXd Matrix;

class Layer {
public:
	Layer(int neuronsAmountVal, double (*activationMethod)(double x, bool derivative) = sigmoid);
	void setWeights(Matrix weightsVal);
	virtual void setRandomWeights(Layer *nextLayer) = 0;
	virtual Matrix forward(Matrix) = 0;
	virtual Matrix back(Matrix, Matrix) = 0;
	virtual void update(Matrix, Matrix, Matrix, double) = 0;
	int getNeuronsAmount();
	double (*activationMethod)(double x, bool derivative);
	Matrix getWeights();
protected:
	Matrix weights;
	int neuronsAmount{0};
};


#endif //NEURAL_NETWORK_LAYER_H