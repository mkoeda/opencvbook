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
  string file_src = "src_depth_ball.png"; // 入力画像のファイル名
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

  // セグメンテーション
  int depth_min = 206;
  int depth_max = 210;
  inRange(img_src, depth_min, depth_max, img_dst);

  // ノイズ除去（収縮・膨張）
  erode(img_dst, img_dst, Mat(), Point(-1, -1), 3);
  dilate(img_dst, img_dst, Mat(), Point(-1, -1), 3);

  // ラベリング
  Mat img_lab;
  int nlabel = connectedComponents(img_dst, img_lab);
  for(int i = 1; i < nlabel; i++) {
    Mat img_dst;
    compare(img_lab, i, img_dst, CMP_EQ); // ラベルiを抜き出し
    cout << i << " / " << (nlabel - 1) << endl;
    imwrite("dst" + to_string(i) + ".png", img_dst);
    imshow(win_src, img_src);
    imshow(win_dst, img_dst);
    waitKey(0);
  }

  return 0;
}
