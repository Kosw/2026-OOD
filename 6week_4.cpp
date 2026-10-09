#include <iostream>
#include <stdexcept>
#include <string>

// 1. 기본 계좌 클래스
class Account {
  protected:
    int balance_; // 자식 클래스에서 접근 가능하도록 설정
  public:
    // TODO 1: 생성자 구현 (초기 잔액이 0 미만이면 std::invalid_argument 예외 발생)
    Account(int balance) : balance_(balance) { // [추가] 초기화 리스트로 balance_ 초기화
        // [추가 시작] 초기 잔액이 0 미만이면 invalid_argument 예외
        if (balance < 0) {
            throw std::invalid_argument("초기 잔액은 0원 이상이어야 합니다.");
        }
        // [추가 끝]
    }
    int getBalance() const { return balance_; }
};

// 2. 마이너스 통장 클래스 (Account 상속)
// TODO 2: Account 클래스를 public 상속받도록 선언
class MinusAccount : public Account {
  private:
    int limit_; // 마이너스 한도 (예: 10000이면 -10000원까지 출금 가능)
  public:
    // TODO 3: 생성자 구현 (부모 생성자 명시적 호출 및 limit_ 초기화)
    MinusAccount(int balance, int limit)
        : Account(balance),
          limit_(limit) { // [추가] 부모 생성자 Account(balance) 명시적 호출 + limit_ 초기화
    }

    // TODO 4: 출금 함수 구현 (한도 초과 시 std::runtime_error 예외 발생)
    void withdraw(int amount) {
        // [추가 시작] 출금 가능한 최대 금액 = 잔액 + 마이너스 한도
        if (amount > balance_ + limit_) {
            throw std::runtime_error("마이너스 한도를 초과하여 출금할 수 없습니다.");
        }
        balance_ -= amount;
        std::cout << "[출금 성공] 출금액 " << amount << "원 / 현재 잔액: " << balance_ << "원"
                  << std::endl;
        // [추가 끝]
    }
};

// 3. 계좌 컨트롤러 클래스
class AccountController {
  public:
    void processWithdraw(int initial_balance, int limit, int amount) {
        MinusAccount *acc = nullptr;
        // TODO 5: try-catch 구문을 작성하여 동적 객체 생성 및 출금 로직 실행
        // - 예외가 발생하더라도 동적 할당된 acc의 메모리가 해제(delete)되어야 함
        // - std::invalid_argument 및 std::runtime_error 예외를 포착하여 에러 메시지 출력
        /* 아래에 try-catch 로직 구현 */
        try {
            acc = new MinusAccount(
                initial_balance,
                limit); // [추가] 동적 객체 생성 (초기 잔액 < 0 이면 여기서 invalid_argument)
            acc->withdraw(amount); // [추가] 출금 시도 (한도 초과면 여기서 runtime_error)
            delete acc;            // 메모리 해제
            acc = nullptr;
        } catch (const std::invalid_argument &e) { // [추가] 포착할 예외 타입 지정
            std::cout << "[인자 예외 발생]: " << e.what() << std::endl;
            // [추가 시작] 예외 경로에서도 메모리 해제
            // 생성자에서 예외가 나면 new가 할당한 메모리는 자동으로 반환되고 acc는 nullptr 그대로라
            // delete nullptr은 아무 일도 하지 않아 안전함
            delete acc;
            acc = nullptr;
            // [추가 끝]
        } catch (const std::runtime_error &e) { // [추가] 포착할 예외 타입 지정
            std::cout << "[런타임 예외 발생]: " << e.what() << std::endl;
            // [추가 시작] withdraw()에서 예외가 나면 try 안의 delete를 건너뛰므로 여기서 해제 (안
            // 하면 메모리 누수)
            delete acc;
            acc = nullptr;
            // [추가 끝]
        }
    }
};

int main() {
    AccountController controller;
    const int limit = 50000;

    std::cout << "Transaction 1" << std::endl;
    controller.processWithdraw(10000, limit, 30000); // 10,000원에서 30,000원 출금 (잔액: -20,000원)

    std::cout << "\nTransaction 2" << std::endl;
    controller.processWithdraw(10000, limit,
                               70000); // 10,000원에서 70,000원 출금 시도 (한도 -50,000원 초과)

    std::cout << "\nTransaction 3" << std::endl;
    controller.processWithdraw(-5000, limit, 10000); // 초기 잔액 음수 설정

    return 0;
}
