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
bool suite_notTestSuit_init = false;
#include "notTestSuit.h"

static notTestSuit suite_notTestSuit;

static CxxTest::List Tests_notTestSuit = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_notTestSuit( "notTestSuit.h", 6, "notTestSuit", suite_notTestSuit, Tests_notTestSuit );

static class TestDescription_suite_notTestSuit_testNot : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_notTestSuit_testNot() : CxxTest::RealTestDescription( Tests_notTestSuit, suiteDescription_notTestSuit, 8, "testNot" ) {}
 void runTest() { suite_notTestSuit.testNot(); }
} testDescription_suite_notTestSuit_testNot;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
