#include <iostream>
#include "cArray.h"

using namespace std;

int main() {

    cArray myArr(1);
    cout << "\n--- NHAP DU LIEU ---" << endl;
    myArr.NhapMang();
    cout << "\nMang ban dau: ";
    myArr.XuatMang();
    if (myArr.kiemTraTangDan()) {
        cout << "\nMang dang o trang thai tang dan." << endl;
    } else {
        cout << "\nMang khong phai la mang tang dan." << endl;
    }
    int maxP = myArr.timSoNguyenToLonNhat();
    if (maxP != -1) {
        cout << "So nguyen to lon nhat trong mang la: " << maxP << endl;
    } else {
        cout << "Khong co so nguyen to nao trong mang." << endl;
    }
    int minOdd = myArr.timLeNhoNhat();
    if (minOdd != 0) {
        cout << "So le nho nhat trong mang la: " << minOdd << endl;
    }
    cout << "\n--- SAP XEP TANG DAN ---" << endl;
    myArr.sapXepTangDan();
    cout << "Mang sau khi sap xep: ";
    myArr.XuatMang();
    int x;
    cout << "\nNhap gia tri x can dem: ";
    cin >> x;
    cout << "So " << x << " xuat hien " << myArr.demSoLanXuatHien(x) << " lan." << endl;
    return 0;
}