#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
  // 640x480の黒い画像
  Mat img_src = Mat::zeros(Size(640, 480), CV_8UC3);

  // 点(0, 0)と点(640, 480)を結ぶ太さ5の黄色の線分
  line(img_src, Point(0, 0), Point(640, 480), Scalar(0, 255, 255), 5);
  // 点(200, 50)と点(300, 50)を結ぶ太さ5の黄色の矢印
  arrowedLine(img_src, Point(200, 50), Point(300, 50), Scalar(0, 255, 255), 5);
  // 左上座標(100, 150)，幅50，高さ150，太さ2の赤色の矩形
  rectangle(img_src, Rect(100, 150, 50, 150), Scalar(0, 0, 255), 2);
  // 左上座標(50, 350)，幅200，高さ50，塗りつぶしの赤色の矩形
  rectangle(img_src, Rect(50, 350, 200, 50), Scalar(0, 0, 255), -1);
  // 中心座標(320, 240)，半径100，太さ3の青色の円
  circle(img_src, Point(320, 240), 100, Scalar(255, 0, 0), 3);
  // 中心座標(500, 100)，半径50，塗りつぶしの青色の円
  circle(img_src, Point(500, 100), 50, Scalar(255, 0, 0), -1);
  // 中心座標(550, 250)，幅100，高さ50，太さ3の45度傾いた青色の楕円
  ellipse(img_src, RotatedRect(Point(550, 250), Size(100, 50), 45), Scalar(255, 0, 0), 3);
  // 中心座標(550, 250)，長径100，短径50，太さ3の45度傾いた青色の半円
  ellipse(img_src, Point(550, 250), Size(100, 50), 45, 0, 180, Scalar(255, 0, 0), 3);
  // 左下座標(300, 450), 倍率3，太さ5の水色の文字列123
  putText(img_src, "123", Point(300, 450), 0, 3, Scalar(255, 255, 0), 5);
  // 様々な形状の大きさ10，太さ2の緑色のマーカ
  drawMarker(img_src, Point(50, 20), Scalar(0, 255, 0), MARKER_CROSS, 10, 2);
  drawMarker(img_src, Point(70, 20), Scalar(0, 255, 0), MARKER_TILTED_CROSS, 10, 2);
  drawMarker(img_src, Point(90, 20), Scalar(0, 255, 0), MARKER_STAR, 10, 2);
  drawMarker(img_src, Point(110, 20), Scalar(0, 255, 0), MARKER_DIAMOND, 10, 2);
  drawMarker(img_src, Point(130, 20), Scalar(0, 255, 0), MARKER_SQUARE, 10, 2);
  drawMarker(img_src, Point(150, 20), Scalar(0, 255, 0), MARKER_TRIANGLE_UP, 10, 2);
  drawMarker(img_src, Point(170, 20), Scalar(0, 255, 0), MARKER_TRIANGLE_DOWN, 10, 2);
  // 表示
  namedWindow("src", WINDOW_AUTOSIZE);
  imshow("src", img_src);
  // キー入力待ち
  waitKey(0);

  return 0;
}