#include <iostream>

void swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
} // 함수안에서만 바꾸고 반환을 따로 해주는게 없어서 포인터를 이용해서 바꿔야함

int main() {
    int a = 2, b = 3;
    swap(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}
