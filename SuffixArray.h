#pragma once
#include "header.h"
#include "toolsFunc.h"

/******************************************************************                                 
*     created:	5:10:2012   15:07        
*	   author:	FRYONE  
*       brief:  use suffix array to find max duplicate phrase of a en/ch text file                                 
******************************************************************/
class SuffixArray
{
private:
	char* file_name_;
	ifstream in_file_;
	vector<unsigned int> offset_array_;
public:
	SuffixArray(void);
	SuffixArray(char* file_name);
	~SuffixArray(void);
	bool readToSuffix(void);
	string getWordsFromText( unsigned int now_offset, char end_pos, char* file_name= "english.txt");
	bool sortSuffArray(void);
	bool arrayToFile(char* offset_file);
	bool arrayToFile(void);
	string findMostDup(void);
	priority_queue<string> findKMostDup(int k);
	bool binarySearch(string key_string);
	bool readSortedArray(const char* file_name);
};

