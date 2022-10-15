
#include <iostream>
using namespace std;

int main()
{
    cout << ("Nhap so nguyen: ");
    int n;
    cin >> n;
    (n % 2 == 0) 
    ? cout << n << " la so chan" 
    : cout << n << " la so le";
    return 0;
}