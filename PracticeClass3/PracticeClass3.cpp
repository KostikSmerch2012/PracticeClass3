#include <iostream>
#include <fstream>
#include <cctype>
#include <limits>
#include <string>

using namespace std;


void task3_1() {
    ofstream fin("bebebe.txt");
    if (!fin.is_open()) {
        cout << "Ненаход" << endl;
        return;
    }
    string a;
    getline(cin, a);
    fin << a;
    fin.close();
    ifstream fout("bebebe.txt");
    if (!fout.is_open()) {
        cout << "Ненаход" << endl;
        return;
    }
    
    string line;
    while (getline(fout, line)) {
        cout << line << endl;
    }
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
        cout << "Ответ: " << num;
    }
    fin.close();
}

void task3_3() {
    ofstream fout("bebebe.txt");
    if (!fout.is_open()) {
        cerr << "Err" << endl;
        return;
    }
    string text;
    getline(cin, text);
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

void task3_4(){
  ofstream fout("bebebe.txt");
  if (!fout.is_open()) {
      cerr << "Err" << endl;
      return;
  }
  
  string fnum, snum;

  cout << "1 number = ";
  if (getline(cin, fnum)) {
    fout << fnum << endl;
  }
  cout << "2 number = ";
  if (getline(cin, snum)) {
    fout << snum << endl;
  }
  fout.close();

  ifstream fin("bebebe.txt");
  if (!fin.is_open()) {
    cerr << "Err" << endl;
    return;
  }
  
  string file_fnum, file_snum;
  getline(fin, file_fnum);
  getline(fin, file_snum);

  int a = stoi(file_fnum);
  int b = stoi(file_snum);
  while (a != 0 && b != 0) {
      if (a > b) {
          a = a % b;
      } else {
          b = b % a;
      }
  }
    cout << "НОД путём деления = " << a + b << endl;

  int M = stoi(file_fnum);
  int N = stoi(file_snum);

  while (M != N){
    if (M > N) {
      M = M - N;
    }
    else{
      N = N - M;
    }
  }
  cout << "НОД путём вычитания = " << M << endl;
}

void task3_5(){
    ofstream fout("bebebe.txt");
  if (!fout.is_open()) {
      cerr << "Err" << endl;
      return;
  }
  cout << "Введите числа через пробел" << endl;
  string nums;
  getline(cin, nums);
  fout << nums;
  fout.close();

}

void task3_6(){
  ofstream fout("bebebe.txt");
  if (!fout.is_open()) {
      cerr << "Err" << endl;
      return;
  }
  cout << "Введите числа через пробел" << endl;
  string nums;
  getline(cin, nums);
  fout << nums;
  fout.close();

  ifstream fin("bebebe.txt");
  if (!fin.is_open()) {
      cerr << "Err" << endl;
      return;
    }

  char i;
  double summa = 0;
  string number = "";
  while (fin.get(i)) {
    if (isdigit(i)) {
      number += i;
    }
    else if (!number.empty()) {
      double nm = stod(number);
      summa += nm;
      number = "";
    }
  }
  if (!number.empty()) {
    double nm = stod(number);
    summa += nm;
  }

  cout << "Сумма равна: " << summa << endl;
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
    case 4:
        task3_4();
    case 5:
        task3_6();
        break;
    }
    return 0;
}
