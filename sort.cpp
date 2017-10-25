#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>
template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);
    auto lambda = [&e2, &dist] () -> T { return dist(e2); };
    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}

int main()
{
    std::cout << "Enter size first vector" << std::endl;
    size_t length1 = 0;
    std::cin >> length1;

    std::vector<int> set1 = generate_random_vector<int>(length1, -10, 10);
    for (int i = 0; i < set1.size(); ++i)
    {
        std::cout << set1[i] << " ";
    }
    std::cout << std::endl;
    int c = 0;
    for (int i = 0; i < set1.size() - 1; ++i)
    {
        for (int j = i + 1; j < set1.size(); ++j)
        {
            if (set1[i] > set1[j])
            {
                c = set1[i];
                set1[i] = set1[j];
                set1[j] = c;
            }
        }
    }
    for (int i = 0; i < set1.size(); ++i)
    {
        std::cout << set1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Enter size second vector" << std::endl;
    size_t length2 = 0;
    std::cin >> length2;
    std::vector<int> set2 = generate_random_vector<int>(length2, -10, 10);
    for (int i = 0; i < set2.size(); ++i)
    {
        std::cout << set2[i] << " ";
    }
    std::cout << std::endl;
    int b = 0;
    for (int i = 0; i < set2.size() - 1; ++i)
    {
        for (int j = i + 1; j < set2.size(); ++j)
        {
            if (set2[i] > set2[j])
            {
                b = set2[i];
                set2[i] = set2[j];
                set2[j] = b;
            }
        }
    }
    for (int i = 0; i < set2.size(); ++i)
    {
        std::cout << set2[i] << " ";
    }
    std::cout << std::endl;
    int maxlength = length1 + length2;
    std::vector<int> finalArray(maxlength);
    maxlength = 0;
    int i = 0;
    int j = 0;
    while ((i < length1) && (j < length2))
    {
        if (set1[i] <= set2[j])
        {
            finalArray[maxlength] = set1[i];
            ++i;
            ++maxlength;
        }
        else if (set1[i] > set2[j])
        {
            finalArray[maxlength] = set2[j];
            ++j;
            ++maxlength;
        }
        if (i == length1)
        {
            for (int k = j; k < length2; ++k)
            {
                finalArray[maxlength] = set1[k];
                ++maxlength;
            }
        }
        if (j == length2)
        {
            for (int k = i; k < length1; ++k)
            {
                finalArray[maxlength] = set2[k];
                ++maxlength;
            }
        }
    }
    for (int k = 0; k < length1 + length2; ++k)
    {
        std::cout << finalArray[k] << " ";
    }
    return 0;
}
