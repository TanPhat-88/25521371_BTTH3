#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
#include <string>

class cCandidate {
private:
    std::string ma, ten, ngaySinh;
    float toan, van, anh;
public:
    void Nhap();
    void Xuat() const;
    float TongDiem() const;
    std::string GetTen() const { return ten; }
};


#endif