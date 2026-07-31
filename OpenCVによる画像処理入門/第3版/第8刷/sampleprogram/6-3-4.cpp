#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
string win_src = "src";
string win_dst = "dst";
string win_hst = "hst";

int main()
{
  string file_src = "src.png"; // 入力画像のファイル名
  string file_dst = "dst.png"; // 出力画像のファイル名
  string file_hst = "hst.png"; // 出力画像のファイル名
  Mat img_src = imread(file_src, IMREAD_GRAYSCALE); // 入力画像（グレースケール）の読み込み

  Mat img_dst;
  if(!img_src.data) {
    cout << "error" << endl;
    return -1;
  }

  // ウインドウ生成
  namedWindow(win_src, WINDOW_AUTOSIZE);
  namedWindow(win_dst, WINDOW_AUTOSIZE);
  namedWindow(win_hst, WINDOW_AUTOSIZE);

  // ルックアップテーブル生成
  double gamma = 2.0;
  Mat lut(256, 1, CV_8U);
  for(int i = 0; i < 256; i++) {
    lut.data[i] = (unsigned char)(255.0 * pow(i / 255.0, 1.0 / gamma));
  }
  // ルックアップテーブル変換
  LUT(img_src, lut, img_dst);

  // ヒストグラム表示用，256×100ピクセル，0（黒）で初期化
  Mat img_hst;
  img_hst = Mat::zeros(Size(256, 100), CV_8UC1);

  const int hdims[] = {256}; // 次元ごとの度数分布のサイズ
  const float ranges[] = {0, 256};
  const float *hranges[] = {ranges}; // 次元ごとのビンの下限上限

  // 1チャンネル画像の度数分布を計算
  Mat hist;
  calcHist(&img_src, 1, 0, Mat(), hist, 1, hdims, hranges);
  // 度数の最大値を取得
  double hist_min, hist_max;
  minMaxLoc(hist, &hist_min, &hist_max);

  // ヒストグラムを白線で描画
  for(int i = 0; i <= 255; i++) {
    int v = saturate_cast<int>(hist.at<float>(i));
    cout << i << " " << v << endl;
    line(img_hst, Point(i, img_hst.rows), Point(i, img_hst.rows - img_hst.rows * (v / hist_max)), Scalar(255, 255, 255));
  }

  imshow(win_src, img_src); // 入力画像を表示
  imshow(win_dst, img_dst); // 出力画像を表示
  imshow(win_hst, img_hst); // 出力画像を表示
  imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
