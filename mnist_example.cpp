#include <iostream>
#include "Network.h"

int main() {
	Network network;
	network.addLayer(new FullyConnected(792));
	network.addLayer(new FullyConnected(792));
	network.addLayer(new FullyConnected(792));
	network.setRandomWeights();
//	network.activate()
}
