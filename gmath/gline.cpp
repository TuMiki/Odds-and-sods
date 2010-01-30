#include <stdio.h>
#include <math.h>

#include "gline.h"

/*
 * コンストラクタ
 */
gline::gline(const gvector& pos, const gvector& vec) {
  this->pos = pos;
  this->vec = vec;
}

gline::gline(const gline& lin) {
  this->pos = lin.pos;
  this->vec = lin.vec;
}

/*
 * デストラクタ
 */
gline::~gline() {
  // 今のところ必要ない
}

gline& gline::operator=(const gline& lin) {
  this->pos = lin.pos;
  this->vec = lin.vec;

  return *this;
}

std::string gline::toString() {
  return "{ pos" + this->pos.toString() + ", vec" + this->vec.toString() + " }";
}

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& o, gline lin) {
  return o << lin.toString();
}

// 垂線の足を求める
// TODO: 外積を用いて計算しているが、X-Y平面限定だと、もう少し計算量を減らすことができる
gvector footOfAPerpendicular(gvector& pos, gline& lin) {
  gvector va(lin.getVec().unit());
  gvector p(pos - lin.getPos());

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
gvector intersect(gline& linA, gline& linB) {
  double  eps = 1.0E-10;

  gvector va(linA.getVec().unit());
  gvector pos(3);

  double t;

  // 2直線が平行なら計算しない
  if((va * linB.getVec()).length() <= eps) {
    return pos;
  }

  // 2直線が同一平面上に無いのなら計算しない
  if((((linB.getPos() - linA.getPos()) * linA.getVec()) * ((linB.getPos() - linA.getPos()) * linB.getVec())).length() >= eps) {
    return pos;
  }

  t = ((linB.getPos() - linA.getPos() ) * linB.getVec() ).length() / ( va * linB.getVec() ).length();
  pos = linA.getPos() + va * t;

/*
    // 直線Aと直線Bの方向ベクトルの外積をとって、大きさが0なら平行
    if((linA.getVec() * linB.getVec()).length()<=eps) {
        // 平行
        // 直線Aの始点から直線Bの始点へ伸ばしたベクトルと直線Bのベクトルの外積が0なら同一直線上にある
        if(((linB.getPos() - linA.getPos()) * linB.getVec()).length()<=eps) {
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
*/
    return pos;
}

