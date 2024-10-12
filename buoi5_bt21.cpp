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
    do {
        cout << "Toc do xung nhip (GHz): ";
        cin >> pc.clockSpeed;
        if (pc.clockSpeed < 0) cout << "Toc do xung nhip khong the be hon 0. Vui long nhap lai.\n";
    } while (pc.clockSpeed < 0);

    do {
        cout << "So loi CPU: ";
        cin >> pc.coreCount;
        if (pc.coreCount <= 0) cout << "So loi CPU phai lon hon 0. Vui long nhap lai.\n";
    } while (pc.coreCount <= 0);

    do {
        cout << "Dung luong RAM (GB): ";
        cin >> pc.ramCapacity;
        if (pc.ramCapacity <= 0) cout << "Dung luong RAM phai lon hon 0. Vui long nhap lai.\n";
    } while (pc.ramCapacity <= 0);

    do {
        cout << "Dung luong o cung (GB): ";
        cin >> pc.storageCapacity;
        if (pc.storageCapacity <= 0) cout << "Dung luong o cung phai lon hon 0. Vui long nhap lai.\n";
    } while (pc.storageCapacity <= 0);

    do {
        cout << "Diem danh gia hieu suat: ";
        cin >> pc.performanceScore;
        if (pc.performanceScore < 0) cout << "Diem danh gia hieu suat khong the be hon 0. Vui long nhap lai.\n";
    } while (pc.performanceScore < 0);

    do {
        cout << "Gia (VND): ";
        cin >> pc.price;
        if (pc.price < 0) cout << "Gia khong the be hon 0. Vui long nhap lai.\n";
    } while (pc.price < 0);
}

void showComputerInfo(const Computer& pc) {
    cout << "Toc do xung nhip: " << pc.clockSpeed << " GHz" << endl;
    cout << "So loi CPU: " << pc.coreCount << endl;
    cout << "Dung luong RAM: " << pc.ramCapacity << " GB" << endl;
    cout << "Dung luong o cung: " << pc.storageCapacity << " GB" << endl;
    cout << "Diem danh gia hieu suat: " << pc.performanceScore << endl;
    cout << "Gia: " << pc.price << " VND" << endl;
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

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Them mot may tinh moi\n";
        cout << "2. Thay doi gia cua mot may tinh\n";
        cout << "3. Hien thi thong tin toan bo may tinh\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int newSize;
                cout << "Nhap so luong may tinh moi can them: ";
                cin >> newSize;

                Computer* newComputers = new Computer[numComputers + newSize];
                for (int i = 0; i < numComputers; ++i) {
                    newComputers[i] = computers[i];
                }

                for (int i = numComputers; i < numComputers + newSize; ++i) {
                    cout << "\nNhap thong tin cho may tinh thu " << i + 1 << ":\n";
                    inputComputerInfo(newComputers[i]);
                }

                delete[] computers;
                computers = newComputers;
                numComputers += newSize;
                break;
            }

            case 2: {
                int index;
                cout << "Nhap so thu tu may tinh can thay doi gia (1-" << numComputers << "): ";
                cin >> index;

                if (index > 0 && index <= numComputers) {
                    do {
                        cout << "Nhap gia moi cho may tinh " << index << ": ";
                        cin >> computers[index - 1].price;
                        if (computers[index - 1].price < 0) cout << "Gia khong the be hon 0. Vui long nhap lai.\n";
                    } while (computers[index - 1].price < 0);
                } else {
                    cout << "So thu tu may tinh khong hop le.\n";
                }
                break;
            }

            case 3: {
                cout << "\nThong tin cac may tinh:\n";
                for (int i = 0; i < numComputers; ++i) {
                    cout << "\nMay tinh thu " << i + 1 << ":\n";
                    showComputerInfo(computers[i]);
                }
                break;
            }

            case 4:
                cout << "Thoat chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le, vui long chon lai.\n";
        }
    } while (choice != 4);

    delete[] computers;  

    return 0;
}
