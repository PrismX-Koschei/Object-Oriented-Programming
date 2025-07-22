#include <iostream>
using namespace std;

class Student {
private:
    int usualScore;      // ƽʱ�ɼ�
    int finalScore;      // ��ĩ�ɼ�
    static float prop;   // ��ɱ�������̬��Ա��

public:
    // ������ɱ���
    static void setProp(float p) {
        if (p >= 0 && p <= 1) {
            prop = p;
        }
    }

    // ���㲢����ɼ�
    void compScore() const {
        float score = usualScore * prop + finalScore * (1 - prop);
        cout << score << " ";
    }

    // ����ƽʱ����ĩ�ɼ�
    void setScores(int usual, int final) {
        usualScore = usual;
        finalScore = final;
    }
};

// ��̬��Ա��ʼ��
float Student::prop = 0;

class Teacher {
private:
    Student* pStu; // ѧ������ָ��

public:
    // ���캯��������ѧ����������
    Teacher(int size) {
        pStu = new Student[size];
    }

    // ����һ��ѧ�������ƽʱ����ĩ�ɼ�
    void assign(int index, int usual, int final) {
        pStu[index].setScores(usual, final);
    }

    // ����һ��ѧ�������compScore��������ʾ��ɼ�
    void show(int index) const {
        pStu[index].compScore();
    }

    // �����������ͷŶ�̬�ڴ�
    ~Teacher() {
        delete[] pStu;
    }
};

int main() {
    // ������ɱ���
    float prop;
    cin >> prop;
    Student::setProp(prop);

    // ����ѧ�����������ʦ����
    int num;
    cin >> num;
    Teacher teacher(num);

    // Ϊÿ��ѧ����������ƽʱ����ĩ�ɼ�
    for (int i = 0; i < num; ++i) {
        int usual, final;
        cin >> usual >> final;
        teacher.assign(i, usual, final);
    }

    // ���㲢���ÿ��ѧ���ĳɼ�
    for (int i = 0; i < num; ++i) {
        teacher.show(i);
    }
    cout << endl;

    return 0;
}
