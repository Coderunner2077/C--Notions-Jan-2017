#include <iostream>



int main()
{
    int i = 9;
    decltype(i) a = 10;
    decltype((i)) b = i;
    a = 15;
    i--;
    const int *const pointer = &i;
    decltype(pointer) pointer2 = &a;
    const int entier = 11;
    decltype(entier) integer = 50;
    //integer = 60; ==> ERROR
    /*
    * avec decltype le top-level const ne disparaît pas comme avec auto
    * decltype est le seul contexte dans lequel une variable déclarée comme référence n'est pas traitée comme un synonime de
    * l'objet auquel la référence réfère.
    */
    std :: cout << b << std :: endl;

    int &r = a, *p = &a;
    decltype(r+0) c; // c is an int;
    decltype(*p) d = a;; //d est une référence (pas un pointeur !!)
    int ent = 3, nb = 4;
    decltype(ent) nb2 = 8;
    decltype((ent)) ref1 = nb;
    ref1++;
    std :: cout << nb << std :: endl;
    int a1 = 3, a2 = 4, a3 = 10;
    decltype(a1 = a2) a4 = a3;
    a4++;
    std :: cout << a3 << std :: endl;
    const int &ref2 = 8, ent2 = 9;
    decltype(ref2) ref3 = ent2;
    auto &ref4 = ent2;
    auto ent3 = ref2;
    decltype(ref2) notEnt = 9; // une référence sur const
    //notEnt = 0; == > ERROR
    ent3 = 0; // un int

    return 0;
}
