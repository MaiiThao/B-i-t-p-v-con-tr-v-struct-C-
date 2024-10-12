#include <iostream>
using namespace std;

int findMode(int* a, int n) {
    if (n <= 0) return -1;

    int maxValue = *a;
    for (int* p = a + 1; p < a + n; ++p) {
        if (*p > maxValue) {
            maxValue = *p;
        }
    }

    int* count = new int[maxValue + 1]();

    for (int* p = a; p < a + n; ++p) {
        ++count[*p];
    }

    int mode = -1;
    int maxCount = 1;
    for (int i = 0; i <= maxValue; ++i) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            mode = i;
        }
    }

    delete[] count;

    return (maxCount > 1) ? mode : -1;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong phan tu khong hop le." << endl;
        return 1;
    }

    int* a = new int[n];

    for (int i = 0; i < n; ++i) {
        cout << "Phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "Mang da nhap: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    int mode = findMode(a, n);
    if (mode != -1) {
        cout << "Mode cua mang: " << mode << endl;
    } else {
        cout << "Khong co mode (khong co gia tri nao xuat hien nhieu hon mot lan)." << endl;
    }

    delete[] a;

    return 0;
}
