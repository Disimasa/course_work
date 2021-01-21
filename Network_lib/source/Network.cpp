#include "../headers/Network.h"
#include <iostream>
#include <fstream>

Network::~Network() {
	for (Layer * layer : layers) {
		delete layer;
	}
}

void Network::addLayer(Layer *layer) {
	layers.push_back(layer);
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
		layers[ind]->setRandomWeights(layers[ind+1]);
	}
}

void Network::recordWeights(std::string path) {
	std::ofstream out;
	out.open(path);
	if (out.is_open()) {
		out<<layers.size()-1<<std::endl;
		for (Layer *layer : layers) {
			out<<layer->getWeights().rows()<<' '<<layer->getWeights().cols()<<std::endl;
			for (int row = 0; row < layer->getWeights().rows(); row++) {
				for (int col = 0; col < layer->getWeights().cols(); col++) {
					out<<layer->getWeights()(row, col)<<' ';
				}
			}
			out<<std::endl;
		}
	}
	out.close();
}

void Network::readWeights(std::string path) {
	std::ifstream file(path);
	if (file.is_open()) {
		std::vector<Matrix> weights;
		int amount;
		file>>amount;
		for (int iter = 0; iter < amount; iter++) {
			int rows, cols;
			file >> rows>>cols;
			Matrix matrix(rows, cols);
			for (int row = 0; row<rows; row++) {
				for (int col = 0; col < cols; col++) {
					file>>matrix(row, col);
				}
			}
			weights.push_back(matrix);
		}
		setWeights(weights);
	} else {
		throw std::invalid_argument("can't find the file");
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
			layers[ind]->update(deltas[layers.size()-2-ind], activatedLayers[ind-1], activatedLayers[ind], learningRate);
		}
		layers[0]->update(deltas.back(), input, activatedLayers[0], learningRate);
	}
	return activate(input).back();
}

void Network::printTopology() {
	for (Layer *layer : layers) {
		std::cout<<layer->getNeuronsAmount()<<' ';
	}
}