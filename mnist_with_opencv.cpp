#include "Network.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>

int main() {
	cv::Mat img = cv::imread("ex.png", cv::IMREAD_GRAYSCALE);
	cv::resize(img, img, cv::Size(28, 28));
	Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> matrix;
	cv::cv2eigen(img, matrix);
	Matrix testData(1, 28*28);
	for (int row = 0; row < 28; row++) {
		for (int col = 0; col < 28; col++) {
			testData(row*28 + col) = matrix(row, col);
		}
	}
	std::cout<<testData<<std::endl<<std::endl;
//	Network network;
//	network.addLayer(new Convolutional(28, 28, 3));
//	network.addLayer(new FullyConnected(676));
//	network.addLayer(new FullyConnected(10));
//	network.readWeights("./weights.txt");
//
//	std::cout<<network.activate(matrix).back();
//	cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
//	imshow("Display window", img);
	cv::waitKey(0);
}
