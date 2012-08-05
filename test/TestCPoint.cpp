#include "../include/CPoint.h"
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/Test.h>
#include <cppunit/TestSuite.h>

class CTestCPoint: public CppUnit::TestFixture
{
    void setUp();
    void tearDown();
    static CppUnit::Test* suit();

    void testEQ();
    void testLess();
private:
    //CPoint *p1;
    //CPoint *p2;
};

CppUnit::Test* CTestCPoint::suit()
{
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "CPoint tests" );
    suiteOfTests->addTest( new CppUnit::TestCaller<CTestCPoint>( "testEQ", &CTestCPoint::testEQ ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<CTestCPoint>( "testLess", &CTestCPoint::testLess ) );
    return suiteOfTests;
}

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
    CPPUNIT_ASSERT(! (p1 < p2) );
}
