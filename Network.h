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
	void printTopology();
private:
	std::vector<Layer*> layers;
};


#endif //NEURAL_NETWORK_NETWORK_H
