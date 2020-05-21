//notTestSuit.hpp
#include "not.hpp"
#include <cxxtest/TestSuite.h>

class notTestSuit : publicCxxTest::TestSuit{
    public:
    void testNot(){

        TS_ASSERT_EQUALS(Negation::Not(true), 0);
        TS_ASSERT_EQUALS(Negation::Not(false), 1);
        TS_ASSERT_EQUALS(Negation::invOfNot(true), 'F');
        TS_ASSERT_EQUALS(Negation::invOfNot(false), 'T');

        }

    }
