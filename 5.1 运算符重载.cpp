#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* array;

public:
    // 构造函数
    String(const char* p = "") {
        array = new char[strlen(p) + 1];
        strcpy(array, p);
    }

    // 析构函数
    ~String() {
        delete[] array;
    }

    // 重载 [] 运算符
    char& operator[](int index) {
        if (index >= 0 && index < static_cast<int>(strlen(array))) {
            return array[index];
        } else {
            cout << "Index out of range." << endl;
            static char dummy = '\0';
            return dummy;
        }
    }

    // 重载 + 运算符（String + String），修改左操作数
    String& operator+(const String& other) {
        char* newArray = new char[strlen(array) + strlen(other.array) + 1];
        strcpy(newArray, array);
        strcat(newArray, other.array);
        delete[] array;
        array = newArray;
        return *this;
    }

    // 重载 + 运算符（String + const char*），生成新对象
    String operator+(const char* other) const {
        char* newArray = new char[strlen(array) + strlen(other) + 1];
        strcpy(newArray, array);
        strcat(newArray, other);
        String result(newArray);
        delete[] newArray;
        return result;
    }

    // 计算字符串长度
    int length() const {
        return strlen(array);
    }

    // 重载输出运算符
    friend ostream& operator<<(ostream& os, const String& str) {
        os << str.array;
        return os;
    }

    // 隐式转换为长度（用于string3 + 3）
    operator int() const {
        return length();
    }

    // 赋值运算符重载（深拷贝）
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
