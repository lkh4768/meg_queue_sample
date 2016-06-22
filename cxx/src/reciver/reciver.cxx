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
	for(;;){
		priority_msg_q.pop(msg);

		msg.print();
	}

	return 0;
}
