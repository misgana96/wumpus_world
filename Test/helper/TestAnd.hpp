#include <cxxtest/TestSuite.h>
#include <iostream>
#include <iomanip>
#include "and.hpp"
#include "or.hpp"


using namespace Wumpus;
using namespace helper;

using namespace std;

class TestAnd: public And
{};

class AndSuite : public CxxTest::TestSuite
{
public:
    /**
     * @param A is truth value either true or false
     * @param B is truth value either true or false
     * @return true if both is true else false
     */
    void test_getAnd()
    {
        bool value = TestAnd().getAnd(true, false);
        TS_ASSERT_EQUALS(false, value);
    }

    /**
     * @param A is truth value either true or false
     * @return A and B which is  inverse of A
     */
    void test_invOfAnd()
    {
        valuesOfAnd value = TestAnd().invOfAnd(true);
        TS_ASSERT_EQUALS(get<0>(value.value1), true);
        TS_ASSERT_EQUALS(get<1>(value.value1), true);
    }
};

class TestOr: public Wumpus::helper::Or
{};

class OrSuite : public CxxTest::TestSuite
{
public:
    /**
     * @param A is truth value either true or false
     * @param B is truth value either true or false
     * @return true if both is true else false
     */
    void test_getOr()
    {
        bool value = TestOr().getOr(true, false);
        //TS_ASSERT_EQUALS(TRUE, value);
    }

    /**
     * @param A is truth value either true or false
     * @return A and B which is  inverse of A
     */
    void test_invOfOr()
    {
        valuesOfOr value = TestOr().invOfOr(false);
        // TS_ASSERT_EQUALS(get<0>(value.value1), TRUE);
        // TS_ASSERT_EQUALS(get<1>(value.value1), TRUE);
        // TS_ASSERT_EQUALS(get<0>(value.value2), TRUE);
        // TS_ASSERT_EQUALS(get<1>(value.value2), TRUE);
    }
};
