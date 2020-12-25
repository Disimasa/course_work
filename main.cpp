#include <iostream>
#include "Network.h"
#include "FullyConnected.h"

int main() {
	Matrix data(4, 2);
	data << 0, 0,
					0, 1,
					1, 0,
					1, 1;
	Matrix answers(4, 1);
	answers << 0,
						 1,
						 1,
						 0;
	Network network;
	network.addLayer(FullyConnected(2));
	network.addLayer(FullyConnected(15));
	network.addLayer(FullyConnected(1));
	network.setRandomWeights();
//	network.printTopology();
//	std::cout<<network.activate(data)[0]<<std::endl;
	std::cout<<network.train(data, answers, 1, 1);
}
