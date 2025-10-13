#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include <cassert>

template<typename T>
void insertion_sort(T& container) {
    // The j > 0 doesn't work with unsigned sizes + 0 index counting
    assert(container.size() != std::numeric_limits<size_t>::max());

    const auto sz = container.size();
    for (auto i = 2u; i < sz + 1; ++i) {
        auto key = std::move(container[i - 1]);

        auto j = i - 1;
        while (j > 0 && container[j - 1] > key) {
            container[j + 1 - 1] = std::move(container[j - 1]);
            --j;
        }

        container[j + 1 - 1] = std::move(key);
    }
}

int main()
{
    std::vector<int> vec = {8,9,5,7,6,4,1,2,3};

    std::cout << "before" << std::endl;
    std::for_each(vec.begin(), vec.end(),[](const auto& u) {
        std::cout << u << ",";
    });
    std::cout << std::endl;

    insertion_sort(vec);

    std::cout << "after" << std::endl;
    std::for_each(vec.begin(), vec.end(),[](const auto& u) {
        std::cout << u << ",";
    });
    std::cout << std::endl;

    return 0;
}
