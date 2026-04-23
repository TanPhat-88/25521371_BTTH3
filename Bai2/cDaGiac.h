#ifndef CDAGIAC_H
#define CDAGIAC_H

#include "Diem.h"

class cDaGiac {
private:
    int soDinh;       // so luong dinh cua da giac (n >= 3)
    Diem* arrDinh;    // mang dong chua toa do cac dinh
public:
    // khoi tao
    cDaGiac();
    cDaGiac(int n);

    // quan ly bo nho (rule of 3 do dung con tro)
    cDaGiac(const cDaGiac& other); // copy constructor
    ~cDaGiac(); // destructor
    cDaGiac& operator=(const cDaGiac& other); // toan tu gan

    // cac phuong thuc co ban
    void Nhap();
    void Xuat() const;

    // cac phuong thuc tinh toan
    double TinhChuVi() const;
    double TinhDienTich() const;

    // cac phuong thuc bien doi
    void TinhTien(double dx, double dy);
    void TinhTien(Diem v);
    void Quay(double GocQuay);
    void PhongToThuNho(double k);
};

#endif