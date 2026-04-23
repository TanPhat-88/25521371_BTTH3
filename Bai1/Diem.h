#ifndef DIEM_H
#define DIEM_H

class cDiem {
private:
    float x, y;
public:
    void NhapDiem();
    void XuatDiem();

    float GetX();
    float GetY();

    bool operator==(const cDiem &other);
    float KhoangCach(const cDiem &other);
    void TinhTienDiem(float dx,float dy);
    void QuayDiem(float alpha);
    void ThuPhongDiem(float gx, float gy, float k);
};

#endif