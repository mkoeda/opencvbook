#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
string win_src1 = "src1";
string win_src2 = "src2";
string win_src3 = "src3";
string win_dst = "dst";

int main()
{
  string file_src1 = "src1_fd.jpg"; // 入力画像1のファイル名
  string file_src2 = "src2_fd.jpg"; // 入力画像2のファイル名
  string file_src3 = "src3_fd.jpg"; // 入力画像3のファイル名
  string file_dst = "dst.jpg"; // 出力画像のファイル名
  Mat img_src1 = imread(file_src1, IMREAD_GRAYSCALE); // 入力画像1の読み込み
  Mat img_src2 = imread(file_src2, IMREAD_GRAYSCALE); // 入力画像2の読み込み
  Mat img_src3 = imread(file_src3, IMREAD_GRAYSCALE); // 入力画像3の読み込み

  Mat img_dst;
  if(!img_src1.data || !img_src2.data || !img_src3.data) {
    cout << "error" << endl;
    return -1;
  }

  // ウインドウ生成
  namedWindow(win_src1, WINDOW_AUTOSIZE);
  namedWindow(win_src2, WINDOW_AUTOSIZE);
  namedWindow(win_src3, WINDOW_AUTOSIZE);
  namedWindow(win_dst, WINDOW_AUTOSIZE);

  Mat img_df1, img_df2, img_df1b, img_df2b, img_m, img_md, img_msk;
  // 画像 A と B の差分画像を計算
  absdiff(img_src1, img_src2, img_df1);
  // 画像 B と C の差分画像を計算
  absdiff(img_src2, img_src3, img_df2);
  // それぞれの差分画像を2値化
  threshold(img_df1, img_df1b, 30, 255, THRESH_BINARY);
  threshold(img_df2, img_df2b, 30, 255, THRESH_BINARY);
  // 2値化された差分画像の共通部分を取得
  bitwise_and(img_df1b, img_df2b, img_m);
  // 膨張・収縮してマスク画像を生成
  dilate(img_m, img_md, Mat(), Point(-1, -1), 3);
  erode(img_md, img_msk, Mat(), Point(-1, -1), 3);
  // マスク画像を使って画像 B から対象を切り出す
  bitwise_and(img_src2, img_msk, img_dst);

  imshow(win_src1, img_src1); // 入力画像1を表示
  imshow(win_src2, img_src2); // 入力画像2を表示
  imshow(win_src3, img_src3); // 入力画像3を表示
  imshow(win_dst, img_dst); // 出力画像を表示
  imwrite(file_dst, img_dst); // 処理結果の保存

  waitKey(0); // キー入力待ち
  return 0;
}
