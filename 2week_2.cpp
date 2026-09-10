#include <iostream>
class SetValue {
  private:
    int x, y;
    /* 이곳에 코드 추가 */
  public:
    void setXY(int a, int b) {
        x = a;
        y = b;
    }
    void show() { std::cout << "X: " << x << ", Y: " << y << std::endl; }
};
int main() {
    SetValue obj;
    obj.setXY(33, 44);
    obj.show(); // X, Y 출력 함수 (X 는 x 값, Y 는 y 값)
    system("pause");
    return 0;
}
