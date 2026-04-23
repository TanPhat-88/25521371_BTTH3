#ifndef PHANSO_H
#define PHANSO_H

class cPhanSo {
private:
    int tu, mau;
public:
    cPhanSo();
    cPhanSo(int,int);
    void RutGon();
    void NhapPhanSo();
    void XuatPhanSo();
    cPhanSo operator+(const cPhanSo &other);
    bool operator>(const cPhanSo &other);
    bool operator<(const cPhanSo &other);
    bool KiemTraTuNguyenTo();
};

#endif