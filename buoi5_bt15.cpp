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
    cout << "------------------------------\n";
    cout << "Thong tin phim:\n";
    cout << "Ten phim   : " << phim.tenPhim << endl;
    cout << "Dao dien   : " << phim.daoDien << endl;
    cout << "Nam phat hanh: " << phim.namPhatHanh << endl;
    cout << "Thoi luong : " << phim.thoiLuong << " phut" << endl;
    cout << "------------------------------\n";
}

int main() {
   
    MovieData phim1, phim2;

    phim1.tenPhim = "Your Name";
    phim1.daoDien = "Shinkai Makoto";
    phim1.namPhatHanh = 2016;
    phim1.thoiLuong = 110;

    phim2.tenPhim = "Spirited Away";
    phim2.daoDien = "Hayao Miyazaki";
    phim2.namPhatHanh = 2001;
    phim2.thoiLuong = 125;

    cout << "Thong tin ve cac bo phim:\n\n";
    displayMovieInfo(phim1);
    cout << endl;
    displayMovieInfo(phim2);

    return 0;
}