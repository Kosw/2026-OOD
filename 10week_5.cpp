#include <cassert>
#include <iostream>

class Student {
  public:
    virtual ~Student() {}
};

class Employee {
  public:
    virtual ~Employee() {}
};

class TA : public Student, public Employee {};

class Undergraduate : public Student {};

int main() {
    Employee *employee = new TA();
    Student *student = dynamic_cast<Student *>(employee);

    assert(student != nullptr);

    Undergraduate *undergraduate = new Undergraduate();
    Employee *underemployee = (Employee *)undergraduate;
    TA *ta = dynamic_cast<TA *>(underemployee);
    assert(ta == nullptr);

    std::cout << "Cross-casting test passed." << std::endl;

    delete employee;
    delete undergraduate;

    return 0;
}
