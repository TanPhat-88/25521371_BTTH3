#ifndef DSPHANSO_H
#define DSPHANSO_H

#include "cPhanSo.h"

class cDSPhanSo{
private:
    int size;
    cPhanSo* list;
public:
    cDSPhanSo(int);
    void NhapDSPhanSo();
    void XuatDSPhanSo();
    cPhanSo Tong();
    cPhanSo PSLonNhat();
    cPhanSo PSNhoNhat();
    cPhanSo PSTuNguyenToLonNhat();

    void SapXepTang();
    void SapXepGiam();
};

#endif