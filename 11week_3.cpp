#include <iostream>
#include <vector>

class Observer;

class Subject {
  private:
    std::vector<Observer *> observers;
    int state;

  public:
    int getState() { return state; }
    void setState(int state) {
        this->state = state;
        notifyAllObservers();
    }
    void attach(Observer *observer) { observers.push_back(observer); }
    void notifyAllObservers();
};

class Observer {
  protected:
    Subject *subject;

  public:
    virtual void update() = 0;
    virtual ~Observer() {}
};

void Subject::notifyAllObservers() {
    for (std::vector<Observer *>::iterator itr = observers.begin(); itr != observers.end(); ++itr)
        (*itr)->update();
}

class BinaryObserver : public Observer {
  public:
    BinaryObserver(Subject *subject) {
        this->subject = subject;
        this->subject->attach(this);
    }
    void update() override {
        int n = subject->getState();
        std::string s;
        if (n == 0)
            s = "0";
        while (n > 0) {
            s = char('0' + n % 2) + s;
            n /= 2;
        }
        std::cout << "Binary String: " << s << std::endl;
    }
};

class OctalObserver : public Observer {
  public:
    OctalObserver(Subject *subject) {
        this->subject = subject;
        this->subject->attach(this);
    }
    void update() override {
        std::cout << "Octal String: " << std::oct << subject->getState() << std::dec << std::endl;
    }
};

class HexaObserver : public Observer {
  public:
    HexaObserver(Subject *subject) {
        this->subject = subject;
        this->subject->attach(this);
    }
    void update() override {
        std::cout << "Hex String: " << std::hex << std::uppercase << subject->getState()
                  << std::nouppercase << std::dec << std::endl;
    }
};

int main() {
    Subject subject;

    HexaObserver hexa(&subject);
    OctalObserver octal(&subject);
    BinaryObserver binary(&subject);

    std::cout << "First state change: 15" << std::endl;
    subject.setState(15);
    std::cout << "Second state change: 10" << std::endl;
    subject.setState(10);

    return 0;
}
