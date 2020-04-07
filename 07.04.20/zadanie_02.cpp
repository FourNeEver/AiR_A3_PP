
#include <iostream>
#include <list>
#include <random>

int randomInt(int min, int max) {
    static std::default_random_engine e{};
    std::uniform_int_distribution<int> d{ min, max };
    return d(e);
}

void print(std::list<int> vec)
{
    for (auto number = vec.begin(); number != vec.end(); ++number)
        std::cout << *number << " ,";
}

void find_delete(std::list<int>& l, int f)
{
    for (auto number = l.begin(); number != l.end();)
    {
        if (*number == f) {
            number = l.erase(number);
        }
        else {
            ++number;
        }
    }
}

int main()
{
    const int n = 100;
    std::list<int> numbers;
    for (int i = 0; i < n; ++i) {
        numbers.push_back(randomInt(-20, 20));
    }
    print(numbers);
    std::cout << std::endl;;
    find_delete(numbers, 5);
    print(numbers);
}