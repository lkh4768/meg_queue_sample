#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include <cerrno>
#include <cstring>

#include <stdexcept>

#include "Message.hxx"


class PriorityMsgQueue
{
	private:
		int id;
		const key_t key;
		const mode_t mode;
	public:
		PriorityMsgQueue();
		void init();
		void push(Message& msg);
		void pop(Message& msg);
		int get_id();
};

#endif
