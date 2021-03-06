#include <iostream>
#include <fstream>
#include "../Network_lib/headers/Network.h"


int intoDec (int x) //from 32bit
{
	unsigned char q1, q2, q3, q4;

	q1 = x & 255;
	q2 = (x >> 8) & 255;
	q3 = (x >> 16) & 255;
	q4 = (x >> 24) & 255;

	return ((int)q1 << 24) + ((int)q2 << 16) + ((int)q3 << 8) + q4;
}

int main() {
	std::ifstream data_file("../train_data/train-images.idx3-ubyte", std::ios::binary);
	Matrix trainData(60000, 784);
	if (data_file.is_open())
	{
		int imagesAmount = 0, magic = 0, rows = 0, cols = 0;
		data_file.read((char *)&magic, sizeof(magic));
		data_file.read((char *)&imagesAmount, sizeof(imagesAmount));
		imagesAmount = intoDec(imagesAmount);
		data_file.read((char *)&rows, sizeof(rows));
		rows = intoDec(rows);
		data_file.read((char *)&cols, sizeof(cols));
		cols = intoDec(cols);
		for (int image = 0; image < 60000; image++) {
			for (int ind = 0; ind < rows * cols; ind++) {
				unsigned char pixel = 0;
				data_file.read((char *) &pixel, sizeof(pixel));
				trainData(image, ind) = pixel/255.0;
			}
		}
	}
	data_file.close();
	std::ifstream answers_file("../train_data/train-labels.idx1-ubyte", std::ios::binary);
	Matrix trainAnswers(60000, 10);
	if (answers_file.is_open()) {
		int magic = 0, answersAmount = 0;
		answers_file.read((char *)&magic, sizeof(magic));
		answers_file.read((char *)&answersAmount, sizeof(answersAmount));
		answersAmount = intoDec(answersAmount);
		for (int answer_ind = 0; answer_ind < 60000; answer_ind++) {
			unsigned char answer = 0;
			answers_file.read((char *) &answer, sizeof(answer));
			for (int i = 0; i < 10; i++) {
				i == (int) answer ? trainAnswers(answer_ind, i) = 1 : trainAnswers(answer_ind, i) = 0;
			}
		}
	}
	answers_file.close();
	Network network;
	network.addLayer(new Convolutional(28, 28, 3));
	network.addLayer(new FullyConnected(676));
	network.addLayer(new FullyConnected(10));

	network.setRandomWeights();
	network.train(trainData, trainAnswers, 500, 0.0015);
	network.recordWeights("../weights/trained_weights.txt");
	std::system("pause");
}
