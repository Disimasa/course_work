#include <iostream>
#include "Network.h"
#include "FullyConnected.h"

int main() {
	Network network;
	network.addLayer(FullyConnected(10));
	network.addLayer(FullyConnected(15));
	network.setWeights(std::vector<Matrix> {Matrix()});
	network.printTopology();
}
