#include <iostream>
#include "Vector.h"

using namespace std;

#pragma pack(push, 1)
struct PackedVector {
    int* elements;
    int size;
};
#pragma pack(pop)

int main() {
    cout << "Size of the class without #pragma pack(1): " << sizeof(Vector) << endl;
    cout << "Size of the class with #pragma pack(1): " << sizeof(PackedVector) << endl;

    Vector v1, v2;

    cout << "Input value for v1:" << endl;
    cin >> v1;

    cout << "Input value for v2:" << endl;
    cin >> v2;

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    Vector v3 = v1 + v2;
    cout << "v1 + v2: " << v3 << endl;

    cout << "v1 == v2: " << (v1 == v2) << endl;
    cout << "v1 != v2: " << (v1 != v2) << endl;

    cout << "norm v1: " << v1.norm() << endl;
    cout << "norm v2: " << v2.norm() << endl;

    cout << "v1[0]: " << v1[0] << endl;
    v1[0] = 100;
    cout << "v1 after changes: " << v1 << endl;

    string str1 = static_cast<string>(v1);
    string str2 = static_cast<string>(v2);
    cout << "string outcome v1: " << str1 << endl;
    cout << "string outcome v2: " << str2 << endl;

    return 0;
}