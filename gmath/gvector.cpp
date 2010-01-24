#include <stdio.h>
#include <math.h>

#include "gvector.h"

/*
 * コンストラクタ
 */
gvector::gvector(int n) {
  this->dim = n;
  this->v[2] = 0;
  for(int i=0; i < this->dim; i++) {
    this->v[i] = 0;
  }
}

gvector::gvector(double x, double y) {
  this->dim = 2;
  this->v[0] = x;
  this->v[1] = y;
  this->v[2] = 0;
}

gvector::gvector(double x, double y, double z) {
  this->dim = 3;
  this->v[0] = x;
  this->v[1] = y;
  this->v[2] = z;
}

gvector::gvector(const gvector& cod) {
  this->dim = cod.dim;
  this->v[3] = 0;
  for(int i=0; i < this->dim; i++) {
    this->v[i] = cod.v[i];
  }
}

/*
 * デストラクタ
 */
gvector::~gvector() {
  // 今のところ必要ない
}

gvector& gvector::operator=(const gvector& cod) {
  this->dim = cod.dim;
  this->v[3] = 0;
  for(int i=0; i < this->dim; i++) {
    this->v[i] = cod.v[i];
  }

  return *this;
}

gvector gvector::operator+(const gvector& cod) {
  gvector tmp(*this);
  for(int i=0; i < tmp.dim; i++) {
    tmp.v[i] += cod.v[i];
  }
  return tmp;
}

gvector gvector::operator-(const gvector& cod) {
  gvector tmp(*this);
  for(int i=0; i < tmp.dim; i++) {
    tmp.v[i] -= cod.v[i];
  }
  return tmp;
}

gvector gvector::operator-() {
  gvector tmp(*this);
  for(int i=0; i < tmp.dim; i++) {
    tmp.v[i] *= -1;
  }
  return tmp;
}
gvector gvector::operator*(double a) {
  gvector tmp(*this);
  tmp.v[0] *= a;
  tmp.v[1] *= a;
  tmp.v[2] *= a;
  return tmp;
}

gvector gvector::operator*(const gvector& cod) {
  // TODO: 双方のベクトルで次元が違うとエラーかな？0解釈？
  gvector tmp(3);
  tmp.v[0] = this->v[1]*cod.v[2] - this->v[2]*cod.v[1];
  tmp.v[1] = this->v[2]*cod.v[0] - this->v[0]*cod.v[2];
  tmp.v[2] = this->v[0]*cod.v[1] - this->v[1]*cod.v[0];
  return tmp;
}

std::string gvector::toString() {
  std::string a;
  char tmp1[256];
  char tmp2[256];

  snprintf(tmp1, sizeof(tmp1)-1, "%lg", this->v[0]);
  snprintf(tmp2, sizeof(tmp2)-1, "%lg", this->v[1]);
  a  = std::string("(")
     + std::string(tmp1)
     + std::string(",")
     + std::string(tmp2)
     ;
  if(this->dim==3) {
    snprintf(tmp1, sizeof(tmp1)-1, "%lg", this->v[2]);
    a += std::string(",") + std::string(tmp1);
  }
  a += ")";
  return a;
}

bool gvector::operator==(const gvector& vec) {
  double eps = 1.0E-10;
  if(
      fabs(this->v[0] - vec.v[0])
     +fabs(this->v[1] - vec.v[1])
     +fabs(this->v[2] - vec.v[2])
     <= eps) {  // TODO: 共通化して目的毎に変えれるようにしないとだめかなぁ。それと絶対・相対誤差はどうするか・・やっぱ後だ！
     return true;
  }
  
  return false;
}

bool gvector::operator!=(const gvector& cod) {
  return !(*this == cod);
}

#define sq(x) ((x)*(x))

double gvector::length() { return sqrt(sq(this->v[0]) + sq(this->v[1]) + sq(this->v[2])); }

double gvector::dot(const gvector& cod) {
  return this->v[0] * cod.v[0]
       + this->v[1] * cod.v[1]
       + this->v[2] * cod.v[2];
}

gvector gvector::unit() {
  double  eps = 1.0E-10;
  double l = this->length();

  gvector p(*this);

  if(l <= eps) {
    p.v[0] = 0;
    p.v[1] = 0;
    p.v[2] = 0;
    return p;
  }

  p.v[0] /= l;
  p.v[1] /= l;
  p.v[2] /= l;

  return p;
}

gvector operator*(const double a, const gvector& b) {
  gvector tmp(b);
  return tmp * a;
}

//bool operator==(const gvector& va, const gvector& vb) {
//  return va==vb;
//}

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& o, gvector cod) {
  return o << cod.toString();
}

// 垂線の足を求める
gvector footOfAPerpendicular(gvector pos, gvector posA, gvector vecA) {
  gvector va(vecA.unit());
  gvector p(pos - posA);

  // 点と直線を含む平面に垂直なベクトルと直線のベクトルの外積を求める。
  gvector v((p * va) * va);
  v = v.unit();

  // 点から垂線の足までの長さを求める
  double t = (p * va) .length();

  p =  pos + v * t;

  return p;
}

// TODO: 交点が無かったら・・・どうしよう。
// 交点が無い条件
// 　直線Aと直線Bが平行。この時は同一直線上の場合も含むか？（この場合はある意味交点は無数に存在する）
// 　直線Aと直線Bがねじれの位置（3次元）
// 　交点はあるが、直線Aまたは直線Bの区間上に存在しない
gvector intersect(gvector posA, gvector vecA, gvector posB, gvector vecB) {
    double  eps = 1.0E-10;

    gvector tmp(posA);

    // 直線Aと直線Bの方向ベクトルの外積をとって、大きさが0なら平行
    if((vecA * vecB).length()<=eps) {
        // 平行
        // 直線Aの始点から直線Bの始点へ伸ばしたベクトルと直線Bのベクトルの外積が0なら同一直線上にある
        if(((posB - posA) * vecB).length()<=eps) {
            // 同一直線上
            // あとは双方の区間の調査かな
        } else {
            // 平行
        }
    } else {
        // 平行ではない
        // 2直線が同一平面上にあるか？
        // 垂線の足を求める
        // 後は長さをピタゴラスの方程式で求めて、ベクトル加算かなぁ。
        // 最後は双方の区間に乗っているか調査
    }
    return tmp;
}

