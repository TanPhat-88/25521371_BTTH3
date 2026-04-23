#include <iostream>
#include <cmath>
#include <algorithm>
#include "cPhanSo.h" 
using namespace std;

/* * Input: Không
 * Output: Đối tượng phân số với giá trị 0/1
 * Hướng giải quyết: Sử dụng danh sách khởi tạo gán tử = 0, mẫu = 1.
 */
cPhanSo::cPhanSo() : tu(0) , mau(1){};

/* * Input: Hai số nguyên t (tử), m (mẫu)
 * Output: Đối tượng phân số t/m đã được định dạng
 * Hướng giải quyết: Gán giá trị, tự động đổi mẫu thành 1 nếu nhập m=0, sau đó gọi hàm rút gọn.
 */
cPhanSo::cPhanSo(int t = 0, int m = 1) : tu(t), mau(m)
{
    if (mau == 0) mau = 1;
    RutGon();
}

/* * Input: Không
 * Output: Phân số hiện tại trở thành dạng tối giản
 * Hướng giải quyết: Dùng hàm __gcd tìm UCLN, chia tử/mẫu cho UCLN và đẩy dấu trừ (nếu có) từ mẫu lên tử.
 */
void cPhanSo::RutGon() {
    int ucln = __gcd(tu,mau);
    tu /= ucln;
    mau /= ucln;
    if (mau < 0)
    {
        mau = -mau;
        tu = -tu;
    }
}

/* * Input: Dữ liệu (tử, mẫu) từ bàn phím
 * Output: Đối tượng được cập nhật dữ liệu mới
 * Hướng giải quyết: Dùng vòng lặp do-while để ép người dùng nhập lại nếu mẫu = 0, nhập xong gọi rút gọn.
 */
void cPhanSo::NhapPhanSo()
{
    do {
        cout << "Nhap tu: "; cin >> tu;
        cout << "Nhap mau: "; cin >> mau;

        if (mau == 0) cout << "Mau bang khong, phan so khong hop le! Vui long nhap lai!\n";
    } while (mau == 0);
    RutGon();
}

/* * Input: Không
 * Output: Chuỗi giá trị in ra màn hình
 * Hướng giải quyết: Biện luận các trường hợp đặc biệt (mẫu = 1 in số nguyên, tử = 0 in 0) để hiển thị đẹp mắt.
 */
void cPhanSo::XuatPhanSo()
{
    if (mau == 1) cout << tu;
    else if (tu == 0) cout << 0;
    else cout << tu << "/" << mau;
}

/* * Input: Đối tượng phân số `other`
 * Output: Một phân số mới là tổng của 2 phân số
 * Hướng giải quyết: Áp dụng công thức cộng phân số cơ bản: (a*d + b*c) / (b*d).
 */
cPhanSo cPhanSo::operator+(const cPhanSo &other)
{
    return cPhanSo(tu * other.mau + other.tu * mau, mau * other.mau);
}

/* * Input: Đối tượng phân số `other`
 * Output: Giá trị boolean (true/false)
 * Hướng giải quyết: Quy đồng và so sánh nhân chéo (a*d > b*c). Thuật toán an toàn vì hàm RutGon đã đảm bảo mẫu số luôn dương.
 */
bool cPhanSo::operator> (const cPhanSo &other)
{
    return (tu*other.mau > other.tu*mau);
}

/* * Input: Đối tượng phân số `other`
 * Output: Giá trị boolean (true/false)
 * Hướng giải quyết: So sánh nhân chéo tương tự toán tử >, nhưng đổi chiều thành (a*d < b*c).
 */
bool cPhanSo::operator< (const cPhanSo &other)
{
    return (tu*other.mau < other.tu*mau);
}

/* * Input: Không
 * Output: Giá trị boolean (true nếu tử là số nguyên tố, ngược lại false)
 * Hướng giải quyết: Loại các số < 2, lặp kiểm tra chia hết từ 2 đến căn bậc hai của tử số.
 */
bool cPhanSo::KiemTraTuNguyenTo()
{
    if (tu < 2) return false;
    for (int i = 2; i <= sqrt(tu); i++)
        if (tu % i == 0) return false;
    return true;
}