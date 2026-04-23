#ifndef NHANVIENSX_H
#define NHANVIENSX_H

#include <string>

// Lớp đại diện cho một Nhân viên sản xuất
class cNhanVienSX {
private:
    std::string maNV;
    std::string hoTen;
    int ngay, thang, nam;
    int soSanPham;
    long long donGia;

public:
    // Constructor
    cNhanVienSX();

    // Getters & Setters
    std::string getMaNV() const;
    void setMaNV(const std::string& ma);
    int getNgay() const;
    int getThang() const;
    int getNam() const;
    long long getLuong() const; // Thay thế TinhLuong để gọi cho ngắn gọn

    // Các phương thức xử lý
    void Nhap();
    void Xuat() const;
};

// Lớp đại diện cho Danh sách nhân viên sản xuất
class cListNhanVienSX {
private:
    int n;
    cNhanVienSX* ds;

public:
    // Constructor & Destructor
    cListNhanVienSX();
    ~cListNhanVienSX();

    // Các phương thức xử lý danh sách
    void NhapDS();
    void XuatDS() const;
    void TimLuongThapNhat() const;
    long long TinhTongLuong() const;
    void TimTuoiCaoNhat() const;
    void SapXepLuongTangDan();
};

#endif