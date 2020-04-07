
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

auto smaller = [](int x, int y) { return x < y; };

auto larger = [](int x, int y) { return x > y; };

auto larger_absolute = [](int x, int y) { return abs(x) > abs(y); };

int main()
{
    const int n = 10;
    std::vector<int> numbers;
    for (int i = 0; i < n; ++i) {
        numbers.push_back(randomInt(-20, 20));
    }
    std::cout << "Oryginalnie: " << std::endl;
    print(numbers);
    std::sort(numbers.begin(), numbers.end(), smaller);
    std::cout << std::endl <<"Od najmniejszej: "<< std::endl;
    print(numbers);
    std::sort(numbers.begin(), numbers.end(), larger);
    std::cout << std::endl << "Od najwiekszej: " << std::endl;
    print(numbers);
    std::sort(numbers.begin(), numbers.end(), larger_absolute);
    std::cout << std::endl << "Od najwiekszej wartoœci bezwzglêdnej: " << std::endl;
    print(numbers);
}