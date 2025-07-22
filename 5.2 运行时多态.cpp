#include <iostream>
#include <cstring>

using namespace std;

// ����A
class A {
protected:
    char* name; // ��Ŀì�ܣ����Ϊprotected���ܱ����������
public:
    A(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    virtual ~A() {
        delete[] name;
        cout << "destructor A" << endl;
    }
    virtual void show() = 0; // ���麯��
};

// ������B
class B : public A {
private:
    int age;
public:
    B(const char* n, int a) : A(n), age(a) {}
    ~B() override {
        cout << "destructor B" << endl;
    }
    void show() override {
        cout << "B:" << name << endl;
        cout << age << endl;
    }
};

// ������C
class C : public A {
private:
    char sex;
public:
    C(const char* n, char s) : A(n), sex(s) {}
    ~C() override {
        cout << "destructor C" << endl;
    }
    void show() override {
        cout << "C:" << name << endl;
        cout << sex << endl;
    }
};

// ������
class manager {
private:
    A** array;
    int array_size;
    int len;

public:
    manager(int size) : array_size(size), len(0) {
        array = new A*[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nullptr;
        }
    }

    ~manager() {
        for (int i = 0; i < array_size; ++i) {
            delete array[i];
        }
        delete[] array;
    }

    void add(int index, const char* name, int age) {
        if (index >= 0 && index < array_size) {
            array[index] = new B(name, age);
            ++len;
        }
    }

    void add(int index, const char* name, char sex) {
        if (index >= 0 && index < array_size) {
            array[index] = new C(name, sex);
            ++len;
        }
    }

    void display() {
        for (int i = 0; i < array_size; ++i) {
            if (array[i] != nullptr) {
                array[i]->show();
            }
        }
    }
};

// ����������ĿҪ�󲻿��޸�!!!��
int main() {
    manager m(4);
    m.add(0, "zhang", 18);
    m.add(1, "wang", 'F');
    m.add(3, "liu", 'M');
    m.display();
    return 0;
}
