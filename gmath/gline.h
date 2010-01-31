#ifndef __gline_h
#define __gline_h

#include <string>
#include <iostream>

#include "gvector.h"

/*
 * 直線を扱うためのclass.
 */
class gline {
  protected:
    bool    s, e; // 始点、終点の有界とするかどうかのフラグ。
                  // 初期値はfalse=有界ではない=数学の直線に一致
    gvector pos;  // 直線上の一点。始点
    gvector vec;  // 直線の方向。線分として扱う場合、大きさが長さとします

  public:
    gline(const gvector& pos, const gvector& vec); // 始点とベクトルで直線を生成
    gline(const gline& lin); // 元の直線をコピーして生成
    ~gline();  // デストラクタ

    gline& operator=(const gline& lin);

// TODO 直線の比較はややこしいので後回し
//    bool operator==(const gline& lin); // 比較
//    bool operator!=(const gline& lin); // 比較

    bool getS() { return s; }
    bool getE() { return e; }

    void setS(bool s) { this->s = s; }
    void setE(bool e) { this->e = e; }
    gvector getPos() { return pos; }
    gvector getVec() { return vec; }

    std::string toString();
};

// 垂線の足を求める
gvector footOfAPerpendicular(gvector& pos, gline& lin);

// 2直線の交点を求める
gvector intersect(gline lineA, gline lineB);

// 2点の垂直二等分線を求める XY平面上限定
gline perpendicularBisectorOnXY(gvector& posA, gvector& posB);

#endif
