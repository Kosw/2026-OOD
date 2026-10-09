#include <iostream>
#include <string>

class Person {
  public:
    Person(const std::string &name) : name_(name) {}
    void printName() const { std::cout << "이름: " << name_ << std::endl; }

  protected: // 수정 private -> public name_ 멤버를 상속받은 Student 클래스에서 접근 가능하도록 변경
    std::string name_;
};

// Person 을 상속받는 Student 클래스
class Student : public Person {
  public:
    // (문제 1) Student 생성자
    Student(const std::string &name, int student_id)
        : Person(name) { // 수정 : Person(name)로 부모 클래스 생성자 호출
        student_id_ = student_id;
    }

    void printStudentInfo() const {
        // (문제 2) 부모의 name_ 멤버에 직접 접근하여 출력
        std::cout << "이름: " << name_ << ", 학번: " << student_id_ << std::endl;
    }

  private:
    int student_id_;
};

int main() {
    Student s("김철수", 20260001);
    s.printStudentInfo();
    return 0;
}
