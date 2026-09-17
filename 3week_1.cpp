#include <iostream>

void increment(int x) {
    ++x; // 복사본만 56 이 되고, 함수가 끝나면 사라진다 따로 반환하는게 없음 포인터도 아니고
}

int main() {
    int x = 55;
    std::cout << " Before increment: " << x << std::endl;
    increment(x);
    std::cout << " After increment: " << x << std::endl;

    system("pause");
    return 0;
}
