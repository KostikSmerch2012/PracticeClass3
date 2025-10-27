#include <iostream>
#include <fstream>
#include <cctype>
#include <limits>
#include <string>

using namespace std;


void task3_1() {
    ofstream fin("bebebe.txt");
    if (!fin) {
        cout << "Ненаход" << endl;
    }
    fin << "bebebe bybyby";
    fin.close();
    ifstream fout("bebebe.txt");
    string line;
    getline(fout, line);
    cout << line << endl;
}


void task3_2() {
    ofstream fout("bebebe.txt");
    if (!fout.is_open()) {
        cerr << "Err" << endl;
        return;
    }
    string bebra;
    cout << "Введите текст с числами и буквами: ";
    getline(cin, bebra);
    fout << bebra;
    fout.close();
    ifstream fin("bebebe.txt");
    if (!fin.is_open()) {
        cerr << "Err" << endl;
        return;
    }
    char i;
    string num = "";
    cout << "Ответ: ";
    while (fin.get(i)) {
        if (isdigit(i)) {
            num += i;
        }
        else if (!num.empty()) {
            cout << num << " ";
            num = "";
        }
    }
    if (!num.empty()) {
        cout << num;
    }
    fin.close();
}

void task3_3() {
    ofstream fout("bebebe.txt");
    if (!fout.is_open()) {
        cerr << "Err" << endl;
        return;
    }
    string text = "qWeRtYuIoPaSdFgHjKlZxCvBnMqAzXsDc";
    fout << text;
    fout.close();
    ifstream fin("bebebe.txt");
    if (!fin.is_open()) {
        cerr << "Err" << endl;
        return;
    }
    char c;
    string letters = "";
    while (fin.get(c)) {
        letters += c;
    }
    fin.close();
    for (int i = 0; i < letters.length(); i++) {
        for (int j = 0; j < letters.length() - 1; j++) {
            if (tolower(letters[j]) > tolower(letters[j + 1])) {
                char temp = letters[j];
                letters[j] = letters[j + 1];
                letters[j + 1] = temp;
            }
        }
    }
    cout << "Ответ: " << letters << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int x;
    cout << "Выберите номер таски" << endl;
    cin >> x;
    cin.ignore();
    switch (x)
    {
    case 1:
        task3_1();
        break;
    case 2:
        task3_2();
        break;
    case 3:
        task3_3();
        break;
    }
    return 0;
}