#ifndef ARRAY_H
#define ARRAY_H

class cArray {
private:
    int *arr;
    int size;
public:
    // Constructor: Khởi tạo mảng với kích thước n (mặc định = 0)
    cArray(int);

    // Destructor: Giải phóng bộ nhớ động khi đối tượng bị hủy
    ~cArray();

    void NhapMang();
    void XuatMang();
    void taoNgauNhien(int n);
    int demSoLanXuatHien(int x);
    bool kiemTraTangDan();
    int timLeNhoNhat();
    int timSoNguyenToLonNhat();
    void sapXepTangDan();
    void sapXepGiamDan();
};

#endif