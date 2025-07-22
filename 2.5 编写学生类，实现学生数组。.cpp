#include <iostream>
#include <cstring>

class Student {
private:
    char* name;
    float g1;
    float g2;

public:
    // 构造函数
    Student(const char* n, float score1, float score2) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        g1 = score1;
        g2 = score2;
        std::cout << "construct " << name << std::endl;
    }

    // 拷贝构造函数
    Student(const Student& other) {
        name = new char[strlen(other.name) + 2]; // 多一个字符空间
        strcpy(name, other.name);
        strcat(name, "u"); // 追加字符'u'
        g1 = other.g1 - 10.0;
        g2 = other.g2 - 10.0;
        std::cout << "copy " << name << std::endl;
    }

    // 析构函数
    ~Student() {
        std::cout << "destruct " << name << std::endl;
        delete[] name;
    }

    // 返回两个分数
    void getScores(float& score1, float& score2) const {
        score1 = g1;
        score2 = g2;
    }

    // 返回对象地址
    Student* getAddress() {
        return this;
    }
};

int main() {
    // 定义学生对象a
    Student a("li", 90.0, 80.0);

    {
        // 定义大小为2的学生对象数组st
        Student st[] = {Student("zhang", 80.0, 70.0), Student("wang", 90.0, 80.0)};

        // 输出数组中每个学生的平均值
        for (int i = 0; i < 2; ++i) {
            float score1, score2;
            st[i].getScores(score1, score2);
            std::cout << (score1 + score2) / 2;
            if (i < 1) std::cout << " "; // 只在第一个平均值后加空格
        }
        std::cout << std::endl;
    } // st数组在此处析构

    // 用a拷贝构造另一个学生对象b
    Student b = a;

    // 取b地址，并调用b的返回对象地址成员函数，输出两者的差
    Student* bAddress = &b;
    std::cout << (b.getAddress() - bAddress) << std::endl;

    return 0;
}

