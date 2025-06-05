#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	// Check if the image file exists using ifstream
	ifstream file("C:\\Users\\Smarth Kaushal\\OneDrive\\Desktop\\demo.jpeg");
	if (!file) {
		cout << "Could not open the file!" << endl;
		return -1;
	}

	// Load the image
	Mat input_image = imread("C:\\Users\\Smarth Kaushal\\OneDrive\\Desktop\\demo.jpeg");

	// Check if the image was loaded successfully
	if (input_image.empty()) {
		cerr << "Error: Could not open or find the image!" << endl;
		return -1;
	}
	// Create a destination image
	Mat blurredImage;

	// Apply Gaussian blur
	GaussianBlur(input_image, blurredImage, Size(15, 15), 0);

	// Display the original and blurred images
	imshow("Original Image", input_image);
	imshow("Blurred Image", blurredImage);

	// Wait for a key press indefinitely
	waitKey(0);
	return 0;
}
