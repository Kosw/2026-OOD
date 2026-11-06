#include <iostream>
class BaseClass {
  public:
    virtual void specificFunction() {}
};
class DerivedClass : public BaseClass {
  public:
    void specificFunction() { std::cout << "Everything is OKAY\n"; }
};
int main() {
    BaseClass *base = new DerivedClass();
    DerivedClass *derived = dynamic_cast<DerivedClass *>(base);
    if (derived) {
        derived->specificFunction();
    }
    delete base;
    return 0;
}
