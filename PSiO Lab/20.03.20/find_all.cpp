#include <iostream>
#include <string>
#include <vector>

std::vector<size_t> find_all(std::string word, char s)
{
	std::vector<size_t> result;
	int pos = -1;
	while(word.find(s, pos + 1)!=std::string::npos)
	{
		pos = (word.find(s, pos + 1));
		result.push_back(pos);
	}
	return result;
}

void print(std::vector<size_t> const& input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

int main()
{
	std::string word;
	char searched;
	std::cout << "Podaj wyrazenie: ";
	std::getline(std::cin, word);
	std::cout << "Podaj litere ktorej szukasz: ";
	std::cin >> searched;
	std::vector<size_t> pos = find_all(word, searched);
	print(find_all(word, searched));
}
