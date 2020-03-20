#include <iostream>
#include <string>




std::string find_and_replace(std::string sentence, std::string word, std::string new_word)
{
	while (sentence.find(word) != std::string::npos) sentence.replace(sentence.find(word), word.length(), new_word);

	return  sentence;
}
int main()
{
	std::string sentence, searched, replace;
	std::cout << "Podaj wyrazenie: ";
	std::getline(std::cin, sentence);
	std::cout << "Podaj szukane slowo: ";
	std::getline(std::cin, searched);
	std::cout << "Podaj slowo do wymiany: ";
	std::getline(std::cin, replace);
	std::cout << find_and_replace(sentence, searched, replace) << std::endl;
}