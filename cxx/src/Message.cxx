#include "Message.hxx"

const int Message::MAX_PRIORITY = 10;
const int Message::MAX_TEXT_LEN = 50;

Message::Message(){}

Message::Message(const int priority, std::string text)
{
	if(check_priority(priority) == false)
		throw std::invalid_argument("Message error - Message priority value overflow");

	if(check_text_len(text.size()) == false)
		throw std::invalid_argument("Message error - Message text length overflow");

	priority_ = priority;
	text_ = text;
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
	return priority_;
}

std::string Message::get_text()
{
	return text_;
}

int Message::get_text_len()
{
	return text_.size();
}
