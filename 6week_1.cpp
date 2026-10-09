#include <iostream>
#include <stdexcept>
#include <string>

// (1) 이 함수는 절대로 예외를 던지지 않음을 컴파일러 및 사용자에게 명시합니다.
void printMessage(const std::string &msg) noexcept { std::cout << "[LOG] " << msg << std::endl; }

// (2) 인자 x 가 0 미만이면 std::invalid_argument 예외를 던집니다.
double calculateSquareRoot(double x) {
    if (x < 0) {
        throw std::invalid_argument("음수의 제곱근 계산 불가");
    }
    return x;
}

// (3) 인덱스 idx 가 범위를 벗어나면 std::out_of_range 예외를 던집니다.
int getElement(int arr[], int size, int idx) {
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("배열 인덱스 범위를 초과");
    }
    return arr[idx];
}

int main() {
    try {
        int arr[5] = {
            0,
        };
        printMessage("프로그램 시작");
        getElement(arr, 5, 6);
    } catch (const std::exception &e) {
        std::cout << "예외 발생1: " << e.what() << std::endl;
        try {
            calculateSquareRoot(-5.0);
        } catch (const std::exception &e) {
            std::cout << "예외 발생2: " << e.what() << std::endl;
        }
    }
    return 0;
}
