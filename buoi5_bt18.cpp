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

    cout << "Nhap so luot thich: ";
    cin >> quote->likes;
}

void displayQuoteData(QuoteData* quote) {
    cout << "\nThong tin cau trich dan:\n";
    cout << "Tac gia: " << quote->author << endl;
    cout << "Noi dung: \"" << quote->content << "\"" << endl;
    cout << "So luot thich: " << quote->likes << endl;
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

    for (int i = 0; i < numberOfQuotes; ++i) {
        displayQuoteData(&quotes[i]);
    }

    delete[] quotes;

    return 0;
}
