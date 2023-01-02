#define _CRT_SECURE_NO_WARNINGS
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

  img_dst = Mat::zeros(img_src.size(), img_src.type());

  for(int i = 1; i <= 255; i += 5) {
    Mat img_tmp;
    cout << i << endl;
    compare(img_src, i, img_tmp, CMP_EQ);
    bitwise_or(img_tmp, img_dst, img_dst);
  }

  imshow(win_src, img_src);
  imshow(win_dst, img_dst);

  imwrite(file_dst, img_dst);
  waitKey(0);

  return 0;
}
