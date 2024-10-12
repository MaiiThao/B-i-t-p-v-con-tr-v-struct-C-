#include <iostream>
#include <string>
using namespace std;

void sortScores(string* names, float* scores, int numStudents) {
    for (int i = 0; i < numStudents - 1; ++i) {
        for (int j = i + 1; j < numStudents; ++j) {
            if (*(scores + i) > *(scores + j)) {
               
                float tempScore = *(scores + i);
                *(scores + i) = *(scores + j);
                *(scores + j) = tempScore;
                
                string tempName = *(names + i);
                *(names + i) = *(names + j);
                *(names + j) = tempName;
            }
        }
    }
}

void calculateAverage(float* scores, int numStudents) {
    float sum = 0.0;
    for (float* ptr = scores; ptr < scores + numStudents; ++ptr) {
        sum += *ptr;
    }
    float average = sum / numStudents;
    cout << "\nDiem trung binh: " << average << endl;
}

int main() {
    int numStudents;
    cout << "Nhap so luong hoc sinh: ";
    cin >> numStudents;
    while (numStudents <= 0) {
        cout << "So luong hoc sinh phai la so nguyen duong. Hay nhap lai: ";
        cin >> numStudents;
    }

    string* names = new string[numStudents];
    float* scores = new float[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "Nhap ten hoc sinh " << (i + 1) << ": ";
        cin.ignore();
        getline(cin, *(names + i));

        cout << "Nhap diem cua " << *(names + i) << ": ";
        cin >> *(scores + i);
        while (*(scores + i) < 0) {
            cout << "Diem kiem tra phai la so khong am. Hay nhap lai: ";
            cin >> *(scores + i);
        }
    }

    sortScores(names, scores, numStudents);

    cout << "\nDanh sach hoc sinh va diem da sap xep: " << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << *(names + i) << ": " << *(scores + i) << endl;
    }

    calculateAverage(scores, numStudents);

    delete[] names;
    delete[] scores;
    system("pause");
    return 0;
}