#include <stdio.h>
#include <math.h>

#include "gvector.h"

/*
 * コンストラクタ
 */
gvector::gvector(int n) {
  dim = n;
  v[2] = 0;
  for(int i=0; i < dim; i++) {
    v[i] = 0;
  }
}

gvector::gvector(double x, double y) {
  dim = 2;
  v[0] = x;
  v[1] = y;
  v[2] = 0;
}

gvector::gvector(double x, double y, double z) {
  dim = 3;
  v[0] = x;
  v[1] = y;
  v[2] = z;
}

gvector::gvector(const gvector& cod) {
  dim = cod.dim;
  v[2] = 0;
  for(int i=0; i < dim; i++) {
    v[i] = cod.v[i];
  }
}

/*
 * デストラクタ
 */
gvector::~gvector() {
  // 今のところ必要ない
}

gvector& gvector::operator=(const gvector& cod) {
  dim = cod.dim;
  v[2] = 0;
  for(int i=0; i < dim; i++) {
    v[i] = cod.v[i];
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
  char tmp[256];

  a = "(";
  sprintf(tmp, "%lg", this->v[0]);
  a += std::string(tmp);
  a += ",";
  sprintf(tmp, "%lg", this->v[1]);
  a += std::string(tmp);
  if(this->dim==3) {
    sprintf(tmp, "%lg", this->v[2]);
    a += std::string(",") + std::string(tmp);
  }
  a += ")";
  return a;
}

bool gvector::operator==(const gvector& cod) {
  if(
      fabs(this->v[0] - cod.v[0])
     +fabs(this->v[1] - cod.v[1])
     +fabs(this->v[2] - cod.v[2])
     <= 1.0E-10) {  // TODO: 共通化して目的毎に変えれるようにしないとだめかなぁ。それと絶対・相対誤差はどうするか・・やっぱ後だ！
     return true;
  }
  
  return false;
}

bool gvector::operator!=(const gvector& cod) {
  return !(*this == cod);
}

#define sq(x) ((x)*(x))

double gvector::length() {
  return sqrt(sq(this->v[0]) + sq(this->v[1]) + sq(this->v[2]));
}

double gvector::dot(const gvector& cod) {
  return this->v[0] * cod.v[0] + this->v[1] * cod.v[1] + this->v[2] * cod.v[2];
}

gvector operator*(const double a, const gvector& b) {
  gvector tmp(b);
  return tmp * a;
}

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& o, gvector cod) {
  return o << cod.toString();
}

// TODO: 交点が無かったら・・・どうしよう。
// 交点が無い条件
// 　直線Aと直線Bが平行。この時は同一直線上の場合も含むか？（この場合はある意味交点は無数に存在する）
// 　直線Aと直線Bがねじれの位置（3次元）
// 　交点はあるが、直線Aまたは直線Bの区間上に存在しない
gvector intersect(const gvector posA, const gvector vecA, const gvector posB, const gvector vecB) {
    gvector tmp(posA);

    return tmp;
}

