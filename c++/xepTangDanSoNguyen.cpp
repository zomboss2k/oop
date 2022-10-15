#include "iostream"

using namespace std;

int main()
{
    int a, b, c, d;
    cout << "Nhap 4 so nguyen bat ky: " << endl;
    cin >> a >> b >> c >> d;

    if (a > b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    if (a > c)
    {
        a = a + c;
        c = a - c;
        a = a - c;
    }
    if (a > d)
    {
        a = a + d;
        d = a - d;
        a = a - d;
    }
    if (b > c)
    {
        b = b + c;
        c = b - c;
        b = b - c;
    }
    if (b > d)
    {
        b = b + d;
        d = b - d;
        b = b - d;
    }
    if (c > d)
    {
        c = c + d;
        d = c - d;
        c = c - d;
    }
    cout << endl;
    cout << "Day so da duoc sap xep la: " << a << ", " << b << ", " << c << ", " << d << ", " << endl;
}