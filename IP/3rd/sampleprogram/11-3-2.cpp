#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
string win_src = "src";
string win_dst = "dst";

int main(int argc, char **argv)
{
  string file_src = "src_depth_wall.png"; // 入力画像のファイル名
  string file_dst = "dst.png"; // 出力画像のファイル名
  // Mat img_src = imread(file_src, 1); // 入力画像（カラー）の読み込み
  Mat img_src = imread(file_src, 0); // 入力画像（グレースケール）の読み込み

  Mat img_dst;
  if(!img_src.data) {
    cout << "error" << endl;
    return -1;
  }

  // ウインドウ生成
  namedWindow(win_src, WINDOW_AUTOSIZE);
  namedWindow(win_dst, WINDOW_AUTOSIZE);

  Mat img_max = 255 * Mat::ones(img_src.size(), img_src.type());

  vector<Mat> vec_hsv(3);
  img_src.copyTo(vec_hsv[0]); // H
  img_max.copyTo(vec_hsv[1]); // S
  img_src.copyTo(vec_hsv[2]); // V

  Mat img_hsv;
  merge(vec_hsv, img_hsv);
  cvtColor(img_hsv, img_dst, COLOR_HSV2BGR_FULL);

  imshow(win_src, img_src);
  imshow(win_dst, img_dst);

  imwrite(file_dst, img_dst);
  waitKey(0);

  return 0;
}
