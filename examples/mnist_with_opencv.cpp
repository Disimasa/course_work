#include "../Network_lib/headers/Network.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include <string>

int main() {
	std::cout<<"Input the path to the image:"<<std::endl<<std::endl;
	std::string path;
	std::cin>>path;
	cv::Mat img = cv::imread(path, cv::IMREAD_GRAYSCALE);
	cv::resize(img, img, cv::Size(28, 28));
	Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> matrix;
	cv::cv2eigen(img, matrix);
	Matrix testData(1, 28*28);
	for (int row = 0; row < 28; row++) {
		for (int col = 0; col < 28; col++) {
			if (matrix(row, col) > 150) {
				matrix(row, col) = 0;
				testData(0, row * 28 + col) = 0;
			} else {
				testData(0, row * 28 + col) = (255 - matrix(row, col)) / 255.0;
			}
		}
	}
	Network network;
	network.addLayer(new Convolutional(28, 28, 3));
	network.addLayer(new FullyConnected(676));
	network.addLayer(new FullyConnected(10));
	network.readWeights("./trained_weights.txt");
	Matrix prediction = network.activate(testData).back();
	double maxVal = prediction(0, 0);
	int maxId = 0;
	for (int i = 0; i < 10; i++) {
		if (maxVal<prediction(0, i)) {
			maxVal = prediction(0, i);
			maxId = i;
		}
	}
	std::cout<<std::endl<<"There is " + std::to_string(maxId) + " on the image";
}
