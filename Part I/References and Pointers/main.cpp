#include <iostream>


int main()
{
    int nombre = 4;
    int &reference1 = nombre;
    reference1 = 5;
    std :: cout << nombre << std :: endl;

    //AVEC CONST
    const int &refCon = nombre;
    nombre = 9;
    std :: cout << refCon << std :: endl;
    //refCon = 10; ==> ERREUR !
    const int* pointeur = &nombre; //Low-level const (pointeur sur const)
    //*pointeur = 11; ==> ERREUR !
    int *const pointeur2 = &nombre; //Top-level const (const pointeur)
    int nombre2 = 2;
    //pointeur2 = &nombre2; ==> ERREUR (un const pointeur ne peut pas changer l'adresse sur laquelle il pointe)

    const int *&refSurPointeur = pointeur; // REFERENCE SUR POINTEUR
    std :: cout << *refSurPointeur << std :: endl;
    //*refSurPointeur = 0; ERREUR ==>
    //int *&refSurPointeurNonConst = pointeur; ==> ERREUR !

    const int &refSurUnnamedObject = 43; //OBLIGATOIREMENT const
    std :: cout << refSurUnnamedObject << std :: endl;

    //REFERENCE ET CONVERSION DE TYPES
    double doubleNb = 3.232232323;
    const int &refSurInt = doubleNb; // ICI, refSurInt est une référence sur une variable temporaire créée lors de la conversion
    // ==> du double doubleNb en int
    std :: cout << "Ceci est la valeur d'un \"unnamed object\" renvoyée par une reference sur const : "
                << refSurInt << std :: endl;
    // const int *pointeurSurInt = &doubleNb; ==> ERROR, Cela ne marche que pour les références on dirait...

    int *pteur = 0;
    const int *const pteur2 = &nombre;
    // pteur = pteur2; ==> ERROR
    const int nb = 9;
    // pteur = &nb; ==> ERROR

    const int *pteur3 = pteur2;

    int null = 9;
    int *pt = &null;

    //TYPEDEF
    typedef double wages;
    double salaire = 9999.99;
    const wages *pointeurSurDouble = &salaire; // pointeur sur const double
    double salaire2 = 0;
    pointeurSurDouble = &salaire2;

    typedef double* salary;
    const salary pointeurSurSalaire = &salaire;
    //pointeurSurSalaire = &salaire2; ==> SURPRISE - ERREUR car const pointeur sur double

    //USING
    using entier = int;
    entier un = 1;
    const entier *ptEntier = &un; // pointeur sur const int
    entier deux = 2;
    ptEntier = &deux;

    using pstring = char*;
    const pstring cstr = 0;
    char m = 22;
    // cstr = &m; SURPRISE - ERREUR CAR CONST POINTEUR !!

    // constexpr (for the constant expressions)
    constexpr double nombreX = 99.0;
    constexpr int constant = 89;
    const int *pt4 = nullptr; //pointeur sur const int
    constexpr int *pteur4 = nullptr;// const pointeur sur int
    pt4 = &nombre;
    //pteur4 =&nombre; ==> ERREUR
    // constexpr imposes a top-level const on the object it defines
    constexpr const int *pteur5 = nullptr; // const pointeur sur const int
    //constexpr const int *pteur6 = &constant; // WTF ! DEVRAIT MARCHER MEME AVEC UN NON CONST

    //auto
    auto var = 9, var2 = 10;
    auto var3 = 9.99, *pt5 = &var3;
    //auto var4 = 2, var5 = 2.2; ERREUR CAR var4 est un int et var5 est un double
    int i = 9, &ri = i;
    //attention, auto ne déduit pas toujours le type exact attendu
    auto bi = ri; // bi is an int, not a reference
    //==> ri n'était pas un objet mais un alias de l'int i, et le compileur utilise le type de ce dernier pour déduire auto
    bi = 0;
    std :: cout << "valeur de i : " << i << std :: endl;

    //auto and const
    const int ci = 8, &cr = ci;
    auto b = ci; //ci est un int (top-level const is ignored by auto)
    auto c = cr; // c est un int (cr étant un alias d'un int dont le const est top-level)
    auto d = &i; // d est un pointeur sur int (& of an int object is int*)
    auto e = &ci; // e est un pointeur sur const int (& of a const object is low-level)

    //pour forcer d'avoir un const top-level, on écrit explicitement const devant auto :
    const auto g = ci; //g est un const int
    //on peut aussi spécifier que l'on veut une référence
    auto &h = ci; // h est une référence sur const int
    // quand on lie une référence à une const variable, la const est low-level, donc not ignored by auto

    //auto &k = 43; ==> ERREUR
    const auto &k = 43;

    auto &mr = ci, *n = &ci; //mr est une référence sur const int et n un pointeur sur const int
    int integ = 9;
    //auto &rr = integ, *p = &ci; ==> conflit, car rr est une référence sur int, alors que p est un pointeur sur const int

    auto entier2 = ci;
    entier2 = 9;
    const auto &refrence = ci;
    //refrence = 10; ==> ERREUR
    auto *pointeurrr = &ci;
    //*pointeurrr = 10; ==> ERREUR
    const auto namber = ci, &refarence = nombre;


    return 0;
}
