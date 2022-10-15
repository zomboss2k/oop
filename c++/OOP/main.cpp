// Đề tài 3. Xây dựng chương trình hoàn chỉnh cài đặt cấu trúc Danh sách mảng biểu diễn danh sách sinh viên (maSV, họ đệm, tên, quê quán, khoa, lớp, khóa học). Chương trình gồm các chức năng:
// Danh sách sinh viên được lưu trong 1 file. Bắt đầu chương trình, toàn bộ dữ liệu được đọc từ file vào một Danh sách mảng.
// Tạo bảng chỉ mục, sắp xếp bảng chỉ mục hỗ trợ cho quá trình tìm kiếm dữ liệu.
// Thêm một sinh viên vào trong danh sách liên kết đơn. Đảm bảo mã sinh viên nhập vào chưa có trong danh sách. (Lưu ý cập nhật file dữ liệu gốc).
// Xóa một sinh viên trong danh sách liên kết đơn. (Lưu ý cập nhật file dữ liệu gốc).
// Chỉnh sửa thông tin của một sinh viên trong danh sách. (Lưu ý cập nhật file dữ liệu gốc).
// Tìm kiếm thông tin của một sinh viên theo mã sinh viên (Cài đặt thuật toán tìm kiếm nhị phân).
// Lọc và hiển thị một danh sách sinh viên theo lớp. Kết quả lọc lưu vào một file mới.

#include "iostream"
#include "fstream"
#include "string"
#include "iomanip" // thư viện iomanip để căn lề xuất dữ liệu
using namespace std;
struct SinhVien
{
    int maSV;       // mã sinh viên
    string hoDem;   // họ đệm
    string ten;     // tên
    string queQuan; // quê quán
    string khoa;    // khoa
    string lop;     // lớp
    int khoaHoc;    // khóa học
};
void Out1SinhVien(SinhVien s)
{

    cout << setw(10) << s.maSV; // căn lề phải 10 ký tự rồi xuất ra mã sinh viên
    cout << setw(15) << s.hoDem;
    cout << setw(15) << s.ten;
    cout << setw(20) << s.queQuan;
    cout << setw(15) << s.khoa;
    cout << setw(15) << s.lop;
    cout << setw(20) << s.khoaHoc;
    cout << endl;
}

void ReadFile(SinhVien a[], int &n) // đọc file vào mảng
{
    ifstream in("sinhvien.txt"); // mở file để đọc
    if (in.fail())               // nếu không thể đọc file
    {
        cout << "Khong mo duoc file" << endl; // thông báo lỗi
        return;                               // thoát khỏi hàm
    }
    while (!in.eof()) // đọc đến cuối file
    {
        in >> a[n].maSV;    // đọc mã sinh viên
        in >> a[n].hoDem;   // đọc họ đệm
        in >> a[n].ten;     // đọc tên
        in >> a[n].queQuan; // đọc quê quán
        in >> a[n].khoa;    // đọc khoa
        in >> a[n].lop;     // đọc lớp
        in >> a[n].khoaHoc; // đọc khóa học
        n++;                // tăng biến n
    }
    cout << " " << endl;
    cout << "Da luu file vao mang"<<endl;
    in.close(); // đóng file
}

void SaveFile(SinhVien a[], int n) // lưu dữ liệu ra file
{
    ofstream out("sinhvien.txt"); // mở file để ghi
    for (int i = 0; i < n; i++)       // duyệt mảng
    {
        out << a[i].maSV << " ";     // ghi mã sinh viên
        out << a[i].hoDem << " ";    // ghi họ đệm
        out << a[i].ten << " ";      // ghi tên
        out << a[i].queQuan << " ";  // ghi quê quán
        out << a[i].khoa << " ";     // ghi khoa
        out << a[i].lop << " ";      // ghi lớp
        out << a[i].khoaHoc << endl; // ghi khóa học
    }
    cout << "luu file thanh cong vao file sinhvien.txt" << endl;
    out.close(); // đóng filen
}

int findIndex(SinhVien a[], int n, int maSV) // tìm kiếm vi tri của một sinh viên trong mảng
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].maSV == maSV)
        {
            return i;
        }
    }
    return -1;
}

void AddSinhVien(SinhVien a[], int &n) // thêm sinh viên vào danh sách
{
    SinhVien s; // tạo một sinh viên
    cout << "Nhap ma sinh vien: ";
    cin >> s.maSV;                        // nhập mã sinh viên
    while (findIndex(a, n, s.maSV) != -1) // nếu mã sinh viên đã tồn tại{
    {
        cout << "Ma sinh vien da ton tai. Nhap lai: ";
        cin >> s.maSV;
    }
    cin.ignore();
    cout << "Nhap ho dem: ";
    // cin >> s.hoDem;
    getline(std::cin, s.hoDem); // nhập họ đệm
    cout << "Nhap ten: ";
    cin >> s.ten; // nhập tên
    cout << "Nhap que quan: ";
    cin >> s.queQuan; // nhập quê quán
    cout << "Nhap khoa: ";
    cin >> s.khoa; // nhập khoa
    cout << "Nhap lop: ";
    cin >> s.lop; // nhập lớp
    cout << "Nhap khoa hoc: ";
    cin >> s.khoaHoc; // nhập khóa học
    a[n] = s;         // ghi dữ liệu vào mảng
    n++;              // tăng biến n
    SaveFile(a, n);   // lưu dữ liệu ra file
}

void DeleteSinhVien(SinhVien a[], int &n, int maSv) // xóa sinh viên khỏi danh sách
{
    for (int i = 0; i < n; i++) // duyệt mảng
    {
        if (a[i].maSV == maSv) // nếu mã sinh viên bằng mã sinh viên cần xóa
        {
            for (int j = i; j < n; j++) // duyệt từ vị trí i đến n-1
            {
                a[j] = a[j + 1]; // ghi dữ liệu từ vị trí i+1 đến n-1 vào vị trí i
            }
            n--;   // giảm biến n
            break; // thoát khỏi vòng lặp
        }
    }

    SaveFile(a, n); // lưu dữ liệu ra file
}

void EditSinhVien(SinhVien a[], int &n, int maSv) // sửa thông tin sinh viên
{
    int index = findIndex(a, n, maSv); // tìm kiếm vị trí của một sinh viên trong mảng
    if (index == -1)                   // nếu không tìm thấy
    {
        cout << "Khong tim thay sinh vien co ma so: " << maSv << endl;
    }
    else // nếu tìm thấy
    {
        cout << "Nhap ho dem: ";
        cin >> a[index].hoDem; // nhập họ đệm
        cout << "Nhap ten: ";
        cin >> a[index].ten; // nhập tên
        cout << "Nhap que quan: ";
        cin >> a[index].queQuan; // nhập quê quán
        cout << "Nhap khoa: ";
        cin >> a[index].khoa; // nhập khoa
        cout << "Nhap lop: ";
        cin >> a[index].lop; // nhập lớp
        cout << "Nhap khoa hoc: ";
        cin >> a[index].khoaHoc; // nhập khóa học
        SaveFile(a, n);          // lưu dữ liệu ra file
    }
}

void SearchSinhVien(SinhVien a[], int n, int maSv) // tìm kiếm sinh viên
{
    // sắp xếp amngr tăng theo mã sinh viên;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].maSV > a[j].maSV)
            {
                SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // tìm kiếm
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid].maSV == maSv)
        {
            cout << "Tim thay sinh vien co ma so: " << a[mid].maSV << endl;
            cout << "Ho dem: " << a[mid].hoDem << endl;
            cout << "Ten: " << a[mid].ten << endl;
            cout << "Que quan: " << a[mid].queQuan << endl;
            cout << "Khoa: " << a[mid].khoa << endl;
            cout << "Lop: " << a[mid].lop << endl;
            cout << "Khoa hoc: " << a[mid].khoaHoc << endl;
            return;
        }
        else if (a[mid].maSV > maSv)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << "Khong tim thay sinh vien co ma so: " << maSv << endl;
}

void LocSinhVien(SinhVien a[], int n, string lop)
{
    ofstream out("sinhvien_cau5.txt"); // mở file để ghi
    int flag = 0;                      // biến đếm số sinh viên có lớp là lớp cần tìm
    for (int i = 0; i < n; i++)
    {
        if (a[i].lop == lop)
        {
            Out1SinhVien(a[i]); // xuat sinh vien
            flag = 1;
            out << a[i].maSV << " " << a[i].hoDem << " " << a[i].ten << " " << a[i].queQuan << " " << a[i].khoa << " " << a[i].lop << " " << a[i].khoaHoc << endl;
        }
    }
    if (flag == 0) // nếu không tìm thấy
        cout << "Khong tim thay sinh vien co lop: " << lop << endl;

    out.close(); // đóng file
}

void Menu() // menu
{
    int choice = 1;
    SinhVien a[100];
    int n = 0;
    while (choice != 0)
    {
        cout << "\n";
        cout << "1. doc file thong tin sinh vien" << endl;
        cout << "2. xuat thong tin sinh vien" << endl;
        cout << "3. them sinh vien" << endl;
        cout << "4. xoa sinh vien" << endl;
        cout << "5. sua thong tin sinh vien" << endl;
        cout << "6. tim kiem sinh vien" << endl;
        cout << "7. loc sinh vien" << endl;
        cout << "0. thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        system("cls"); // xóa màn hình
        switch (choice)
        {
        case 1:
            ReadFile(a, n); // đọc file
            break;
        case 2:
            for (int i = 0; i < n; i++)
                Out1SinhVien(a[i]); // xuất sinh viên
            break;
        case 3:
            AddSinhVien(a, n); // thêm sinh viên
            break;
        case 4:
        {
            int maSv;
            cout << "Nhap ma sinh vien can xoa: ";
            cin >> maSv;
            DeleteSinhVien(a, n, maSv); // xóa sinh viên
            break;
        }
        case 5:
        {
            int maSv;
            cout << "Nhap ma so sinh vien can sua: ";
            cin >> maSv;
            EditSinhVien(a, n, maSv); // sửa sinh viên
            break;
        }
        case 6:
        {
            int maSv;
            cout << "Nhap ma so sinh vien can tim: ";
            cin >> maSv;
            SearchSinhVien(a, n, maSv); // tìm kiếm sinh viên
            break;
        }
        case 7:
        {
            string lop;
            cout << "Nhap lop can loc: ";
            cin >> lop;
            LocSinhVien(a, n, lop); // lọc sinh viên
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
    Menu();
    return 0;
}