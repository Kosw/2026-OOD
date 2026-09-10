#include <iostream>
class Set {
    int num;
    char word;

  public:
    void set_value(/*채우기*/ int n) { this->num = n; }
    void set_value(/*채우기*/ char w) { this->word = w; }
    void show() { std::cout << "num=" << this->num << ", word=" << this->word << std::endl; }
};
int main() {
    Set s;
    s.set_value(3);
    s.set_value('c');
    s.show();
}
