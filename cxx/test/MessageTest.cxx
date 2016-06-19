#include <limits.h>
#include "gtest/gtest.h"
#include "../src/Message.hxx"

class MessageTest : public ::testing::Test
{
	public:
		Message msg;
	protected:
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST_F(MessageTest, check_priority_test)
{
	ASSERT_TRUE(msg.check_priority(3));
	ASSERT_FALSE(msg.check_priority(12));
	ASSERT_FALSE(msg.check_priority(-1));
}

TEST_F(MessageTest, check_text_len_test)
{
	ASSERT_TRUE(msg.check_text_len(10));
	ASSERT_FALSE(msg.check_text_len(100));
}
