#include "../PriorityMsgQueue.hxx"

#include <cstdio>
#include <cstdlib>

int main(int argn ,char** argv)
{
	try
	{
		if(argn != 3)
			throw std::invalid_argument("usage: ./sender msg priority\n");
	}
	catch(const std::exception& e)
	{
		printf("%s", e.what());
		exit(1);
	}

	PriorityMsgQueue priority_msg_q;

	try
	{
		priority_msg_q.init();
	}
	catch(const std::exception& e)
	{
		printf("%s", e.what());
		exit(1);
	}

	Message msg(atoi(argv[2]), argv[1]);

	priority_msg_q.push(msg);

	return 0;
}
