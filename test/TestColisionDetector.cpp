#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/Test.h>
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../include/CColisionDetector.h"
#include "../include/IFrameElement.h"
#include "../include/CPoint.h"

class CFakeFrameEl: public IFrameElement<PointsList>
{
public:
    PointsList p;
    virtual const PointsList& getFrameElements() const;
};
const PointsList& CFakeFrameEl::getFrameElements() const
{
    return p;
}

class CTestColisionDetector: public CppUnit::TestFixture
{
public:
    void setUp();
    void tearDown();

    void colision();
private:
    CPPUNIT_TEST_SUITE( CTestColisionDetector );
    CPPUNIT_TEST( colision );
    CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION(CTestColisionDetector);

void CTestColisionDetector::setUp(){}
void CTestColisionDetector::tearDown(){}

void CTestColisionDetector::colision()
{
    CColisionDetector detector;
    CFakeFrameEl el1;
    CFakeFrameEl el2;
    CFakeFrameEl el3;
    CFakeFrameEl el4;
    el1.p.push_back(CPoint(1,1));
    el1.p.push_back(CPoint(2,1));
    el1.p.push_back(CPoint(2,3));
    el2.p.push_back(CPoint(2,3));
    el3.p.push_back( CPoint(4,3) );

    CPPUNIT_ASSERT( detector(el1, el2) ); // colision
    CPPUNIT_ASSERT( !detector(el1, el3) ); //no colision
    CPPUNIT_ASSERT( !detector(el4, el3) ); //1 empty
    CPPUNIT_ASSERT( !detector(el3, el4) ); // 1 empty
    CPPUNIT_ASSERT( !detector(el4, el4) ); // 2 empty




    }
