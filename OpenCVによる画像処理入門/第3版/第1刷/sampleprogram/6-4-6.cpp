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

  int width = img_src.cols, height = img_src.rows;
  img_dst = Mat::zeros(height, width, img_src.type());

  int thresh = 128;
  int error = 0;
  for(int y = 0; y < height - 1; y++) {
    for(int x = 0; x < width - 1; x++) {
      int v = img_src.data[y * width + x] + error;
      if(v < thresh) {
        img_dst.data[y * width + x] = 0;
        error = v;
      } else {
        img_dst.data[y * width + x] = 255;
        error = v - 255;
      }
    }
  }

  imshow(win_src, img_src); // 入力画像を表示
  imshow(win_dst, img_dst); // 出力画像を表示
  imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
