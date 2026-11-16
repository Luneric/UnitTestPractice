/**
 * Unit Tests for Password class
 **/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
protected:
	PasswordTest() {}		   // constructor runs before each test
	virtual ~PasswordTest() {} // destructor cleans up after tests
	virtual void SetUp() {}	   // sets up before each test (after constructor)
	virtual void TearDown() {} // clean up after each test, (before destructor)
};

TEST(PasswordTest, one_character_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zaaaaaaaaaaz");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multiple_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZZZZZZZz");
	ASSERT_EQ(10, actual);
}

TEST(PasswordTest, no_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, whole_string_same_character)
{
	Password my_password;
	int actual = my_password.count_leading_characters("!!!!");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, only_leading_run_counted)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aabaa");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, mixed_case_true)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("passWord"));
}

TEST(PasswordTest, all_lower_case_false)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("password1!"));
}

TEST(PasswordTest, all_upper_case_false)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("PASSWORD1!"));
}

TEST(PasswordTest, no_letters_false)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("12345!@#"));
}

TEST(PasswordTest, empty_string_mixed_case_false)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case(""));
}

TEST(PasswordTest, lower_then_upper_at_end_true)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("passW"));
}

TEST(PasswordTest, upper_then_lower_true)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Password"));
}