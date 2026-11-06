#include <cassert>
#include <iostream>
#include <typeinfo>

class CEO {
  public:
    virtual void ceo() {}
    virtual ~CEO() {}
};
class CPO {
  public:
    virtual void cpo() {}
    virtual ~CPO() {}
};
class Manager : public CEO, public CPO {};
class Staff : public Manager {};

int main() {
    CPO *cpo = new Staff();
    Staff *staff = dynamic_cast<Staff *>(cpo);
    assert(typeid(*cpo) == typeid(Staff));
    std::cout << "Assertion Pass!\n";
    delete cpo;
    return 0;
}
// typeid(cpo)가 가리키는 것은 CPO*이고 cpo가 가리키는 실제 객체의 타입을 알고 싶으면 *cpo로
// 표기해야 한다 cpo가 가리키는 실제 객체의 타입은 Staff이기에 Staff*가 아닌 Staff와 비교해야한다.
