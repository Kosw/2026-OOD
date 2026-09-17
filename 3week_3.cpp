#include <iostream>

void increment(int &x) {
    ++x; // 실습3 래퍼런스 활용
}

int main() {
    int x = 55;
    std::cout << " Before increment: " << x << std::endl;
    increment(x);
    std::cout << " After increment: " << x << std::endl;

    system("pause");
    return 0;
}
