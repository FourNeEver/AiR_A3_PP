
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

int randomInt(int min, int max) {
    static std::default_random_engine e{};
    std::uniform_int_distribution<int> d{ min, max };
    return d(e);
}

void print(std::vector<int> vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << vec.at(i) << " ,";
}

int main()
{
    const int n = 10;
    std::vector<int> numbers;
    for (int i = 0; i < n; ++i) {
        numbers.push_back(randomInt(-20, 20));
    }
    print(numbers);
    std::cout << std::endl;
	
    std::cout << "Largest element: " << *std::max_element(numbers.begin(), numbers.end()) << std::endl;
    std::cout << "Smallest element: " << *std::min_element(numbers.begin(), numbers.end()) << std::endl;
    const auto result = std::minmax_element(numbers.begin(), numbers.end());
    std::cout << "Largest element: " << *result.second << std::endl;
    std::cout << "Smallest element: " << *result.first << std::endl;
}