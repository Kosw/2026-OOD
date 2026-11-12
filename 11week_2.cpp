#include <algorithm>
#include <iostream>
#include <vector>

class Rect {
    int w, h;

  public:
    Rect() : w(0), h(0) {}
    Rect(int w, int h) : w(w), h(h) {}
    int area() { return w * h; }
    void print() { std::cout << "(" << w << "," << h << "," << area() << ")" << std::endl; }
};

bool Compare(Rect a, Rect b) { return a.area() < b.area(); }

int main() {
    int count;
    std::cout << "Count: ";
    std::cin >> count;

    std::vector<Rect> rect;
    for (int i = 0; i < count; i++) {
        int w, h;
        std::cout << "Width: ";
        std::cin >> w;
        std::cout << "Height: ";
        std::cin >> h;
        rect.push_back(Rect(w, h));
    }

    sort(rect.begin(), rect.end(), Compare);

    for (int i = 0; i < count; i++) {
        rect[i].print();
    }

    return 0;
}
