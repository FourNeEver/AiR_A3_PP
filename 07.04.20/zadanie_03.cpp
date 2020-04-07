
#include <iostream>
#include <random>

int randomInt(int min, int max) {
    static std::default_random_engine e{};
    std::uniform_int_distribution<int> d{ min, max };
    return d(e);
}

void print1(std::vector<int> vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << vec.at(i) << " ,";
}
void print2(std::vector<int> vec)
{
    for (auto number = vec.begin(); number != vec.end(); ++number)
        std::cout << *number << " ,";
}

void find_delete(std::vector<int>& vec, int f)
{
    while(std::find(vec.begin(),vec.end(),f)!=vec.end())
    {
        vec.erase(std::find(vec.begin(), vec.end(), f));
    }
}

int main()
{
    const int n = 100;
    std::vector<int> numbers;
    for (int i = 0; i < n; ++i) {
        numbers.push_back(randomInt(-20, 20));
    }
    print1(numbers);
    std::cout << std::endl;;
    find_delete(numbers, 5);
    print2(numbers);
}