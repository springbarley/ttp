#ifndef _BLOOM_FILTER_
#define _BLOOM_FILTER_
#include "header.h"
#define BIT_NUM 1000000
#define HASH_FUNC_NUM 5
/******************************************************************                                 
*     created:	10:10:2012   20:24        
*	   author:	FRYONE  
*       brief:  �ж����ݿ��У��Ƿ��û�ֹ��ĸ�����key����bloom filiterʵ��
*               mӦ��>=nlg(1/E)*lge(m��bitset��λ����n������ʵ���ĸ�����E�ǳ�����)
*               hash�����ĸ���Ӧ��Ϊk=(ln2)*(m/n)                                  
******************************************************************/

extern const unsigned int kPrimNum;

void addBloomFilter(string& s, unsigned int (*hash_ptr[])(const string&), bitset<BIT_NUM>& bloom_bit_set);

bool searchString(string& s, unsigned int (*hash_ptr[])(const string&), bitset<BIT_NUM>& bloom_bit_set);

int testBloomFilter(void);
#endif