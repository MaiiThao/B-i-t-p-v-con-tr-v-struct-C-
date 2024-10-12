#include <iostream>
#include <string>
using namespace std;

struct MovieData {
    string tenPhim;   
    string daoDien;       
    int namPhatHanh;       
    int thoiLuong;          
    float chiPhiSanXuat;    
    float doanhThu;         
};

void inputMovieData(MovieData& phim) {
    cout << "Nhap ten phim: ";
    cin.ignore(); 
    getline(cin, phim.tenPhim);

    cout << "Nhap dao dien: ";
    getline(cin, phim.daoDien);

    cout << "Nhap nam phat hanh: ";
    cin >> phim.namPhatHanh;

    cout << "Nhap thoi gian (phut): ";
    cin >> phim.thoiLuong;

    cout << "Nhap chi phi san xuat: ";
    cin >> phim.chiPhiSanXuat;

    cout << "Nhap doanh thu trong nam dau tien: ";
    cin >> phim.doanhThu;
}

void displayMovieInfo(const MovieData& phim) {
    cout << "\nThong tin phim:\n";
    cout << "Ten phim: " << phim.tenPhim << endl;
    cout << "Dao dien: " << phim.daoDien << endl;
    cout << "Nam phat hanh: " << phim.namPhatHanh << endl;
    cout << "Thoi luong: " << phim.thoiLuong << " phut" << endl;
    cout << "Chi phi san xuat: " << phim.chiPhiSanXuat << " trieu dong" << endl;
    cout << "Doanh thu trong nam dau tien: " << phim.doanhThu << " trieu dong" << endl;

    float loiNhuan = phim.doanhThu - phim.chiPhiSanXuat;
    if (loiNhuan > 0) {
        cout << "Loi nhuan: " << loiNhuan << " trieu dong" << endl;
    } else if (loiNhuan < 0) {
        cout << "Thua lo: " << -loiNhuan << " trieu dong" << endl;
    } else {
        cout << "Khong co loi nhuan hoac thua lo." << endl;
    }
}

int main() {
    int soLuongPhim;

    cout << "Nhap so luong phim: ";
    cin >> soLuongPhim;

    MovieData* phim = new MovieData[soLuongPhim];

    for (int i = 0; i < soLuongPhim; ++i) {
        cout << "\nNhap thong tin cho phim thu " << i + 1 << ":" << endl;
        inputMovieData(phim[i]);
    }

    for (int i = 0; i < soLuongPhim; ++i) {
        displayMovieInfo(phim[i]);
    }

    delete[] phim;

    return 0;
}