#ifndef NEURAL_NETWORK_LAYER_H
#define NEURAL_NETWORK_LAYER_H
#include <Eigen/Dense>

typedef Eigen::MatrixXd Matrix;

class Layer {
public:
	Layer(int neuronsAmountVal);
	void setWeights(Matrix weightsVal);
	virtual Matrix forward(Matrix input) = 0;
	int getNeuronsAmount();
protected:
	Matrix weights;
	int neuronsAmount{0};
};


#endif //NEURAL_NETWORK_LAYER_H
