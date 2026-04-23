#include <iostream>
#include <cmath>
#include "TamGiac.h"
using namespace std;
const double PI = 3.14159265358979323846;

// Input: Nhập tọa độ 3 điểm A, B, C từ bàn phím.
// Output: Gán dữ liệu cho 3 thực thể cDiem.
// Giải thuật: Dùng vòng lặp do-while để kiểm tra điều kiện trùng điểm và bất đẳng thức tam giác (tránh 3 điểm thẳng hàng).
void cTamGiac::NhapTamGiac()
{
    bool hople = false;
    do {
        cout << "Nhap diem A: \n"; A.NhapDiem();
        cout << "Nhap diem B: \n"; B.NhapDiem();
        cout << "Nhap diem C: \n"; C.NhapDiem();
        if (A == B || A == C || B == C) 
        {
            cout << "Phat hien diem trung nhau! Vui long nhap lai!\n";
            continue;
        }

        float AB = A.KhoangCach(B);
        float AC = A.KhoangCach(C);
        float BC = B.KhoangCach(C);

        if (AB + AC <= BC || AB + BC <= AC || AC + BC <= AB)
        {
            cout << "Ba diem thang hang, khong the tao thanh tam giac! Vui long nhap lai!";
            continue;
        }
        else
            hople = true;
    } while(!hople);
}

// Input: Không có.
// Output: Xuất tọa độ 3 đỉnh của tam giác ra màn hình.
// Giải thuật: Gọi phương thức XuatDiem() của từng thực thể cDiem.
void cTamGiac::XuatTamGiac()
{
    cout << "Tam giac ABC co ba diem: \n";
    cout << "A"; A.XuatDiem(); cout << ", ";
    cout << "B"; B.XuatDiem(); cout << ", ";
    cout << "C"; C.XuatDiem(); cout << ".\n";
}

// Input: Không có.
// Output: In ra màn hình tên loại tam giác (Đều, Vuông, Cân, Thường).
// Giải thuật: Tính 3 cạnh, dùng hằng số EPS (sai số) để so sánh các cạnh và kiểm tra định lý Pytago.
void cTamGiac::KiemTraLoaiTamGiac() {
    float a = A.KhoangCach(B);
    float b = B.KhoangCach(C);
    float c = C.KhoangCach(A);
    const float EPS = 1e-5;
    if (abs(a - b) < EPS && abs(b - c) < EPS) {
        cout << "Tam giac deu!\n";
    }
    else {
        bool can = (abs(a - b) < EPS || abs(b - c) < EPS || abs(a - c) < EPS);
        bool vuong = (abs(a*a + b*b - c*c) < EPS || 
                      abs(a*a + c*c - b*b) < EPS || 
                      abs(b*b + c*c - a*a) < EPS);

        if (can && vuong) cout << "Tam giac vuong can!\n";
        else if (can) cout << "Tam giac can!\n";
        else if (vuong) cout << "Tam giac vuong!\n";
        else cout << "Tam giac thuong!\n";
    }
}

// Input: Không có.
// Output: Trả về giá trị chu vi (float).
// Giải thuật: Tổng khoảng cách của 3 cặp điểm (AB + BC + CA).
float cTamGiac::TinhChuVi()
{
    return A.KhoangCach(B)+B.KhoangCach(C)+C.KhoangCach(A);
}

// Input: Không có.
// Output: Trả về giá trị diện tích (float).
// Giải thuật: Sử dụng công thức Heron với nửa chu vi p.
float cTamGiac::TinhDienTich()
{
    float a = A.KhoangCach(B);
    float b = B.KhoangCach(C);
    float c = C.KhoangCach(A);
    float p = (a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

// Input: Độ dời dx, dy.
// Output: Tọa độ 3 đỉnh mới.
// Giải thuật: Gọi hàm TinhTienDiem cho cả 3 đỉnh A, B, C.
void cTamGiac::TinhTien(float dx, float dy)
{
    A.TinhTienDiem(dx,dy);
    B.TinhTienDiem(dx,dy);
    C.TinhTienDiem(dx,dy);
}

// Input: Góc quay alpha (độ).
// Output: Tọa độ 3 đỉnh mới sau khi quay quanh gốc tọa độ.
// Giải thuật: Đổi alpha sang Radian, sau đó gọi hàm QuayDiem cho 3 đỉnh.
void cTamGiac::Quay(float alpha)
{
    alpha = (alpha*PI)/180;
    A.QuayDiem(alpha);
    B.QuayDiem(alpha);
    C.QuayDiem(alpha);
}

// Input: Hệ số tỉ lệ k.
// Output: Tọa độ 3 đỉnh mới sau khi thu phóng.
// Giải thuật: Xác định trọng tâm G (gx, gy) của tam giác, sau đó gọi ThuPhongDiem cho 3 đỉnh quanh tâm G.
void cTamGiac::ThuPhong(float k)
{
    float gx = (A.GetX()+B.GetX()+C.GetX())/3.0;
    float gy = (A.GetY()+B.GetY()+C.GetY())/3.0;
    A.ThuPhongDiem(gx,gy,k);
    B.ThuPhongDiem(gx,gy,k);
    C.ThuPhongDiem(gx,gy,k);
}