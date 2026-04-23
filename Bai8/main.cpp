#include <iostream>
#include "NhanVienSX.h"

using namespace std;

int main() {
    cListNhanVienSX congTy;

    cout << "===== CHUONG TRINH QUAN LY NHAN VIEN SAN XUAT =====\n\n";

    // 1. Nhập danh sách
    congTy.NhapDS();

    // 2. Xuất danh sách
    cout << "\n===== DANH SACH NHAN VIEN SAN XUAT =====" << endl;
    congTy.XuatDS();

    // 3. Cho biết nhân viên có lương thấp nhất
    congTy.TimLuongThapNhat();

    // 4. Tổng quỹ lương
    cout << "\n[Tong luong cong ty phai tra]: " << congTy.TinhTongLuong() << " VND" << endl;

    // 5. Nhân viên có tuổi cao nhất
    congTy.TimTuoiCaoNhat();

    // 6. Sắp xếp lương tăng dần
    congTy.SapXepLuongTangDan();
    cout << "\n===== DANH SACH SAU KHI SAP XEP LUONG TANG DAN =====" << endl;
    congTy.XuatDS();

    cout << "\n===== HOAN THANH =====" << endl;
    
    return 0;
}