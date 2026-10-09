#include <iostream>  // [추가]
#include <stdexcept> // [추가] std::invalid_argument, std::out_of_range 사용

// ======================= [추가 시작] =======================

// 1. 기본 클래스 Calculator (기초 계산기)
class Calculator {
  protected:
    double result_; // 연산 결과값 (파생 클래스에서도 접근할 수 있도록 protected)

  public:
    Calculator() : result_(0.0) {} // 멤버 초기화 리스트로 result_를 0.0으로 초기화

    double add(double a, double b) {
        result_ = a + b;
        return result_;
    }

    double subtract(double a, double b) {
        result_ = a - b;
        return result_;
    }

    double multiply(double a, double b) {
        result_ = a * b;
        return result_;
    }

    double divide(double a, double b) {
        if (b == 0) { // 나누는 수가 0이면 잘못된 인자 → invalid_argument
            throw std::invalid_argument("0으로 나눌 수 없습니다.");
        }
        result_ = a / b;
        return result_;
    }
};

// 2. 파생 클래스 EngineeringCalculator (공학용 계산기) - Calculator를 public 상속
class EngineeringCalculator : public Calculator {
  public:
    double percentage(double total, double percent) {
        if (percent < 0) { // 백분율이 허용 범위(0% 이상)를 벗어남 → out_of_range
            throw std::out_of_range("백분율은 0% 이상이어야 합니다.");
        }
        result_ = total * (percent / 100.0); // 부모의 protected 멤버 result_에 저장
        return result_;
    }
};

// 3. 컨트롤러 클래스 CalculatorController
//    - 정상 실행: try 안에서 결과 출력 후 delete
//    - 예외 발생: 해당 catch 안에서 delete → 어느 경로든 메모리 누수 없음
//    - 출력 예시에 맞춰 "메모리 해제 완료" 메시지는 정상 경로에서만 출력
class CalculatorController {
  public:
    void runDivideProcess(double a, double b) {
        EngineeringCalculator *calc = nullptr;
        try {
            calc = new EngineeringCalculator();
            double result =
                calc->divide(a, b); // b가 0이면 여기서 예외 발생 → 아래 줄들은 실행되지 않음
            std::cout << "[나눗셈 결과]: " << result << std::endl;

            delete calc;
            calc = nullptr;
            std::cout << "[CalculatorController] 동적 객체 메모리 해제 완료." << std::endl;
        } catch (const std::invalid_argument &e) {
            std::cout << "[인자 예외 포착]: " << e.what() << std::endl;
            delete calc; // 예외가 나도 메모리 해제
            calc = nullptr;
        } catch (const std::out_of_range &e) {
            std::cout << "[범위 예외 포착]: " << e.what() << std::endl;
            delete calc;
            calc = nullptr;
        }
    }

    void runPercentProcess(double total, double percent) {
        EngineeringCalculator *calc = nullptr;
        try {
            calc = new EngineeringCalculator();
            double result = calc->percentage(total, percent); // percent가 음수면 여기서 예외 발생
            std::cout << "[백분율 결과]: " << result << std::endl;

            delete calc;
            calc = nullptr;
            std::cout << "[CalculatorController] 동적 객체 메모리 해제 완료." << std::endl;
        } catch (const std::invalid_argument &e) {
            std::cout << "[인자 예외 포착]: " << e.what() << std::endl;
            delete calc;
            calc = nullptr;
        } catch (const std::out_of_range &e) {
            std::cout << "[범위 예외 포착]: " << e.what() << std::endl;
            delete calc; // 예외가 나도 메모리 해제
            calc = nullptr;
        }
    }
};

// ======================= [추가 끝] =======================

int main() {
    CalculatorController controller;

    std::cout << "case1" << std::endl;
    controller.runDivideProcess(10, 2);
    controller.runPercentProcess(200, 15);

    std::cout << "\ncase2" << std::endl;
    controller.runDivideProcess(5, 0);

    std::cout << "\ncase3" << std::endl;
    controller.runPercentProcess(100, -10);

    return 0;
}
