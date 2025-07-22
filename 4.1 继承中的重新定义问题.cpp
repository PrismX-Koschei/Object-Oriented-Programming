#include <iostream>
using namespace std;

// 1. 定义基类Base
class Base {
private:
    int x;
public:
    Base(int x_val) : x(x_val) {}
    void show() const {
        cout << "x=" << x << endl;
    }
};

// 2. 定义公有派生类derived
class Derived : public Base {
private:
    int y;
public:
    Derived(int x_val, int y_val) : Base(x_val), y(y_val) {}
    void show() const {
        Base::show();  // 调用基类的show函数
        cout << "y=" << y << endl;
    }
};

// 3. 定义外部函数func1、func2
void func1(const Base& obj) {
    obj.show();
}

void func2(const Derived& obj) {
    obj.show();
}

// 4. 在main函数中测试
int main() {
    // 静态定义derived类对象a，实参为10、20
    Derived a(10, 20);
    a.show();  // 调用a的show函数

    // 定义Base指针、derived指针，都指向a
    Base* basePtr = &a;
    Derived* derivedPtr = &a;

    // 分别用指针调用其show函数
    basePtr->show();
    derivedPtr->show();

    // 以a为实参，调用函数func1、func2
    func1(a);
    func2(a);

    return 0;
}
