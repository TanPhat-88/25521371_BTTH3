#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>
#include <vector>
#include <cmath>

class cDaThuc {
private:
    int bac;
    double* heSo; 

public:
    cDaThuc();
    cDaThuc(int n);
    ~cDaThuc();

    void Nhap();
    void Xuat();
    double TinhGiaTri(double x);

    cDaThuc operator+(const cDaThuc& other);
    cDaThuc operator-(const cDaThuc& other);
    cDaThuc& operator=(const cDaThuc& other); // Phép gán
};

#endif