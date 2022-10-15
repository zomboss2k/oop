#include "iostream"

using namespace std;

int main()
{
    int a, b, c;
    int max;
    cout << "Nhap so thu nhat: ";
    cin >> a;
    cout << "Nhap so thu hai: ";
    cin >> b;
    cout << "Nhap so thu ba: ";
    cin >> c;
    if (a > b)
    {
        max = a;
    }
    else if (b > c)
    {
        max = b;
    }
    else
    {
        max = c;
    }
    cout << endl;
    cout << "So lon nhat la: " << max << endl;
    return 0;
}