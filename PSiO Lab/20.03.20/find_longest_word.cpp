#include <iostream>
#include <string>


std::string find_longest_word(std::string sentence)
{
	std::string long_word = " ";
	std::string word;
	int begin = 0;
	for(int i = 0; i < sentence.length()-1; i++)
	{
		if(sentence.at(i)==32)
		{
			word = sentence.substr(begin, i - begin);
			begin = i + 1;
		}
		if (word.length() > long_word.length())
		{
			long_word = word;
		}
	}
	
	word = sentence.substr(begin, sentence.length() - begin);
	
	if (word.length() > long_word.length())
	{
		long_word = word;
	}
	return long_word;
}


int main()
{
	std::string word;
	std::cout << "Podaj wyrazenie: ";
	std::getline(std::cin, word);

	std::cout << find_longest_word(word) << std::endl;

	return 0;
}
