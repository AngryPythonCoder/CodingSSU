#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int X;
int func(int sum, int x) { // ������� ������������ � ��������
    if (x % X == 0)
        sum += x;

    return sum;
}

bool even(int x) { // �������� ��������
    return (x % 2 == 0);
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, a, b, maximum;
    vector<int> v;

    cout << "������� n, X: ";
    cin >> n >> X; // ����
    v.resize(n);

    cout << "������������������: ";
    for(int i = 0; i < n; i++) // ����������
        cin >> v[i];

    cout << "����� ���������, ������� " << X << ": " << accumulate(v.begin(), v.end(), 0, func) << endl; // �����
    cout << "����������� �������: " << *min_element(v.begin(), v.end()) << endl;

    maximum = *max_element(v.begin(), v.end()); // ���������� ���������
    replace_if(v.begin(), v.end(), even, maximum); // � ������ ������ ��������� �� ��������

    cout << "�������� ������������������: ";
    for(int i = 0; i < n; i++) // �����
        cout << v[i] << " ";

    return 0;
}
