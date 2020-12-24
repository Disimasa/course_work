#ifndef NEURAL_NETWORK_LAYER_H
#define NEURAL_NETWORK_LAYER_H
#include <Eigen/Dense>

typedef Eigen::MatrixXd Matrix;

class Layer {
public:
	Layer(int neuronsAmountVal);
	void setWeights(Matrix weightsVal);
	virtual Matrix forward(Matrix input);
	int getNeuronsAmount();
private:
	int neuronsAmount{0};
	Matrix weights;
};


#endif //NEURAL_NETWORK_LAYER_H
