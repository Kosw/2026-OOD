#include <exception>
#include <iostream>
#include <string>

// 상속받는 사용자 정의 예외 클래스 작성
class AccountException : public std::exception { // A
  private:
    std::string msg_;

  public:
    AccountException(const std::string &msg) : msg_(msg) {}

    // what() 메서드 재정의
    virtual const char *what() const noexcept override { return msg_.c_str(); } // B
};

void transferMoney(int balance, int amount) {
    std::cout << "트랜잭션 시작..." << std::endl;
    try {
        if (balance < amount) {
            throw AccountException("잔액이 부족합니다.");
        }
        std::cout << "이체 성공!" << std::endl;
    } catch (...) {
        std::cout << "오류 발생! 트랜잭션 롤백 수행." << std::endl;
        // [요구사항 2] 포착한 예외를 상위 함수(main)로 다시 던짐(Rethrow)
        throw; // C
    }
}

int main() {
    try {
        transferMoney(1000, 5000);        // 1,000원 계좌에서 5,000원 이체 시도
    } catch (const AccountException &e) { // D
        std::cout << "[UI Layer] 사용자 알림: " << e.what() << std::endl;
    }
    return 0;
}
