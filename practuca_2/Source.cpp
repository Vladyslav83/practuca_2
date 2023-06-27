#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> L1;
    std::list<int> L2;

    int num;
    std::cout << "Enter elements for list L1 (enter -1 to stop):\n";
    while (std::cin >> num && num != -1) {
        L1.push_back(num);
    }

    std::cout << "Enter elements for list L2 (enter -1 to stop):\n";
    while (std::cin >> num && num != -1) {
        L2.push_back(num);
    }

    L1.sort();

    std::list<int>::iterator it1 = L1.begin();
    std::list<int>::const_iterator it2 = L2.begin();

    while (it1 != L1.end() && it2 != L2.end()) {
        if (*it2 < *it1) {
            it1 = L1.insert(it1, *it2);
            it2++;
        }
        else {
            it1++;
        }
    }

    int count = 0;
    for (const auto& element : L1) {
        std::cout << element << " ";
        count++;
        if (count == 10) {
            std::cout << std::endl;
            count = 0;
        }
    }

    return 0;
}
