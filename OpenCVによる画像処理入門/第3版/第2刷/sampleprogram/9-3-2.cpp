#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
string win_src = "src";
string win_bkg = "bkg";
string win_dst = "dst";

int main()
{
  string file_src = "src.jpg"; // 入力画像のファイル名
  string file_bkg = "bkg.jpg"; // 背景画像のファイル名
  string file_dst = "dst.jpg"; // 出力画像のファイル名
  Mat img_src = imread(file_src, IMREAD_GRAYSCALE); // 入力画像の読み込み
  Mat img_bkg = imread(file_bkg, IMREAD_GRAYSCALE); // 背景画像の読み込み

  Mat img_dst;
  if(!img_src.data || !img_bkg.data) {
    cout << "error" << endl;
    return -1;
  }

  // ウインドウ生成
  namedWindow(win_src, WINDOW_AUTOSIZE);
  namedWindow(win_bkg, WINDOW_AUTOSIZE);
  namedWindow(win_dst, WINDOW_AUTOSIZE);

  Mat img_fg, img_bg, img_df, img_m, img_md, img_msk;

  // 背景画像との差分画像を計算
  absdiff(img_fg, img_bg, img_df);
  // 差分画像の二値化
  threshold(img_df, img_m, 120, 255, THRESH_BINARY);
  // 膨張・収縮してマスク画像を生成
  dilate(img_m, img_md, Mat(), Point(-1, -1), 4);
  erode(img_md, img_msk, Mat(), Point(-1, -1), 4);
  // マスク画像を使って前景画像から対象を切り出す
  bitwise_and(img_fg, img_msk, img_dst);

  imshow(win_src, img_src); // 入力画像を表示
  imshow(win_bkg, img_bkg); // 背景画像を表示
  imshow(win_dst, img_dst); // 出力画像を表示
  imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
