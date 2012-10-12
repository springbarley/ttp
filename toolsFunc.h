#pragma once
#include "header.h"
#include "SuffixArray.h"
#define NOTICE_LENGTH 50
#define NOTICE_SIMBOL '*'

/******************************************************************                                 
*     created:	6:10:2012   21:05        
*	   author:	FRYONE  
*       brief:  strLess function object, override the (), with a member variable-SuffixArray object                                   
******************************************************************/
template <class Ty>
class strLess
{
private:
	Ty& sa_;
	static int count;
public:
	strLess(Ty& sa):sa_(sa)
	{
	}
	bool operator()(unsigned int a, unsigned int b)
	{
		string words_a = sa_.getWordsFromText(a, '\n');
		string words_b = sa_.getWordsFromText(b, '\n');
		const char* pos_a = words_a.c_str(), *pos_b = words_b.c_str();
		char c_a, c_b;
		do{
			c_a = *pos_a;
			c_b = *pos_b;
			if(c_a == '\0') 
				return c_a < c_b;
		}
		while(*pos_a++ == *pos_b++);
		count++;
		if(count % 10000 == 0)
			cout << count << endl;
		return c_a < c_b;
	}
};

bool file_exists(char* file_name);

bool file_exists(const char* file_name);

pair<int, string> getMostDupString(const string& a, const string& b);

bool stringLess(unsigned int a, unsigned int b);

void noticeFunFinish(const char* function_name, ostream & os);

//bool strLess(SuffixArray& sa, unsigned int a, unsigned int b);
void welcomeTitle(void);
