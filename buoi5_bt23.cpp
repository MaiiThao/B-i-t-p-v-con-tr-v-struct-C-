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

void displaySpeaker(const Speaker& speaker, int index) {
    cout << "\nThong tin dien gia thu " << index + 1 << ":\n";
    cout << "Ten: " << speaker.name << endl;
    cout << "So dien thoai: " << speaker.phoneNumber << endl;
    cout << "Chu de bai phat bieu: " << speaker.topic << endl;
    cout << "Phi dien thuyet: $" << speaker.speakingFee << endl;
}

void updateSpeakingFee(Speaker& speaker) {
    do {
        cout << "Nhap phi dien thuyet moi (>= 0): ";
        cin >> speaker.speakingFee;
        if (speaker.speakingFee < 0) {
            cout << "Phi dien thuyet khong the am. Hay nhap lai." << endl;
        }
    } while (speaker.speakingFee < 0);

    cout << "Phi dien thuyet da duoc cap nhat thanh cong!" << endl;
}

int main() {
    int numberOfSpeakers = 0;
    int choice;

    Speaker* speakers = nullptr;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Them dien gia moi\n";
        cout << "2. Cap nhat phi dien thuyet cua dien gia\n";
        cout << "3. Hien thi danh sach dien gia\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int newCount = numberOfSpeakers + 1;
                Speaker* newSpeakers = new Speaker[newCount];

                for (int i = 0; i < numberOfSpeakers; ++i) {
                    newSpeakers[i] = speakers[i];  
                }

                cout << "\nNhap thong tin cho dien gia thu " << newCount << ":" << endl;
                inputSpeaker(newSpeakers[numberOfSpeakers]);

                delete[] speakers;  
                speakers = newSpeakers; 
                numberOfSpeakers = newCount;

                cout << "Dien gia moi da duoc them thanh cong!" << endl;
                break;
            }
            case 2: {
                if (numberOfSpeakers == 0) {
                    cout << "Khong co dien gia nao de cap nhat.\n";
                } else {
                    int index;
                    do {
                        cout << "Nhap so thu tu cua dien gia (1 - " << numberOfSpeakers << "): ";
                        cin >> index;
                        if (index < 1 || index > numberOfSpeakers) {
                            cout << "So thu tu khong hop le. Hay nhap lai.\n";
                        }
                    } while (index < 1 || index > numberOfSpeakers);

                    updateSpeakingFee(speakers[index - 1]);
                }
                break;
            }
            case 3: {
                if (numberOfSpeakers == 0) {
                    cout << "Khong co dien gia nao de hien thi.\n";
                } else {
                    for (int i = 0; i < numberOfSpeakers; ++i) {
                        displaySpeaker(speakers[i], i);
                    }
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

    delete[] speakers;  
    return 0;
}
