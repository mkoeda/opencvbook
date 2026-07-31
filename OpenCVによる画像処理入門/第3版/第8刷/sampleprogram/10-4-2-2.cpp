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

  // 回転： 45[deg],  スケーリング： 1.0[ 倍 ]
  float angle = 45.0, scale = 1.0;

  // 回転中心：画像の中心
  Point2f center(img_src.cols * 0.5, img_src.rows * 0.5);

  // 以上の条件から 2 次元の回転行列を計算
  Mat affine_matrix = getRotationMatrix2D(center, angle, scale);

  // アフィン変換を行う
  warpAffine(img_src, img_dst, affine_matrix, img_src.size(), INTER_CUBIC);

  imshow(win_src, img_src); // 入力画像を表示
  imshow(win_dst, img_dst); // 出力画像を表示
  imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
