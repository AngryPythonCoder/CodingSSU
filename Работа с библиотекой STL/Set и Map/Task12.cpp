#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

bool is_number(string &s) { // функция, проверяющая, является ли строка числом
    bool flag = true;

    for (int i = 0; i < s.length(); i++)
        if (!isdigit(s[i]))
            flag = false;

    return flag;
}

int main() {
    map<string, int> frequency; // мэп для хранения частот слов
    string text, line;
 
    ifstream input_file("input.txt"); // окрываем файл для чтения

    if (input_file.is_open())
        while (getline(input_file, line))
            text += line;

    input_file.close(); // закрываем файл

    int start = 0, 
        end = text.find_first_of(" "); // границы слова

    while (end != string::npos) {
        string word = text.substr(start, end - start); // слово

        if (!is_number(word)) {
            if (frequency.find(word) == frequency.end()) // в случае отсутствия слова в мэпе добавляем
                frequency[word] = 1;

            else // иначе увеличиваем уже имеющееся значение
                frequency[word]++;
        }

        start = end + 1; // обновление границ слова
        end = text.find_first_of(" ", start);
        }

    cout << endl << "Frequency:" << endl;

    for (map<string, int>::iterator it = frequency.begin(); it != frequency.end(); it++) { // вывод по принципу <слово>: <количество вхождений>
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}