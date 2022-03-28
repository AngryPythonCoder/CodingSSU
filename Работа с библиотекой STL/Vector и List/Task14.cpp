#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int X;
bool pred1(int x) { // ������� �������� � ��������� X
    return ((x % 2 == 0) && (x % X == 0));
}

int Y;
bool pred2(int x) { // �������� ��������� ������� ���������
    return (x == Y);
}

int main() {
    setlocale(LC_ALL, "RUS");

    int n, m, curr_elem, new_elem, maximum;
    list<int> lst1, lst2;

    cout << "������� ����� �������������������, X � ����������� �������: ";
    cin >> n >> m >> X >> new_elem; // ����

    cout << "������ ������������������: ";
    for(int i = 0; i < n; i++) { // ����������
        cin >> curr_elem;
        lst1.push_back(curr_elem);
    }

    cout << "������ ������������������: ";
    for(int i = 0; i < m; i++) { // ����������
        cin >> curr_elem;
        lst2.push_back(curr_elem);
    }

    for(list<int>::iterator it = lst1.begin(); it != lst1.end(); it++) // ������� ������ �������� �� ��������� �������
        if (pred1(*it)) {
            lst1.insert(++it, new_elem);
            it--;
        }

    Y = *max_element(lst2.begin(), lst2.end()); // ���������� ���������
    lst2.erase(remove_if(lst2.begin(), lst2.end(), pred2), lst2.end()); // �������� ������������ ���������

    cout << endl << "������ ������������������ ����� ������� ����� ���������: ";
    for(list<int>::iterator it = lst1.begin(); it != lst1.end(); it++) // �����
        cout << *it << " ";
    cout << endl;

    cout << "������ ������������������ ����� �������� ������������ ���������: ";
    for(list<int>::iterator it = lst2.begin(); it != lst2.end(); it++) // �����
        cout << *it << " ";
    cout << endl;

    lst1.sort(); // ���������� �������������������
    lst2.sort();

    cout << endl << "������ ������������������ ����� ����������: ";
    for(list<int>::iterator it = lst1.begin(); it != lst1.end(); it++) // �����
        cout << *it << " ";
    cout << endl;

    cout << "������ ������������������ ����� ����������: ";
    for(list<int>::iterator it = lst2.begin(); it != lst2.end(); it++) // �����
        cout << *it << " ";
    cout << endl;

    lst1.unique(); // �������� ����������
    lst2.unique();

    cout << endl << "������ ������������������ ����� �������� ����������: ";
    for(list<int>::iterator it = lst1.begin(); it != lst1.end(); it++) // �����
        cout << *it << " ";
    cout << endl;

    cout << "������ ������������������ ����� �������� ����������: ";
    for(list<int>::iterator it = lst2.begin(); it != lst2.end(); it++) // �����
        cout << *it << " ";
    cout << endl;

    lst1.merge(lst2); // ����������� ���� ������������������� � ����

    cout << endl << "�������� ������������������: ";
    for(list<int>::iterator it = lst1.begin(); it != lst1.end(); it++)//�����
        cout << *it << " ";
    cout << endl;

    return 0;
}
