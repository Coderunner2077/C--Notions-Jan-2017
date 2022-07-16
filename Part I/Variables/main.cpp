#include <iostream>
#include "constante.h"

long long number; // DEFAULT INITIALIZATION (=> 0)
int reused = 100;

constexpr int fcn(){
    return 4;
}

int main()
{
    unsigned u = 10, u2 = 42;
    int i = 10;

    std :: cout << u - i << std :: endl;
    std :: cout << i - u2 << std :: endl; // i converti en unsigned avant le calcul (and it "wraps around")
    int month = 07;
    int month2 = 0xB;
    std :: cout << month - month2 << std :: endl;
    char char1 = 'é';
    char carac = '\a';
    std :: cout << char1 << '\12' << std :: endl;
    std :: cout << carac << "bell?" << std :: endl;
    int nombre = {3.12};//warning
    int nombre2{2.23}; // warning
    long double ld = 3.1423476483;
    int nb = {ld}; // WARNING, A EVITER (BECAUSE OF LOSS OF INFORMATION WHEN CONVERTED...)
    int bb2(ld); // OK


    std :: cout << nombre << "+" << nombre2 << std :: endl;
    int no, no2; // UNDEFINED VALUES...
    std :: cout << number << std :: endl;
    std :: cout << no - no2 << std :: endl;

    std :: string local_str;
    std :: cout << "local_str :" << local_str <<"is empty" << std :: endl;
    extern int declared_but_not_defined;
    int declared_and_defined; // BUT UNDEFINED VALUE...
    std :: cerr << declared_and_defined << std :: endl;

    //LES 4 FACONS D'INITIALISER UNE VARIABLE
    int entier = 4;
    int entier2(4);
    int entier3 = {4}; // C++11
    int entier4{4}; // C++11
    std :: cout << "variable globale : " << reused << std :: endl;
    int reused = 50;
    std :: cout << "Variable locale : " << reused << std :: endl;
    std :: cout << "Variable globale : " << :: reused << std :: endl;

    const int constReusedElsewhere = fcn();


    return 0;
}


