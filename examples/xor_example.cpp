#include <iostream>
#include "../Network_lib/headers/Network.h"

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
	network.addLayer(new FullyConnected(2));
	network.addLayer(new FullyConnected(10));
	network.addLayer(new FullyConnected(1));
	network.setRandomWeights();
	std::cout<<network.train(data, answers, 5000, 1);
	std::system("pause");
}
