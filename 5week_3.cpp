#include <cstring>
#include <iostream>
class Animal {
  private:
    std::string name;

  public:
    Animal() {};
    Animal(std::string name) : name(name) {};
    void showName() { std::cout << "Name is " << name << std::endl; }
    // operator+ 구현
    Animal operator+(const Animal &a) const { return Animal(name + a.name); } // 추가
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
