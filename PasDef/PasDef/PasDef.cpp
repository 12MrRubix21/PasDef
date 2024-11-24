#include <iostream>
#include <vector>
#include <time.h>
#include <istream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;
char messagebase[52] = {
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};
int main();
string generatepas();
void showpass(string path);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*if (i == str || i == str + 1 || i == str + 2) {
    cout << "Новое: ";
    cin >> strnew;
    file << strnew;
    i++;
    continue;
}
*/
void replaceline() {
    
    int strnum;
    cout << "Введите группу: ";
    cin >> strnum;
    strnum = (strnum * 4) - 3;
    string beta;
    fstream x,y;
    x.open("passwords.txt", ios::in);
    y.open("backup.txt", ios::app);
    system("cls");
    int i = 1;
    int num = 1;
    while (!x.eof()) {
        string strnew;
        string strreplace;
        getline(x, strnew);
        
        if (i == strnum || i == strnum + 1 || i == strnum + 2) { 
            cout << "Стрнам" << strnum << endl;
            cout << "Совпало" << " " << i << endl;
            cin >> strreplace;
            y << strreplace << endl;
            system("pause");
            i++;
            continue;
        }
        y << strnew << endl;
        i++;
        
        

    }
    y.close();
    x.close();
    system("cls");
    showpass("backup.txt");
    system("pause");


}


void clearpas() {
    cout << "Вы точно желаете почистить все пароли? (1/0): " << "\n";
    int request;
    cin >> request;
    system("cls");
    if (request == 1) { 
        cout << "\n*Успешно*\n";
        ofstream x; x.open("passwords.txt", ios::out);
        x.close();
    }
    if (request == 0) cout << "\n#Отменено#\n";
    Sleep(1000);
    main();
    
}

void savepassword(string password, string login, string objective) {
    ofstream f;
    f.open("passwords.txt", ios::app);
    f << objective << "\n" << login << "\n" << password << endl;
    f << "------------------" << endl;
    f.close();
    
}

void question_save_and_password() {
    string log, objective;
    cout << "Введите логин: ";
    cin >> log;
    system("cls");
    cout << "Для чего пароль?: ";
    cin >> objective;
    system("cls");
    string pasgen = generatepas();
    cout << "Для чего: " << objective << endl;
    cout << "Ваш логин: " << log << endl;
    cout << "Ваш пароль: " << pasgen << endl;
    savepassword(pasgen, log, objective);
    system("pause");
}

void question_save() {
    string log, objective, pass;
    cout << "Введите логин: ";
    cin >> log;
    system("cls");
    cout << "Введите пароль: ";
    cin >> pass;
    system("cls");
    cout << "Для чего пароль?: ";
    cin >> objective;
    system("cls");
    cout << "Для чего: " << objective << endl;
    cout << "Ваш логин: " << log << endl;
    cout << "Ваш пароль: " << pass << endl;
    savepassword(pass, log, objective);
    system("pause");
}

void menu() {
    system("cls");
    cout 
    << "\nThis code writed by Shira Skywalker" << "\n"
    << "1.Просмотреть пароли" << "\n"
    << "2.Сохранить новый пароль" << "\n"
    << "3.Сгенерировать и сохранить пароль" << "\n"
    << "4.Почистить пароли" << "\n"
    << "5.Заменить что-то" << "\n"
    ;
    cout << "Что вы желаете сделать? -> ";
}
string generatepas() {
    srand(time(NULL));
    string strpas;
    int limit = 10 + rand() % 20;
    for (int i = 0; i < limit; i++) {
        strpas += messagebase[rand() % 52];
    }
    return strpas;
}

void showpass(string path) {
    system("cls");
    string beta;
    ifstream x;
    x.open(path, ios::in);
    system("cls");
    int i = 0;
    int num = 1;
    while (!x.eof()) {
        x >> beta;
        if (i == 0 || !(i % 4)) { 
            cout << num << ".";
            num++;
        }
        cout << beta << endl;
        i++;
        
        
    }
    x.close();
   
}

int main()
{
    setlocale(LC_ALL, "ru");
    int x; menu(); 
    cin >> x;
    switch (x)
    {
    case 1:
        system("cls");
        showpass("passwords.txt");
        system("pause");
        main();
        break;
    case 2:
        system("cls");
        question_save();
        system("pause");
        main();
        break;
    case 3:
        system("cls");
        question_save_and_password();
        system("pause");
        main();
        break;
    case 4:
        system("cls");
        clearpas();
        system("pause");
        main();
        break;
    case 5:
        system("cls");
        showpass("passwords.txt");
        replaceline();
        system("pause");
        main();
        break;

    default:
        main();
    }

    return 0;
}