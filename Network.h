#ifndef NEURAL_NETWORK_NETWORK_H
#define NEURAL_NETWORK_NETWORK_H
#include <vector>
#include "Layer.h"
#include "FullyConnected.h"

class Network {
public:
	Network() = default;
	Network(int inputWidth, int inputHeight);
	void addLayer(Layer *layer);
	void setWeights(std::vector<Matrix> weights);
	void setRandomWeights();
	std::vector<Matrix> activate(Matrix input);
	Matrix train(Matrix input, Matrix answers, int epochs, double learningRate);
	void printTopology();
private:
	std::vector<Layer*> layers;
	int inputWidth = 0;
	int inputHeight = 0;
};


#endif //NEURAL_NETWORK_NETWORK_H
