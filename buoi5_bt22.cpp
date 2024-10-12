#include <iostream>
#include <string>

using namespace std;

struct Computer {
    double clockSpeed;  
    int coreCount;
    int ramCapacity;  
    int storageCapacity; 
    double performanceScore;
    double price;  
};

void inputComputerInfo(Computer& pc) {
    cout << "Toc do xung nhip (GHz): ";
    cin >> pc.clockSpeed;
    cout << "So loi CPU: ";
    cin >> pc.coreCount;
    cout << "Dung luong RAM (GB): ";
    cin >> pc.ramCapacity;
    cout << "Dung luong o cung (GB): ";
    cin >> pc.storageCapacity;
    cout << "Diem danh gia hieu suat: ";
    cin >> pc.performanceScore;
    cout << "Gia (VND): ";
    cin >> pc.price;
}

void showComputerInfo(const Computer& pc) {
    cout << "Toc do xung nhip: " << pc.clockSpeed << " GHz" << endl;
    cout << "So loi CPU: " << pc.coreCount << endl;
    cout << "Dung luong RAM: " << pc.ramCapacity << " GB" << endl;
    cout << "Dung luong o cung: " << pc.storageCapacity << " GB" << endl;
    cout << "Diem danh gia hieu suat: " << pc.performanceScore << endl;
    cout << "Gia: " << pc.price << " VND" << endl;
}

void searchComputers(const Computer* computers, int numComputers, double minPerformance, double maxPrice) {
    bool found = false;
    for (int i = 0; i < numComputers; ++i) {
        if (computers[i].performanceScore >= minPerformance && computers[i].price <= maxPrice) {
            cout << "\nMay tinh thu " << i + 1 << " phu hop:\n";
            showComputerInfo(computers[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "Khong co may tinh nao phu hop voi yeu cau.\n";
    }
}

int main() {
    int numComputers;
    cout << "Nhap so luong may tinh can luu tru thong tin: ";
    cin >> numComputers;

    Computer* computers = new Computer[numComputers];

    for (int i = 0; i < numComputers; ++i) {
        cout << "\nNhap thong tin cho may tinh thu " << i + 1 << ":\n";
        inputComputerInfo(computers[i]);
    }

    cout << "\nThong tin cac may tinh da nhap:\n";
    for (int i = 0; i < numComputers; ++i) {
        cout << "\nMay tinh thu " << i + 1 << ":\n";
        showComputerInfo(computers[i]);
    }

    double minPerformance, maxPrice;
    cout << "\nNhap diem danh gia hieu suat toi thieu: ";
    cin >> minPerformance;
    cout << "Nhap gia toi da (VND): ";
    cin >> maxPrice;

    searchComputers(computers, numComputers, minPerformance, maxPrice);

    delete[] computers;  

    return 0;
}
