#include <iostream>
#include <string>
using namespace std;

struct QuoteData {
    string author;         
    string content;        
    int likes;             
};

void inputQuoteData(QuoteData* quote) {
    cout << "Nhap ten tac gia cua cau trich dan: ";
    cin.ignore();
    getline(cin, quote->author);

    cout << "Nhap noi dung cau trich dan: ";
    getline(cin, quote->content);

    do {
        cout << "Nhap so luot thich (khong chap nhan gia tri am): ";
        cin >> quote->likes;
        if (quote->likes < 0) {
            cout << "Luot thich khong the am. Hay nhap lai." << endl;
        }
    } while (quote->likes < 0);
}

int calculateTotalLikes(QuoteData* quotes, int size) {
    int totalLikes = 0;
    for (int i = 0; i < size; ++i) {
        totalLikes += (quotes + i)->likes;
    }
    return totalLikes;
}

void displayPopularQuotes(QuoteData* quotes, int size, double averageLikes) {
    cout << "\nCac cau trich dan pho bien hon muc trung binh:\n";
    for (int i = 0; i < size; ++i) {
        if ((quotes + i)->likes > averageLikes) {
            double percentage = ((quotes + i)->likes / averageLikes) * 100;
            cout << "\"" << (quotes + i)->content << "\" - " << (quotes + i)->author;
            cout << " (Luot thich: " << (quotes + i)->likes << ", chiem " << percentage << "% so voi trung binh)\n";
        }
    }
}

int main() {
    int numberOfQuotes;

    cout << "Nhap so luong cau trich dan: ";
    cin >> numberOfQuotes;

    QuoteData* quotes = new QuoteData[numberOfQuotes];

    for (int i = 0; i < numberOfQuotes; ++i) {
        cout << "\nNhap thong tin cho cau trich dan thu " << i + 1 << ":" << endl;
        inputQuoteData(&quotes[i]);
    }

    int totalLikes = calculateTotalLikes(quotes, numberOfQuotes);
    double averageLikes = static_cast<double>(totalLikes) / numberOfQuotes;

    displayPopularQuotes(quotes, numberOfQuotes, averageLikes);

    delete[] quotes;

    return 0;
}