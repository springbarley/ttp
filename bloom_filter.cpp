#include "bloom_filter.h"
#include "HashFunction.h"

const unsigned int kPrimNum = 9973;

void addBloomFilter(string& s, unsigned int (*hash_ptr[])(const string&), bitset<BIT_NUM>& bloom_bit_set)
{
	for(int i = 0; i < HASH_FUNC_NUM; i++)
	{
		unsigned int key = hash_ptr[i](s);
		bloom_bit_set.set(key);
	}
}

bool searchString(const string& s, unsigned int (*hash_ptr[])(const string&), bitset<BIT_NUM>& bloom_bit_set)
{
	int i = 0;
	for(; i < HASH_FUNC_NUM; i++)
	{
		if(bloom_bit_set[hash_ptr[i](s)] == 1)
			continue;
		else
			break;
	}
	return (i == HASH_FUNC_NUM) ? true:false;
}

int testBloomFilter(void)
{
	unsigned int (*hash_ptr[HASH_FUNC_NUM])(const string&);
	hash_ptr[0] = HashFunction::hashFunc_1;
	hash_ptr[1] = HashFunction::hashFunc_2;
	hash_ptr[2] = HashFunction::hashFunc_3;
	hash_ptr[3] = HashFunction::hashFunc_4;
	hash_ptr[4] = HashFunction::hashFunc_5;

	bitset<BIT_NUM> bloom_bit_set(0);
	ifstream inFile("The Holy Bible.txt", ios::in);
	if(!inFile)
	{
		cerr << "can't open file: the holy bibles.txt" << endl;
		exit(-1);
	}
	clock_t read_beg, read_end;
	read_beg = clock();
	string s;
	while(!inFile.eof())
	{
		getline(inFile, s);
		addBloomFilter(s, hash_ptr, bloom_bit_set);
	}
	read_end = clock();
	cout << "read to bloom filter cost: " << (double)(read_end - read_beg)/CLOCKS_PER_SEC << " seconds";
	cout << endl;
	clock_t search_beg;
	clock_t search_end;
	string string_array[] = {"1.	In the beginning God created the heaven and the earth. ", 
		"13	And the evening and the morning were the third day. ",
		"10	And he said, I heard thy voice in the garden, and I was afraid, because I [was] naked; and I hid myself. ", 
	"18	Thorns also and thistles shall it to thee; and thou shalt eat the herb of the feld; "};
	search_beg = clock();
	for(int i = 0; i < 10; i++)
	{
		if(searchString(string(string_array[i]), hash_ptr, bloom_bit_set))
		{
			cout << "find the string: " << string_array[i] << endl;
		}
		else
		{
			cout << "can't find the string: " << string_array[i] << endl;
		}
	}
	search_end = clock();
	cout << "search the string cost: " << (double)(search_end - search_beg)/CLOCKS_PER_SEC << endl;
	cout << "bitset中1的个数为: " << bloom_bit_set.count() << endl;
	return 0;
}