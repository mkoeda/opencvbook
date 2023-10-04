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
  string file_src = "src.png"; // 入力画像のファイル名
  string file_dst = "dst.png"; // 出力画像のファイル名
  Mat img_src = imread(file_src, IMREAD_COLOR); // 入力画像（カラー）の読み込み

  Mat img_dst;
  if(!img_src.data) {
    cout << "error" << endl;
    return -1;
  }

  // ウインドウ生成
  namedWindow(win_src, WINDOW_AUTOSIZE);
  namedWindow(win_dst, WINDOW_AUTOSIZE);

  Point2f pts1[] = {Point2f(0, 0), Point2f(0, 479), Point2f(639, 479), Point2f(639, 0)};
  Point2f pts2[] = {Point2f(160, 240), Point2f(0, 479), Point2f(639, 479), Point2f(480, 240)};

  // 射影変換行列を計算
  Mat perspective_matrix = getPerspectiveTransform(pts1, pts2);

  // 射影変換
  warpPerspective(img_src, img_dst, perspective_matrix, img_src.size(), INTER_CUBIC);

  imshow(win_src, img_src); // 入力画像を表示
  imshow(win_dst, img_dst); // 出力画像を表示
  imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
