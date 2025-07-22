#include <iostream>
#include <cstring>

class Student {
private:
    char* name;
    float g1;
    float g2;

public:
    // ���캯��
    Student(const char* n, float score1, float score2) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        g1 = score1;
        g2 = score2;
        std::cout << "construct " << name << std::endl;
    }

    // �������캯��
    Student(const Student& other) {
        name = new char[strlen(other.name) + 2]; // ��һ���ַ��ռ�
        strcpy(name, other.name);
        strcat(name, "u"); // ׷���ַ�'u'
        g1 = other.g1 - 10.0;
        g2 = other.g2 - 10.0;
        std::cout << "copy " << name << std::endl;
    }

    // ��������
    ~Student() {
        std::cout << "destruct " << name << std::endl;
        delete[] name;
    }

    // ������������
    void getScores(float& score1, float& score2) const {
        score1 = g1;
        score2 = g2;
    }

    // ���ض����ַ
    Student* getAddress() {
        return this;
    }
};

int main() {
    // ����ѧ������a
    Student a("li", 90.0, 80.0);

    {
        // �����СΪ2��ѧ����������st
        Student st[] = {Student("zhang", 80.0, 70.0), Student("wang", 90.0, 80.0)};

        // ���������ÿ��ѧ����ƽ��ֵ
        for (int i = 0; i < 2; ++i) {
            float score1, score2;
            st[i].getScores(score1, score2);
            std::cout << (score1 + score2) / 2;
            if (i < 1) std::cout << " "; // ֻ�ڵ�һ��ƽ��ֵ��ӿո�
        }
        std::cout << std::endl;
    } // st�����ڴ˴�����

    // ��a����������һ��ѧ������b
    Student b = a;

    // ȡb��ַ��������b�ķ��ض����ַ��Ա������������ߵĲ�
    Student* bAddress = &b;
    std::cout << (b.getAddress() - bAddress) << std::endl;

    return 0;
}

