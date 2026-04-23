#include "NhanVienSX.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Input: Không có
// Output: Khởi tạo đối tượng cNhanVienSX với các giá trị mặc định
// Thuật toán: Gán chuỗi rỗng cho mã và tên, ngày mặc định là 1/1/2000, số SP và đơn giá = 0.
cNhanVienSX::cNhanVienSX() : maNV(""), hoTen(""), ngay(1), thang(1), nam(2000), soSanPham(0), donGia(0) {}

// Input: Không có
// Output: Trả về mã nhân viên
// Thuật toán: return biến maNV
string cNhanVienSX::getMaNV() const { return maNV; }

// Input: Chuỗi mã nhân viên mới
// Output: Cập nhật lại mã nhân viên
// Thuật toán: Gán maNV = ma
void cNhanVienSX::setMaNV(const string& ma) { maNV = ma; }

// Input: Không có
// Output: Trả về ngày sinh (int)
// Thuật toán: return biến ngay
int cNhanVienSX::getNgay() const { return ngay; }

// Input: Không có
// Output: Trả về tháng sinh (int)
// Thuật toán: return biến thang
int cNhanVienSX::getThang() const { return thang; }

// Input: Không có
// Output: Trả về năm sinh (int)
// Thuật toán: return biến nam
int cNhanVienSX::getNam() const { return nam; }

// Input: Không có
// Output: Tiền lương của nhân viên (số sản phẩm * đơn giá)
// Thuật toán: Trả về kết quả của phép nhân soSanPham * donGia.
long long cNhanVienSX::getLuong() const { 
    return (long long)soSanPham * donGia; 
}

// Input: Thông tin nhân viên từ bàn phím (mã, tên, ngày sinh, số sp, đơn giá)
// Output: Đối tượng được cập nhật thông tin
// Thuật toán: Dùng cin.ignore() để xóa bộ đệm. Dùng getline để nhập chuỗi có khoảng trắng, cin để nhập số.
void cNhanVienSX::Nhap() {
    cin.ignore();
    cout << "Nhap ma nhan vien: "; getline(cin, maNV);
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap ngay thang nam sinh (cach nhau khoang trang): ";
    cin >> ngay >> thang >> nam;
    cout << "Nhap so san pham da gia cong: "; cin >> soSanPham;
    cout << "Nhap don gia 1 san pham: "; cin >> donGia;
}

// Input: Đối tượng hiện tại
// Output: Hiển thị thông tin nhân viên ra màn hình
// Thuật toán: Sử dụng setw() và left/right trong <iomanip> để căn lề hiển thị dạng bảng.
void cNhanVienSX::Xuat() const {
    cout << left << setw(10) << maNV 
         << setw(20) << hoTen 
         << right << setw(2) << setfill('0') << ngay << "/" 
         << setw(2) << thang << "/" 
         << left << setw(6) << setfill(' ') << nam 
         << "| SP: " << setw(5) << soSanPham 
         << "| Gia: " << setw(8) << donGia 
         << "| Luong: " << getLuong() << endl;
}