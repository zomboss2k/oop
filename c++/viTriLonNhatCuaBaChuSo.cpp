#include "iostream"

using namespace std;

int main()
{
    int n, hangTram, hangChuc, hangDonVi;
    cout << "Nhap so nguyen co 3 chu so bat ky: ";
    cin >> n;
    hangTram = n / 100;
    hangChuc = ((n % 100) / 10);
    hangDonVi = n % 10;
    if (hangTram > hangChuc)
    {
        cout << "So lon nhat cua ba so la: " <<hangTram<<", nam o Hang Tram";
    }
    else if (hangChuc > hangDonVi)
    {
        cout << "So lon nhat cua ba so la: " <<hangChuc<<", nam o Hang Chuc";
    }
    else
    {
        cout << "So lon nhat cua ba so la: " <<hangDonVi<<", nam o Hang Don Vi";
    }
}