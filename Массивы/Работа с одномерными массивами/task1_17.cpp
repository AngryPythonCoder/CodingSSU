#include <iostream>
#include <ctime>

using namespace std;

void arr_out(int *arr, int length) { // ������� ������ ������� � �������
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;
    int *arr = new int [n];
    srand((unsigned)time(NULL));

    cout << "������� n: "; // ����
    cin >> n;

    for (int i = 0; i < n; i++) // ��������� �������� � �������
        arr[i] = rand() % 10;

    cout << "��������� ������: ";
    arr_out(arr, n); // ����� �������

    swap(arr[n/2], arr[(1-n%2)*(n/2-1)]); // n / 2 - ������ �������, � ������ ������ = 0 ��� �������� n
                                          // � ������� ������� �������� ��� ������
    cout << "�������� ������: ";
    arr_out(arr, n); // ����� �������

    system("pause");
    return 0;
}
