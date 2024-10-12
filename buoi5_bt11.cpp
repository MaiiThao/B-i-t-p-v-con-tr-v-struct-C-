#include <iostream>

using namespace std;

int* noiMang(int* a1, int size1, int* a2, int size2) {
    int newSize = size1 + size2;
    int* pNewArray = new int[newSize]; 

    for (int* p = a1; p < a1 + size1; p++, pNewArray++) {
        *pNewArray = *p;
    }
  
    for (int* p = a2; p < a2 + size2; p++, pNewArray++) {
        *pNewArray = *p;
    }
    
    return pNewArray - (size1 + size2); 
}

void inMang(int* a, int size) {
    for (int* p = a; p < a + size; p++) {
        cout << *p << " ";
    }
    cout << endl;
}

void nhapMang(int* a, int size) {
    for (int* p = a; p < a + size; p++) {
        cout << "Nhap phan tu thu " << p - a + 1 << ": ";
        cin >> *p;
    }
}

int main() {
    int size1, size2;
    
    cout << "Nhap kich thuoc mang 1: ";
    cin >> size1;
    int* a1 = new int[size1];
    cout << "Nhap cac phan tu cua mang 1:\n";
    nhapMang(a1, size1);
    
    cout << "Nhap kich thuoc mang 2: ";
    cin >> size2;
    int* a2 = new int[size2];
    cout << "Nhap cac phan tu cua mang 2:\n";
    nhapMang(a2, size2);
    
    cout << "Mang 1: ";
    inMang(a1, size1);
    
    cout << "Mang 2: "; 
    inMang(a2, size2);
    
    int* resultArray = noiMang(a1, size1, a2, size2);
    int newSize = size1 + size2;
    
    cout << "Mang sau khi noi: ";
    inMang(resultArray, newSize);
   
    delete[] a1;
    delete[] a2;
    delete[] resultArray;
    
    return 0;
}
