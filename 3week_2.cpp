#include <iostream>

void increment(int *x) {
    ++*x; // 포인터를 통해 원본 값을 수정
}

int main() {
    int x = 55;
    std::cout << " Before increment: " << x << std::endl;
    increment(&x);
    std::cout << " After increment: " << x << std::endl;

    system("pause");
    return 0;
}
