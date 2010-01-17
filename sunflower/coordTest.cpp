#include <string>
#include <iostream>
#include <cppunit/extensions/HelperMacros.h>

#include "coord.h"

using std::string;
using std::cout;
using std::endl;

class coordTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(coordTest);
        // TODO: 対象の関数名をここに記述して、定義を下で記述している。この場所で直接関数を定義できないものか調査
        CPPUNIT_TEST(constractor_2d_Test);
        CPPUNIT_TEST(constractor_3d_Test);
        CPPUNIT_TEST(constractor_2d_set_Test);
        CPPUNIT_TEST(constractor_2d_copy_Test);

        CPPUNIT_TEST(operator_assign_2d_Test);

        CPPUNIT_TEST(operator_add_2d_Test);
        CPPUNIT_TEST(operator_subtract_2d_Test);
        
    CPPUNIT_TEST_SUITE_END();

private:
public:
    void setUp() {};
    void tearDown() {};

protected:
    void constractor_2d_Test() {
        coord a(2);
        string s = "(0,0)";

        CPPUNIT_ASSERT_EQUAL( s, a.toString() );
    }

    void constractor_3d_Test() {
        coord a(3);
        string s = "(0,0,0)";

        CPPUNIT_ASSERT_EQUAL( s, a.toString() );
    }

    void constractor_2d_set_Test() {
        coord a(2, 3);
        string s = "(2,3)";

        CPPUNIT_ASSERT_EQUAL( s, a.toString() );
    }

    void constractor_2d_copy_Test() {
        coord a(3, 4);
        coord b(a);

        string s = "(3,4)";

        CPPUNIT_ASSERT_EQUAL( s, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s, b.toString() );
    }

    void operator_assign_2d_Test() {
        coord a(2, 3);
        coord b(2);

        string s1 = "(2,3)";
        string s2 = "(0,0)";

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s2, b.toString() );

        b = a;

        CPPUNIT_ASSERT_EQUAL( s1, a.toString() );
        CPPUNIT_ASSERT_EQUAL( s1, b.toString() );
    }

    void operator_add_2d_Test() {
        coord a(2, 3);
        coord b(4, 5);
        coord c(2);
        coord d(2);

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
        coord a(3, 5);
        coord b(1, 2);
        coord c(2);
        coord d(2);

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
};

CPPUNIT_TEST_SUITE_REGISTRATION(coordTest);

/*
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
