#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> split(std::string sentence, char separator)
{
	
	std::vector<std::string> words;
	int begin = 0;
	for (int i = 0; i < sentence.length() - 1; i++)
	{
		if (sentence.at(i) == separator)
		{
			words.push_back(sentence.substr(begin, i - begin));
			begin = i + 1;
		}
	}

	words.push_back(sentence.substr(begin, sentence.length() - begin));

	return words;
}

void print(std::vector<std::string> const& input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ", ";
	}
}

int main()
{
	std::string word;
	char sep;
	std::cout << "Podaj wyrazenie: ";
	std::getline(std::cin, word);
	std::cout << "Podaj separator: ";
	sep=getchar();

	print(split(word,sep));
}
