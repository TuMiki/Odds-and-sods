#include <string>
#include <iostream>
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>

#include "coord.h"

class coordTest : public CppUnit::TestFixture {
private:
public:
    void setUp() {
    }

    void tearDown() {
    }

    void constractorTest() {
        std::cout << "■ coord(int dim); // 指定した次元で座標を生成" << std::endl;

        coord a(2);
        CPPUNIT_ASSERT( a.toString() == "(0, 0)");
        coord b(3);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
/*
    {
        std::cout << "■ coord(double x, double y);  // 2次元で座標を生成" << std::endl;

        coord a(2, 3);
        std::cout << a << std::endl;
    }
    {
        std::cout << "■ coord(const coord& cod);  // 指定した座標をコピーして生成" << std::endl;

        coord a(3, 4);
        coord b(a);
        
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }

    {
        std::cout << "■ coord& operator=(const coord& cod); // coord = coord。戻り値が参照！" << std::endl;

        coord a(2, 3);
        coord b(2);

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        b = a;

        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }

        std::cout << "■ coord operator+(const coord& cod); // coord + coord" << std::endl;
        std::cout << "■ coord operator-(const coord& cod); // coord - coord" << std::endl;
        std::cout << "■ coord operator-(); // - coord" << std::endl;
        std::cout << "■ coord operator*(double a); // coord * double" << std::endl;
        std::cout << "■ coord operator*(const coord& cod); // 外積" << std::endl;

        std::cout << "■ double length();" << std::endl;
        std::cout << "■ double dot(const coord& cod); // 内積" << std::endl;

        std::cout << "■ std::string toString();" << std::endl;

// 2項演算子で左側が coord 以外の場合は、通常の関数として演算子をオーバーロードする
// double * coord を解釈する
        std::cout << "■ coord operator*(const double a, const coord& b);" << std::endl;

        std::cout << "■ std::basic_ostream<char>& operator<<(std::basic_ostream<char>& o, coord cod);" << std::endl;

    return 0;
    */
}
