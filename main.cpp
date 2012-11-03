#include "header.h"
#include "SuffixArray.h"
#include "bloom_filter.h"
#include "SimHash.h"

void testSuffixArray()
{
	SuffixArray sa("The Holy Bible.txt");
	sa.readToSuffix();
	noticeFunFinish("readToSuffix", cout);
	sa.arrayToFile("suffix.txt");
	noticeFunFinish("arrayToFile", cout);
	sa.sortSuffArray();
	noticeFunFinish("sortSuffArray", cout);
// 	sa.readSortedArray("suffix_s.txt");
// 	noticeFunFinish("readSortedArray", cout);
	sa.arrayToFile("suffix_s.txt");
	noticeFunFinish("arrayToFile", cout);
	sa.findMostDup();
	noticeFunFinish("findMostDup", cout);
	sa.binarySearch("Mr.");
	noticeFunFinish("binarySearch", cout);
	system("pause");
}
void testOpenFile()
{
	clock_t begin =clock() ;
	ifstream is;
	for(int i = 0; i < 10000; i++)
	{
		is.open("The Holy Bible.txt");
		is.seekg(i);
		is.close();
	}
	clock_t total=clock() - begin;
	cout << "cost time: " << (double)total/CLOCKS_PER_SEC << endl;
}
int main(void)
{
	cout << sizeof(int);
	//welcomeTitle();
	//testSuffixArray();
	//testBloomFilter();
	return 0;
}