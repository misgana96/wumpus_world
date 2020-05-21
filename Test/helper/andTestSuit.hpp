//andTestSuit.hpp
#include <cxxtest/TestSuite.h>
#include "../../Wumpus/helper/and.hpp"

using namespace std;
using namespace Wumpus::helper;

class andTestSuit : public CxxTest::TestSuit{
    public:
    void testAnd(){
        L_and test;
        TS_ASSERT_EQUALS(test.And(true,true), 1);
        TS_ASSERT_EQUALS(test.And(false,true), 0);
        TS_ASSERT_EQUALS(test.And(false,true), 0);
        TS_ASSERT_EQUALS(test.And(false,true), 0);
        TS_ASSERT_EQUALS(test.invOfAnd(true), make_tuple(true,1,true));
        TS_ASSERT_EQUALS(test.invOfAnd(false), make_tuple(false,0,false));

        }

    }
