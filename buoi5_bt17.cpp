#include <iostream>
#include <string>
using namespace std;

struct EarthquakeData {
    string name;          
    string location;       
    int year;              
    float magnitude;       
    int casualties;      
};

void inputEarthquakeData(EarthquakeData* earthquake) {
    cout << "Nhap ten tran dong dat: ";
    cin.ignore(); 
    getline(cin, earthquake->name);
    
    cout << "Nhap vi tri tran dong dat: ";
    getline(cin, earthquake->location);

    cout << "Nhap nam xay ra: ";
    cin >> earthquake->year;

    cout << "Nhap do lon (theo thang Richter): ";
    cin >> earthquake->magnitude;

    cout << "Nhap so nguoi thiet mang: ";
    cin >> earthquake->casualties;
}

void displayEarthquakeData(EarthquakeData* earthquake) {
    cout << "\nThong tin tran dong dat:\n";
    cout << "Ten: " << earthquake->name << endl;
    cout << "Vi tri: " << earthquake->location << endl;
    cout << "Nam xay ra: " << earthquake->year << endl;
    cout << "Do lon: " << earthquake->magnitude << endl;
    cout << "So nguoi thiet mang: " << earthquake->casualties << endl;
}

int main() {
    const int numberOfEarthquakes = 3; 
    EarthquakeData* earthquakes = new EarthquakeData[numberOfEarthquakes];

    for (int i = 0; i < numberOfEarthquakes; ++i) {
        cout << "\nNhap thong tin cho tran dong dat thu " << i + 1 << ":" << endl;
        inputEarthquakeData(&earthquakes[i]);
    }

    for (int i = 0; i < numberOfEarthquakes; ++i) {
        displayEarthquakeData(&earthquakes[i]);
    }

    delete[] earthquakes;

    return 0;
}
