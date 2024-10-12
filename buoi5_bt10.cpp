#include <iostream>
#include <cmath>

using namespace std;

int* extractArray(int* a, int size) {
    int newSize = ceil(size / 2.0);
    int* newArray = new int[newSize];
    
    for (int* p = a, *q = newArray; p < a + size; p += 2, q++) {
        *q = *p;
    }
    
    return newArray;
}

int main() {
    int size;
    
    cout << "Nhap kich thuoc cua mang: ";
    cin >> size;
    
    int* a = new int[size];

    for (int* p = a; p < a + size; p++) {
        cout << "Phan tu thu " << p - a << ": ";
        cin >> *p;
    }
    
    cout << "Mang goc: ";
    for (int* p = a; p < a + size; p++) {
        cout << *p << " ";
    }
    cout << endl;
    
    int* resultArray = extractArray(a, size);
    int newSize = ceil(size / 2.0);
    
    cout << "Mang moi chua cac phan tu o vi tri chan: ";
    for (int* p = resultArray; p < resultArray + newSize; p++) {
        cout << *p << " ";
    }
    cout << endl;
   
    delete[] a;
    delete[] resultArray;
    
    return 0;
}