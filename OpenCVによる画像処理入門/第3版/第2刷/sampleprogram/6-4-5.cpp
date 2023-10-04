#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <ctime>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
string win_src = "src";
string win_dst = "dst";

int main()
{
  string file_src = "src.png"; // 入力画像のファイル名
  string file_dst = "dst.png"; // 出力画像のファイル名
  Mat img_src = imread(file_src, IMREAD_GRAYSCALE); // 入力画像（グレースケール）の読み込み

  Mat img_dst;
  if(!img_src.data) {
    cout << "error" << endl;
    return -1;
  }

  // ウインドウ生成
  namedWindow(win_src, WINDOW_AUTOSIZE);
  namedWindow(win_dst, WINDOW_AUTOSIZE);

  srand((unsigned int)time(NULL)); // 乱数の初期化
  int width = img_src.cols, height = img_src.rows;
  img_dst = Mat::zeros(height, width, img_src.type());

  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      int v = img_src.data[y * width + x];
      if(v < rand() % 256) img_dst.data[y * width + x] = 0;
      else img_dst.data[y * width + x] = 255;
    }
  }

  imshow(win_src, img_src); // 入力画像を表示
  imshow(win_dst, img_dst); // 出力画像を表示
  imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
