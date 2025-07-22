#include <iostream>
using namespace std;

// 1. �������Base
class Base {
private:
    int x;
public:
    Base(int x_val) : x(x_val) {}
    void show() const {
        cout << "x=" << x << endl;
    }
};

// 2. ���幫��������derived
class Derived : public Base {
private:
    int y;
public:
    Derived(int x_val, int y_val) : Base(x_val), y(y_val) {}
    void show() const {
        Base::show();  // ���û����show����
        cout << "y=" << y << endl;
    }
};

// 3. �����ⲿ����func1��func2
void func1(const Base& obj) {
    obj.show();
}

void func2(const Derived& obj) {
    obj.show();
}

// 4. ��main�����в���
int main() {
    // ��̬����derived�����a��ʵ��Ϊ10��20
    Derived a(10, 20);
    a.show();  // ����a��show����

    // ����Baseָ�롢derivedָ�룬��ָ��a
    Base* basePtr = &a;
    Derived* derivedPtr = &a;

    // �ֱ���ָ�������show����
    basePtr->show();
    derivedPtr->show();

    // ��aΪʵ�Σ����ú���func1��func2
    func1(a);
    func2(a);

    return 0;
}
