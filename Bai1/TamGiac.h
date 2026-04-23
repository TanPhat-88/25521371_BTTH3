#ifndef TAMGIAC_H
#define TAMGIAC_H

#include "Diem.h"

class cTamGiac {
private:
    cDiem A,B,C;
public:
    void NhapTamGiac();
    void XuatTamGiac();
    void KiemTraLoaiTamGiac();
    float TinhChuVi();
    float TinhDienTich();
    void TinhTien(float dx,float dy);
    void Quay(float alpha);
    void ThuPhong(float k);
};

#endif