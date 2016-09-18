#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <cstdlib>

using  namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define OPT_ADD_LINK 1
#define OPT_PRIM 2
#define OPT_PRINT 3
#define OPT_EXIT 0

#define INVALID_OPTION "Opcion invalida\n"
#define DONE "Listo\n"
#define ERROR "Error\n"

void show_menu() {
    cout << OPT_ADD_LINK << ") Agregar conexion" << endl;
    cout << OPT_PRIM << ") Prim" << endl;
    cout << OPT_PRINT << ") Imprimir" << endl;
    cout << OPT_EXIT << ") Salir" << endl;
}

int get_int(string msg = ">", int def = -1) {
    int i;
    cout << msg;
    if(!(cin >> i)) {
        i = def;
        cin.clear();
        cin.ignore();
    }
    cin.ignore();
    return i;
}

string get_string(string msg = ">") {
    string s;
    cout << msg;
    getline(cin, s);
    return s;
}

void msg(const string m) {
    cout << m;
}

void pause() {
    cout << "Presione entrar para continuar . . .";
    cin.ignore();
}

void clear_screen() {
    system(CLEAR);
}

#endif
