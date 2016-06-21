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
	catch(std::exception e)
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
	catch(std::exception e)
	{
		printf("push test - %s\n", e.what());
		exit(1);
	}

	Message smsg(3, "test msg");
	try
	{
		priority_msg_queue.push(&smsg);
	}
	catch(std::exception e)
	{
		printf("push test - %s\n", e.what());
		exit(1);
	}

	Message rmsg;
	struct q_entry tmp;
	printf("id : %d\n", priority_msg_queue.get_id());
	msgrcv(priority_msg_queue.get_id(), &tmp, Message::MAX_TEXT_LEN, (-1 * Message::MAX_PRIORITY), MSG_NOERROR);
	printf("recive fin\n");

	ASSERT_STREQ(smsg.get_text().c_str(), rmsg.get_text().c_str());
	ASSERT_EQ(smsg.get_priority(), rmsg.get_priority());
}
/*
TEST_F(PriorityMsgQueueTest, pop_test)
{
	Message smsg(1, "test msg");
	msgsnd(priority_msg_queue.get_id(), &msg, msg_text_len, 0)
	try
	{
		Message* rmsg();
		rmsg = priority_msg_queue.pop();
	}
	catch(std::exception e)
	{
		printf("%s", e.what());
		exit(1);
	}

	ASSERT_STREQ(smsg.get_text(), rmsg.get_text());
	ASSERT_EQ(smsg.get_priority(), rmsg.get_priority());
}
*/
