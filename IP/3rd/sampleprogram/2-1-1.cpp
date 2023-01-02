#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
  Mat img_src = Mat::zeros(Size(640, 480), CV_8UC3);
  imshow("src", img_src);
  waitKey(0);
  return 0;
}
