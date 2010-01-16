#include <stdio.h>
#include <math.h>

#include "coord.h"

/*
 * コンストラクタ
 */
coord::coord(int n) {
  dim = n;
  v[2] = 0;
  for(int i=0; i < dim; i++) {
    v[i] = 0;
  }
}

coord::coord(double x, double y) {
  dim = 2;
  v[0] = x;
  v[1] = y;
  v[2] = 0;
}

coord::coord(const coord& cod) {
  dim = cod.dim;
  v[2] = 0;
  for(int i=0; i < dim; i++) {
    v[i] = cod.v[i];
  }
}

/*
 * デストラクタ
 */
coord::~coord() {
  // 今のところ必要ない
}

coord& coord::operator=(const coord& cod) {
  dim = cod.dim;
  v[2] = 0;
  for(int i=0; i < dim; i++) {
    v[i] = cod.v[i];
  }

  return *this;
}

coord coord::operator+(const coord& cod) {
  coord tmp(*this);
  for(int i=0; i < tmp.dim; i++) {
    tmp.v[i] += cod.v[i];
  }
  return tmp;
}

coord coord::operator-(const coord& cod) {
  coord tmp(*this);
  for(int i=0; i < tmp.dim; i++) {
    tmp.v[i] -= cod.v[i];
  }
  return tmp;
}

coord coord::operator-() {
  coord tmp(*this);
  for(int i=0; i < tmp.dim; i++) {
    tmp.v[i] *= -1;
  }
  return tmp;
}
coord coord::operator*(double a) {
  coord tmp(*this);
  tmp.v[0] *= a;
  tmp.v[1] *= a;
  tmp.v[2] *= a;
  return tmp;
}

coord coord::operator*(const coord& cod) {
  // TODO: 双方のベクトルで次元が違うとエラーかな？0解釈？
  coord tmp(3);
  tmp.v[0] = this->v[1]*cod.v[2] - this->v[2]*cod.v[1];
  tmp.v[1] = this->v[2]*cod.v[0] - this->v[0]*cod.v[2];
  tmp.v[2] = this->v[0]*cod.v[1] - this->v[1]*cod.v[0];
  return tmp;
}

std::string coord::toString() {
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

#define sq(x) ((x)*(x))

double coord::length() {
  return sqrt(sq(this->v[0]) + sq(this->v[1]) + sq(this->v[2]));
}

double coord::dot(const coord& cod) {
  return this->v[0] * cod.v[0] + this->v[1] * cod.v[1] + this->v[2] * cod.v[2];
}

coord operator*(const double a, const coord& b) {
  coord tmp(b);
  return tmp * a;
}

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& o, coord cod) {
  return o << cod.toString();
}
