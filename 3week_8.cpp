#include <iostream>

int findMin(int (&arr)[5]) {
    int min = arr[0];
    for (int i = 1; i < 5; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {

    int array[5] = {8, 1, 7, 3, 5};
    int (&refArray)[5] = array;

    std::cout << "Minimum Value: " << findMin(refArray) << std::endl;

    return 0;
}
