#ifndef __gvector_h
#define __gvector_h

#include <string>
#include <iostream>
#include <math.h>
/*
 * 座標を扱うためのclass.
 * vectorとしたいところだが、コンテナクラスに同名があるため、gvectorとした
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
    gvector() { this->dim=2; this->v[0] = 0; this->v[1] = 0; this->v[2]=0; };
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
    gvector operator/(double a); // gvector / double

//    bool operator==(const gvector& cod); // 比較
    bool operator!=(const gvector& cod); // 比較

    double length();
    double dot(const gvector& cod); // 内積
    gvector unit(); // 単位ベクトル化

    double getX() { return v[0]; }
    double getY() { return v[1]; }
    double getZ() { return v[2]; }
    // TODO: 変数にコピーして返さないと安全じゃないよなぁ
    double* get() { return this->v; };
    
    std::string toString();

    static
    bool sames(gvector va, gvector vb) {
      double *a = va.get();
      double *b = vb.get();
      double eps = 1.0E-10;
      if(
          fabs(a[0] - b[0])
         +fabs(a[1] - b[1])
         +fabs(a[2] - b[2])
         <= eps) {  // TODO: 共通化して目的毎に変えれるようにしないとだめかなぁ。それと絶対・相対誤差はどうするか・・やっぱ後だ！
         return true;
      }
  
      return false;
    }
};

// 2項演算子で左側が gvector 以外の場合は、通常の関数として演算子をオーバーロードする
// double * gvector を解釈する
gvector operator*(const double a, const gvector& b);
//bool operator==(const gvector& va, const gvector& vb); // 比較

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& o, gvector cod);

bool operator==(gvector a, gvector b); // 比較
#endif
