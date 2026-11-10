#include <iostream>
#include <string>

class Shape {
  public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class RoundedRectangle : public Shape {
  public:
    void draw() { std::cout << "Inside RoundedRectangle::draw() method." << std::endl; }
};

class RoundedSquare : public Shape {
  public:
    void draw() { std::cout << "Inside RoundedSquare::draw() method." << std::endl; }
};

class Rectangle : public Shape {
  public:
    void draw() { std::cout << "Inside Rectangle::draw() method." << std::endl; }
};

class Square : public Shape {
  public:
    void draw() { std::cout << "Inside Square::draw() method." << std::endl; }
};

class AbstractFactory {
  public:
    virtual Shape *getShape(const std::string &shapeType) = 0;
    virtual ~AbstractFactory() {}
};

class ShapeFactory : public AbstractFactory {
  public:
    Shape *getShape(const std::string &shapeType) override {
        if (shapeType == "Rectangle") {
            return new Rectangle;
        } else if (shapeType == "Square") {
            return new Square;
        }
        return nullptr;
    }
};

class RoundedShapeFactory : public AbstractFactory {
  public:
    Shape *getShape(const std::string &shapeType) override {
        if (shapeType == "Rectangle") {
            return new RoundedRectangle;
        } else if (shapeType == "Square") {
            return new RoundedSquare;
        }
        return nullptr;
    }
};

class FactoryProducer {
  public:
    static AbstractFactory *getFactory(bool rounded) {
        if (rounded) {
            return new RoundedShapeFactory;
        } else {
            return new ShapeFactory;
        }
    }
};

int main() {
    AbstractFactory *shapeFactory = FactoryProducer::getFactory(false);

    Shape *shape1 = shapeFactory->getShape("Rectangle");
    shape1->draw();

    Shape *shape2 = shapeFactory->getShape("Square");
    shape2->draw();

    AbstractFactory *shapeFactory1 = FactoryProducer::getFactory(true);

    Shape *shape3 = shapeFactory1->getShape("Rectangle");
    shape3->draw();

    Shape *shape4 = shapeFactory1->getShape("Square");
    shape4->draw();

    delete shape1;
    delete shape2;
    delete shape3;
    delete shape4;
    delete shapeFactory;
    delete shapeFactory1;

    return 0;
}
