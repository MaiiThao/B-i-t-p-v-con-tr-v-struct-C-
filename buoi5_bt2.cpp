#include <iostream>
using namespace std;

void sortScores(float* scores, int numScores) {
    for (int i = 0; i < numScores - 1; ++i) {
        for (int j = i + 1; j < numScores; ++j) {
            if (*(scores + i) > *(scores + j)) {
                float temp = *(scores + i);
                *(scores + i) = *(scores + j);
                *(scores + j) = temp;
            }
        }
    }
}

void calculateAverage(float* scores, int numScores) {
    float sum = 0.0;
    for (int i = 0; i < numScores; ++i) {
        sum += *(scores + i); 
    }
    float average = sum / numScores;
    cout << "\nDiem trung binh: " << average << endl;
}

int main() {
    int numScores;
    cout << "Nhap so luong diem kiem tra: ";
    cin >> numScores;
    while (numScores <= 0) {
        cout << "So luong diem kiem tra phai la so nguyen duong. Hay nhap lai: ";
        cin >> numScores;
    }
    float* scores = new float[numScores];

    for (int i = 0; i < numScores; ++i) {
        cout << "Diem " << i + 1 << ": ";
        cin >> *(scores + i);

        while (*(scores + i) < 0) {
            cout << "Diem kiem tra phai la so nguyen khong am. Hay nhap lai: ";
            cin >> *(scores + i);
        }
    }
    sortScores(scores, numScores);
    cout << "\nDanh sach diem da sap xep: " << endl;
    for (int i = 0; i < numScores; ++i) {
        cout << *(scores + i) << " ";
    }
    calculateAverage(scores, numScores);
    delete[] scores;
    system("pause");
    return 0;
}