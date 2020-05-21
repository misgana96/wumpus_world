#include <cxxtest/TestSuite.h>
#include <iostream>
#include <iomanip>
#include <tuple>
#include "../../Wumpus/helper/and.hpp"
#include "../../Wumpus/helper/or.hpp"
#include "../../Wumpus/helper/not.hpp"
#include "../../Wumpus/helper/implication.hpp"


using namespace Wumpus;
using namespace helper;

using namespace std;

class TestAnd: public L_and
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
        TS_ASSERT_EQUALS(TestAnd().And(true, false), 0);
        TS_ASSERT_EQUALS(TestAnd().And(true, true), 1);
        TS_ASSERT_EQUALS(TestAnd().And(false, false), 0);
        TS_ASSERT_EQUALS(TestAnd().And(false, true), 0);
    }

    /**
     * @param A is truth value either true or false
     * @return A and B which is  inverse of A
     */
    void test_invOfAnd()
    {
        TS_ASSERT_EQUALS(TestAnd().invOfAnd(true), make_tuple(true,1,true));
        // TS_ASSERT_EQUALS(TestAnd().invOfAnd(false), make_tuple(false,0,false));
    }
};

class TestOr: public Wumpus::helper::L_or
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
        TS_ASSERT_EQUALS(TestOr().Or(true, false), 1);
        TS_ASSERT_EQUALS(TestOr().Or(false, false), 0);
        TS_ASSERT_EQUALS(TestOr().Or(false, true), 1);
        TS_ASSERT_EQUALS(TestOr().Or(true, true), 1);
    }

    /**
     * @param A is truth value either true or false
     * @return A and B which is  inverse of A
     */
    void test_invOfOr()
    {
        TS_ASSERT_EQUALS(TestOr().invOfOr(false), make_tuple(false,1,false));
        // TS_ASSERT_EQUALS(TestOr().invOfOr(true), make_tuple(true,1,false));
        // TS_ASSERT_EQUALS(TestOr().invOfOr(true), make_tuple(false,1,true));
    }
};

class notSuite: public CxxTest::TestSuite
{
    Negation neg;
public:
    /**
     * @param A which is boolean either true or false
     * @return not A which is true if A is false or false if A is true
     */
    void test_getNot()
    {
        TS_ASSERT_EQUALS(neg.Not(false), true);
    }

    /**
     *  @param A which is boolean either true or false
     * @return not A which is true if A is false or false if A is true
     */
    void test_invOfNot()
    {
        TS_ASSERT_EQUALS(neg.invOfNot(true), 0);
        // TS_ASSERT_EQUALS(neg.invOfNot(false), 1);
    } 
};

class ImpSuite: public CxxTest::TestSuite
{
    implication Imp;
public:
    void test_Implication()
    {
        TS_ASSERT_EQUALS(Imp.Implication(true, false), false);
        TS_ASSERT_EQUALS(Imp.Implication(false, false), true);
        TS_ASSERT_EQUALS(Imp.Implication(true, true), true);
        TS_ASSERT_EQUALS(Imp.Implication(false, false), true);
    }

    void test_invOfImplication()
    {
        TS_ASSERT_EQUALS(Imp.invOfImplication(false), make_tuple(true,1,false));
        TS_ASSERT_EQUALS(Imp.invOfImplication(true), make_tuple(false, 0, true));
    }
};
