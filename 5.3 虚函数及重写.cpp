#include <iostream>
using namespace std;

class A {
protected:
    int a;
public:
    A(int val = 0) : a(val) {}
    virtual void addValue(int x) { a += x; }
    A& operator+(int x) {
        addValue(x);
        return *this;
    }
    virtual void show() {
        cout << "a=" << a << endl;
    }
    virtual ~A() = default;
};

class B : public A {
private:
    int b;
public:
    B(int aVal = 0, int bVal = 0) : A(aVal), b(bVal) {}
    virtual void addValue(int x) override {
        b += x;
    }
    virtual void show() override {
        cout << "a=" << a << endl;
        cout << "b=" << b << endl;
    }
};

void add(A& obj, int x) {
    obj + x;
}

int main() {
    A myA, *p;
    B myB(2, 3);
    
    add(myA, 3);
    p = &myA;
    p->show();
    
    add(myB, 3);
    p = &myB;
    p->show();

    return 0;
}
