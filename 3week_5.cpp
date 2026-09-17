#include <iostream>

int main() {

    int y = 5;
    int &x = y; // x의 래퍼런스를 유지해야하므로 y를 참조하도록 설정
    std::cout << x << std::endl;
}
