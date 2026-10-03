#include <cstring>
#include <iostream>
class Animal {
  private:
    std::string name;

  public:
    Animal() {};
    Animal(std::string name) : name(name) {};
    void showName() { std::cout << "Name is " << name << std::endl; }
    Animal &operator+(const Animal &a) {
        name += a.name;
        return *this;
    }
};
int main() {
    Animal cat("Nabi");
    cat.showName();
    Animal dog("Jindo");
    dog.showName();
    Animal catDog = dog + cat;
    catDog.showName();
    dog.showName();
    return 0;
}
// 실습3번과 출력이 다른 이유 : 실습4번에서는 operator+를 호출하면 dog의 name이 변경되기 때문에
// catDog.showName()을 호출하면 dog의 name이 변경된 상태로 출력된다.
