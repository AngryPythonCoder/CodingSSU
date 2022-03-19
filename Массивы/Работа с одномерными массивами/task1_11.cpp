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

    int b = -1, a = 21; // ������� �������� ���������, ��������
    int *maximum = &b, *minimum = &a; // ��������� �� ��������, �������

    int n;
    float average = 0;
    int *arr = new int [n];
    srand((unsigned)time(NULL));

    cout << "������� n: "; // ����
    cin >> n;

    for (int i = 0; i < n; i++) // ��������� �������� � �������
        arr[i] = rand() % 21;

    cout << "������: ";
    arr_out(arr, n); // ����� �������

    for (int i = 0; i < n; i++) {
        if (arr[i] < *minimum) // ���� ������ �������
            minimum = &arr[i];

        if (arr[i] >= *maximum) // ���� ���������� ��������
            maximum = &arr[i];
    }

    if (maximum < minimum)
        cout << "MAX ����� MIN" << endl;

    else if (maximum == (minimum + 1))
        cout << "0 ��������� ����� MAX � MIN" << endl;

    else {
        for (int *current = minimum+1; current < maximum; current++) // � ������� ��������� �������� �� ��������� � ���������
            average += *current;

        average /= (maximum - minimum) - 1; // ������� ������� ��������������

        cout << "������� ��������������: " << average; // �����
    }

    system("pause");
    return 0;
}
