#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* array;

public:
    // ���캯��
    String(const char* p = "") {
        array = new char[strlen(p) + 1];
        strcpy(array, p);
    }

    // ��������
    ~String() {
        delete[] array;
    }

    // ���� [] �����
    char& operator[](int index) {
        if (index >= 0 && index < static_cast<int>(strlen(array))) {
            return array[index];
        } else {
            cout << "Index out of range." << endl;
            static char dummy = '\0';
            return dummy;
        }
    }

    // ���� + �������String + String�����޸��������
    String& operator+(const String& other) {
        char* newArray = new char[strlen(array) + strlen(other.array) + 1];
        strcpy(newArray, array);
        strcat(newArray, other.array);
        delete[] array;
        array = newArray;
        return *this;
    }

    // ���� + �������String + const char*���������¶���
    String operator+(const char* other) const {
        char* newArray = new char[strlen(array) + strlen(other) + 1];
        strcpy(newArray, array);
        strcat(newArray, other);
        String result(newArray);
        delete[] newArray;
        return result;
    }

    // �����ַ�������
    int length() const {
        return strlen(array);
    }

    // ������������
    friend ostream& operator<<(ostream& os, const String& str) {
        os << str.array;
        return os;
    }

    // ��ʽת��Ϊ���ȣ�����string3 + 3��
    operator int() const {
        return length();
    }

    // ��ֵ��������أ������
    String& operator=(const String& other) {
        if (this == &other) return *this;
        delete[] array;
        array = new char[strlen(other.array) + 1];
        strcpy(array, other.array);
        return *this;
    }
};

int main(){
String string1("mystring"),string2("yourstring"),string3("herstring");
cout<<string1<<endl;
string1[7]='n';
cout<<string1<<endl;
string1[8]='n';
cout<<string1+string2+string3<<endl;
cout<<string1<<endl;
cout<<string2+"ab"<<endl;
cout<<string2<<endl;
cout<<string3+3<<endl;
cout<<string3<<endl;
return 0;
}
