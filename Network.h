#ifndef NEURAL_NETWORK_NETWORK_H
#define NEURAL_NETWORK_NETWORK_H
#include <vector>
#include "Layer.h"
#include "FullyConnected.h"
#include "Convolutional.h"

class Network {
public:
	Network() = default;
	void addLayer(Layer *layer);
	void setWeights(std::vector<Matrix> weights);
	void setRandomWeights();
	std::vector<Matrix> activate(Matrix input);
	Matrix train(Matrix input, Matrix answers, int epochs, double learningRate);
	void printTopology();
private:
	std::vector<Layer*> layers;
};


#endif //NEURAL_NETWORK_NETWORK_H
