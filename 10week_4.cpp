#include <iostream>

class DrawAPI {
  public:
    virtual void drawCircle(int radius, int x, int y) = 0;
    virtual ~DrawAPI() {}
};

class RedCircle : public DrawAPI {
  public:
    void drawCircle(int radius, int x, int y) override {
        std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", " << y
                  << "]" << std::endl;
    }
};

class GreenCircle : public DrawAPI {
  public:
    void drawCircle(int radius, int x, int y) override {
        std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y
                  << "]" << std::endl;
    }
};

class Shape {
  protected:
    DrawAPI *drawAPI;
    Shape(DrawAPI *drawAPI) { this->drawAPI = drawAPI; }

  public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
  private:
    int x;
    int y;
    int radius;

  public:
    Circle(int x, int y, int radius, DrawAPI *drawAPI) : Shape(drawAPI) {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    void draw() override { drawAPI->drawCircle(radius, x, y); }
};

int main() {
    RedCircle red;
    GreenCircle green;

    Shape *redCircle = new Circle(100, 100, 10, &red);
    Shape *greenCircle = new Circle(100, 100, 10, &green);

    redCircle->draw();
    greenCircle->draw();

    delete redCircle;
    delete greenCircle;
    return 0;
}
