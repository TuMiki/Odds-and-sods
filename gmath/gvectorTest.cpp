#include <math.h>
#include <string>
#include <iostream>
#include <cppunit/extensions/HelperMacros.h>

#include "gline.h"

using std::string;
using std::cout;
using std::endl;

class gvectorTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(gvectorTest);
        // TODO: 対象の関数名をここに記述して、定義を下で記述している。この場所で直接関数を定義できないものか調査
        CPPUNIT_TEST(constructor_2d_Test);
        CPPUNIT_TEST(constructor_3d_Test);
        CPPUNIT_TEST(constructor_2d_set_Test);
        CPPUNIT_TEST(constructor_2d_copy_Test);

        CPPUNIT_TEST(operator_assign_2d_Test);

        CPPUNIT_TEST(operator_add_2d_Test);
        CPPUNIT_TEST(operator_subtract_2d_Test);
        CPPUNIT_TEST(operator_negative_2d_Test);
        CPPUNIT_TEST(operator_multiply_2d_Test);

        CPPUNIT_TEST(operator_exterior_Test);
        CPPUNIT_TEST(operator_equals_Test);

        CPPUNIT_TEST(length_Test);
        CPPUNIT_TEST(dot_Test);

//        CPPUNIT_TEST(footOfAPerpendicular_Test);
        CPPUNIT_TEST(intersect_Test);
        
    CPPUNIT_TEST_SUITE_END();

private:
public:
    void setUp() {};
    void tearDown() {};

protected:
    // 
    void constructor_2d_Test() {
        gvector a(2);
        string s = "(0,0)";

        CPPUNIT_ASSERT_EQUAL( s, a.toString() );
    }

    void constructor_3d_Test() {
        gvector a(3);
        string s = "(0,0,0)";

        CPPUNIT_ASSERT_EQUAL( s, a.toString() );
    }

    void constructor_2d_set_Test() {
        gvector a(2, 3);
        string s = "(2,3)";

        CPPUNIT_ASSERT_EQUAL( s, a.toString() );
    }

    void constructor_2d_copy_Test() {
        gvector a(3, 4);
        gvector b(a);

        string s = "(3,4)";

        CPPUNIT_ASSERT_EQUAL( s, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s, b.toString() );
    }

    void operator_assign_2d_Test() {
        gvector a(2, 3);
        gvector b(2);

        string s1 = "(2,3)";
        string s2 = "(0,0)";

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );

        b = a;

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s1, b.toString() );
    }

    void operator_add_2d_Test() {
        gvector a(2, 3);
        gvector b(4, 5);
        gvector c(2);
        gvector d(2);

        string s1 = "(2,3)";
        string s2 = "(4,5)";
        string s3 = "(0,0)";
        string s4 = "(6,8)";

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );
        CPPUNIT_ASSERT_EQUAL( s3, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s3, d.toString() );

        c = a + b;

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );
        CPPUNIT_ASSERT_EQUAL( s4, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s3, d.toString() );

        d = b + a;

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );
        CPPUNIT_ASSERT_EQUAL( s4, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s4, d.toString() );
    }

    void operator_subtract_2d_Test() {
        gvector a(3, 5);
        gvector b(1, 2);
        gvector c(2);
        gvector d(2);

        string s1 = "(3,5)";
        string s2 = "(1,2)";
        string s3 = "(0,0)";
        string s4 = "(2,3)";
        string s5 = "(-2,-3)";

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );
        CPPUNIT_ASSERT_EQUAL( s3, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s3, d.toString() );

        c = a - b;

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );
        CPPUNIT_ASSERT_EQUAL( s4, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s3, d.toString() );

        d = b - a;

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );
        CPPUNIT_ASSERT_EQUAL( s4, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s5, d.toString() );
    }

    void operator_negative_2d_Test() {
        gvector a(3, 5);
        gvector c(2);

        string s1 = "(3,5)";
        string s3 = "(0,0)";
        string s4 = "(-3,-5)";

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s3, c.toString() );

        c = - a;

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s4, c.toString() );
    }

    void operator_multiply_2d_Test() {
        gvector a(3, 5);
        double b = 2;
        gvector c(2);
        gvector d(2);

        string s1 = "(3,5)";
        double d2 = 2;
        string s3 = "(0,0)";
        string s4 = "(6,10)";

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( d2, b );
        CPPUNIT_ASSERT_EQUAL( s3, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s3, d.toString() );

        c = a * b;

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( d2, b );
        CPPUNIT_ASSERT_EQUAL( s4, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s3, d.toString() );

        d = b * a;

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( d2, b );
        CPPUNIT_ASSERT_EQUAL( s4, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s4, d.toString() );
    }

    void operator_exterior_Test() {
        gvector a(1, 2, 3);
        gvector b(4, 6, 5);
        gvector c(3);
        gvector d(3);
        gvector e(3);

        string s1 = "(1,2,3)";
        string s2 = "(4,6,5)";
        string s3 = "(0,0,0)";
        string s4 = "(-8,7,-2)";
        string s5 = "(8,-7,2)";

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );
        CPPUNIT_ASSERT_EQUAL( s3, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s3, d.toString() );

        c = a * b;

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );
        CPPUNIT_ASSERT_EQUAL( s4, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s3, d.toString() );

        d = b * a;

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );
        CPPUNIT_ASSERT_EQUAL( s4, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s5, d.toString() );

        e = - ( a * b );

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );
        CPPUNIT_ASSERT_EQUAL( s4, c.toString() );
        CPPUNIT_ASSERT_EQUAL( s5, d.toString() );

        CPPUNIT_ASSERT_EQUAL( d, e );
    }

    void operator_equals_Test() {
        gvector a(1, 2, 3);
        gvector b(a);
        gvector c(1,0,0);

        string s1 = "(1,2,3)";
        string s3 = "(0,0,0)";
        string s4 = "(1,0,0)";

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s1, b.toString() );
        CPPUNIT_ASSERT_EQUAL( s4, c.toString() );


        CPPUNIT_ASSERT_EQUAL(a, b);
        CPPUNIT_ASSERT(!(a != b));
        CPPUNIT_ASSERT_EQUAL(a, (b + (c * 1e-11))); // ちょっと大雑把。絶対比較で誤差比較してるってこと
        CPPUNIT_ASSERT(a != (b + (c * 1e-10)));

    }

    void length_Test() {
        gvector a(1, 2, 3);
        double c = 0;

        string s1 = "(1,2,3)";
        double d3 = 0;
        double d4 = sqrt(1*1+2*2+3*3);

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( d3, c);

        c = a.length();

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( d4, c );
    }

    void dot_Test() {
        gvector a(1, 2, 3);
        gvector b(4, 6, 5);

        string s1 = "(1,2,3)";
        string s2 = "(4,6,5)";

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );

        CPPUNIT_ASSERT_EQUAL( 1.0*4+2*6+3*5,  a.dot(b) );
        CPPUNIT_ASSERT_EQUAL( 1.0*4+2*6+3*5,  b.dot(a) );
    }
/*
    void footOfAPerpendicular_Test() {
        gvector pos(1, 1, 1);
        gvector posA(0, 0, 0);
        gvector vecA(0, 2, 0);
        gvector posC(0, 1, 0);

        CPPUNIT_ASSERT( posC == footOfAPerpendicular(pos, posA, vecA) );
    }
*/
    void intersect_Test() {
        CPPUNIT_ASSERT_EQUAL_MESSAGE( "双方の線分の中",
                gvector(3,0),
                intersect(gline(gvector(1,0), gvector(5,0)),
                          gline(gvector(3,1), gvector(0,1))));

        CPPUNIT_ASSERT_EQUAL_MESSAGE( "双方の線分の外（終点の先）",
                gvector(6,0),
                intersect(gline(gvector(1,0), gvector(5,0)),
                          gline(gvector(6,2), gvector(0,1))));

        CPPUNIT_ASSERT_EQUAL_MESSAGE( "前の終点の先、後ろの始点の先",
                gvector(6,0),
                intersect(gline(gvector(1,0), gvector(5,0)),
                          gline(gvector(6,2), gvector(0,-1))));

        CPPUNIT_ASSERT_EQUAL_MESSAGE( "前の始点の先、後ろの終点の先",
                gvector(6,0),
                intersect(gline(gvector(1,0), gvector(-5,0)),
                          gline(gvector(6,2), gvector(0,1))));

        CPPUNIT_ASSERT_EQUAL_MESSAGE( "前の始点の先、後ろの始点の先",
                gvector(6,0),
                intersect(gline(gvector(1,0), gvector(-5,0)),
                          gline(gvector(6,2), gvector(0,-1))));
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION(gvectorTest);

#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

int main( int argc, char* argv[] ) {
  // イベント・マネージャとテスト・コントローラを生成する
  CPPUNIT_NS::TestResult controller;

  // テスト結果収集リスナをコントローラにアタッチする
  CPPUNIT_NS::TestResultCollector result;
  controller.addListener( &result );

  // 「.」で進行状況を出力するリスナをアタッチする
  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener( &progress );

  // テスト・ランナーにテスト群を与え、テストする
  CPPUNIT_NS::TestRunner runner;
  runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
  runner.run( controller );

  // テスト結果を標準出力に吐き出す
  CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
  outputter.write();

  return result.wasSuccessful() ? 0 : 1;
} 
