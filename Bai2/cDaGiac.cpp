#include "cDaGiac.h"
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

/* * Input: Không
 * Output: Đối tượng đa giác rỗng
 * Hướng giải quyết: Gán mặc định số đỉnh = 0, con trỏ mảng = nullptr.
 */
cDaGiac::cDaGiac() {
    soDinh = 0;
    arrDinh = nullptr;
}

/* * Input: Số nguyên n (số đỉnh)
 * Output: Đối tượng đa giác n đỉnh
 * Hướng giải quyết: Kiểm tra n >= 3, dùng `new` cấp phát mảng động.
 */
cDaGiac::cDaGiac(int n) {
    if (n >= 3) {
        soDinh = n;
        arrDinh = new Diem[soDinh];
    }
    else {
        soDinh = 0;
        arrDinh = nullptr;
    }
}

/* * Input: Đối tượng cDaGiac (other)
 * Output: Một bản sao độc lập của other
 * Hướng giải quyết: Áp dụng Deep Copy (cấp phát mảng mới và chép từng phần tử) để tránh lỗi chung vùng nhớ.
 */
cDaGiac::cDaGiac(const cDaGiac& other) {
    soDinh = other.soDinh;
    if (soDinh > 0) {
        arrDinh = new Diem[soDinh];
        for (int i = 0; i < soDinh; i++) {
            arrDinh[i] = other.arrDinh[i];
        }
    }
    else {
        arrDinh = nullptr;
    }
}

/* * Input: Không
 * Output: Thu hồi vùng nhớ
 * Hướng giải quyết: Dùng `delete[]` để xóa mảng động.
 */
cDaGiac::~cDaGiac() {
    delete[] arrDinh;
}

/* * Input: Đối tượng cDaGiac (other)
 * Output: Gán dữ liệu sang đối tượng hiện tại
 * Hướng giải quyết: Xóa mảng cũ, cấp phát lại mảng mới và copy sâu (Deep copy).
 */
cDaGiac& cDaGiac::operator=(const cDaGiac& other) {
    if (this != &other) {
        delete[] arrDinh;
        soDinh = other.soDinh;
        if (soDinh > 0) {
            arrDinh = new Diem[soDinh];
            for (int i = 0; i < soDinh; i++) {
                arrDinh[i] = other.arrDinh[i];
            }
        }
        else {
            arrDinh = nullptr;
        }
    }
    return *this;
}

/* * Input: Dữ liệu từ bàn phím (số đỉnh, tọa độ)
 * Output: Đối tượng được cập nhật tọa độ
 * Hướng giải quyết: Vòng lặp lấy số đỉnh >= 3, cấp phát mảng, gọi hàm NhapDiem() cho từng đỉnh.
 */
void cDaGiac::Nhap() {
    do {
        cout << "Nhap so luong dinh cua da giac (n >= 3): ";
        cin >> soDinh;
        if (soDinh < 3) {
            cout << "Da giac phai co it nhat 3 dinh. Vui long nhap lai!\n";
        }
    } while (soDinh < 3);

    delete[] arrDinh;
    arrDinh = new Diem[soDinh];

    cout << "--- NHAP TOA DO CAC DINH CUA DA GIAC ---\n";
    for (int i = 0; i < soDinh; i++) {
        cout << "Dinh thu " << i + 1 << ":\n";
        arrDinh[i].NhapDiem();
    }
}

/* * Input: Không
 * Output: Tọa độ, chu vi, diện tích in ra màn hình
 * Hướng giải quyết: Duyệt mảng gọi XuatDiem(), sau đó gọi hàm tính Chu vi & Diện tích.
 */
void cDaGiac::Xuat() const {
    if (soDinh == 0 || arrDinh == nullptr) {
        cout << "Da giac rong!\n";
        return;
    }

    for (int i = 0; i < soDinh; i++) {
        cout << "Dinh " << i + 1 << ": ";
        arrDinh[i].XuatDiem();
        cout << endl;
    }
    cout << "CHU VI: " << TinhChuVi() << endl;
    cout << "DIEN TICH: " << TinhDienTich() << endl;
}

/* * Input: Không
 * Output: Số thực (Chu vi)
 * Hướng giải quyết: Cộng dồn khoảng cách các đỉnh kề nhau, dùng (i+1)%soDinh để nối đỉnh cuối với đỉnh đầu.
 */
double cDaGiac::TinhChuVi() const {
    if (soDinh < 3) return 0;

    double chuVi = 0;
    for (int i = 0; i < soDinh; i++) {
        int nextDinh = (i + 1) % soDinh;
        chuVi += arrDinh[i].KhoangCach(arrDinh[nextDinh]);
    }
    return chuVi;
}

/* * Input: Không
 * Output: Số thực (Diện tích)
 * Hướng giải quyết: Áp dụng công thức Shoelace (tổng chéo tọa độ).
 */
double cDaGiac::TinhDienTich() const {
    if (soDinh < 3) return 0;
    double area = 0;
    for (int i = 0; i < soDinh; i++) {
        int nextDinh = (i + 1) % soDinh;
        area += (arrDinh[i].x * arrDinh[nextDinh].y) - (arrDinh[nextDinh].x * arrDinh[i].y);
    }
    return abs(area) / 2.0;
}

/* * Input: Hai số thực dx, dy (độ dời)
 * Output: Tọa độ các đỉnh thay đổi
 * Hướng giải quyết: Duyệt mảng, cộng x với dx, y với dy.
 */
void cDaGiac::TinhTien(double dx, double dy) {
    for (int i = 0; i < soDinh; i++) {
        arrDinh[i].x += dx;
        arrDinh[i].y += dy;
    }
}

/* * Input: Đối tượng Diem v (vector)
 * Output: Tọa độ các đỉnh thay đổi
 * Hướng giải quyết: Gọi lại hàm TinhTien(dx, dy) truyền vào v.x và v.y.
 */
void cDaGiac::TinhTien(Diem v) {
    TinhTien(v.x, v.y);
}

/* * Input: Số thực GocQuay (tính bằng Độ)
 * Output: Đa giác bị xoay
 * Hướng giải quyết: Đổi Độ sang Radian, áp dụng công thức Ma trận quay 2D quanh gốc (0,0) cho từng đỉnh.
 */
void cDaGiac::Quay(double GocQuay) {
    double GocQuayRadian = GocQuay * (PI / 180.0);
    double cosQ = cos(GocQuayRadian);
    double sinQ = sin(GocQuayRadian);

    for (int i = 0; i < soDinh; i++) {
        double oldX = arrDinh[i].x;
        arrDinh[i].x = oldX * cosQ - arrDinh[i].y * sinQ;
        arrDinh[i].y = oldX * sinQ + arrDinh[i].y * cosQ;
    }
}

/* * Input: Số thực k (hệ số tỉ lệ > 0)
 * Output: Đa giác đổi kích thước
 * Hướng giải quyết: Thực hiện phép vị tự tâm (0,0) bằng cách nhân tọa độ x, y với k.
 */
void cDaGiac::PhongToThuNho(double k) {
    if (k <= 0) return; 

    for (int i = 0; i < soDinh; i++) {
        arrDinh[i].x *= k;
        arrDinh[i].y *= k;
    }
}