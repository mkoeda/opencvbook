#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
string win_src1 = "src1";
string win_src2 = "src2";
string win_dst = "dst";

int main()
{
  string file_src1 = "src1.png"; // 入力画像1のファイル名
  string file_src2 = "src2.png"; // 入力画像2のファイル名
  string file_dst = "dst.png"; // 出力画像のファイル名
  Mat img_src1 = imread(file_src1, IMREAD_COLOR); // 入力画像1の読み込み
  Mat img_src2 = imread(file_src2, IMREAD_COLOR); // 入力画像2の読み込み

  Mat img_dst;
  if(!img_src1.data || !img_src2.data) {
    cout << "error" << endl;
    return -1;
  }

  // ウインドウ生成
  namedWindow(win_src1, WINDOW_AUTOSIZE);
  namedWindow(win_src2, WINDOW_AUTOSIZE);
  namedWindow(win_dst, WINDOW_AUTOSIZE);

  addWeighted(img_src1, 0.5, img_src2, 0.5, 0.0, img_dst);

  imshow(win_src1, img_src1); // 入力画像1を表示
  imshow(win_src2, img_src2); // 入力画像2を表示
  imshow(win_dst, img_dst); // 出力画像を表示
  imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
