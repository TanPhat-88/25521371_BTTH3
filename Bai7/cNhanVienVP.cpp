#include <iostream>
#include <iomanip>
#include <string>
#include "cNhanVienVP.h"

using namespace std;

// Input: Không có
// Output: Khởi tạo đối tượng cNhanVienVP mặc định
// Thuật toán: Sử dụng danh sách khởi tạo (initializer list) để gán chuỗi rỗng cho mã/tên, 
//             ngày 1/1/2000 cho ngày tháng năm sinh và 0 cho lương.
cNhanVienVP::cNhanVienVP() : maNV(""), hoTen(""), ngay(1), thang(1), nam(2000), luong(0) {}

// Input: Dữ liệu nhập từ bàn phím gồm mã NV, họ tên, ngày sinh và lương.
// Output: Đối tượng cNhanVienVP hiện tại lưu trữ các thông tin vừa nhập.
// Thuật toán: Dùng cin.ignore() để xóa bộ nhớ đệm. Dùng getline() để nhập chuỗi có khoảng trắng 
//             (mã, tên). Dùng cin để nhập các số nguyên (ngày, tháng, năm, lương).
void cNhanVienVP::Nhap() {
    cin.ignore();
    cout << "Nhap ma nhan vien: "; getline(cin, maNV);
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap ngay thang nam sinh (cach nhau khoang trang): ";
    cin >> ngay >> thang >> nam;
    cout << "Nhap luong: ";
    cin >> luong;
}

// Input: Không có (sử dụng dữ liệu của đối tượng hiện tại).
// Output: Thông tin của nhân viên được in ra màn hình.
// Thuật toán: Sử dụng setw() để định dạng độ rộng cột và left để căn trái, 
//             giúp thông tin in ra thành từng cột thẳng hàng, dễ nhìn.
void cNhanVienVP::Xuat() const {
    cout << left << setw(10) << maNV 
         << setw(20) << hoTen 
         << setw(2) << ngay << "/" << setw(2) << thang << "/" << setw(6) << nam 
         << " | Luong: " << setw(12) << luong << endl;
}

// Input: Không có
// Output: Trả về mức lương của nhân viên (kiểu long long)
// Thuật toán: Trả về giá trị của thuộc tính luong.
long long cNhanVienVP::getLuong() const { return luong; }

// Input: Không có
// Output: Trả về năm sinh của nhân viên (kiểu int)
// Thuật toán: Trả về giá trị của thuộc tính nam.
int cNhanVienVP::getNamSinh() const { return nam; }

// Input: Không có
// Output: Trả về họ và tên của nhân viên (kiểu string)
// Thuật toán: Trả về giá trị của thuộc tính hoTen.
std::string cNhanVienVP::getHoTen() const { return hoTen; }