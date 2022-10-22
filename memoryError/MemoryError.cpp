#include "MemoryError.h"

void memoryLost(int arr_size = 5){ //Выделяем память, но не удаляем ее

    int *array = new int[arr_size];
}

void extraIndex(int arr_size = 5){ //Обращаемся к несуществующему элементу массива (выход за рамки)

int *array = new int[arr_size];
array[arr_size] = 1;
array[arr_size+1] = 2;

}