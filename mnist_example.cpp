#include <iostream>
#include <fstream>
#include "Network.h"


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
	std::ifstream data_file("../train-images.idx3-ubyte", std::ios::binary);
	Matrix trainData(1000, 784);
	Matrix testData(1000, 784);
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
		for (int image = 0; image < 1000; image++) {
			for (int ind = 0; ind < rows * cols; ind++) {
				unsigned char pixel = 0;
				data_file.read((char *) &pixel, sizeof(pixel));
				trainData(image, ind) = pixel/255.0;
			}
		}
		for (int image = 0; image < 1000;image++) {
			for (int ind = 0; ind < rows*cols; ind++) {
				unsigned char pixel = 0;
				data_file.read((char *)&pixel, sizeof(pixel));
				testData(image, ind) = pixel/255.0;
			}
		}
	}
	data_file.close();
	std::ifstream answers_file("../train-labels.idx1-ubyte", std::ios::binary);
	Matrix trainAnswers(1000, 10);
	Matrix testAnswers(1000, 10);
	if (answers_file.is_open()) {
		int magic = 0, answersAmount = 0;
		answers_file.read((char *)&magic, sizeof(magic));
		answers_file.read((char *)&answersAmount, sizeof(answersAmount));
		answersAmount = intoDec(answersAmount);
		for (int answer_ind = 0; answer_ind < 1000; answer_ind++) {
			unsigned char answer = 0;
			answers_file.read((char *) &answer, sizeof(answer));
			for (int i = 0; i < 10; i++) {
				i == (int) answer ? trainAnswers(answer_ind, i) = 1 : trainAnswers(answer_ind, i) = 0;
			}
		}
		for (int answer_ind = 0; answer_ind < 1000; answer_ind++) {
			unsigned char answer = 0;
			answers_file.read((char *)&answer, sizeof(answer));
			for (int i = 0; i < 10; i++) {
				i == (int)answer ? testAnswers(answer_ind, i) = 1 : testAnswers(answer_ind, i) = 0;
			}
		}
	}
	answers_file.close();
	Network network;
	network.addLayer(new Convolutional(28, 28, 3));
	network.addLayer(new FullyConnected(676));
	network.addLayer(new FullyConnected(10));
	network.setRandomWeights();
//	std::cout<<network.activate(trainData).back();
	network.train(trainData, trainAnswers, 100, 0.8);
	auto s = network.activate(testData);
	int counter = 0;
	for (int j = 0; j < 1000; j++) {
		double max = s.back()(j, 0);
		int maxId = 0;
		int rightId = 0;
		for (int k = 0; k < 10; k++) {
			if (s.back()(j, k) > max) {
				max = s.back()(j, k);
				maxId = k;
			}
			if (testAnswers(j, k) == 1) rightId = k;
		}
		for (int k = 0; k < 10; k++) {
			s.back()(j, k) = 0;
		}
		s.back()(j, maxId) = 1;
		if (rightId != maxId) counter++;
	}
	std::cout <<"Test data error: "<< counter << std::endl<<std::endl;
}
