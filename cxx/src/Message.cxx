#include "Message.hxx"

const long Message::MAX_PRIORITY = 10;
const int Message::MAX_TEXT_LEN = MAXTEXT;

Message::Message()
{
	msg.mtext[0] = NULL;
	msg.mtype = -1;
}

Message::Message(const long priority, const char* text)
{
	if(check_priority(priority) == false)
		throw std::invalid_argument("Message error - Message priority value overflow");

	if(check_text_len(strlen(text)) == false)
		throw std::invalid_argument("Message error - Message text length overflow");

	strncpy(msg.mtext, text, MAX_TEXT_LEN);
	msg.mtype = priority;
}

bool Message::check_priority(const long priority)
{
	return ((priority < 0 || priority > MAX_PRIORITY)? false:true);
}

bool Message::check_text_len(const int text_len)
{
	return ((text_len > MAX_TEXT_LEN)? false:true);
}

struct q_entry* Message::get_msg()
{
	return &msg;
}

long Message::get_priority()
{
	return msg.mtype;
}

char* Message::get_text()
{
	return msg.mtext;
}

int Message::get_text_len()
{
	return strlen(msg.mtext);
}

void Message::print()
{
	printf("recive msg text : %s, priority : %ld\n", msg.mtext, msg.mtype);
}
