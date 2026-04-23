#include "cDaThuc.h"
#include <iostream>

using namespace std;

int main() {
    cDaThuc dt1, dt2;

    cout << "--- Nhap da thuc 1 ---" << endl;
    dt1.Nhap();
    cout << "Da thuc 1: ";
    dt1.Xuat();

    cout << "\n--- Nhap da thuc 2 ---" << endl;
    dt2.Nhap();
    cout << "Da thuc 2: ";
    dt2.Xuat();

    // Tinh gia tri
    double x;
    cout << "\nNhap gia tri x de tinh P(x): ";
    cin >> x;
    cout << "P1(" << x << ") = " << dt1.TinhGiaTri(x) << endl;

    // Cong/Tru
    cDaThuc tong = dt1 + dt2;
    cout << "\nTong hai da thuc: ";
    tong.Xuat();

    cDaThuc hieu = dt1 - dt2;
    cout << "Hieu hai da thuc: ";
    hieu.Xuat();

    return 0;
}