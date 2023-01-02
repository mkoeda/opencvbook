#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
  string file_src = "src.png";
  Mat img_gray = imread(file_src, 0);
  Mat img_src = imread(file_src, 1);
  namedWindow("src", WINDOW_AUTOSIZE);
  namedWindow("gray", WINDOW_AUTOSIZE);

  int x = 10, y = 50, v = 255, r = 255, g = 255, b = 0;

  // グレースケール画像の場合
  cout << (int)img_gray.at<uchar>(y, x) << endl;
  img_gray.at<uchar>(y, x) = 255;
  cout << (int)img_gray.at<uchar>(y, x) << endl;

  // カラー画像の場合
  cout << img_src.at<Vec3b>(y, x) << endl;
  img_src.at<Vec3b>(y, x) = Vec3b(b, g, r);
  cout << img_src.at<Vec3b>(y, x) << endl;

  imshow("src", img_src);
  imshow("gray", img_gray);
  waitKey(0);
  return 0;
}