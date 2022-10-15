#include "iostream"

using namespace std;

int main()
{
    int tienDienThangCu, tienDienThangMoi;
    cout << "Thang truoc bao nhieu tien dien: ";
    cin >> tienDienThangCu;
    cout << "Thang moi bao nhieu tien dien: ";
    cin >> tienDienThangMoi;

    int chuDien = tienDienThangMoi - tienDienThangCu;

    if (chuDien <= 100)
        chuDien = chuDien * 1000;
    else if (101 <= chuDien && chuDien >= 150)
        chuDien = 100 * 1000 + ((chuDien - 100) * 1200);
    else if (151 <= chuDien && chuDien >= 200)
        chuDien = 100 * 1000 + 50 + 1200 + ((chuDien - 150) * 2000);
    else
        chuDien = 100 * 1000 + 50 + 1200 + 50 * 2000 + ((chuDien - 200) * 2500);

    cout << "Tien dien thang nay la: " << chuDien << endl;
}