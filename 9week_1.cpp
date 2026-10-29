#include <iostream>

class MyData {
    int number;
    std::string strNumber;

  public:
    MyData(int data, std::string str) : number(data), strNumber(str) {}

    operator int() { return number; }
    operator std::string() { return strNumber; }

    int operator++(int) {
        int temp = number;
        number++;
        return temp;
    }
    int operator++() { return ++number; }

    friend std::ostream &operator<<(std::ostream &, MyData &);
};

std::ostream &operator<<(std::ostream &os, MyData &md) {
    return os << "This number is: " << md.strNumber << "\n";
}

int main() {
    MyData mydata(1, "one");
    std::string strNum = mydata;
    int intNum = mydata;
    std::cout << strNum << std::endl;
    std::cout << intNum << std::endl;
    std::cout << mydata++ << std::endl;
    std::cout << ++mydata << std::endl;
    std::cout << mydata;
}
