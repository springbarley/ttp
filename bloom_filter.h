#ifndef _BLOOM_FILTER_
#define _BLOOM_FILTER_
#include "header.h"
#define BIT_NUM 1000000
#define HASH_FUNC_NUM 5
/******************************************************************                                 
*     created:	10:10:2012   20:24        
*	   author:	FRYONE  
*       brief:  判断数据库中，是否出没现过的给定的key，用bloom filiter实现
*               m应该>=nlg(1/E)*lge(m是bitset的位数，n是输入实例的个数，E是出错率)
*               hash函数的个数应该为k=(ln2)*(m/n)                                  
******************************************************************/

extern const unsigned int kPrimNum;

void addBloomFilter(string& s, unsigned int (*hash_ptr[])(const string&), bitset<BIT_NUM>& bloom_bit_set);

bool searchString(string& s, unsigned int (*hash_ptr[])(const string&), bitset<BIT_NUM>& bloom_bit_set);

int testBloomFilter(void);
#endif