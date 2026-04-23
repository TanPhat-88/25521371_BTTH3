#include <iostream>
#include <cmath> // Bổ sung cmath cho hàm pow()
#include "cDaThuc.h"
using namespace std;

// Input: Không có
// Output: Đối tượng cDaThuc được khởi tạo với bậc = 0 và hệ số = 0
// Thuật toán: Gán biến bac bằng 0. Cấp phát mảng động heSo có 1 phần tử và gán giá trị 0.
cDaThuc::cDaThuc() {
    bac = 0;
    heSo = new double[1]{0};
}

// Input: Số nguyên n (bậc của đa thức)
// Output: Đối tượng cDaThuc có bậc n, các hệ số đều bằng 0
// Thuật toán: Gán bac = n. Cấp phát mảng heSo kích thước (n + 1). Dùng vòng lặp gán tất cả hệ số bằng 0.
cDaThuc::cDaThuc(int n) {
    bac = n;
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++) heSo[i] = 0;
}

// Input: Không có
// Output: Giải phóng bộ nhớ của đối tượng
// Thuật toán: Dùng delete[] để thu hồi vùng nhớ đã cấp phát cho con trỏ heSo.
cDaThuc::~cDaThuc() {
    delete[] heSo;
}

// Input: Đối tượng cDaThuc khác (other)
// Output: Đa thức hiện tại được gán giá trị giống với 'other'
// Thuật toán: Kiểm tra tự gán (this != &other). Nếu khác, xóa mảng hệ số cũ, cập nhật bậc, 
//             cấp phát mảng mới và sao chép từng phần tử từ 'other' sang mảng hiện tại.
cDaThuc& cDaThuc::operator=(const cDaThuc& other) {
    if (this != &other) {
        delete[] heSo;
        bac = other.bac;
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; i++) heSo[i] = other.heSo[i];
    }
    return *this;
}

// Input: Bậc và các hệ số tương ứng nhập từ bàn phím
// Output: Đa thức được lưu trữ các hệ số vừa nhập
// Thuật toán: Nhập bậc. Xóa mảng cũ, cấp phát mảng mới có kích thước (bac + 1). 
//             Dùng vòng lặp for để yêu cầu người dùng nhập hệ số từ bậc cao nhất xuống bậc 0.
void cDaThuc::Nhap() {
    cout << "Nhap bac cua da thuc: ";
    cin >> bac;
    delete[] heSo;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; i++) {
        cout << "Nhap he so cho x^" << bac - i << ": ";
        cin >> heSo[i];
    }
}

// Input: Đa thức hiện tại
// Output: In chuỗi đa thức dạng toán học ra màn hình (VD: 3x^2 - x + 5)
// Thuật toán: Duyệt mảng hệ số. Bỏ qua các hệ số bằng 0. In dấu (+, -) dựa vào giá trị hệ số 
//             và vị trí của nó. In giá trị tuyệt đối của hệ số (bỏ qua số 1 nếu đi kèm biến x). 
//             In ký tự 'x' và '^' ứng với số mũ hiện tại. Xử lý in số "0" nếu đa thức rỗng.
void cDaThuc::Xuat() {
    bool first = true;
    for (int i = 0; i <= bac; i++) {
        if (heSo[i] == 0) continue;
        
        if (!first && heSo[i] > 0) cout << " + ";
        if (heSo[i] < 0) cout << " - ";
        
        double absVal = abs(heSo[i]);
        if (absVal != 1 || (bac - i) == 0) cout << absVal;
        
        if ((bac - i) > 0) cout << "x";
        if ((bac - i) > 1) cout << "^" << bac - i;
        
        first = false;
    }
    if (first) cout << "0";
    cout << endl;
}

// Input: Giá trị thực x
// Output: Giá trị của đa thức tại x (kiểu double)
// Thuật toán: Khởi tạo biến ketQua = 0. Duyệt qua mảng hệ số, tính giá trị của từng hạng tử 
//             bằng heSo[i] * x^(bac - i) (dùng hàm pow), sau đó cộng dồn vào ketQua.
double cDaThuc::TinhGiaTri(double x) {
    double ketQua = 0;
    for (int i = 0; i <= bac; i++) {
        ketQua += heSo[i] * pow(x, bac - i);
    }
    return ketQua;
}

// Input: Đa thức 'other' để cộng
// Output: Một đối tượng cDaThuc mới là tổng của 2 đa thức
// Thuật toán: Tìm bậc lớn nhất (maxBac) giữa 2 đa thức. Tạo đa thức kết quả theo maxBac. 
//             Duyệt từ i = 0 đến maxBac (đại diện cho x^0 đến x^maxBac). Ở mỗi bậc, 
//             lấy hệ số tương ứng của 2 đa thức (nếu bậc vượt quá bậc thực tế thì coi hệ số là 0), 
//             cộng lại rồi gán vào vị trí tương ứng trong đa thức kết quả.
cDaThuc cDaThuc::operator+(const cDaThuc& other) {
    int maxBac = max(this->bac, other.bac);
    cDaThuc ketQua(maxBac);
    
    for (int i = 0; i <= maxBac; i++) {
        double v1 = (i <= this->bac) ? this->heSo[this->bac - i] : 0;
        double v2 = (i <= other.bac) ? other.heSo[other.bac - i] : 0;
        ketQua.heSo[maxBac - i] = v1 + v2;
    }
    return ketQua;
}

// Input: Đa thức 'other' để trừ
// Output: Một đối tượng cDaThuc mới là hiệu của 2 đa thức
// Thuật toán: Tương tự như phép cộng. Tìm maxBac, tạo đa thức kết quả. Duyệt theo bậc, 
//             lấy hệ số tương ứng của đa thức hiện tại (v1) trừ đi hệ số của đa thức other (v2) 
//             (nếu khuyết bậc thì coi hệ số là 0) và gán vào đa thức kết quả.
cDaThuc cDaThuc::operator-(const cDaThuc& other) {
    int maxBac = max(this->bac, other.bac);
    cDaThuc ketQua(maxBac);
    
    for (int i = 0; i <= maxBac; i++) {
        double v1 = (i <= this->bac) ? this->heSo[this->bac - i] : 0;
        double v2 = (i <= other.bac) ? other.heSo[other.bac - i] : 0;
        ketQua.heSo[maxBac - i] = v1 - v2;
    }
    return ketQua;
}