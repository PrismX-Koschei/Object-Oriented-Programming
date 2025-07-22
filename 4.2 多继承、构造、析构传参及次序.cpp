#include <iostream>
#include <cstring>
using namespace std;

// 1. 定义基类Base
class Base {
private:
    char* name;
    int age;
public:
    Base(const char* name_val, int age_val) : age(age_val) {
        name = new char[strlen(name_val) + 1];
        strcpy(name, name_val);
        cout << "Base constructor" << endl;
    }
    virtual ~Base() {
        delete[] name;
        cout << "Base destructor" << endl;
    }
    virtual void show() const {
        cout << name << " " << age;
    }
};

// 2. 定义派生类Leader
class Leader : virtual public Base {
private:
    char position[10];
public:
    Leader(const char* name_val, const char* position_val, int age_val)
        : Base(name_val, age_val) {
        strcpy(position, position_val);
        cout << "Leader constructor" << endl;
    }
    ~Leader() {
        cout << "Leader destructor" << endl;
    }
    const char* getPosition() const {
        return position;
    }
};

// 2. 定义派生类Engineer
class Engineer : virtual public Base {
private:
    char major[10];
public:
    Engineer(const char* name_val, const char* major_val, int age_val)
        : Base(name_val, age_val) {
        strcpy(major, major_val);
        cout << "Engineer constructor" << endl;
    }
    ~Engineer() {
        cout << "Engineer destructor" << endl;
    }
    const char* getMajor() const {
        return major;
    }
};

// 3. 定义派生类Chairman
class Chairman : public Leader, public Engineer {
public:
    Chairman(const char* name_val, const char* position_val, const char* major_val, int age_val)
        : Base(name_val, age_val), Leader(name_val, position_val, age_val), Engineer(name_val, major_val, age_val) {
        cout << "Chairman constructor" << endl;
    }
    ~Chairman() {
        cout << "Chairman destructor" << endl;
    }
    void show() const override {
        Base::show(); // 只调用一次 Base::show
        cout << " " << Leader::getPosition() << " " << Engineer::getMajor() << endl;
    }
};

// 7. 在main函数中测试
int main() {
    Chairman a("Li", "chair", "computer", 20);
    a.show();
    return 0;
}
