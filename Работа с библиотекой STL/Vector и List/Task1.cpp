#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int A, B;
int func(int sum, int x) { // ������� ������������ � ��������
    if (!((A <= x) && (x <= B)))
        sum += x;

    return sum;
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n;
    vector<int> v;

    cout << "������� n, a, b: ";
    cin >> n >> A >> B; // ����
    v.resize(n);

    cout << "������������������: ";
    for(int i = 0; i < n; i++) // ����������
        cin >> v[i];

    cout << "����� ���������, �� ���������� � ��������: " << accumulate(v.begin(), v.end(), 0, func) << endl; // �����

    return 0;
}
