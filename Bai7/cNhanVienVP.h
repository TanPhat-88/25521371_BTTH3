#ifndef CNHANVIENVP_H
#define CNHANVIENVP_H

#include <iostream>
#include <string>

class cNhanVienVP {
private:
    std::string maNV;
    std::string hoTen;
    int ngay, thang, nam;
    long long luong;

public:
    cNhanVienVP();
    
    // Getter & Setter
    long long getLuong() const;
    int getNamSinh() const;
    std::string getHoTen() const;

    // Các phương thức nhập xuất
    void Nhap();
    void Xuat() const;
};


#endif