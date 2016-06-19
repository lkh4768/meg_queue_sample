#include "PriorityMsgQueue.hxx"

#include <cstdio>

PriorityMsgQueue::PriorityMsgQueue() : key(0105), mode(0660){}

void PriorityMsgQueue::init()
{
	if((id = msgget(key, IPC_CREAT | mode))== -1){
		std::string what("PriorityMsgQueue -> init() - ");
		what+=strerror(errno);
		throw std::runtime_error(what);
	}
}

void PriorityMsgQueue::push(Message* msg)
{
	printf("id %d\n", id);
	if(msgsnd(id, msg->get_msg(), Message::MAX_TEXT_LEN, 0) == -1){
		std::string what("PriorityMsgQueue -> push() -> msgsnd() - ");
		what+=strerror(errno);
		throw std::runtime_error(what);
	}
}

Message* PriorityMsgQueue::pop()
{
	Message msg(1, "test msg");

	return &msg;
}

int PriorityMsgQueue::get_id()
{
	return id;
}
