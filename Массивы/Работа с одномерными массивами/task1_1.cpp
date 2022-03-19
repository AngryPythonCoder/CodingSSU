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

    int n, left, right, answer = 0;
    int *arr = new int [n];
    srand((unsigned)time(NULL));

    cout << "������� n: "; // ����
    cin >> n;

    cout << "������� ����� � ������ ������� ����� ������: ";
    cin >> left >> right;

    for (int i = 0; i < n; i++) // ��������� �������� � �������
        arr[i] = rand() % 15;

    cout << "������: ";
    arr_out(arr, n); // ����� �������

    for (int i = 0; i < n; i++)
        answer += ((arr[i] % 2 == 0) && (arr[i] >= left) && (arr[i] <= right)) ? arr[i]: 0; // ������� ����� ������ ��������� �� ���������

    if (answer == 0) cout << "����� ��������� ���" << endl; // �����
    else cout << "�����: " <<  answer << endl;

    system("pause");
    return 0;
}
