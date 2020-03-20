#include <iostream>
#include <string>

bool is_palindrome(std::string word)
{
	while(word.find(32) != std::string::npos)
	{
		word.erase(word.find(32), 1);
	}

	for(int i = 0; i < word.length(); i++ )
	{
		
		char t1 = tolower(word.at(i));
		char t2 = tolower(word.at(word.length()- 1 - i));
		
		if (t1 != t2) return false;
		
	}
	return true;
}

int main()
{
	std::string word;
	std::cout << "Podaj wyrazenie: ";
	std::getline(std::cin, word);
	
	if (is_palindrome(word)) {
		std::cout << "To palindrom!" << std::endl;
	}
	else {
		std::cout << "Nope" << std::endl;
	}
	return 0;
}
