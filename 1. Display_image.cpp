#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
    // Console log to indicate program start
    cout << "Hello World!\n";

    // Step 1: Check if the image file exists using ifstream
    ifstream file("C:\\Users\\Smarth Kaushal\\OneDrive\\Desktop\\radhakrishna.jpg");
    if (!file) {
        cerr << "File does not exist!" << endl;
        return -1;
    }
    else {
        cout << "File opened successfully!" << endl;
    }

    // Step 2: Load the image using OpenCV's imread()
    Mat image = imread("C:\\Users\\Smarth Kaushal\\OneDrive\\Desktop\\radhakrishna.jpg");

    // Step 3: Validate if the image was loaded correctly
    if (image.empty()) {
        cerr << "Could not open or find the image!" << endl;
        cin.get(); // Pause to let user see the error message
        return -1;
    }
    cout << "Image loaded successfully. Size = " << image.size() << endl;

    // Step 4: Display the image in a window
    imshow("Display Image", image);

    // Step 5: Wait for a key press before exiting
    waitKey(0);
    return 0;
}



