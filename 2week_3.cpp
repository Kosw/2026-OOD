#include <stdio.h>
void print(int var) { printf("Integer number: %d \n", var); }
void print(float var) { printf("Float number: %f \n", var); }
void print(int var1, float var2) {
    printf("Integer number: %d \n", var1);
    printf(" and float number: %f", var2);
}
int main() {
    int a = 7;
    float b = 9;
    print(a);
    print(b);
    print(a, b);
    // 확장팩 때문인지 둘다 오류는 안뜨지만 원래라면 c 확장자로 실행하면 오류가 떠야하는거같고
    // 이유는 cpp에는 method overloading 기능이 있어서 그런거같다.
    return 0;
}
