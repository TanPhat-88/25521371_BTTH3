#include <iostream>
#include <iomanip>
#include "cCandidate.h" 

using namespace std;

// Input: Dữ liệu nhập từ bàn phím gồm mã, tên, ngày sinh và điểm 3 môn.
// Output: Đối tượng cCandidate hiện tại lưu trữ các thông tin vừa nhập.
// Thuật toán: Dùng cin.ignore() để xóa bộ nhớ đệm trước khi nhập chuỗi. 
//             Dùng getline để lấy chuỗi có khoảng trắng và cin để lấy điểm số.
void cCandidate::Nhap() {
    cin.ignore();
    cout << "Nhap ma: "; getline(cin, ma);
    cout << "Nhap ten: "; getline(cin, ten);
    cout << "Nhap ngay sinh: "; getline(cin, ngaySinh);
    cout << "Nhap diem Toan - Van - Anh: ";
    cin >> toan >> van >> anh;
}

// Input: Không có (sử dụng dữ liệu của đối tượng hiện tại).
// Output: Thông tin của thí sinh được in ra màn hình.
// Thuật toán: Sử dụng setw() từ thư viện <iomanip> để căn lề cho các cột, 
//             tạo bảng xuất dữ liệu ngay ngắn. Gọi hàm TongDiem() để in tổng điểm.
void cCandidate::Xuat() const {
    cout << setw(10) << ma << " | " 
         << setw(20) << ten << " | " 
         << setw(12) << ngaySinh << " | "
         << "Tong: " << TongDiem() << endl;
}

// Input: Không có.
// Output: Tổng điểm 3 môn Toán, Văn, Anh (kiểu float).
// Thuật toán: Trả về kết quả của phép cộng toan + van + anh.
float cCandidate::TongDiem() const {
    return toan + van + anh;
}