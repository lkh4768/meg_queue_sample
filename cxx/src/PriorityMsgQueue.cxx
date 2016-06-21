#include "PriorityMsgQueue.hxx"

#include <cstdio>

PriorityMsgQueue::PriorityMsgQueue() : key(0105), mode(0660){}

void PriorityMsgQueue::init()
{
	if((id = msgget(key, IPC_CREAT | mode))== -1)
	{
		std::string what("PriorityMsgQueue -> init() - ");
		what+=strerror(errno);
		what+="\n";
		throw std::runtime_error(what);
	}
}

void PriorityMsgQueue::push(Message* msg)
{
	int len = msg->get_text_len();
	printf("msg text: %s, priority : %d, len: %d\n", msg->get_text().c_str(), msg->get_priority(), len);
	if(msgsnd(id, msg, len, 0) == -1){
		std::string what("PriorityMsgQueue -> push() -> msgsnd() - ");
		what+=strerror(errno);
		throw std::runtime_error(what);
	}
}

void PriorityMsgQueue::pop(Message& rev_msg)
{
	rev_msg = Message(1, "test msg");
}

int PriorityMsgQueue::get_id()
{
	return id;
}
