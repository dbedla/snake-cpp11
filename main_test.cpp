#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/Test.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>



int main()
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();

    runner.addTest( registry.makeTest() );
    bool wasSucessful = runner.run("",false);
    return wasSucessful;
}
