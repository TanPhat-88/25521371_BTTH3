#include <iostream>
#include <algorithm>
#include "cListNhanVien.h"

using namespace std;

// Input: Không có
// Output: Khởi tạo đối tượng cListNhanVien rỗng
// Thuật toán: Gán con trỏ mảng ds = nullptr và số lượng n = 0.
cListNhanVien::cListNhanVien() : ds(nullptr), n(0) {}

// Input: Không có
// Output: Giải phóng vùng nhớ đã cấp phát cho mảng danh sách nhân viên
// Thuật toán: Dùng toán tử delete[] để thu hồi bộ nhớ con trỏ ds.
cListNhanVien::~cListNhanVien() {
    delete[] ds;
}

// Input: Số lượng n và thông tin chi tiết của n nhân viên từ bàn phím.
// Output: Mảng ds chứa toàn bộ dữ liệu nhân viên vừa nhập.
// Thuật toán: Nhập số lượng n. Cấp phát động mảng ds với kích thước n. 
//             Dùng vòng lặp for duyệt từ 0 đến n-1, gọi hàm Nhap() của từng đối tượng.
void cListNhanVien::NhapDS() {
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    ds = new cNhanVienVP[n];
    for (int i = 0; i < n; i++) {
        cout << "\nNhap nhan vien thu " << i + 1 << ":" << endl;
        ds[i].Nhap();
    }
}

// Input: Mảng ds hiện tại
// Output: In toàn bộ danh sách nhân viên ra màn hình
// Thuật toán: Dùng vòng lặp for duyệt qua mảng ds và gọi hàm Xuat() của từng phần tử.
void cListNhanVien::XuatDS() const {
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}

// Input: Mảng ds hiện tại
// Output: In ra màn hình thông tin nhân viên có lương cao nhất.
// Thuật toán: Nếu n == 0 thì thoát. Khởi tạo vị trí lớn nhất idx = 0.
//             Duyệt vòng lặp từ 1 đến n-1. So sánh getLuong() của phần tử hiện tại 
//             với getLuong() của phần tử tại idx. Nếu lớn hơn thì cập nhật lại idx. 
//             Cuối cùng gọi hàm Xuat() tại vị trí idx.
void cListNhanVien::TimLuongCaoNhat() const {
    if (n == 0) return;
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i].getLuong() > ds[idx].getLuong()) idx = i;
    }
    cout << "\nNhan vien luong cao nhat:\n";
    ds[idx].Xuat();
}

// Input: Mảng ds hiện tại
// Output: Tổng quỹ lương của tất cả nhân viên (kiểu long long)
// Thuật toán: Khởi tạo biến tong = 0. Duyệt vòng lặp qua tất cả phần tử trong mảng, 
//             cộng dồn giá trị getLuong() vào biến tong, sau đó trả về tong.
long long cListNhanVien::TinhTongLuong() const {
    long long tong = 0;
    for (int i = 0; i < n; i++) tong += ds[i].getLuong();
    return tong;
}

// Input: Mảng ds hiện tại
// Output: In ra màn hình thông tin nhân viên có tuổi cao nhất.
// Thuật toán: Tuổi cao nhất tương đương với năm sinh nhỏ nhất. 
//             Khởi tạo idx = 0. Duyệt mảng, nếu getNamSinh() của phần tử hiện tại 
//             nhỏ hơn getNamSinh() của phần tử tại idx thì cập nhật idx. 
//             Gọi hàm Xuat() in ra kết quả.
void cListNhanVien::TimTuoiCaoNhat() const {
    if (n == 0) return;
    int idx = 0;
    for (int i = 1; i < n; i++) {
        // Nam sinh cang nho thi tuoi cang cao
        if (ds[i].getNamSinh() < ds[idx].getNamSinh()) idx = i;
    }
    cout << "\nNhan vien co tuoi cao nhat:\n";
    ds[idx].Xuat();
}

// Input: Mảng ds hiện tại
// Output: Mảng ds được sắp xếp tăng dần theo mức lương.
// Thuật toán: Sử dụng thuật toán Interchange Sort. Dùng hai vòng lặp lồng nhau 
//             (i chạy từ 0 đến n-2, j chạy từ i+1 đến n-1). Nếu lương của người đứng trước (i) 
//             lớn hơn lương của người đứng sau (j) thì hoán đổi vị trí của hai đối tượng.
void cListNhanVien::SapXepLuongTangDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getLuong() > ds[j].getLuong()) {
                swap(ds[i], ds[j]);
            }
        }
    }
}