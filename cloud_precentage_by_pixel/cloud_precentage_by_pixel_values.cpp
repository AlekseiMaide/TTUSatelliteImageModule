#include <iostream>
#include <string>
#include <sstream>
#include <random>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


void cloudPrecentage(cv::Mat &image) {
    cv::Mat_<cv::Vec3b>::iterator it = image.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::iterator itend = image.end<cv::Vec3b>();

    int count{};
    int total{};
    for (; it != itend; ++it) {
        total++;
        if ((*it)[0] > 225 && (*it)[1] > 225 && (*it)[2] > 225) {
            count++;
        }
    }
    std::cout << count << "\n";
    std::cout << total / 3 << "\n";
    std::cout << "Cloud precentage: " << (float)count / (float)(total / 3) * 100 << "%";
}


int main() {

    cv::Mat image = cv::imread("../data/Testphoto.jpg", CV_LOAD_IMAGE_UNCHANGED);
    //cv::Mat image = cv::imread("../data/cloudsfromspace.jpg", CV_LOAD_IMAGE_UNCHANGED);
    if (image.empty()) {
        std::cout << "!!! Failed imread()" << std::endl;
        return -1;
    }
    ////cv::Mat result;
    cloudPrecentage(image);
    cv::resize(image, image, cv::Size(image.cols / 2, image.rows / 2));
    cv::namedWindow("Display frame", CV_WINDOW_AUTOSIZE);
    cv::resizeWindow("Display frame", 500, 500);
    cv::imshow("Display frame", image);

    cv::waitKey(0);

    return 0;
}