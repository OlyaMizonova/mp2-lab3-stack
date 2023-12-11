#include"TStack.h"
#include "gtest.h"
#include "Calculator.h"

TEST(TCalculator, can_create_calculator)
{
    std::string a = "1+1";
    ASSERT_NO_THROW(TCalculator calc(a));
} 

TEST(TCalculator, can_get_infix_form_of_calculator)
{
    std::string a = "2+(3*5)";
    std::string b;
    TCalculator calc(a);
    ASSERT_NO_THROW(b = calc.get_infix());
    EXPECT_EQ(a, b);
}
TEST(TCalculator, can_set_infix_form_of_calculator)
{
    std::string a = "2+(3*5)";
    std::string b;
    TCalculator c(a);
    ASSERT_NO_THROW(c.set_infix(b));
    EXPECT_EQ(c.get_infix(), b);
}
TEST(TCalculator, can_get_correct_postfix_form_of_calculator_if_the_number_of_brackets_is_correct)
{
    std::string a = "2+(3*5)";
    std::string b = "235*+";
    std::string c;
    TCalculator ca(a);
    ASSERT_NO_THROW(c = ca.get_postfix());
    EXPECT_EQ(c, b);
}
TEST(TCalculator, cant_get_correct_postfix_form_of_calculator_if_the_number_of_brackets_is_incorrect)
{
    std::string a = "2+((3*5)";
    std::string b = "235*+";
    std::string c;
    TCalculator calc(a);
    c = calc.get_postfix();
    EXPECT_NE(c, b);
}
TEST(TCalculator, check_expression_return_true_when_the_number_of_brackets_is_correct)
{
    std::string a = "2+(3*5)";  
    TCalculator ca(a);
    bool check;
    ASSERT_NO_THROW(check = ca.isCorrect());
    EXPECT_EQ(1, check);
}
TEST(TCalculator, check_expression_return_false_when_the_number_of_brackets_is_incorrect)
{
    std::string a = "2+((3*5)";
    TCalculator ca(a);
    bool check;
    ASSERT_NO_THROW(check = ca.isCorrect());
    EXPECT_EQ(0, check);
}

TEST(TCalculator, check_add){
    std::string s = "2+3";
    TCalculator ca(s);
    double check = ca.calc();
    ASSERT_NO_THROW(ca.calc());
    EXPECT_EQ(5, check);
    ASSERT_NO_THROW(check = ca.CalcPostfix());
}

TEST(TCalculator, check_sub) {
    std::string s = "2-3";
    TCalculator ca(s);
    double check = ca.calc();
    ASSERT_NO_THROW(ca.calc());
    EXPECT_EQ(-1, check);
    ASSERT_NO_THROW(check = ca.CalcPostfix());
}

TEST(TCalculator, check_mul) {
    std::string s = "2*3";
    TCalculator ca(s);
    double check = ca.calc();
    ASSERT_NO_THROW(ca.calc());
    EXPECT_EQ(6, check);
    ASSERT_NO_THROW(check = ca.CalcPostfix());
}

TEST(TCalculator, check_div) {
    std::string s = "4/3";
    TCalculator ca(s);
    double check = ca.calc(),x = 4.0/3;
    ASSERT_NO_THROW(ca.calc());
    EXPECT_EQ(x, check);
    ASSERT_NO_THROW(check = ca.CalcPostfix());
}

TEST(TCalculator, check_pow) {
    std::string s = "2^3";
    TCalculator ca(s);
    double check = ca.calc(), x = pow(2.0,3.0);
    ASSERT_NO_THROW(ca.calc());
    EXPECT_EQ(x, check);
    ASSERT_NO_THROW(check = ca.CalcPostfix());
}

TEST(TCalculator, can_calculate_first_if_the_number_of_brackets_is_correct)
{
    std::string a = "5+(3*7)-(5*(5-1)/5)";
    TCalculator ca(a);
    double check, x;
    check = ca.CalcPostfix();
    x = 5 + 3 * 7 - (5 * (5 - 1)/5.0);
    ASSERT_NO_THROW(check = ca.CalcPostfix());
    EXPECT_EQ(x, check);
}

TEST(TCalculator, can_calculate_second_if_the_number_of_brackets_is_correct)
{
    std::string a = "5+3*7-(15*(5-1.5))";
    TCalculator ca(a);
    double check, x;
    x = 5+3*7-(15*(5-1.5));
    check = ca.calc();
    ASSERT_NO_THROW(check = ca.calc());
    EXPECT_EQ(x, check);
}

TEST(TCalculator, cant_calculate_if_the_number_of_brackets_is_incorrect)
{
    std::string a = "2+((3*5)";
    TCalculator ca(a);
    double check;
    ASSERT_ANY_THROW(check = ca.CalcPostfix());
    EXPECT_NE(17, check);
}