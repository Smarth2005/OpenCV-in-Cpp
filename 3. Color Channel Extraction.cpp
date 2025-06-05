#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	// Check if the image file exists using ifstream
	ifstream file("C:\\Users\\Smarth Kaushal\\OneDrive\\Desktop\\butterfly.jpeg");
	if (!file) {
		cout << "File not found!" << endl;
		return -1;
	}

	// Load the image from file
	Mat image = imread("C:\\Users\\Smarth Kaushal\\OneDrive\\Desktop\\butterfly.jpeg", IMREAD_COLOR);
	
	// Check if the image was loaded successfully
	if (image.empty()) {
		cout << "Could not open or find the image!" << endl;
		return -1;
	}
	
	// Split the image into its 3 separate BGR channels
	vector<Mat> channels(3); // std::vector to hold the channels, cv::Mat for each channel
	split(image, channels);  // Use OpenCV split() to decompose the image into B, G, R channels

	// Display the individual channels (optional, for debugging purposes)
	imshow("Original Image", image);
	imshow("Blue Channel",  channels[0]);
	imshow("Green Channel", channels[1]);
	imshow("Red Channel",   channels[2]);

	// Wait for a key press indefinitely
	waitKey(0);
	return 0;
}
