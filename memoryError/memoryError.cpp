#include "memoryError.h"


int * memoryLost(int arrSize = 5) {  // Выделяем память, но не удаляем ее
    int *array = new int[arrSize];
    return array;
}

void extraIndex(int arrSize = 5) {  // Обращаемся к несуществующему элементу массива (выход за рамки)
    int *array = new int[arrSize];
    array[arrSize] = 1;
    array[arrSize+1] = 2;
}
