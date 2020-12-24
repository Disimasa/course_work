#ifndef NEURAL_NETWORK_NETWORK_H
#define NEURAL_NETWORK_NETWORK_H
#include <vector>
#include "Layer.h"
#include "FullyConnected.h"

class Network {
public:
	Network() = default;
	void addLayer(FullyConnected layer);
	void setWeights(std::vector<Matrix> weights);
	std::vector<Matrix> activate(Matrix input);
	void printTopology();
	static float sigmoid(float x, bool derivative = false) {
		return derivative ? sigmoid(x)*(1-sigmoid(x)) : 1/(1+exp(-x));
	}
private:
	std::vector<Layer*> layers;
};


#endif //NEURAL_NETWORK_NETWORK_H