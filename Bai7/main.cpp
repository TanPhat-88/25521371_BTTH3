#include <iostream>
#include "cListNhanVien.h" 

using namespace std;

int main() {
    cListNhanVien congTy;

    // Nhập danh sách
    congTy.NhapDS();

    // Xuất danh sách
    cout << "\nDanh sach nhan vien vua nhap:\n";
    congTy.XuatDS();

    // Tính tổng lương
    cout << "\nTong luong can chi tra: " << congTy.TinhTongLuong() << " VND\n";

    // Tìm nhân viên lương cao nhất (Hàm này đã có sẵn cout bên trong)
    congTy.TimLuongCaoNhat();

    // Tìm nhân viên lớn tuổi nhất (Hàm này đã có sẵn cout bên trong)
    congTy.TimTuoiCaoNhat();

    // Sắp xếp và xuất lại danh sách
    congTy.SapXepLuongTangDan();
    cout << "\nDanh sach sau khi sap xep luong tang dan:\n";
    congTy.XuatDS();

    return 0; 
}