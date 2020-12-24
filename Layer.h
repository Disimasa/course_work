#ifndef NEURAL_NETWORK_LAYER_H
#define NEURAL_NETWORK_LAYER_H
#include <Eigen/Dense>

typedef Eigen::MatrixXd Matrix;

class Layer {
public:
	Layer(int neuronsAmountVal, double (*activationMethod)(double x, bool derivative) = sigmoid);
	void setWeights(Matrix weightsVal);
	virtual Matrix forward(Matrix input) = 0;
	int getNeuronsAmount();
	static double sigmoid(double x, bool derivative) {
		return derivative ? sigmoid(x, false)*(1-sigmoid(x, false)) : 1/(1+exp(-x));
	}
protected:
	Matrix weights;
	double (*activationMethod)(double x, bool derivative);
	int neuronsAmount{0};
};


#endif //NEURAL_NETWORK_LAYER_H
