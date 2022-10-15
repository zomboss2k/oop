#include "iostream"
#include "math.h"
using namespace std;

bool kiemTraChanLe(int numberTest)
{
    return numberTest % 2 == 0 ? true : false;
}

int giaiThua(int n)
{
    int giaiThua = 1;
    for (int i = 1; i <= n; i++)
        giaiThua = giaiThua * i;
    return giaiThua;
}

void hoanVi2So(int a, int b)
{
}

bool kiemTraNgayThangNam(int ngay, int thang, int nam)
{
    bool check = true;
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        (ngay > 0 && ngay <= 31) ? check = true : check = false;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        (ngay > 0 && ngay <= 30) ? check = true : check = false;
        break;

    case 2:
        if ((nam % 4 == 0 && nam % 100 == 0) || nam % 400 == 0)
        {
            (ngay > 0 && ngay <= 29) ? check = true : check = false;
        }
        else
        {
            (ngay > 0 && ngay <= 28) ? check = true : check = false;
        }
        break;
    }
    return check;
}

void checkHoanVi(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

bool kiemTraSoNguyenTo(int n)
{
    // Bước 1: Nhập vào n
    // Bước 2: Kiểm tra nếu n < 2 thì kết luận n không phải là số nguyên tố
    // Bước 3: Lặp từ 2 tới (n-1), nếu trong khoảng này tồn tại số mà n chia hết thì kết luận
    // n không phải là số nguyên tố, ngược lại n là số nguyên tố.
    if (n < 2)
        return false;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
        {
            return false;
        }
    return true;
}
double tinhTrungBinhCong(double diemToan, double diemVan, double diemAnh, double &TBC)
{
    TBC = ((diemToan + diemVan + diemAnh) / 3);
    return TBC;
}

int daoNguocBaSo(int n)
{
    int daoNguoc = 0;
    while (n > 0)
    {
        daoNguoc = n % 10;
        n /= 10;
    }
    return daoNguoc;
}

int chuSoLonNhat(int n)
{
    int max = 0; // lưu giá trị lớn nhất
    while (n > 0)
    {
        int t = n % 10; // 1234 % 10 = 4

        if (t > max) // 4 > 0
            max = t; // max = 4

        n = n / 10; // n = 4
    }
    return max;
}

string docSo(int n)
{
    switch (n)
    {
    case 0:
        return "khong";
    case 1:
        return "mot";
    case 2:
        return "hai";
    case 3:
        return "ba";
    case 4:
        return "bon";
    case 5:
        return "nam";
    case 6:
        return "sau";
    case 7:
        return "bay";
    case 8:
        return "tam";
    case 9:
        return "chin";
    default:
        break;
    };
}

string inRaSo(int n){
    string a;
    while(n>=0){
        int b = n % 10;
        if (b == docSo(n))
    }
    // return n;
}

void Menu() // menu
{
    int choice = 1;
    int n = 0;
    while (choice != 0)
    {
        cout << "\n";
        cout << "1. Kiem tra So Chan Le" << endl;
        cout << "2. Tinh giai thua" << endl;
        cout << "3. Kiem tra Ngay, Thang, Nam" << endl;
        cout << "4. Hoan vi 2 bien" << endl;
        cout << "5. Kiem tra so nguyen to" << endl;
        cout << "6. Tinh trung binh cong" << endl;
        cout << "7. Dao nguoc ba so" << endl;
        cout << "0. thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        system("cls"); // xóa màn hình
        switch (choice)
        {
        case 1:
            int numberTest;
            cout << "Kiem tra so chan le: ";
            cin >> numberTest;
            kiemTraChanLe(numberTest) ? cout << "So chan" << endl : cout << "So le" << endl;
            break;
        case 2:
            int n;
            cout << "Tinh giai thua cua so n: ";
            cin >> n;
            cout << "Giai thua cua so " << n << " la: " << giaiThua(n) << endl;
            break;
        case 3:
            int ngay, thang, nam;
            cout << "Nhap ngay: ";
            cin >> ngay;
            cout << "Nhap thang: ";
            cin >> thang;
            cout << "Nhap nam: ";
            cin >> nam;

            if (kiemTraNgayThangNam(ngay, thang, nam))
            {
                cout << endl;
                cout << "Hop le" << endl;
            }
            else
            {
                cout << endl;
                cout << "Khong hop le" << endl;
            }
            break;
        case 4:
        {
            int a, b;
            cout << "Nhap so 1 ban can hoan vi: ";
            cin >> a;
            cout << "Nhap so 1 ban can hoan vi: ";
            cin >> b;
            cout << endl;
            cout << "Truoc khi hoan vi la: " << endl;
            cout << "a = " << a << ", "
                 << "b = " << b << endl;
            checkHoanVi(a, b);
            cout << "Sau khi hoan vi la: " << endl;
            cout << "a = " << a << ", "
                 << "b = " << b << endl;
            break;
        }
        case 5:
        {
            int n;
            cout << "Nhap so nguyen to ban can kiem tra: ";
            cin >> n;
            kiemTraSoNguyenTo(n) ? cout << "So nguyen to" << endl : cout << "Khong phai so nguyen to" << endl;
            break;
        }
        case 6:
        {
            double diemToan, diemVan, diemAnh, TBC;
            string hoVaTen;
            cout << "Nhap ten hoc sinh: ";
            cin >> hoVaTen;
            cout << "Nhap diem Toan: ";
            cin >> diemToan;
            cout << "Nhap diem Van: ";
            cin >> diemVan;
            cout << "Nhap diem Anh: ";
            cin >> diemAnh;
            cout << endl;
            cout << "Ho va Ten hoc sinh: " << hoVaTen << endl;
            cout << "Diem Toan: " << diemToan << endl;
            cout << "Diem Van: " << diemVan << endl;
            cout << "Diem Anh: " << diemAnh << endl;
            tinhTrungBinhCong(diemToan, diemVan, diemAnh, TBC);
            cout << "Diem trung binh cua ba mon la: " << TBC << endl;
            break;
        }
        case 7:
        {
            int n;
            cin >> n;
            cout << daoNguocBaSo(n);
            break;
        }
        case 0:
            break;
        default:
            cout << "Nhap sai" << endl;
            break;
        }
    }
}

int main()
{
    // Menu();
    int n;
    cin >> n;

    // cout << n / 10;
    // int max = chuSoLonNhat(n);
    // cout << max;
    cout << inRaSo(n);
    return 0;
}