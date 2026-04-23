#include "NhanVienSX.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Input: Không có
// Output: Khởi tạo danh sách quản lý nhân viên rỗng
// Thuật toán: Gán số lượng n = 0 và con trỏ mảng ds = nullptr
cListNhanVienSX::cListNhanVienSX() : n(0), ds(nullptr) {}

// Input: Không có
// Output: Giải phóng vùng nhớ của danh sách
// Thuật toán: Gọi delete[] cho con trỏ ds để tránh rò rỉ bộ nhớ
cListNhanVienSX::~cListNhanVienSX() {
    delete[] ds;
}

// Input: Số lượng n và thông tin n nhân viên từ bàn phím
// Output: Mảng ds chứa đầy đủ thông tin nhân viên
// Thuật toán: Nhập n, cấp phát mảng động ds = new cNhanVienSX[n]. Lặp n lần, gọi hàm Nhap() của từng phần tử.
void cListNhanVienSX::NhapDS() {
    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> n;
    ds = new cNhanVienSX[n];
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin NVSX thu " << i + 1 << " ---" << endl;
        ds[i].Nhap();
    }
}

// Input: Danh sách hiện tại
// Output: Hiển thị n nhân viên ra màn hình
// Thuật toán: Lặp n lần, gọi hàm Xuat() của từng phần tử trong mảng ds.
void cListNhanVienSX::XuatDS() const {
    if (n == 0) {
        cout << "Danh sach trong!" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}

// Input: Danh sách hiện tại
// Output: In ra màn hình nhân viên có mức lương thấp nhất
// Thuật toán: Khởi tạo minIdx = 0. Duyệt mảng từ 1 đến n-1, nếu getLuong() tại i nhỏ hơn getLuong() tại minIdx thì cập nhật minIdx = i. Gọi Xuat() tại minIdx.
void cListNhanVienSX::TimLuongThapNhat() const {
    if (n == 0) return;
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].getLuong() < ds[minIdx].getLuong()) {
            minIdx = i;
        }
    }
    cout << "\n[Nhan vien co luong thap nhat]:" << endl;
    ds[minIdx].Xuat();
}

// Input: Danh sách hiện tại
// Output: Trả về tổng lương công ty phải trả (long long)
// Thuật toán: Khởi tạo tong = 0. Duyệt qua mảng, cộng dồn getLuong() của từng phần tử vào biến tong.
long long cListNhanVienSX::TinhTongLuong() const {
    long long tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].getLuong();
    }
    return tong;
}

// Input: Danh sách hiện tại
// Output: In ra nhân viên có tuổi cao nhất
// Thuật toán: Tuổi cao nhất tức là ngày tháng năm sinh nhỏ nhất. 
//             Chuyển ngày sinh về số đại diện (Năm*10000 + Tháng*100 + Ngày). 
//             Tìm phần tử có số đại diện nhỏ nhất.
void cListNhanVienSX::TimTuoiCaoNhat() const {
    if (n == 0) return;
    int maxAgeIdx = 0;
    // Tính score cho ngày sinh của nhân viên đầu tiên
    long long minDateScore = (long long)ds[0].getNam() * 10000 + ds[0].getThang() * 100 + ds[0].getNgay();

    for (int i = 1; i < n; i++) {
        long long currentDateScore = (long long)ds[i].getNam() * 10000 + ds[i].getThang() * 100 + ds[i].getNgay();
        if (currentDateScore < minDateScore) {
            minDateScore = currentDateScore;
            maxAgeIdx = i;
        }
    }
    cout << "\n[Nhan vien co tuoi cao nhat]:" << endl;
    ds[maxAgeIdx].Xuat();
}

// Input: Danh sách hiện tại
// Output: Mảng ds được sắp xếp tăng dần theo lương
// Thuật toán: Dùng thuật toán Interchange Sort. Duyệt mảng bằng 2 vòng lặp lồng nhau, 
//             nếu getLuong() phần tử trước lớn hơn phần tử sau thì hoán đổi (swap).
void cListNhanVienSX::SapXepLuongTangDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getLuong() > ds[j].getLuong()) {
                swap(ds[i], ds[j]);
            }
        }
    }
}