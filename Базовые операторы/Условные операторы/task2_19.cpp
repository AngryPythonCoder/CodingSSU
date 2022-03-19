#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    double a, b, c, d, e, f, det, detX, detY;

    cout << "Первая прямая: "; //ввод
    cin >> a >> b >> c;

    cout << "Вторая прямая: ";
    cin >> d >> e >> f;

    if ((a == 0 && b == 0) && (d == 0 && e == 0))
        cout << "Не прямые" << endl;

    else if (a == 0 && b == 0)
        cout << "1 уравнение - не прямая" << endl;

    else if (d == 0 && e == 0)
        cout << "2 уравнение - не прямая" << endl;

    else {
        det = (a * e - b * d); //высчитаем определители для применения формулы крамера
        detX = (b * f - c * e);
        detY = (c * d - a * f);

        if (det == 0) {
            if ((detX != 0) || (detY != 0)) { //пропорциональные коэффициенты при x, y
                cout << "Параллельны" << endl;

            } else //пропорциональны все коэффициенты
                cout << "Совпадают" << endl;

        } else {
            double x = detX / det; //доводим формулу до конца, ищем точку пересечения
            double y = detY / det;
            cout << "Пересекаются в точке (" << x << ", " << y << ")" << endl;
        }
    }

    system("pause");
    return 0;
}
