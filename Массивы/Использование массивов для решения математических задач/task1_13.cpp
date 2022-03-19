#include <iostream>
#include <iomanip>
#include <numeric>

using namespace std;

void line_out(int *arr, int n) { // ������� ������ ������� ������������ � �������
    for (int i = 0; i < n; i++)
        cout << setw(5) << arr[i+1] << " ";

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");
    cout << setiosflags(ios::left);

    int n, S, len;

    cout << "������� n: "; // ����
    cin >> n;
    len = max(10, n);

    int *arr = new int[len+2];     //��� ������� ��� ��������� ����� ������ ������������ �� ������ ������
    int *new_arr = new int[len+2];

    fill(arr, arr + (len+2), 0);
    fill(new_arr, new_arr + (len+2), 0);

    new_arr[1] = 1;
    cout << endl;
    line_out(new_arr, 1); // ����� ������� ������

    if (n == 0) // ������� ��� ����
        S = 1;

    for (int i = 1; i <= len; i++) {
        swap(arr, new_arr);

        for (int j = 1; j <= (i+1); j++)
            new_arr[j] = arr[j-1] + arr[j]; // ������� ����� ������

        if (i == n)
            S = accumulate(new_arr, new_arr + (n+2), 0); // ������� 2^k

        line_out(new_arr, i+1); // ����� ������
    }

    cout << endl << "2^" << n << " = " << S << endl; // ����� 2^k

    return 0;
}
