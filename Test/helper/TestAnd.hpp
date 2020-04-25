#include <cxxtest/TestSuite.h>
#include <iostream>
#include <iomanip>
#include <tuple>
#include "and.hpp"
#include "or.hpp"
#include "not.hpp"
#include "implication.hpp"


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
    }
};

class notSuite: public CxxTest::TestSuite
{
    Not negation;
public:
    /**
     * @param A which is boolean either true or false
     * @return not A which is true if A is false or false if A is true
     */
    void test_getNot()
    {
        bool val = negation.getNot(false);
        TS_ASSERT_EQUALS(val, true);
    }

    /**
     *  @param A which is boolean either true or false
     * @return not A which is true if A is false or false if A is true
     */
    void test_invOfNot()
    {
        bool inv = negation.invOfNot(true);
        TS_ASSERT_EQUALS(inv, false);
    } 
};

class ImpSuite: public CxxTest::TestSuite
{
    Implication Imp;
public:
    void test_Implication()
    {
        bool imp = Imp.implication(true, false);
        TS_ASSERT_EQUALS(imp, false);
    }

    void test_invOfImplication()
    {
        valuesOfImp  impVal = Imp.invOfImplication(false);
        cout << get<0>(impVal.value1) << endl;
        cout << get<1>(impVal.value1) << endl;
    }
};
