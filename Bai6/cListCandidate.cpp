#include <iostream>
#include <algorithm> 
#include "cListCandidate.h"

using namespace std;

// Input: Không có.
// Output: Khởi tạo đối tượng cListCandidate rỗng.
// Thuật toán: Gán số lượng thí sinh n = 0 và con trỏ ds (danh sách) = nullptr.
cListCandidate::cListCandidate() : n(0), ds(nullptr) {}

// Input: Không có.
// Output: Giải phóng vùng nhớ đã cấp phát cho mảng thí sinh.
// Thuật toán: Dùng toán tử delete[] để thu hồi bộ nhớ con trỏ ds.
cListCandidate::~cListCandidate() {
    delete[] ds;
}

// Input: Số lượng n và thông tin chi tiết của n thí sinh từ bàn phím.
// Output: Mảng ds chứa toàn bộ dữ liệu thí sinh vừa nhập.
// Thuật toán: Nhập số lượng n. Cấp phát động mảng ds với kích thước n. 
//             Dùng vòng lặp for từ 0 đến n-1, gọi hàm Nhap() của từng đối tượng cCandidate.
void cListCandidate::NhapDS() {
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    ds = new cCandidate[n];
    for(int i = 0; i < n; i++) {
        cout << "\nNhap thi sinh thu " << i + 1 << ":" << endl;
        ds[i].Nhap();
    }
}

// Input: Danh sách thí sinh hiện tại.
// Output: In ra màn hình các thí sinh có tổng điểm lớn hơn 15.
// Thuật toán: Duyệt mảng ds bằng vòng lặp for. Kiểm tra nếu ds[i].TongDiem() > 15 
//             thì gọi hàm Xuat() của thí sinh đó.
void cListCandidate::XuatTren15() {
    cout << "\nThi sinh co tong diem > 15: " << endl;
    for(int i = 0; i < n; i++) {
        if(ds[i].TongDiem() > 15) {
            ds[i].Xuat();
        }
    }
}

// Input: Danh sách thí sinh hiện tại.
// Output: In ra thông tin thí sinh đạt tổng điểm cao nhất.
// Thuật toán: Nếu n == 0 thì thoát hàm. Gán vị trí lớn nhất ban đầu indexMax = 0. 
//             Duyệt từ thí sinh thứ 1 đến n-1. Nếu phát hiện thí sinh có TongDiem() 
//             lớn hơn điểm của thí sinh tại indexMax thì cập nhật lại indexMax = i. 
//             Cuối cùng in ra thông tin tại ds[indexMax].
void cListCandidate::ThiSinhDiemCaoNhat() {
    if(n == 0) return;
    int indexMax = 0;
    for(int i = 1; i < n; i++) {
        if(ds[i].TongDiem() > ds[indexMax].TongDiem()) {
            indexMax = i;
        }
    }
    cout << "\nThi sinh co diem cao nhat: " << endl;
    ds[indexMax].Xuat();
}

// Input: Danh sách thí sinh hiện tại.
// Output: Mảng ds được sắp xếp giảm dần theo tổng điểm và in ra màn hình.
// Thuật toán: Dùng thuật toán Interchange Sort. Sử dụng hai vòng lặp lồng nhau 
//             (i từ 0 đến n-1, j từ i+1 đến n). Nếu tổng điểm của người đứng trước (i) 
//             nhỏ hơn người đứng sau (j) thì hoán đổi (swap) hai đối tượng này. 
//             Sau đó duyệt mảng in ra kết quả.
void cListCandidate::SapXepGiam() {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(ds[i].TongDiem() < ds[j].TongDiem()) {
                swap(ds[i], ds[j]);
            }
        }
    }
    cout << "\n--- DANH SACH SAU KHI SAP XEP GIAM ---" << endl;
    for(int i = 0; i < n; i++) ds[i].Xuat();
}