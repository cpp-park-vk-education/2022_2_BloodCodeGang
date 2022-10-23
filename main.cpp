#include <iostream>

#include "./memoryError/memoryError.h"
#include "./bitCounter/bitCounter.h"
#include "./bitInversion/bitInversion.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    run(std::cin, std::cout);

    start(std::cin, std::cout);

    int arr_size = 10;
    // memoryLost(arr_size);
    // extraIndex(arr_size);
    return 0;
}