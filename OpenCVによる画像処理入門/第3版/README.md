# 正誤表

## 第1～5刷
| ページ番号 | 誤 | 正 |
| :----------- | :-------------------------------- |:--------------------------------|
|p.171<br>C言語プログラムの9行目|// 結果は label[][] に入れる|// 結果は label[] に入れる|
|p.172<br>C言語プログラムの24行目|int xdx = x + dx[k], ydy = x + dy[k];|int xdx = x + dx[k], ydy = y + dy[k];|
|p.172<br>C言語プログラムの25行目|if(xdx >= 0 && ydy >= 0 && xdx < h && ydy < w && label[xdx * w + ydy] != 0) {|if(xdx >= 0 && ydy >= 0 && xdx < w && ydy < h && label[ydy * w + xdx] != 0) {|
|p.172<br>C言語プログラムの26行目|list[count] = table[label[xdx * w + ydy]];|list[count] = table[label[ydy * w + xdx]];|
|p.173<br>C言語プログラムの71行目|if(k2 <= MAXVALUE) {|if(k2 <= TABLESIZE) {|
|p.173<br>C言語プログラムの75行目|// MAXVALUE より大きなラベル値は捨てる|// TABLESIZE より大きなラベル値は捨てる|

## 第1刷
| ページ番号 | 誤 | 正 |
| :----------- | :-------------------------------- |:--------------------------------|
|p.89<br>OpenCVとPython，のプログラムの4行目|img_dst = cv2.merge((img_bgr[2],img_bgr[0],img_bgr[1]))|img_dst = cv2.merge((img_bgr[1],img_bgr[2],img_bgr[0]))|
|p.209<br>OpenCV と C++言語，のプログラムの2行目|Point2f pts2[] = {Point2f(160, 240), Point2f(0, 470), Point2f(639, 479), Point2f(480, 240)};|Point2f pts2[] = {Point2f(160, 240), Point2f(0, 479), Point2f(639, 479), Point2f(480, 240)};|

