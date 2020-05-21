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
bool suite_AndSuite_init = false;
#include "TestAnd.cxxtest"

static AndSuite suite_AndSuite;

static CxxTest::List Tests_AndSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_AndSuite( "TestAnd.cxxtest", 19, "AndSuite", suite_AndSuite, Tests_AndSuite );

static class TestDescription_suite_AndSuite_test_getAnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AndSuite_test_getAnd() : CxxTest::RealTestDescription( Tests_AndSuite, suiteDescription_AndSuite, 27, "test_getAnd" ) {}
 void runTest() { suite_AndSuite.test_getAnd(); }
} testDescription_suite_AndSuite_test_getAnd;

static class TestDescription_suite_AndSuite_test_invOfAnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_AndSuite_test_invOfAnd() : CxxTest::RealTestDescription( Tests_AndSuite, suiteDescription_AndSuite, 39, "test_invOfAnd" ) {}
 void runTest() { suite_AndSuite.test_invOfAnd(); }
} testDescription_suite_AndSuite_test_invOfAnd;

static OrSuite suite_OrSuite;

static CxxTest::List Tests_OrSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_OrSuite( "TestAnd.cxxtest", 49, "OrSuite", suite_OrSuite, Tests_OrSuite );

static class TestDescription_suite_OrSuite_test_getOr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_OrSuite_test_getOr() : CxxTest::RealTestDescription( Tests_OrSuite, suiteDescription_OrSuite, 57, "test_getOr" ) {}
 void runTest() { suite_OrSuite.test_getOr(); }
} testDescription_suite_OrSuite_test_getOr;

static class TestDescription_suite_OrSuite_test_invOfOr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_OrSuite_test_invOfOr() : CxxTest::RealTestDescription( Tests_OrSuite, suiteDescription_OrSuite, 69, "test_invOfOr" ) {}
 void runTest() { suite_OrSuite.test_invOfOr(); }
} testDescription_suite_OrSuite_test_invOfOr;

static notSuite suite_notSuite;

static CxxTest::List Tests_notSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_notSuite( "TestAnd.cxxtest", 77, "notSuite", suite_notSuite, Tests_notSuite );

static class TestDescription_suite_notSuite_test_getNot : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_notSuite_test_getNot() : CxxTest::RealTestDescription( Tests_notSuite, suiteDescription_notSuite, 85, "test_getNot" ) {}
 void runTest() { suite_notSuite.test_getNot(); }
} testDescription_suite_notSuite_test_getNot;

static class TestDescription_suite_notSuite_test_invOfNot : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_notSuite_test_invOfNot() : CxxTest::RealTestDescription( Tests_notSuite, suiteDescription_notSuite, 94, "test_invOfNot" ) {}
 void runTest() { suite_notSuite.test_invOfNot(); }
} testDescription_suite_notSuite_test_invOfNot;

static ImpSuite suite_ImpSuite;

static CxxTest::List Tests_ImpSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ImpSuite( "TestAnd.cxxtest", 101, "ImpSuite", suite_ImpSuite, Tests_ImpSuite );

static class TestDescription_suite_ImpSuite_test_Implication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ImpSuite_test_Implication() : CxxTest::RealTestDescription( Tests_ImpSuite, suiteDescription_ImpSuite, 105, "test_Implication" ) {}
 void runTest() { suite_ImpSuite.test_Implication(); }
} testDescription_suite_ImpSuite_test_Implication;

static class TestDescription_suite_ImpSuite_test_invOfImplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ImpSuite_test_invOfImplication() : CxxTest::RealTestDescription( Tests_ImpSuite, suiteDescription_ImpSuite, 113, "test_invOfImplication" ) {}
 void runTest() { suite_ImpSuite.test_invOfImplication(); }
} testDescription_suite_ImpSuite_test_invOfImplication;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
