#include <iostream>
#include <string>
using namespace std;

struct MovieData {
    string tenPhim;
    string daoDien;
    int namPhatHanh;
    int thoiLuong; 
};

void displayMovieInfo(const MovieData& phim) {
    cout << "Thong tin phim:\n";
    cout << "Ten phim: " << phim.tenPhim << endl;
    cout << "Dao dien: " << phim.daoDien << endl;
    cout << "Nam phat hanh: " << phim.namPhatHanh << endl;
    cout << "Thoi luong: " << phim.thoiLuong << " phut" << endl;
}

int main() {
    
    MovieData phim1;

    cout << "Nhap ten phim: ";
    getline(cin, phim1.tenPhim);

    cout << "Nhap ten dao dien: ";
    getline(cin, phim1.daoDien);

    cout << "Nhap nam phat hanh: ";
    cin >> phim1.namPhatHanh;

    cout << "Nhap thoi luong (phut): ";
    cin >> phim1.thoiLuong;

    cout << "\n";

    displayMovieInfo(phim1);

    return 0;
}
