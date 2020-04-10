#include <cxxtest/TestSuite.h>
#include <iostream>
#include <iomanip>
#include "and.hpp"


using namespace Wumpus;
using namespace helper;

using namespace std;

class TestAnd: public And
{
public:
    TestAnd():And(TRUE, TRUE){}
};

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
        bool value = TestAnd().getAnd(TRUE, FALSE);
        TS_ASSERT_EQUALS(FALSE, value);
    }

    /**
     * @param A is truth value either true and false
     * @return A and B which is inverse of A
     */
    void test_invOfAnd()
    {
       values value = TestAnd().invOfAnd(TRUE);
       TS_ASSERT_EQUALS(value, (TRUE, TRUE));
    }
};
