#ifndef __coord_h
#define __coord_h

#include <string>
#include <iostream>

/*
 * 座標を扱うためのclass.
 * vectorとしたいところだが、コンテナクラスに同名があるため、coordとした
 */
class coord {
  protected:
    /* 以下の変数宣言は実装に関しているため隠したいところ。
     * C++だとヘッダーファイルに書いたクラス定義が公開となるので通常だと隠せない
     * 操作・参照はできないのだけど、実装の変更が変数に及んだときに
     * ヘッダーファイルを変更するのは、気持ちが悪い
     */
    int dim;
    double v[3];

  public:
    coord(int dim); // 指定した次元で座標を生成
    coord(double x, double y);  // 2次元で座標を生成
    coord(const coord& cod);  // 指定した座標をコピーして生成
    ~coord();  // デストラクタ

    coord& operator=(const coord& cod); // coord = coord。戻り値が参照！
    coord operator+(const coord& cod); // coord + coord
    coord operator-(const coord& cod); // coord - coord
    coord operator-(); // - coord
    coord operator*(double a); // coord * double
    coord operator*(const coord& cod); // 外積

    double length();
    double dot(const coord& cod); // 内積

    std::string toString();
};

// 2項演算子で左側が coord 以外の場合は、通常の関数として演算子をオーバーロードする
// double * coord を解釈する
coord operator*(const double a, const coord& b);

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& o, coord cod);

#endif
