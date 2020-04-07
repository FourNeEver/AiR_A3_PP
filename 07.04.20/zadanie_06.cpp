
#include <iostream>
#include <random>

int randomInt(int min, int max) {
    static std::default_random_engine e{};
    std::uniform_int_distribution<int> d{ min, max };
    return d(e);
}

void print(std::vector<int> vec)
{
    for (auto number = vec.begin(); number != vec.end(); ++number)
        std::cout << *number << " ,";
}

std::pair<std::vector<int>, std::vector<int>> amount(std::vector<int> vec)
{
    
    std::sort(vec.begin(), vec.end());
    std::vector<int> unq = vec;
	const auto repeat = std::unique(unq.begin(), unq.end());
    unq.erase(repeat, unq.end());
	
    std::vector<int> a;
	
	for(auto u : unq )
	{
        a.push_back(std::count(vec.begin(), vec.end(), u));
	}

    return std::make_pair(unq, a);
}

int main()
{
    const int n = 30;
    std::vector<int> numbers;
    for (int i = 0; i < n; ++i) {
        numbers.push_back(randomInt(-20, 20));
    }
    print(numbers);
    std::cout << std::endl;
    auto result = amount(numbers);
    std::cout << "Amounts: " << std::endl;
	for(unsigned int i = 0; i < result.first.size(); i++)
	{
        std::cout << result.first.at(i) << ": " << result.second.at(i) << std::endl;
	}
};