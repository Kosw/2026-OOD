/*
    실습 4-1
        int a=5;
        int b=a;
        int c=a+b;
        (a,b,c,5,a+b)의 rvalue와 lvalue를 구분하시오
        lvalue는 특정 메모리 위치를 가리키고 변수는 특정 메모리 주소가 있으므로 a,b,c가 lvalue
        lvalue이지만 더하기 연산자는 rvalue를 취하기 때문에 a+b는 rvalue, 5는 상수이므로 rvalue
*/
// 실습 4-2
#include <iostream>

int &func(int &a) { return a; } // &를 사용해서 lvalue를 반환하도록 함

int main() {
    int x = 1;

    std::cout << func(x)++ << std::endl;
    std::cout << x << std::endl;
}
