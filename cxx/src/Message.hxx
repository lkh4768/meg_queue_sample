#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstring>

#include <string>
#include <stdexcept>

class Message
{
	private:
		std::string text_;
		int priority_;
	public:
		static const int MAX_PRIORITY;
		static const int MAX_TEXT_LEN;
		Message();
		Message(const int priority, std::string text);
		bool check_priority(const int priority);
		bool check_text_len(const int text_len);
		int get_priority();
		std::string get_text();
		int get_text_len();
};

#endif
