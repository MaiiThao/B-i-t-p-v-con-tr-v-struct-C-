#include <iostream>

using namespace std;

void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

int main()
{
    int NUM_DONATIONS;

    cout << "Nhap so luong dong gop: ";
    while (!(cin >> NUM_DONATIONS) || NUM_DONATIONS <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Hay nhap mot so nguyen duong. Thu lai: ";
    }

    int *donations = new int[NUM_DONATIONS];

    for (int i = 0; i < NUM_DONATIONS; i++) {
        cout << "Dong gop #" << (i + 1) << ": ";
        while (!(cin >> donations[i]) || donations[i] < 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Hay nhap mot so khong am. Thu lai: ";
        }
    }

    int **arrPtr = new int*[NUM_DONATIONS];

    for (int count = 0; count < NUM_DONATIONS; count++)
        arrPtr[count] = &donations[count];

    arrSelectSort(arrPtr, NUM_DONATIONS);

    cout << "Cac khoan dong gop, sap xep theo thu tu tang dan:\n";
    showArrPtr(arrPtr, NUM_DONATIONS);

    cout << "Cac khoan dong gop, theo thu tu ban dau:\n";
    showArray(donations, NUM_DONATIONS);

    delete[] donations;
    delete[] arrPtr;

    return 0;
}

void arrSelectSort(int *arr[], int size)
{
    int startScan, minIndex;
    int *minElem;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minElem = arr[startScan];
        minIndex = startScan;
        for (int index = startScan + 1; index < size; index++)
        {
            if (*(arr[index]) < *minElem)
            {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

void showArray(const int arr[], int size)
{
    for (int count = 0; count < size; count++)
        cout << arr[count] << " ";
    cout << endl;
}

void showArrPtr(int *arr[], int size)
{
    for (int count = 0; count < size; count++)
        cout << *(arr[count]) << " ";
    cout << endl;
}