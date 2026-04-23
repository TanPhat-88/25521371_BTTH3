#include <iostream>
#include <cmath>
#include "Diem.h"
using namespace std;

// Khởi tạo mặc định: Gán điểm tại gốc tọa độ (0,0)
Diem::Diem() {
    x = 0;
    y = 0;
}

// Khởi tạo có tham số: Gán tọa độ theo giá trị (a,b) truyền vào
Diem::Diem(double a, double b): x(a), y(b) {}

// Nhập dữ liệu: Yêu cầu người dùng nhập hoành độ x và tung độ y
void Diem::NhapDiem() {
    cout << "Nhap toa do x: ";
    cin >> x;
    cout << "Nhap toa do y: ";
    cin >> y;
}

// Xuất dữ liệu: In ra màn hình tọa độ theo định dạng (x ; y)
void Diem::XuatDiem() {
    cout << "(" << x << " ; " << y << ")";
}

// Tính khoảng cách: Trả về khoảng cách Euclidean giữa điểm hiện tại và điểm "other"
double Diem::KhoangCach(Diem other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}