#include "Network.h"
#include <iostream>

void Network::addLayer(FullyConnected layer) {
	layers.push_back(&layer);
}

void Network::setWeights(std::vector<Matrix> weights) {
	if (weights.size() != layers.size() - 1) {
		throw std::invalid_argument("Your must set weights for all layers except the last");
	}
	for (int ind = 0; ind < weights.size(); ind++) {
		layers[ind]->setWeights(weights[ind]);
	}
}

void Network::printTopology() {
	for (Layer *layer : layers) {
		std::cout<<layer->getNeuronsAmount()<<' ';
	}
}