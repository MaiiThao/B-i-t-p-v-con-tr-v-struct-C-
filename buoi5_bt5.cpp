#include <iostream>
using namespace std;

int doSomething(int* x, int* y)
{
    int temp = *x;  
    *x = (*y) * 10; 
    *y = temp * 10; 
    return *x + *y; 
}

int main() {
    int a = 8;
    int b = 6;

    cout << "Truoc khi goi ham: a = " << a << ", b = " << b << endl;
    int result = doSomething(&a, &b);
    cout << "Sau khi goi ham: a = " << a << ", b = " << b << endl;
    cout << "Ket qua tra ve: " << result << endl;

    return 0;
}