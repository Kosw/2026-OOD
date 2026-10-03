#include <iostream>
using namespace std;

class Timer {
  private:
    int min;
    int sec;

  public:
    // TODO 1: 기본 생성자 및 매개변수 생성자 구현
    Timer() : min(0), sec(0) {}
    Timer(int min, int sec) : min(min), sec(sec) {}

    // TODO 2: Getter 메서드 (getMin, getSec) 구현
    int getMin() const { return min; }
    int getSec() const { return sec; }

    // TODO 3-(1~3): 연산자 오버로딩 (+, +=, 전위 ++) 구현
    Timer operator+(const Timer &t) const {
        int totalSec = (min * 60 + sec) + (t.min * 60 + t.sec);
        return Timer(totalSec / 60, totalSec % 60);
    }

    Timer &operator+=(const Timer &t) {
        int totalSec = (min * 60 + sec) + (t.min * 60 + t.sec);
        min = totalSec / 60;
        sec = totalSec % 60;
        return *this;
    }

    Timer &operator++() {
        sec++;
        if (sec >= 60) {
            sec -= 60;
            min++;
        }
        return *this;
    }

    // TODO 4: printTime() 메서드 구현
    void printTime() { cout << min << "min " << sec << "sec" << endl; }
};

// 아래 main 함수는 수정 금지
int main() {
    Timer t1(1, 45);
    Timer t2(0, 30);

    cout << "Initial Timer" << endl;
    t1.printTime();
    t2.printTime();

    cout << "\nTotal Timer" << endl;
    Timer total = t1 + t2;
    total.printTime();

    cout << "\nChaining" << endl;
    (++t1) += t2;
    t1.printTime();

    return 0;
}
