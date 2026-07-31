#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  const int width = 9, height = 9;
  unsigned char image[height][width]; // 画像用配列
  string filename = "output.pgm"; // ファイル名
  ofstream fout(filename); // ファイルを開く

  // 画像生成
  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      // ここに処理を記述する
    }
  }

  // ファイル出力
  fout << "P2" << endl;
  fout << width << " " << height << endl;
  fout << "255" << endl;
  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      fout << (int)image[y][x] << " ";
    }
    fout << endl;
  }
  fout.flush(); // ファイルを保存する
  fout.close(); // ファイルを閉じる

  return 0;
}
