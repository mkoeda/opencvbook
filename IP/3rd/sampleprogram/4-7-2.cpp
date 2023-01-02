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
  Mat img_src;
  Mat img_dst;
  VideoCapture capture(0); // カメラオープン
  if(!capture.isOpened()) {
    cout << "error" << endl;
    return -1;
  }

  // ウインドウ生成
  namedWindow(win_src, WINDOW_AUTOSIZE);
  namedWindow(win_dst, WINDOW_AUTOSIZE);

  while(1) {
    capture >> img_src; // カメラ映像の読み込み

    // ここに核となる処理を記述する
    flip(img_src, img_dst, 0); // 垂直反転

    imshow(win_src, img_src); // 入力画像を表示
    imshow(win_dst, img_dst); // 出力画像を表示
    if(waitKey(1) == 'q') break; // q キーで終了
  }

  capture.release();
  return 0;
}