#include "iostream"
#include "fstream"
#include "iomanip" // thư viện iomanip để căn lề xuất dữ liệu
#include <bits/stdc++.h>

using namespace std;

int n, a[100], sum = 0, i;

void intergerNumber()
{
    cout << "Nhap so nguyen n: ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        a[i] = i;
        cout << setw(10) << a[i];
    }
    for (i = 1; i <= n; i++)
    {
        sum += a[i];
    }
    cout << endl;
    cout << setw(10) << "Tong cua phan tu so nguyen la: " << sum;
}
int main()
{
    intergerNumber();
}