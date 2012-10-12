#include "toolsFunc.h"

int strLess<SuffixArray>::count = 0;
pair<int, string> getMostDupString(const string& a, const string& b)
{
	if(a.length() == 0 || b.length() == 0)
		return make_pair(0, "");
	size_t i = 0;
	ostringstream oss;
	do
	{
		if(a.at(i) != b.at(i))
			break;
		oss << a.at(i++);
	}
	while(i < a.length() && i < b.length());
	return make_pair(i, oss.str());
}

bool stringLess(unsigned int a, unsigned int b)
{
	SuffixArray sa("english.txt");
	string words_a = sa.getWordsFromText(a, '\n');
	string words_b = sa.getWordsFromText(b, '\n');
	const char* pos_a = words_a.c_str(), *pos_b = words_b.c_str();
	char c_a, c_b;
	do{
		c_a = *pos_a;
		c_b = *pos_b;
		if(c_a == '\0')
			return c_a < c_b;
	}
	while(*pos_a++ == *pos_b++);
	return c_a < c_b; 
}
void noticeFunFinish(const char* function_name, ostream& os)
{
	if(strlen(function_name) <= 0)
	{
		cerr << "function_name in printLine error";
		return;
	}
	os << endl;
	os << "function: ";
	os << function_name;
	os << " over¡­¡­" << endl;  
	for(int i = 0; i < NOTICE_LENGTH; i++)
		os << NOTICE_SIMBOL;
	os << endl;
}
bool file_exists(const char* file_name)
{
	ifstream in;
	in.open(file_name, ios::in);
	if(!in)
	{
		return false;
	}
	return true;
}
bool file_exists(char* file_name)
{
	ifstream in;
	in.open(file_name, ios::in);
	if(!in)
	{
		return false;
	}
	return true;
}

void welcomeTitle()
{
	for(int i = 0; i < 1.5*NOTICE_LENGTH; i++)
		cout << NOTICE_SIMBOL;
	cout << endl;
	
	setw(1.5*NOTICE_LENGTH);
	setiosflags(ios::left);
	cout << NOTICE_SIMBOL;
	string s("have dominion over the fish of the sea, and over the fowl of air......");
	s.push_back(' ');
	s.push_back(NOTICE_SIMBOL);
	cout << setw(1.5*NOTICE_LENGTH - 1) << s;
	cout<< endl;

	setw(1.5*NOTICE_LENGTH);
	setiosflags(ios::left);
	cout << NOTICE_SIMBOL;
	string s_2("by the holy bibles");
	s_2.push_back(' ');
	s_2.push_back(NOTICE_SIMBOL);
	cout << setw(1.5*NOTICE_LENGTH - 1) << s_2;
	cout << endl;

	for(int i = 0; i < 1.5*NOTICE_LENGTH; i++)
		cout << NOTICE_SIMBOL;
	cout << endl;

	cout << "welcome to fry's text processing platform!" << endl;
}