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
  string file_src = "src_bin_circle.png"; // 入力画像のファイル名
  string file_dst = "dst.png"; // 出力画像のファイル名
  Mat img_src = imread(file_src, IMREAD_GRAYSCALE); // 入力画像（グレースケール）の読み込み

  Mat img_dst;
  if(!img_src.data) {
    cout << "error" << endl;
    return -1;
  }

  // ウインドウ生成
  namedWindow(win_src, WINDOW_AUTOSIZE);
  // namedWindow(win_dst, WINDOW_AUTOSIZE);

  vector<vector<Point>> contours;
  findContours(img_src, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
  double area = contourArea(Mat(contours[0])); // 面積
  double perimeter = arcLength(Mat(contours[0]), true); // 周囲長
  double roundness = 4 * M_PI * area / perimeter / perimeter; // 円形度
  cout << area << " " << perimeter << " " << roundness << endl;

  imshow(win_src, img_src); // 入力画像を表示
  // imshow(win_dst, img_dst); // 出力画像を表示
  // imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
