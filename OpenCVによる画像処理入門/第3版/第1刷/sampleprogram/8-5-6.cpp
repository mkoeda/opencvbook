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
  string file_src = "src_bin_ellipse.png"; // 入力画像のファイル名
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
  //namedWindow(win_dst, WINDOW_AUTOSIZE);

  Moments m = moments(img_src, true);
  // 面積
  double area = m.m00;
  cout << "area: " << area << endl;
  // 重心
  double x_g = m.m10 / m.m00;
  double y_g = m.m01 / m.m00;
  cout << x_g << " " << y_g << endl;
  // 主軸の角度
  double ang = 0.5 * atan2(2.0 * m.mu11, m.mu20 - m.mu02);
  cout << ang * 180.0 / M_PI << endl;

  imshow(win_src, img_src); // 入力画像を表示
  // imshow(win_dst, img_dst); // 出力画像を表示
  // imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
