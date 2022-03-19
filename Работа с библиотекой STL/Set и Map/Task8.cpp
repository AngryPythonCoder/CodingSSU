#include <iostream>
#include <set>
#include <string>

using namespace std;

void to_lower(string &s) { // аналог tolower, но для строк
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
}

int main() {
    set<string> declarative, interrogative, exclamatory; // множества слов из соответственно повествовательных, вопросительных и восклицательных
    string text;

    cout << "Input text in 1 line:" << endl; // ввод
    getline (cin, text);

    int start = 0,                      // границы предложения
        end = text.find_first_of(".?!");

    while (end != string::npos) {
        string sentence = text.substr(start, end - start) + " "; // само предложение

        int word_start = 0, 
            word_end = sentence.find_first_of(" "); // границы слова

        while (word_end != string::npos) {
            string word = sentence.substr(word_start, word_end - word_start); // слово
            to_lower(word); // перевод регистра

            if (text[end] == '.') // end указывает на символ знака препинания
                declarative.insert(word);

            else if (text[end] == '?')
                interrogative.insert(word);

            else if (text[end] == '!')
                exclamatory.insert(word);

            word_start = word_end + 1; // обновление границ слова
            word_end = sentence.find_first_of(" ", word_start);
        }

        start = end + 2; // обновление границ предложения
        end = text.find_first_of(".?!", start);
    }

    cout << endl << "Words:" << endl;

    for (set<string>::iterator it = declarative.begin(); it != declarative.end(); it++) { // перебираем все слова из повествовательных и выбираем, отсутствующие в остальных
        if ((interrogative.find(*it) == interrogative.end()) && (exclamatory.find(*it) == exclamatory.end()))
            cout << *it << endl;
    }

    return 0;
}