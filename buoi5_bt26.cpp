#include <iostream>
using namespace std;

struct dateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

void inputDateTime(dateTime& dt) {
    cout << "Nhap nam: ";
    cin >> dt.year;
    
    cout << "Nhap thang (1-12): ";
    cin >> dt.month;
    
    cout << "Nhap ngay (1-31): ";
    cin >> dt.day;
    
    cout << "Nhap gio (0-23): ";
    cin >> dt.hour;
    
    cout << "Nhap phut (0-59): ";
    cin >> dt.minute;
    
    cout << "Nhap giay (0-59): ";
    cin >> dt.second;
}

void displayDateTime(const dateTime& dt) {
    cout << dt.day << "/" << dt.month << "/" << dt.year << " "
         << dt.hour << ":" << dt.minute << ":" << dt.second << endl;
}

int compareDateTime(const dateTime& dt1, const dateTime& dt2) {
    if (dt1.year != dt2.year)
        return (dt1.year < dt2.year) ? -1 : 1;
    
    if (dt1.month != dt2.month)
        return (dt1.month < dt2.month) ? -1 : 1;
    
    if (dt1.day != dt2.day)
        return (dt1.day < dt2.day) ? -1 : 1;
    
    if (dt1.hour != dt2.hour)
        return (dt1.hour < dt2.hour) ? -1 : 1;
    
    if (dt1.minute != dt2.minute)
        return (dt1.minute < dt2.minute) ? -1 : 1;
    
    if (dt1.second != dt2.second)
        return (dt1.second < dt2.second) ? -1 : 1;
    
    return 0;
}

int main() {
    dateTime dt1;
    dateTime dt2;

    cout << "Nhap thong tin ngay va gio thu nhat:\n";
    inputDateTime(dt1);
    
    cout << "Nhap thong tin ngay va gio thu hai:\n";
    inputDateTime(dt2);

    cout << "\nNgay gio thu nhat: ";
    displayDateTime(dt1);
    
    cout << "Ngay gio thu hai: ";
    displayDateTime(dt2);

    int result = compareDateTime(dt1, dt2);
    if (result == 0)
        cout << "Hai ngay gio nay giong nhau.\n";
    else if (result < 0)
        cout << "Ngay gio thu nhat xay ra truoc ngay gio thu hai.\n";
    else
        cout << "Ngay gio thu hai xay ra truoc ngay gio thu nhat.\n";

    return 0;
}
