#include "../include/CPoint.h"
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/Test.h>
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>


class CTestCPoint: public CppUnit::TestFixture
{
public:
    void setUp();
    void tearDown();

    void testEQ();
    void testLess();
private:
    CPPUNIT_TEST_SUITE( CTestCPoint );
    CPPUNIT_TEST( testEQ );
    CPPUNIT_TEST( testLess );
    CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION(CTestCPoint);


void CTestCPoint::setUp()
{

}

void CTestCPoint::tearDown()
{

}

void CTestCPoint::testEQ()
{
    CPoint p1(2,3);
    CPoint p2(4,5);
    CPPUNIT_ASSERT(p1 == p1);
    CPPUNIT_ASSERT(!(p1 == p2) );
}

void CTestCPoint::testLess()
{
    CPoint p1(2,3);
    CPoint p2(4,5);
    CPoint p3(4,1);

    CPPUNIT_ASSERT( p1 < p2 );
    CPPUNIT_ASSERT( !(p1 < p1) );
    CPPUNIT_ASSERT( !(p2 < p1) );
    CPPUNIT_ASSERT( !(p2 < p3) );
}
