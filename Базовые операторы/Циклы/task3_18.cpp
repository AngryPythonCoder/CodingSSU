#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < (i + 2); j++) // ������������ ������
            cout << j << " ";

        cout << endl;

        for (int j = 9; j > (8 - 2 * i); j -= 2) // ��������� ������
            cout << j << " ";

        cout << endl;
    }

    return 0;
}
