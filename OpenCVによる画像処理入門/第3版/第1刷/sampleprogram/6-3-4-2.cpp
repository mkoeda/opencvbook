#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
  // 画像読み込み
  string file_src = "src.png";
  Mat img_src = imread(file_src, 1);

  int gamma = 1;

  // ウインドウ生成
  namedWindow("src", WINDOW_AUTOSIZE);
  namedWindow("dst", WINDOW_AUTOSIZE);
  // トラックバーの生成
  createTrackbar("gamma", "dst", &gamma, 10);
  // 入力画像を表示
  imshow("src", img_src);

  while(1) {
    // トラックバーの値を取得
    int gamma = getTrackbarPos("gamma", "dst") + 1;

    // ガンマ補正
    Mat img_dst;
    Mat lut(256, 1, CV_8U);
    for(int i = 0; i < 256; i++) {
      lut.data[i] = (unsigned char)(255.0 * pow(i / 255.0, 1.0 / gamma));
    }
    LUT(img_src, lut, img_dst);

    // 出力画像を表示
    imshow("dst", img_dst);

    // qキーで終了
    if(waitKey(1) == 'q') break;
  }
  return 0;
}