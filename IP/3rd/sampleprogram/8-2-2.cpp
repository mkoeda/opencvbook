#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
string win_src = "src";
string win_dst = "dst";
string win_mask = "mask";

int main()
{
  string file_src = "src.png"; // 入力画像のファイル名
  string file_dst = "dst.png"; // 出力画像のファイル名
  string file_mask = "mask.png"; // マスク画像のファイル名
  // Mat img_src = imread(file_src, 1); // 入力画像（カラー）の読み込み
  Mat img_src = imread(file_src, 0); // 入力画像（グレースケール）の読み込み
  Mat img_mask = imread(file_mask, 0); // マスク画像

  Mat img_dst;
  if(!img_src.data) {
    cout << "error" << endl;
    return -1;
  }

  // ウインドウ生成
  namedWindow(win_src, WINDOW_AUTOSIZE);
  namedWindow(win_dst, WINDOW_AUTOSIZE);

  img_src.copyTo(img_dst, img_mask);

  imshow(win_src, img_src); // 入力画像を表示
  imshow(win_dst, img_dst); // 出力画像を表示
  imshow(win_mask, img_mask); // マスク画像を表示
  imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
