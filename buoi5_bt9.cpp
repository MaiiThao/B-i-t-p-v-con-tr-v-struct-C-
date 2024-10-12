#include <iostream>

using namespace std;

void sortArray(int* a, int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (*(a + j) > *(a + j + 1)) {
                
                int temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }
    }
}

float findMedian(int* a, int num) {

    if (num % 2 != 0) {
        return *(a + num / 2);
    }
    else {
        int mid1 = *(a + (num / 2) - 1);
        int mid2 = *(a + (num / 2));
        return (mid1 + mid2) / 2.0;
    }
}

int main() {
    int num;

    cout << "Nhap so luong phan tu trong mang: ";
    cin >> num;

    int* a = new int[num];

    for (int i = 0; i < num; ++i) {
        cout << "Nhap gia tri phan tu thu " << i + 1 << ": ";
        cin >> *(a + i);
    }

    sortArray(a, num);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < num; ++i) {
        cout << *(a + i) << " ";
    }
    cout << endl;

    float median = findMedian(a, num);
    cout << "Median cua mang la: " << median << endl;

    delete[] a;

    return 0;
}
