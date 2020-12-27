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

void Network::setRandomWeights() {
	for (int ind = 0; ind < layers.size() - 1;ind++) {
		layers[ind]->setWeights(Matrix::Random(layers[ind]->getNeuronsAmount(), layers[ind+1]->getNeuronsAmount()));
	}
}

std::vector<Matrix> Network::activate(Matrix input) {
	std::vector<Matrix> activatedLayers;
	Matrix previousLayer = input;
	for (int ind = 0; ind < layers.size()-1;ind++) {
		previousLayer = layers[ind]->forward(previousLayer);
		activatedLayers.push_back(previousLayer);
	}
	return activatedLayers;
}

Matrix Network::train(Matrix input, Matrix answers, int epochs, double learningRate) {
	for (int epoch = 0; epoch < epochs; epoch++) {
		std::vector<Matrix> activatedLayers = activate(input);
		Matrix outputError = answers - activatedLayers.back();
		std::cout<<outputError.unaryExpr([](double x) {return x*x;}).sum()/(2*input.rows())<<std::endl;
		std::cout<<"-----------"<<std::endl;
		std::vector<Matrix> deltas;
		deltas.push_back(outputError.array() * activatedLayers.back().unaryExpr(
				[this] (double x) {return layers.back()->activationMethod(x, true);}).array());
		for (int ind = layers.size()-2; ind >0;ind--) {
			deltas.push_back(layers[ind]->back(deltas[layers.size()-2-ind], activatedLayers[ind-1]));
		}
		for (int ind = layers.size()-2; ind > 0; ind--) {
			layers[ind]->update(deltas[layers.size()-2-ind], activatedLayers[ind-1], learningRate);
		}
		layers[0]->update(deltas.back(), input, learningRate);
	}
	return activate(input).back();
}

void Network::printTopology() {
	for (Layer *layer : layers) {
		std::cout<<layer->getNeuronsAmount()<<' ';
	}
}