#include <iostream>
#include <algorithm>
using namespace std;

int mode(int* a, int size) {
    int maxCount = 0, modeValue = -1;

    for (int i = 0; i < size; ++i) {
        int count = 1;
        for (int j = i + 1; j < size; ++j) {
            if (*(a + i) == *(a + j)) {
                ++count;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            modeValue = *(a + i);
        }
    }

    if (maxCount == 1) return -1; 
    return modeValue;
}

double median(int* a, int size) {
    sort(a, a + size);
    if (size % 2 == 0) {
        return (*(a + size / 2 - 1) + *(a + size / 2)) / 2.0;
    } else {
        return *(a + size / 2);
    }
}

double calculateAverage(int* a, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(a + i);
    }
    return (double)sum / size;
}

int main() {
    int numStudents;

    do {
        cout << "Nhap so luong sinh vien da duoc khao sat: ";
        cin >> numStudents;
        if (numStudents <= 0) {
            cout << "So luong sinh vien phai lon hon 0. Hay nhap lai." << endl;
        }
    } while (numStudents <= 0);

    int* movies = new int[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        do {
            cout << "Nhap so phim ma sinh vien thu " << i + 1 << " da xem: ";
            cin >> *(movies + i);
            if (*(movies + i) < 0) {
                cout << "So phim khong duoc am. Hay nhap lai." << endl;
            }
        } while (*(movies + i) < 0);
    }

    double average = calculateAverage(movies, numStudents);
    double medianValue = median(movies, numStudents);
    int modeValue = mode(movies, numStudents);

    cout << "\nTrung binh so phim ma sinh vien xem: " << average << endl;
    cout << "Median so phim: " << medianValue << endl;

    if (modeValue == -1) {
        cout << "Khong co mode (khong co gia tri nao xuat hien nhieu hon mot lan)." << endl;
    } else {
        cout << "Mode (gia tri xuat hien nhieu nhat): " << modeValue << endl;
    }

    delete[] movies;

    return 0;
}