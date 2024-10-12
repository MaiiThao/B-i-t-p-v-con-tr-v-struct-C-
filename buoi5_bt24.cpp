#include <iostream>
#include <string>
using namespace std;

struct Speaker {
    string name;           
    string phoneNumber;    
    string topic;      
    float speakingFee;     
};

void inputSpeaker(Speaker& speaker) {
    cout << "Nhap ten dien gia: ";
    cin.ignore(); 
    getline(cin, speaker.name);

    cout << "Nhap so dien thoai: ";
    getline(cin, speaker.phoneNumber);

    cout << "Nhap chu de bai phat bieu: ";
    getline(cin, speaker.topic);

    do {
        cout << "Nhap phi dien thuyet (>= 0): ";
        cin >> speaker.speakingFee;
        if (speaker.speakingFee < 0) {
            cout << "Phi dien thuyet khong the am. Hay nhap lai." << endl;
        }
    } while (speaker.speakingFee < 0);
}

void displaySpeaker(const Speaker& speaker) {
    cout << "Ten: " << speaker.name << endl;
    cout << "So dien thoai: " << speaker.phoneNumber << endl;
    cout << "Chu de bai phat bieu: " << speaker.topic << endl;
    cout << "Phi dien thuyet: $" << speaker.speakingFee << endl;
}

void updateSpeaker(Speaker& speaker) {
    cout << "Cap nhat thong tin cho dien gia:\n";
    inputSpeaker(speaker);
}

int main() {
    const int SIZE = 10;  
    Speaker speakers[SIZE];  
    int choice = 0;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Nhap thong tin cho dien gia\n";
        cout << "2. Cap nhat thong tin cho dien gia\n";
        cout << "3. Hien thi danh sach dien gia\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                for (int i = 0; i < SIZE; ++i) {
                    cout << "\nNhap thong tin cho dien gia thu " << i + 1 << ":\n";
                    inputSpeaker(speakers[i]);  
                }
                break;
            }
            case 2: {
                int index;
                cout << "Nhap so thu tu cua dien gia de cap nhat (1 - " << SIZE << "): ";
                cin >> index;
                if (index >= 1 && index <= SIZE) {
                    updateSpeaker(speakers[index - 1]);  
                } else {
                    cout << "So thu tu khong hop le." << endl;
                }
                break;
            }
            case 3: {
                cout << "\nDanh sach dien gia:\n";
                for (int i = 0; i < SIZE; ++i) {
                    cout << "\nDien gia thu " << i + 1 << ":\n";
                    displaySpeaker(speakers[i]);  
                }
                break;
            }
            case 4:
                cout << "Thoat chuong trinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le. Hay chon lai.\n";
        }
    } while (choice != 4);

    return 0;
}
