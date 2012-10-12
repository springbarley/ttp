#pragma once
#include "header.h"

extern const unsigned int kPrimNum;//kPrimNum已经在bloom_filter中被定义
/******************************************************************                                 
*     created:	10:10:2012   20:51        
*	   author:	FRYONE  
*       brief:  Hash Function Class                                  
******************************************************************/
class HashFunction
{
public:
	static unsigned int hashFunc_1(const string& s)
	{
		unsigned int hash_key = 0;
		for(size_t i = 0; i < s.length(); i++)
			hash_key += hash_key * 5 + s[i];
		return hash_key%kPrimNum;
	}
	static unsigned int hashFunc_2(const string& s)
	{
		unsigned int hash_key = 0;
		for(size_t i = 0; i < s.length(); i++)
			hash_key = (hash_key << 8) + (hash_key << 16) + s[i];
		return hash_key%kPrimNum;
	}
	static unsigned int hashFunc_3(const string& s)
	{
		unsigned int hash_key = 0;
		for(size_t i = 0; i < s.length(); i++)
			hash_key = (hash_key << 8) + (hash_key << 16) + s[i] + 3;
		return hash_key%kPrimNum;
	}
	static unsigned int hashFunc_4(const string& s)
	{
		unsigned int hash_key = 0;
		for(size_t i = 0; i < s.length(); i++)
			hash_key = (hash_key << 7) + (hash_key << 16) + s[i] - hash_key;
		return hash_key%kPrimNum;;
	}
	static unsigned int hashFunc_5(const string& s)
	{
		unsigned int hash_key = 0;
		for(size_t i = 0; i < s.length(); i++)
			hash_key = (hash_key << 6) + (hash_key << 16) + s[i] - hash_key;
		return hash_key%kPrimNum;
	}
};

