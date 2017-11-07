#include <iostream>

#include "List.h"

enum {
    SUCCESS = 0,
    RANGE_ERROR,
    INVALID_ARGUMENT,
    BAD_ALLOC,
    IOS_BASE_FAILURE,
};

int main() {
    List<int> empty;
    int error_code = SUCCESS;
    try {
        empty.pop_back(); // same as pop_front()
    }
    catch (const std::range_error& e) {
        std::cerr << e.what() << std::endl;
        error_code = RANGE_ERROR;
    }
    try {
        std::cout << empty[1]; // indexes > 0
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        error_code = INVALID_ARGUMENT;
    }
    try {
        std::cout << empty.pop(); // same as front()
    }
    catch (const std::range_error& e) {
        std::cerr << e.what() << std::endl;
        error_code = RANGE_ERROR;
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
        error_code = BAD_ALLOC;
    }
    catch (const std::range_error& e) {
        std::cerr << e.what() << std::endl;
        error_code = RANGE_ERROR;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        error_code = INVALID_ARGUMENT;
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << std::endl;
        error_code = IOS_BASE_FAILURE;
    }

    return error_code;
}
