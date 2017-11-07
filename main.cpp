#include <iostream>

#include "List.h"

int main() {
    List<int> empty;
    try {
        empty.pop_back(); // same as pop_front()
    }
    catch (const std::range_error& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << empty[-1]; // same as indexes > 0
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << empty.pop(); // same as front()
    }
    catch (const std::range_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        List<int> first = {1, 3, 5};
        List<int> second({7, 9, 11});
        std::cout << "Sizes: " << first.size()
                  << ", " << second.size() << std::endl;
        List<int> joint = first + second;
        std::cout << "Joint: " << joint << std::endl
                  << "operator+: " << first + second << std::endl;
        std::cout << "Empty: " << empty << std::endl;
        empty.push_back(1);
        std::cout << empty << ", [0] - " << empty[0] << std::endl;
        empty.push_front(100);
        std::cout << empty << ", [1] - " << empty[1]<< std::endl;
        empty.push_back(100500);
        std::cout << empty << ", [2] - " << empty[2] << std::endl;
        empty.pop_back();
        std::cout << empty << std::endl;
        empty.pop_front();
        std::cout << empty << std::endl;
        empty.clear();
        std::cout << "Empty: " << empty << std::endl;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::range_error& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
