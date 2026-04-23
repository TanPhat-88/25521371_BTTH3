#include <iostream>
#include <cmath>
#include <algorithm>
#include "cPhanSo.h"
#include "cDSPhanSo.h" 
using namespace std;

/* * Input: Kích thước mảng n (mặc định = 0)
 * Output: Đối tượng cDSPhanSo được khởi tạo
 * Hướng giải quyết: Gán kích thước và dùng `new` để cấp phát vùng nhớ mảng động.
 */
cDSPhanSo::cDSPhanSo(int n = 0) : size(n) 
{
    list = new cPhanSo[n];
}

/* * Input: Dữ liệu (số lượng, giá trị tử/mẫu) từ bàn phím
 * Output: Mảng `list` được cập nhật dữ liệu mới
 * Hướng giải quyết: Thu hồi mảng cũ bằng `delete[]`, cấp phát lại mảng mới theo size và lặp để gọi NhapPhanSo().
 */
void cDSPhanSo::NhapDSPhanSo()
{
    cout << "Nhap so luong phan so: "; cin >> size;
    delete[] list;
    list = new cPhanSo[size];
    for (int i = 0; i < size; ++i)
    {
        cout << "Nhap phan so thu " << (i+1) << ": \n";
        list[i].NhapPhanSo();
    }
}

/* * Input: Không
 * Output: In các phân số ra màn hình
 * Hướng giải quyết: Dùng vòng lặp duyệt mảng và gọi hàm XuatPhanSo().
 */
void cDSPhanSo::XuatDSPhanSo()
{
    for (int i = 0; i < size; ++i)
    {
        list[i].XuatPhanSo();
        cout << " ";
    }
}

/* * Input: Không
 * Output: Một đối tượng cPhanSo là tổng của mảng
 * Hướng giải quyết: Khởi tạo biến `tong` = 0/1, dùng vòng lặp cộng dồn các phần tử vào `tong`.
 */
cPhanSo cDSPhanSo::Tong()
{
    cPhanSo tong(0,1);
    for (int i = 0; i < size; ++i)
        tong = tong + list[i];
    return tong;
}

/* * Input: Không
 * Output: Đối tượng cPhanSo có giá trị lớn nhất
 * Hướng giải quyết: Đặt Max là phần tử đầu tiên, duyệt mảng so sánh với các phần tử còn lại để cập nhật Max.
 */
cPhanSo cDSPhanSo::PSLonNhat()
{
    cPhanSo Max = list[0];
    for (int i = 1; i < size; ++i)
        if (list[i] > Max) Max = list[i];
    return Max;
}

/* * Input: Không
 * Output: Đối tượng cPhanSo có giá trị nhỏ nhất
 * Hướng giải quyết: Đặt Min là phần tử đầu tiên, duyệt mảng so sánh tìm giá trị nhỏ nhất.
 */
cPhanSo cDSPhanSo::PSNhoNhat()
{
    cPhanSo Min = list[0];
    for (int i = 1; i < size; ++i)
        if (list[i] < Min) Min = list[i];
    return Min;
}

/* * Input: Không
 * Output: Phân số có tử là số nguyên tố và giá trị lớn nhất
 * Hướng giải quyết: Duyệt mảng tìm phân số ĐẦU TIÊN có tử là số nguyên tố làm cột mốc (Max), sau đó lặp tiếp từ vị trí đó để so sánh và tìm Max thực sự.
 */
cPhanSo cDSPhanSo::PSTuNguyenToLonNhat()
{
    cPhanSo Max;
    int i = 0;
    for ( i ; i < size; ++i)
        if (list[i].KiemTraTuNguyenTo())
        {
            Max = list[i];
            break;
        }
    for (int j = i + 1; j < size; ++j)
        if (list[j].KiemTraTuNguyenTo() && list[j] > Max)
            Max = list[j];
    return Max;
}

/* * Input: Không
 * Output: Mảng `list` được sắp xếp tăng dần
 * Hướng giải quyết: Dùng thuật toán Interchange Sort (2 vòng lặp lồng nhau), hoán vị nếu phần tử đứng trước LỚN HƠN phần tử đứng sau.
 */
void cDSPhanSo::SapXepTang() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i] > list[j]) {
                swap(list[i], list[j]);
            }
        }
    }
}

/* * Input: Không
 * Output: Mảng `list` được sắp xếp giảm dần
 * Hướng giải quyết: Tương tự sắp xếp tăng nhưng hoán vị nếu phần tử đứng trước NHỎ HƠN phần tử đứng sau.
 */
void cDSPhanSo::SapXepGiam() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i] < list[j]) {
                swap(list[i], list[j]);
            }
        }
    }
}