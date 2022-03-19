#include <iostream>

using namespace std;

int main() {
    int year;

    cin >> year; //ввод

    year = (year + 56) % 60; //синхронизация с шестидесятилетним циклом

    switch(year % 10) { //цвет
        case 0: case 1: cout << "Green "; break;
        case 2: case 3: cout << "Red "; break;
        case 4: case 5: cout << "Yellow "; break;
        case 6: case 7: cout << "White "; break;
        case 8: case 9: cout << "Blue "; break;
    }

    switch(year % 12) { //животное
        case 0: cout << "Rat" << endl; break;
        case 1: cout << "Ox" << endl; break;
        case 2: cout << "Tiger" << endl; break;
        case 3: cout << "Rabbit" << endl; break;
        case 4: cout << "Dragon" << endl; break;
        case 5: cout << "Snake" << endl; break;
        case 6: cout << "Horse" << endl; break;
        case 7: cout << "Goat" << endl; break;
        case 8: cout << "Monkey" << endl; break;
        case 9: cout << "Roaster" << endl; break;
        case 10: cout << "Dog" << endl; break;
        case 11: cout << "Pig" << endl; break;
    }

    system("pause");
    return 0;
}
