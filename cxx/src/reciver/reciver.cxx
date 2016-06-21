#include "../Message.hxx"
#include "../PriorityMsgQueue.hxx"

#include <cstdio>
#include <cstdlib>

int main()
{
	PriorityMsgQueue priority_msg_q;

	try
	{
		priority_msg_q.init();
	}
	catch(std::exception e)
	{
		printf("%s", e.what());
		exit(1);
	}

	Message msg;
	msgrcv(priority_msg_q.get_id(), &msg, Message::MAX_TEXT_LEN, (-1 * Message::MAX_PRIORITY), MSG_NOERROR);

	printf("text : %s, priority : %d\n", msg.get_text().c_str(), msg.get_priority());

	return 0;
}
