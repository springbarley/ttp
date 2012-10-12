#include "SuffixArray.h"


SuffixArray::SuffixArray(void)
{
}
SuffixArray::SuffixArray(char* file_name)
{
	if(file_name == NULL || strlen(file_name) <= 0)
	{
		cerr << "file_name error" << endl;
		exit(-1);
	}
	file_name_ = (char*)malloc(strlen(file_name) + 1);
	strcpy(file_name_, file_name);
	in_file_.open(file_name, ios::in);
	if(!in_file_)
	{
		cerr << "open file error" << endl;
	}
}
SuffixArray::~SuffixArray(void)
{
	in_file_.clear();
	in_file_.close();
}
bool SuffixArray::readToSuffix()
{
	unsigned int now_offset_ = 0;
	string word;
	while(in_file_ >> word)
	{
		offset_array_.push_back(in_file_.tellg());
	}
	in_file_.clear();//clear the flag of seek
	return true;
}
bool SuffixArray::sortSuffArray(void)
{
	if(offset_array_.size() <= 0)
	{
		cerr << "suffArray is null" << endl;
		return false;
	}
	/*sort(offset_array_.begin(), offset_array_.end(), stringLess);*/ //这种方法绑定全局函数
	/*sort(offset_array_.begin(), offset_array_.end(), binder1st<SuffixArray&>(ptr_fun(strLess), *this));*/ //这种方法把全局函数变为仿函数，然后绑定一个参数SuffixArray的引用
	sort(offset_array_.begin(), offset_array_.end(), strLess<SuffixArray>(*this));//这种sort的第三个形参，构造出了一个带SuffixArray私有对象的仿函数对象
	//sort(offset_array_.begin(), offset_array_.end());
	return 1;
}

string SuffixArray::getWordsFromText( unsigned int now_offset, char end_pos, char* filename)
{
	if(!in_file_ && !in_file_.is_open())
	{
		cerr << "fstream not open" << endl;
	}
	in_file_.seekg(now_offset, ios::beg);
	int count = 0;
	ostringstream words;
	string word;
// 	while((in_file_ >> word))
// 	{
// 		if( (count++ >= MAX_PHRASE_LENGTH) || (word.length() == 1 && word[0] == end_pos))
// 			break;
// 		else
// 		{
// 			words << word << " ";
// 		}
// 	}
	getline(in_file_, word, end_pos);
	in_file_.clear();
	//return words.str();
	return word;
}
bool SuffixArray::arrayToFile(char* offset_file)
{
	if(!offset_file || strlen(offset_file) == 0)
	{
		cerr << "offset file error" << endl;
		return false;
	}
	if(file_exists(offset_file))
	{
		cout << "file: " << offset_file << " already existed!" << endl;
		return true;
	}
	ofstream out;
	out.open(offset_file, ios::out);
	if(!out)
	{
		cerr << "fstream error" << endl;
		return false;
	}
	vector<unsigned int>::iterator iter;
	for(iter = offset_array_.begin(); iter != offset_array_.end(); iter++)
	{
		/*out << getWordsFromText(*iter, '\n') << endl;*/
		out << *iter << endl;
	}
	out.close();
	return true;
}
string SuffixArray::findMostDup()
{
	int max_count = 0;
	string max_string;
	for(size_t i = 0; i < offset_array_.size() - 1; i++)
	{
		unsigned int first = offset_array_.at(i), second= offset_array_.at(i+1);
		string words_a = getWordsFromText(first, '\n');
		string words_b = getWordsFromText(second, '\n');
		pair<int, string> p = getMostDupString(words_a, words_b);
		if(p.first >= max_count)
		{
			max_count = p.first;
			max_string = p.second;
		}
	}
	cout << "the most duplicate phrase is:" << endl << max_string << endl;
	return max_string;
}
// priority_queue<string> SuffixArray::findKMostDup(int k)
// {
// 	priority_queue<unsigned int, vector<int>, stringLess> topK;
// 	int k_count = 0;
// 	for(size_t i = 0; i < offset_array_.size() - 1; i++)
// 	{
// 		unsigned int first = offset_array_.at(i), second= offset_array_.at(i+1);
// 		string words_a = getWordsFromText(first, '\n');
// 		string words_b = getWordsFromText(second, '\n');
// 		pair<int, string> p = getMostDupString(words_a, words_b);
// 		if(p.first >= k_count)
// 		{
// 			max_count = p.first;
// 			max_string = p.second;
// 		}
// 	}
// }
bool SuffixArray::binarySearch(string key_string)
{
	if(offset_array_.size() <= 0)
	{
		cerr << "offset_arry have not get any records" << endl;
		return false;
	}
	string first_key_word = key_string.substr(0, key_string.find_first_of(" "));
	int begin = 0, end = offset_array_.size();
	do
	{
		int mid = (begin + end) / 2;
		string mid_word = getWordsFromText(offset_array_.at(mid), ' ');
		mid_word = mid_word.substr(0, mid_word.find_first_of(" "));
		if(mid_word == first_key_word)
		{
			cout << "have found: " << key_string << " in phrase: " <<  mid_word << endl;
			return 1;
		}
		else if(mid_word < first_key_word)
		{
			begin = mid + 1;
		}
		else
			end = mid - 1;
	}
	while(begin <= end);
	cout << "can't fine string: " << key_string << '!' << endl;
	return false;
}

bool SuffixArray::readSortedArray(const char* file_name)
{
	if(strlen(file_name) == 0)
	{
		cerr << "file_name error" << endl;
		return false;
	}
	if(!file_exists(file_name))
	{
		cerr << "file not existed yet!" << endl;
		return false;
	}
	ifstream in(file_name, ios::in);
	offset_array_.clear();
	int i = 0;
	int temp = 0;
	while(in >> temp)
	{
		//这里面涉及到文件流读取eof符号是，多读一次的问题
		offset_array_.push_back(temp);
	}
	return true;
}