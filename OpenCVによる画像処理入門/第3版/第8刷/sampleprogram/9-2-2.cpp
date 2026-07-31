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

  Mat img_g1, img_mskg, img_msk, img_mskn, img_s1m, img_s2m;
  // 入力画像1を濃淡画像に変換
  cvtColor(img_src1, img_g1, COLOR_BGR2GRAY);
  // マスク画像生成のための2値化
  threshold(img_g1, img_mskg, 200, 255, THRESH_BINARY_INV);
  // マスク画像 ( カラー ) 生成
  vector<Mat> channels;
  channels.push_back(img_mskg);
  channels.push_back(img_mskg);
  channels.push_back(img_mskg);
  merge(channels, img_msk);
  // 入力画像 1 からマスク画像の部分だけを切り出す ( 切り出し画像 1 の生成 )
  bitwise_and(img_src1, img_msk, img_s1m);
  // マスク画像の反転
  bitwise_not(img_msk, img_mskn);
  // 入力画像 2 からマスク画像の反転部分だけを切り出す ( 切り出し画像 2 の生成 )
  bitwise_and(img_src2, img_mskn, img_s2m);
  // 切り出し画像 1 と切り出し画像 2 を合成
  bitwise_or(img_s1m, img_s2m, img_dst);

  imshow(win_src1, img_src1); // 入力画像1を表示
  imshow(win_src2, img_src2); // 入力画像2を表示
  imshow(win_dst, img_dst); // 出力画像を表示
  imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
