#include <iostream>
#include <cstring>

class MyClass {
public:
    // ��̬���ݳ�Ա
    static int staticData;

    // �Ǿ�̬���ݳ�Ա
    int nonStaticData;
    char* charPtr;
    int& refData;  // ���ó�Ա

    // ���캯��
    MyClass(int data, const char* str, int& ref) 
        : nonStaticData(data), charPtr(new char[strlen(str) + 1]), refData(ref) {
        strcpy(charPtr, str);
        std::cout << "Constructor called for object at address: " << this << std::endl;
    }

    // ��������
    ~MyClass() {
        delete[] charPtr;
        std::cout << "Destructor called for object at address: " << this << std::endl;
    }

    // ��̬��Ա����
    static void staticFunc() {
        std::cout << "Static function called. Static data: " << staticData << std::endl;
    }

    // �Ǿ�̬��Ա����
    void nonStaticFunc() {
        std::cout << "Non-static function called. Non-static data: " << nonStaticData << std::endl;
    }

    // ���������Ϣ
    void printInfo() const {
        std::cout << "Object at address: " << this << std::endl;
        std::cout << "  Static data: " << staticData << " (Address: " << &staticData << ")" << std::endl;
        std::cout << "  Non-static data: " << nonStaticData << " (Address: " << &nonStaticData << ")" << std::endl;
        std::cout << "  Char pointer: " << charPtr << " (Address: " << &charPtr << ")" << std::endl;
        std::cout << "  Reference data: " << refData << " (Address: " << &refData << ")" << std::endl;
        std::cout << "  Size of object: " << sizeof(*this) << " bytes" << std::endl;
    }
};

// ��ʼ����̬���ݳ�Ա
int MyClass::staticData = 10;

// ȫ�ֶ���
MyClass globalObj1(100, "Global1", globalObj1.nonStaticData);
MyClass globalObj2(200, "Global2", globalObj2.nonStaticData);

// �ⲿ����
void func(MyClass obj) {
    MyClass localObj3(300, "Local3", obj.nonStaticData);
    MyClass localObj4(400, "Local4", obj.nonStaticData);

    std::cout << "Inside func:" << std::endl;
    localObj3.printInfo();
    localObj4.printInfo();
}

int main() {
    // �ֲ�����
    MyClass localObj1(500, "Local1", localObj1.nonStaticData);
    MyClass localObj2(600, "Local2", localObj2.nonStaticData);

    // ��̬��������
    MyClass* dynamicObj1 = new MyClass(700, "Dynamic1", localObj1.nonStaticData);
    MyClass* dynamicObj2 = new MyClass(800, "Dynamic2", localObj2.nonStaticData);

    std::cout << "Inside main:" << std::endl;
    localObj1.printInfo();
    localObj2.printInfo();
    dynamicObj1->printInfo();
    dynamicObj2->printInfo();

    // �����ⲿ����
    func(localObj1);

    // �����̬�ͷǾ�̬��Ա������ַ
    std::cout << "Static function address: " << reinterpret_cast<void*>(&MyClass::staticFunc) << std::endl;
    std::cout << "Non-static function address: " << reinterpret_cast<void*>(&MyClass::nonStaticFunc) << std::endl;

    // ����ⲿ������ַ
    std::cout << "func function address: " << reinterpret_cast<void*>(&func) << std::endl;

    // �ͷŶ�̬����
    delete dynamicObj1;
    delete dynamicObj2;

    return 0;
}
