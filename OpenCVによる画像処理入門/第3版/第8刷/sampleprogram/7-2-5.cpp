#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
string win_src = "src";
string win_dst1 = "dst1";
string win_dst2 = "dst2";

int main()
{
  string file_src = "src.png"; // 入力画像のファイル名
  string file_dst1 = "dst1.png"; // 出力画像のファイル名
  string file_dst2 = "dst2.png"; // 出力画像のファイル名
  Mat img_src = imread(file_src, IMREAD_COLOR); // 入力画像（カラー）の読み込み

  Mat img_dst1, img_dst2;
  if(!img_src.data) {
    cout << "error" << endl;
    return -1;
  }

  // ウインドウ生成
  namedWindow(win_src, WINDOW_AUTOSIZE);
  namedWindow(win_dst1, WINDOW_AUTOSIZE);
  namedWindow(win_dst2, WINDOW_AUTOSIZE);

  GaussianBlur(img_src, img_dst1, Size(11, 11), 1); // Gaussian オペレータ
  bilateralFilter(img_src, img_dst2, 10, 50, 1); // バイラテラルオペレータ

  imshow(win_src, img_src); // 入力画像を表示
  imshow(win_dst1, img_dst1); // 出力画像を表示
  imshow(win_dst2, img_dst2); // 出力画像を表示
  imwrite(file_dst1, img_dst1); // 処理結果の保存
  imwrite(file_dst2, img_dst2); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
