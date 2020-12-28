#include "Network.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");
	std::cout<<"Введите путь до изображения:"<<std::endl;
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
				testData(row * 28 + col) = 0;
			} else {
				testData(row * 28 + col) = (255 - matrix(row, col)) / 255.0;
			}
		}
	}
	Network network;
	network.addLayer(new Convolutional(28, 28, 3));
	network.addLayer(new FullyConnected(676));
	network.addLayer(new FullyConnected(10));
	network.readWeights("./new_weights.txt");
//
	std::cout<<network.activate(testData).back();
//	cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
//	imshow("Display window", img);
	cv::waitKey(0);
}
