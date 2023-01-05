#include <iostream>
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
  // namedWindow(win_dst, WINDOW_AUTOSIZE);

  // 解像度の設定
  capture.set(CAP_PROP_FRAME_WIDTH, 640);
  capture.set(CAP_PROP_FRAME_HEIGHT, 480);

  // 解像度の確認
  capture >> img_src;
  cout << img_src.cols << " " << img_src.rows << endl;

  while(1) {
    capture >> img_src; // キャプチャ
    imshow(win_src, img_src); // 表示
    if(waitKey(1) == 'q') break;
  }

  capture.release();
  return 0;
}