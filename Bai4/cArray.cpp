#include <iostream>
#include <ctime>
#include <climits>
#include "cArray.h"
using namespace std;

// Input: n (số lượng phần tử, mặc định = 0)
// Output: Đối tượng cArray được khởi tạo
// Thuật toán: Cấp phát động mảng arr với kích thước n.
cArray::cArray(int n = 0) : size(n)
{
    arr = new int[n];
}

// Input: Không có
// Output: Giải phóng bộ nhớ của mảng
// Thuật toán: Dùng delete[] để thu hồi vùng nhớ đã cấp phát cho con trỏ arr.
cArray::~cArray() { delete[] arr; }

// Input: Kích thước mảng (size) và các phần tử nhập từ bàn phím
// Output: Mảng arr chứa các giá trị vừa nhập
// Thuật toán: Xóa mảng cũ, cấp phát lại mảng mới theo kích thước size. 
//             Dùng vòng lặp for để duyệt và nhập từng phần tử.
void cArray::NhapMang()
{
    cout << "So luong phan tu: "; cin >> size;
    delete[] arr;
    arr = new int[size];
    for (int i = 0; i < size; ++i)
        cin >> arr[i];
}

// Input: Mảng arr hiện tại
// Output: In các phần tử của mảng ra màn hình
// Thuật toán: Dùng vòng lặp for duyệt từ đầu đến cuối mảng, in giá trị kèm khoảng trắng.
void cArray::XuatMang()
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
}

// Input: n (số lượng phần tử cần tạo)
// Output: Mảng arr chứa n số nguyên ngẫu nhiên trong đoạn [0, 99]
// Thuật toán: Giải phóng mảng cũ, cấp phát mảng mới. Đặt seed ngẫu nhiên bằng srand(time(0)). 
//             Lặp n lần, gán mỗi phần tử bằng rand() % 100.
void cArray::taoNgauNhien(int n) {
    size = n;
    delete[] arr;
    arr = new int[size];
    srand(time(0));
    for (int i = 0; i < size; ++i) arr[i] = rand() % 100;
}

// Input: x (giá trị cần đếm)
// Output: Số lần x xuất hiện trong mảng (kiểu int)
// Thuật toán: Khởi tạo biến đếm cnt = 0. Duyệt qua toàn bộ mảng, 
//             nếu phần tử tại i bằng x thì tăng cnt lên 1. Trả về cnt.
int cArray::demSoLanXuatHien(int x) {
    int cnt = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] == x) cnt++;
    return cnt;
}

// Input: Mảng arr hiện tại
// Output: true nếu mảng tăng dần ngặt, ngược lại false
// Thuật toán: Duyệt mảng từ vị trí thứ 1 (index 1). Nếu phát hiện phần tử hiện tại 
//             nhỏ hơn hoặc bằng phần tử đứng ngay trước nó thì lập tức trả về false. 
//             Nếu duyệt hết không vi phạm, trả về true.
bool cArray::kiemTraTangDan() {
    for (int i = 1; i < size; ++i)
        if (*(arr + i) <= *(arr + i - 1))
            return false;
    return true;
}

// Input: Mảng arr hiện tại
// Output: Số lẻ nhỏ nhất trong mảng, hoặc 0 nếu không có số lẻ nào
// Thuật toán: Khởi tạo minOdd bằng giá trị lớn nhất (INT_MAX). Duyệt mảng, kiểm tra 
//             nếu phần tử là số lẻ (% 2 != 0) và nhỏ hơn minOdd thì cập nhật minOdd.
//             Cuối cùng kiểm tra nếu minOdd vẫn bằng INT_MAX thì trả về 0.
int cArray::timLeNhoNhat() {
    int minOdd = INT_MAX;
    for (int i = 0; i < size; ++i)
        if (*(arr + i) % 2 != 0 && *(arr + i) < minOdd)
            minOdd = *(arr + i);
    return (minOdd == INT_MAX) ? 0 : minOdd;
}

// Input: Số nguyên n
// Output: true nếu n là số nguyên tố, false nếu ngược lại
// Thuật toán: Nếu n < 2 trả về false. Lặp từ i = 2 đến căn bậc hai của n, 
//             nếu n chia hết cho i thì trả về false. Nếu không chia hết, trả về true.
bool Prime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

// Input: Mảng arr hiện tại
// Output: Số nguyên tố lớn nhất trong mảng, hoặc -1 nếu không có
// Thuật toán: Đặt maxPrime = -1 và cờ found = false. Duyệt mảng, dùng hàm Prime() kiểm tra. 
//             Nếu là số nguyên tố và (chưa tìm thấy số NT nào HOẶC phần tử > maxPrime) 
//             thì cập nhật lại maxPrime.
int cArray::timSoNguyenToLonNhat() {
    int maxPrime = -1;
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (Prime(arr[i])) {
            if (!found || arr[i] > maxPrime) {
                maxPrime = arr[i];
                found = true;
            }
        }
    }
    return maxPrime;
}

// Input: Mảng arr hiện tại
// Output: Mảng arr được sắp xếp tăng dần
// Thuật toán: Dùng Insertion Sort (Sắp xếp chèn). Duyệt từ phần tử thứ 1 đến n-1, 
//             lưu giá trị hiện tại vào 'key'. Dời các phần tử đứng trước 'key' và lớn hơn 'key' 
//             sang phải 1 vị trí. Chèn 'key' vào vị trí trống đã tìm được.
void cArray::sapXepTangDan() {
    for (int i = 1; i < size; i++) {
        auto key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}