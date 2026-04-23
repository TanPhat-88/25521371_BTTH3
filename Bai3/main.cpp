#include <iostream>
#include "cDSPhanSo.h"

using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan so trong danh sach: ";
    cin >> n;
    cDSPhanSo ds(n);

    cout << "\n--- NHAP DANH SACH PHAN SO ---\n";
    ds.NhapDSPhanSo();

    cout << "\nDanh sach vua nhap: ";
    ds.XuatDSPhanSo();

    cout << "\nPhan so lon nhat: ";
    ds.PSLonNhat().XuatPhanSo();
    
    cout << "\nPhan so nho nhat: ";
    ds.PSNhoNhat().XuatPhanSo();

    cout << "\nPhan so co tu nguyen to lon nhat: ";
    ds.PSTuNguyenToLonNhat().XuatPhanSo();

    cout << "\n\n--- DANH SACH SAU KHI SAP XEP TANG ---";
    ds.SapXepTang();
    ds.XuatDSPhanSo();

    cout << "\n--- DANH SACH SAU KHI SAP XEP GIAM ---";
    ds.SapXepGiam();
    ds.XuatDSPhanSo();

    cout << endl;
    return 0;
}