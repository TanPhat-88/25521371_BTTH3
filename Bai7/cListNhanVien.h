#ifndef LISTNHANVIEN_H
#define LISTNHANVIEN_H

#include "cNhanVienVP.h"

class cListNhanVien {
private:
    cNhanVienVP* ds;
    int n;

public:
    cListNhanVien();
    ~cListNhanVien();

    void NhapDS();
    void XuatDS() const;
    void TimLuongCaoNhat() const;
    long long TinhTongLuong() const;
    void TimTuoiCaoNhat() const;
    void SapXepLuongTangDan();
};

#endif