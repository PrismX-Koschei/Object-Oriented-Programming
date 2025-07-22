#include <iostream>
using namespace std;

class Student {
private:
    int usualScore;      // 平时成绩
    int finalScore;      // 期末成绩
    static float prop;   // 组成比例（静态成员）

public:
    // 设置组成比例
    static void setProp(float p) {
        if (p >= 0 && p <= 1) {
            prop = p;
        }
    }

    // 计算并输出成绩
    void compScore() const {
        float score = usualScore * prop + finalScore * (1 - prop);
        cout << score << " ";
    }

    // 设置平时和期末成绩
    void setScores(int usual, int final) {
        usualScore = usual;
        finalScore = final;
    }
};

// 静态成员初始化
float Student::prop = 0;

class Teacher {
private:
    Student* pStu; // 学生对象指针

public:
    // 构造函数，创建学生对象数组
    Teacher(int size) {
        pStu = new Student[size];
    }

    // 设置一个学生对象的平时和期末成绩
    void assign(int index, int usual, int final) {
        pStu[index].setScores(usual, final);
    }

    // 调用一个学生对象的compScore函数，显示其成绩
    void show(int index) const {
        pStu[index].compScore();
    }

    // 析构函数，释放动态内存
    ~Teacher() {
        delete[] pStu;
    }
};

int main() {
    // 设置组成比例
    float prop;
    cin >> prop;
    Student::setProp(prop);

    // 输入学生数，定义教师对象
    int num;
    cin >> num;
    Teacher teacher(num);

    // 为每个学生对象设置平时和期末成绩
    for (int i = 0; i < num; ++i) {
        int usual, final;
        cin >> usual >> final;
        teacher.assign(i, usual, final);
    }

    // 计算并输出每个学生的成绩
    for (int i = 0; i < num; ++i) {
        teacher.show(i);
    }
    cout << endl;

    return 0;
}
