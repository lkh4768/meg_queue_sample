#include "PriorityMsgQueue.hxx"

#include <cstdio>

PriorityMsgQueue::PriorityMsgQueue() : key(0105), mode(0660) {}

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

void PriorityMsgQueue::push(Message& msg)
{
	int len = msg.get_text_len();
	if(msgsnd(id, msg.get_msg(), len, 0) == -1){
		std::string what("PriorityMsgQueue -> push() -> msgsnd() - ");
		what+=strerror(errno);
		what+="\n";
		throw std::runtime_error(what);
	}
}

void PriorityMsgQueue::pop(Message& msg)
{
	int nrcv;
	if((nrcv = msgrcv(id, msg.get_msg(), Message::MAX_TEXT_LEN, (-1 * Message::MAX_PRIORITY), MSG_NOERROR)) == -1)
	{
		std::string what("PriorityMsgQueue -> pop() -> msgrcv() - ");
		what+=strerror(errno);
		what+="\n";
		throw std::runtime_error(what);
	}

	msg.get_text()[nrcv] = '\0';
}

int PriorityMsgQueue::get_id()
{
	return id;
}
