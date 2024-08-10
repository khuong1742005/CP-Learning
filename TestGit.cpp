#include <iostream>
using namespace std;

int main()
{
    int d; // Đội số d
    cin >> d;

    // Tạo số nguyên n bằng cách lặp lại chữ số 9
    int n = 9;
    while (n % d != 0)
    {
        n = n * 10 + 9;
    }

    cout << "Số nguyên n thỏa mãn: " << n << endl;
    return 0;
}
