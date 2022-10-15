#include "iostream"

using namespace std;

int main()
{
    double a, b, c, d;
    double max;
    cout << "Nhap so thu nhat: ";
    cin >> a;
    cout << "Nhap so thu hai: ";
    cin >> b;
    cout << "Nhap so thu ba: ";
    cin >> c;
    cout << "Nhap so thu tu: ";
    cin >> d;
    if (a > b)
    {
        max = a;
    }
    else if (b > c)
    {
        max = b;
    }
    else if (c > d)
    {
        max = c;
    } else {
        max = d;
    }
    cout << endl;
    cout << "So lon nhat la: " << max << endl;
    return 0;
}