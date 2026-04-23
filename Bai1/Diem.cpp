#include <iostream>
#include <cmath>
#include "Diem.h"
using namespace std;

// Input: Nhập từ bàn phím hoành độ x, tung độ y
// Output: Gán giá trị cho thuộc tính x, y của đối tượng
// Giải thuật: Sử dụng luồng nhập chuẩn cin
void cDiem::NhapDiem()
{
    cout << "Nhap hoanh do x: "; cin >> x;
    cout << "Nhap tung do y: "; cin >> y;
}

// Input: Đối tượng cDiem khác (other)
// Output: True nếu trùng tọa độ, False nếu khác
// Giải thuật: So sánh đồng thời cả x và y
bool cDiem::operator==(const cDiem &other){
    return x == other.x && y == other.y;
}

// Input: Đối tượng cDiem đích (other)
// Output: Giá trị float là khoảng cách giữa 2 điểm
// Giải thuật: Công thức Euclid: căn bậc hai tổng bình phương hiệu tọa độ
float cDiem::KhoangCach(const cDiem &other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

// Input: Không có
// Output: In tọa độ ra màn hình theo định dạng (x,y)
// Giải thuật: Sử dụng luồng xuất chuẩn cout
void cDiem::XuatDiem()
{
    cout << "(" << x << "," << y << ")\n";
}

// Input: Độ dời dx (ngang) và dy (dọc)
// Output: Tọa độ x, y mới sau khi tịnh tiến
// Giải thuật: Cộng trực tiếp độ dời vào tọa độ hiện tại
void cDiem::TinhTienDiem(float dx, float dy)
{
    x += dx;
    y += dy;
}

// Input: Góc quay alpha (đơn vị Radian)
// Output: Tọa độ x, y mới sau khi quay quanh gốc (0,0)
// Giải thuật: Ma trận quay: x' = x*cos - y*sin; y' = x*sin + y*cos (Dùng biến tạm tránh sai số)
void cDiem::QuayDiem(float alpha)
{
    float x_old = x;
    x = x_old * cos(alpha) - y * sin(alpha);
    y = x_old * sin(alpha) + y * cos(alpha);
}

// Getters: Truy xuất dữ liệu thành phần private
float cDiem::GetX() { return x; }
float cDiem::GetY() { return y; }

// Input: Tâm vị tự (gx, gy) và hệ số tỉ lệ k
// Output: Tọa độ x, y mới sau khi thu phóng
// Giải thuật: Biến đổi vector: P' = G + k*(P - G)
void cDiem::ThuPhongDiem(float gx, float gy, float k)
{
    x = gx + (x - gx) * k;
    y = gy + (y - gy) * k;
}