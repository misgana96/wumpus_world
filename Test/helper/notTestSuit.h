//notTestSuit.hpp
#include <cxxtest/TestSuite.h>
#include "../../wumpus_world/helper/not.hpp"
using namespace std;
using namespace wumpus_world::helper;
class notTestSuite : public CxxTest::TestSuite{
    public:
    void testNot(){
        Negation test;

        TS_ASSERT_EQUALS(test.Not(true), 0);
        TS_ASSERT_EQUALS(test.Not(false), 1);
        TS_ASSERT_EQUALS(test.invOfNot(true), 'F');
        TS_ASSERT_EQUALS(test.invOfNot(false), 'F');

        }

    };
