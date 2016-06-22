#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <limits.h>
#include "gtest/gtest.h"
#include "../src/PriorityMsgQueue.hxx"
#include "../src/Message.hxx"

class PriorityMsgQueueTest : public ::testing::Test
{
	public:
		PriorityMsgQueue priority_msg_queue;
	protected:
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST_F(PriorityMsgQueueTest, init_test)
{
	try
	{
		priority_msg_queue.init();
	}
	catch(const std::exception& e)
	{
		printf("init test - %s", e.what());
		exit(1);
	}

	ASSERT_GT(priority_msg_queue.get_id(), -1); 
};

TEST_F(PriorityMsgQueueTest, push_test)
{
	try
	{
		priority_msg_queue.init();
	}
	catch(const std::exception& e)
	{
		printf("push test - %s\n", e.what());
		exit(1);
	}

	Message smsg(3, "test_msg");
	try
	{
		priority_msg_queue.push(smsg);
	}
	catch(const std::exception& e)
	{
		printf("push test - %s\n", e.what());
		exit(1);
	}

	Message rmsg;
	int nrcv = msgrcv(priority_msg_queue.get_id(), rmsg.get_msg(), Message::MAX_TEXT_LEN, (-1 * Message::MAX_PRIORITY), MSG_NOERROR);

	rmsg.get_text()[nrcv] = '\0';
	ASSERT_STREQ(smsg.get_text(), rmsg.get_text());
	ASSERT_EQ(smsg.get_priority(), rmsg.get_priority());
}

TEST_F(PriorityMsgQueueTest, pop_test)
{
	try
	{
		priority_msg_queue.init();
	}
	catch(const std::exception& e)
	{
		printf("push test - %s\n", e.what());
		exit(1);
	}

	Message smsg(1, "test_msg");
	msgsnd(priority_msg_queue.get_id(), smsg.get_msg(), smsg.get_text_len(), 0);

	Message rmsg;
	try
	{
		priority_msg_queue.pop(rmsg);
	}
	catch(const std::exception& e)
	{
		printf("pop test - %s", e.what());
		exit(1);
	}

	ASSERT_STREQ(smsg.get_text(), rmsg.get_text());
	ASSERT_EQ(smsg.get_priority(), rmsg.get_priority());
}
