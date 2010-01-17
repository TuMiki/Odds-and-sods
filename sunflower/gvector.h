#ifndef __gvector_h
#define __gvector_h

#include <string>
#include <iostream>

/*
 * 座標を扱うためのclass.
 * vectorとしたいところだが、コンテナクラスに同名があるため、coordとした
 */
class gvector {
  protected:
    /* 以下の変数宣言は実装に関しているため隠したいところ。
     * C++だとヘッダーファイルに書いたクラス定義が公開となるので通常だと隠せない
     * 操作・参照はできないのだけど、実装の変更が変数に及んだときに
     * ヘッダーファイルを変更するのは、気持ちが悪い
     */
    int dim;
    double v[3];

  public:
    gvector(int dim); // 指定した次元で座標を生成
    gvector(double x, double y);  // 2次元で座標を生成
    gvector(double x, double y, double z);  // 3次元で座標を生成
    gvector(const gvector& cod);  // 指定した座標をコピーして生成
    ~gvector();  // デストラクタ

    gvector& operator=(const gvector& cod); // gvector = gvector。戻り値が参照！
    gvector operator+(const gvector& cod); // gvector + gvector
    gvector operator-(const gvector& cod); // gvector - gvector
    gvector operator-(); // - gvector
    gvector operator*(double a); // gvector * double
    gvector operator*(const gvector& cod); // 外積

    bool operator==(const gvector& cod); // 比較
    bool operator!=(const gvector& cod); // 比較

    double length();
    double dot(const gvector& cod); // 内積

    std::string toString();
};

// 2項演算子で左側が gvector 以外の場合は、通常の関数として演算子をオーバーロードする
// double * gvector を解釈する
gvector operator*(const double a, const gvector& b);

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& o, gvector cod);

// 直線を始点と方向ベクトルで表現
gvector intersect(const gvector posA, const gvector vecA, const gvector posB, const gvector vecB);

#endif
