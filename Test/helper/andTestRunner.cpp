/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_andTestSuite_init = false;
#include "andTestSuit.h"

static andTestSuite suite_andTestSuite;

static CxxTest::List Tests_andTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_andTestSuite( "andTestSuit.h", 8, "andTestSuite", suite_andTestSuite, Tests_andTestSuite );

static class TestDescription_suite_andTestSuite_testAnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_andTestSuite_testAnd() : CxxTest::RealTestDescription( Tests_andTestSuite, suiteDescription_andTestSuite, 10, "testAnd" ) {}
 void runTest() { suite_andTestSuite.testAnd(); }
} testDescription_suite_andTestSuite_testAnd;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
