#include <iostream>
#include <cmath>
#include <iomanip>
#include "TamGiac.h"
using namespace std;

int main()
{
    cTamGiac ABC;
    cout << "Nhap cac diem cho tam giac ABC: \n"; ABC.NhapTamGiac();
    cout << "Xuat cac diem cua tam giac ABC: \n"; ABC.XuatTamGiac();
    cout << "Tam giac ABC vua nhap la: "; ABC.KiemTraLoaiTamGiac();
    cout << "Chu vi tam giac ABC: " << fixed << setprecision(2) << ABC.TinhChuVi() << "\n";
    cout << "Dien tich tam giac ABC: " << fixed << setprecision(2) << ABC.TinhDienTich() << "\n";
    ABC.TinhTien(1,1);
    ABC.Quay(90); // Quay 90 do
    ABC.ThuPhong(2);
}