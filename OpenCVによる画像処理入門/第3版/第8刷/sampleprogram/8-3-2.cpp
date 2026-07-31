#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
string win_src = "src";
string win_dst = "dst";

int main()
{
  string file_src = "src_bin_noise1000.png"; // 入力画像のファイル名
  string file_dst = "dst.png"; // 出力画像のファイル名
  Mat img_src = imread(file_src, IMREAD_GRAYSCALE); // 入力画像（グレースケール）の読み込み

  Mat img_dst;
  if(!img_src.data) {
    cout << "error" << endl;
    return -1;
  }

  // ウインドウ生成
  namedWindow(win_src, WINDOW_AUTOSIZE);
  namedWindow(win_dst, WINDOW_AUTOSIZE);

  Mat element4 = (Mat_<uchar>(3, 3) << 0, 1, 0, 1, 1, 1, 0, 1, 0); // 4 近傍
  Mat element8 = (Mat_<uchar>(3, 3) << 1, 1, 1, 1, 1, 1, 1, 1, 1); // 8 近傍
  // dilate(img_src, img_dst, element8, Point(-1,-1), 1);
  erode(img_src, img_dst, element4, Point(-1, -1), 1);

  imshow(win_src, img_src); // 入力画像を表示
  imshow(win_dst, img_dst); // 出力画像を表示
  imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
