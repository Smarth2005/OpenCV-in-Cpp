/*
  @file VideoPlayer.cpp
  @brief Simple video player using OpenCV. Plays a video file or opens webcam if no file provided.
  
  Usage:
    VideoPlayer <video_file> --window="Window Name"
  
  Example:
    VideoPlayer my_video.mp4 --window="My Video"
    VideoPlayer --window="Webcam View"
  
  Note:
    Audio is not supported as OpenCV handles only video frames.
 */

#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

using namespace std;
using namespace cv;

// Command-line argument keys
const char* keys =
{
    "{help h usage ? | | Print this message.}"
    "{@video        | | Video file to play. If not provided, webcam will be used.}"
    "{window w      | Video Window | Name of the display window.}"
};

int main(int argc, const char** argv)
{
    // Parse command-line arguments
    CommandLineParser parser(argc, argv, keys);
    parser.about("OpenCV Video Player (file or webcam)");

    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

    string videoFile = parser.get<string>("@video");
    string windowName = parser.get<string>("window");

    if (windowName.empty()) {
        windowName = "Video Window";
    }

    // Create a window
    namedWindow(windowName, WINDOW_AUTOSIZE);

    // Open video file or webcam
    VideoCapture cap;
    if (!videoFile.empty()) {
        cap.open(videoFile);
    } else {
        cap.open(0);  // Default camera
    }

    if (!cap.isOpened()) {
        cerr << "Error: Could not open video file or camera." << endl;
        return -1;
    }

    // Read and display frames
    Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        imshow(windowName, frame);
        if (waitKey(30) >= 0) break;  // Exit on any key press
    }

    destroyAllWindows();
    return 0;
}
