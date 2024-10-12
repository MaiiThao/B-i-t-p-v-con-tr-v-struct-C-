#include <iostream>
using namespace std;

int* multiple(int* a, int size, int mult, int &newSize) {
    newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (*(a + i) % mult == 0) {
            ++newSize;
        }
    }

    int* newArray = new int[newSize];
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (*(a + i) % mult == 0) {
            *(newArray + index) = *(a + i);
            ++index;
        }
    }

    return newArray;
}

int main() {
    int size, mult, newSize;

    cout << "Nhap kich thuoc cua mang: ";
    cin >> size;

    int* a = new int[size];

    for (int i = 0; i < size; ++i) {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> *(a + i);
    }

    cout << "Nhap gia tri de loc boi so: ";
    cin >> mult;

    int* newArray = multiple(a, size, mult, newSize);

    cout << "Mang chi chua cac gia tri la boi so cua " << mult << ":\n";
    for (int i = 0; i < newSize; ++i) {
        cout << *(newArray + i) << " ";
    }
    cout << endl;

    delete[] a;
    delete[] newArray;

    return 0;
}
