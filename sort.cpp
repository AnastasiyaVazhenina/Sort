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
    size_t n1 = 0;
    std::cin >> n1;

    std::vector<int> t = generate_random_vector<int>(n1, -10, 10);
    for (int i = 0; i < t.size(); ++i)
    {
        std::cout << t[i] << " ";
    }
    std::cout << std::endl;
    int c = 0;
    for (int i = 0; i < t.size() - 1; ++i)
    {
        for (int j = i + 1; j < t.size(); ++j)
        {
            if (t[i] > t[j])
            {
                c = t[i];
                t[i] = t[j];
                t[j] = c;
            }
        }
    }
    for (int i = 0; i < t.size(); ++i)
    {
        std::cout << t[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Enter size second vector" << std::endl;
    size_t n2 = 0;
    std::cin >> n2;
    std::vector<int> a = generate_random_vector<int>(n2, -10, 10);
    for (int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    int b = 0;
    for (int i = 0; i < a.size() - 1; ++i)
    {
        for (int j = i + 1; j < a.size(); ++j)
        {
            if (a[i] > a[j])
            {
                b = a[i];
                a[i] = a[j];
                a[j] = b;
            }
        }
    }
    for (int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    int m = n1 + n2;
    std::vector<int> g(m);
    m = 0;
    int i = 0;
    int j = 0;
    while ((i < n1) && (j < n2))
    {
        if (t[i] <= a[j])
        {
            g[m] = t[i];
            ++i;
            ++m;
        } else if (t[i] > a[j])
        {
            g[m] = a[j];
            ++j;
            ++m;
        }
        if (i == n1)
        {
            for (int k = j; k < n2; ++k)
            {
                g[m] = t[k];
                ++m;
            }
        }
        if (j == n2)
        {
            for (int k = i; k < n1; ++k)
            {
                g[m] = a[k];
                ++m;
            }
        }
    }
    for (int k = 0; k < n1 + n2; ++k)
    {
        std::cout << g[k] << " ";
    }
    return 0;
}
