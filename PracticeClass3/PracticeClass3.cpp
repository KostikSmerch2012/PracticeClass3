#include <iostream>
#include <fstream>
#include <cctype>
#include <limits>
#include <string>
#include <vector>

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
    string text;
    getline(cin, text);
    
    string letters = text;
    
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
  cout << "Введите 2 числа" << endl;
  int a, b;
  cin >> a;
  cin >> b;
  int M = a;
  int N = b;
  if (a > 0 && b > 0) {
    while (a != 0 && b != 0){
    if (a > b) {
      a = a % b;
    }else{
      b = b % a;
    }
  }
  cout << "НОД делением равен " << a + b << endl;

  while (M != N){
    if (M > N){
      M = M - N;
    }else{
      N = N - M;
    }
  }
  cout << "НОД вычитанием равен " << M << endl;
  }
  else{
    if (a == 0 || b == 0 ) {
      if (a == 0 && b == 0) {
        cout << "Нод не определён" << endl;
      }
      else
        cout << "НОД равен " << max(a, b) << endl;
    }
    else{
    cout << "НОД равен " << max(a, b) << endl;
    }
      return;
    }
}

void task3_5() {
    
    cout << "Введите число" << endl;
    int n;
    cin >> n;
    cin.ignore();
    if (n < 2) {
    return;
    }  
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            cout << i << " ";
        }
    }
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
  int counter = 0;
  double summa = 0;
  string number = "";
  while (fin.get(i) && counter < 10) {
    if ((i >= '0' && i <= '9') || i == '.' || i == '-') {
      number += i;
    }
    else if (!number.empty()) {
      double nm = stod(number);
      summa += nm;
      number = "";
      counter ++;
    }
  }
  if (!number.empty() && counter < 10) {
    double nm = stod(number);
    summa += nm;
  }
  if (counter == 9) {
    cout << "Сумма равна: " << summa << endl;
  }else
    cout << "Надо 10 символов" << endl;
    return;
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
    case 4:
        task3_4();
        break;
    case 5:
        task3_5();
        break;
    case 6:
        task3_6();
        break;
    default:
      cout << "Нету такой таски" << endl;
      break;
    }
    return 0;
}
