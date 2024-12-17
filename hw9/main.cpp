#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

const int size = 100;

int findMinSumPosition(int arr[], int start, int length) {
    if (start > size - length) return -1; 

    int currentSum = 0;
    for (int i = start; i < start + length; ++i) {
        currentSum += arr[i];
    }

    int nextPosition = findMinSumPosition(arr, start + 1, length);
    if (nextPosition == -1) return start;

    int nextSum = 0;
    for (int i = nextPosition; i < nextPosition + length; ++i) {
        nextSum += arr[i];
    }

    return (currentSum < nextSum) ? start : nextPosition;
}


int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    srand(static_cast<unsigned int>(time(0)));
    int arr[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }

    int position = findMinSumPosition(arr, 0, 10);
    std::cout << "ѕозици€ с которой начинаетс€ последовательность: " << position << "\n";




    return 0;
}

