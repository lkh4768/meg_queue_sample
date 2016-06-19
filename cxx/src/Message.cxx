#include "Message.hxx"

const int Message::MAX_PRIORITY = 10;
const int Message::MAX_TEXT_LEN = 50;

Message::Message(){}

Message::Message(const int priority, std::string text)
{
	if(check_priority(priority) == false)
		throw std::invalid_argument("push error - Message priority value overflow");

	if(check_text_len(text.size()) == false)
		throw std::invalid_argument("push error - Message text length overflow");

	msg.mtype = (long) priority;
	strcpy(msg.mtext, text.c_str());
}

bool Message::check_priority(const int priority)
{
	return ((priority < 0 || priority > MAX_PRIORITY)? false:true);
}

bool Message::check_text_len(const int text_len)
{
	return ((text_len > MAX_TEXT_LEN)? false:true);
}

int Message::get_priority()
{
	return (int)(msg.mtype);
}

std::string Message::get_text()
{
	return std::string(msg.mtext);
}

struct q_entry* Message::get_msg()
{
	return &msg;
}
