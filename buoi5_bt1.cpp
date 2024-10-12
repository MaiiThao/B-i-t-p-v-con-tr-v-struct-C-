#include <iostream>
using namespace std;
int main() {
    int a[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int sizeinbytes = sizeof(a);
    cout << "Mang chiem dung " << sizeinbytes << " bytes" << endl;
    for (int i = 0; i < 10; i++) {
    cout << "Phan tu " << i + 1 << ": " << a[i]<< " tai dia chi: " << &a[i] << endl;
  }
  return 0;
}
