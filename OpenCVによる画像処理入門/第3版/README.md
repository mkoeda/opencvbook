# 正誤表

## 未対応
|    ページ番号     |                誤                 |　             正                |
| :----------- | :-------------------------------- |:--------------------------------|
|p.89　OpenCVとPython，のプログラムの4行目|img_dst = cv2.merge((img_bgr[2],img_bgr[0],img_bgr[1]))|img_dst = cv2.merge((img_bgr[1],img_bgr[2],img_bgr[0]))|
|p.209　OpenCV と C++言語，のプログラムの2行目|
Point2f pts2[] = {Point2f(160, 240), Point2f(0, 470), Point2f(639, 479), Point2f(480, 240)};|
Point2f pts2[] = {Point2f(160, 240), Point2f(0, 479), Point2f(639, 479), Point2f(480, 240)};|