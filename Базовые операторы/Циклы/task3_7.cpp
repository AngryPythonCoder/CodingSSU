#include <iostream>

using namespace std;

int main() {
	int n, k;
	long long current = 10; //значение остатка при делении уголком

	cin >> n >> k; //ввод

	cout << "0.";

	for (int i = 0; i < k; i++) {
        if (current < n) // если остаток слишком мал
            cout << 0;   // пишем 0, переходим дальше

        else {
            cout << current / n; // иначе записываем цифру частного
            current %= n;        // и считаем новый остаток
        }

        current *= 10; //при переходе на следующую цифру домножаем на 10
	}

    cout << endl;

	system("pause");
	return 0;
}
