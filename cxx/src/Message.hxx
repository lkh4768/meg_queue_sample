#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstring>
#include <cstdio>

#include <stdexcept>

#define MAXTEXT	50

struct q_entry
{
	long mtype;
	char mtext[MAXTEXT];
};

class Message
{
	private:
		struct q_entry msg;
	public:
		static const long MAX_PRIORITY;
		static const int MAX_TEXT_LEN;
		Message();
		Message(const long priority, const char* text);
		bool check_priority(const long priority);
		bool check_text_len(const int text_len);
		struct q_entry* get_msg();
		long get_priority();
		char* get_text();
		int get_text_len();
		void print();
};

#endif
