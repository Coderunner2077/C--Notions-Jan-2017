#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cstring>


using std :: cin; using std :: cout; using std :: endl; using std :: string; using std :: vector;
using std :: begin; using std :: end;

int fct(){
    constexpr unsigned i = 10;
    return i;
}
int a[10];
int main()
{
    /*
    // Initialisation
    unsigned int cnt = 42;
    //string strTab[cnt]; // JAMAIS CA, CAR cnt N'EST PAS UNE EXPRESSION CONSTANTE
    constexpr unsigned sz = 42;
    int tab[10];
    int tabInitialise[10] = {}; //initialisé à 0 (not default initialized)
    int tab2[10] = {10};
    string strTab[sz];
    int *parray[sz]; // 42 pointeurs sur int
    int tab3[fct()] = {1, 2, 4};
    cout << tab3[4] << endl;
    int *(&refTab)[sz] = parray; // a reference to an array of 42 pointers
    char mot[12] = "fundamental";
    for(int nb : a)
        cout << nb << " ";
    cout << endl;
    for(int nb : tab)
        cout << nb << " ";
    cout << endl;
    //char word[4] = "abcd"; ==> ERREUR (pas de place pour le caractère de fin de chaîne ('\0')
    */

    /*
    constexpr unsigned taille = 10;
    int tableau[taille] = {};
    for(size_t i = 0; i < taille; ++i) // size_t est un unsigned défini dans cstddef
        tableau[i] = i;
    int tab[taille];
    for(size_t i = 0; i != taille; i++)
        tab[i] = tableau[i];
    for(int i : tab)
        cout << i << endl;
    vector<int> ivec;

    for(int i = 0; i != 10; ++i)
        ivec.push_back(i);

    vector<int> ivec2(ivec);
    for(auto i : ivec2)
        cout << i << endl;
    */

    /*
    //Pointeurs et tableaux
    int tab[10] = {2};
    int *ptr = &tab[10]; // off-the-end pointer
    ptr -= 1;
    *ptr = 9;
    for(auto &i : tab)
        cout << i << endl;
    cout << endl << endl;
    int *pointeur = tab; // rappel : tab est un pointeur pointant sur le 1er élément du tableau tab[10]
    int *pointeur2 = pointeur + 5; // on peut jongler avec les pointeurs
    *pointeur2 = 5;
    for(auto &i : tab)
        cout << i << endl;
    cout << endl << endl;

    //c'est plus sûr avec begin et end
    int *pt = begin(tab);
    int *ptOff = end(tab);
    ptrdiff_t taille = ptOff - pt; // ptrdiff_t est un signed défini dans cstddef (pouvant prendre des valeurs négatives)
    cout << "Taille du tableau : " << taille << endl;
    ptOff--;
    *ptOff = *pt;
    for(auto i : tab)
        cout << i << endl;
    ptOff++;
    while(pt != ptOff){
        (*pt)++;
        cout << *pt << " ";
        pt++;
    }
    cout << endl;
    int *p = ptOff - 5;
    int nombre = p[-5]; // équivalent à tab[0]
    cout << "nombre : " << nombre << endl;
    int number = tab[5];
    // ==> équivalent à :
    int *pointer = tab;
    number = *(pointer + 5); // eh oui

    cout << "number : " << number << endl;

    //remise à 0 du tableau à l'aide des pointeurs
    int *q = begin(tab);
    while(q != end(tab))
    {
        *q = 0;
        q++;
    }
    cout << endl << endl;
    for(int i : tab)
        cout << i << " ";

    */

    /*
    //EXO : COMPARER DEUX TABLEAUX
    int tab1[10] = {}, tab2[10] = {};
    for(auto &nb : tab1)
        nb++;
    for(auto &nb : tab2)
        nb += 2;

    bool pr_bigger = false, egaux = false;
    int *pt1 = begin(tab1), *pt2 = begin(tab2);
    auto t1 = end(tab1) - begin(tab1);
    ptrdiff_t t2 = end(tab2) - begin(tab2);
    if(t1 > t2)
        pr_bigger = true;
    else if(t1 == t2){
        int qnt1 = 0, qnt2 = 0;
        while(pt1 != end(tab1) && pt2 != end(tab2)){
            qnt1 += *pt1;
            qnt2 += *pt2;
            pt1++;
            pt2++;
        }
        if(qnt1 > qnt2)
            pr_bigger = true;
        else if(qnt1 == qnt2)
            egaux = true;
        cout << "qnt1 : " << qnt1;
        cout << endl << " qnt2 " << qnt2 << endl;
    }
    if(pr_bigger)
        cout << "Le tableau 1 est plus grand que le tableau 2" << endl;
    if(egaux)
        cout << "Les deux tableaux sont egaux" << endl;
    if(!pr_bigger && !egaux)
        cout << "Le tableau 2 est plus grand que le tableau 1 " << endl;
    for(int i : tab1)
        cout << i << endl;
    for(int i : tab2)
        cout << i << " ";
    vector<int> ivec1(10, 1), ivec2(10, 1);
    ivec1[5] = 9;
    ivec2[4] = 9;
    if(ivec1 > ivec2)
        cout << "Vecteur 1 est plus grand" << endl;
    else if(ivec1 < ivec2)
        cout << "Vecteur 2 est plus grand que le vecteur 1" << endl;
    else
        cout << "Les deux vecteurs sont égaux" << endl;
    */

    //RETOUR VERS LES SOURCES
    char mot[100], mot2[100], mot3[200];
    cin >> mot >> mot2;
    cout << mot << "," << mot2 << endl;
    strcpy(mot3, strcat(mot, mot2));
    cout << mot3 << endl;

    //MIXING THE OLD AND NEW
    char *unMot = "Le ciel bleu";
    string word = unMot;
    cout << word << endl;
    //const char *erreur = word; ==> error !
    const char *chaine = word.c_str();  // c_str() renvoie const char*
    cout << chaine << endl;
    word = "abc";
    cout << chaine << endl; // chaine risque d'être invalide suite à la modification du word

    //UTILISATION DU TABLEAU POUR INITIALISER UN VECTOR
    //L'inverse n'est pas possible
    int tab[10] = {1,4,9,3,0,9,10,344,7};
    vector<int> ivec(begin(tab), end(tab));
    for(auto c : ivec)
        cout << c << ".";
    cout << endl;
    vector<int> sub_ivec(begin(tab) + 2, end(tab) - 1); //copie d'un tableau sur-mesure
    for(auto &c : sub_ivec)
        cout << c << " ";
    //définir un tableau à partir d'un vecteur
    int tab2[10];
    for(int i = 0; i != 10; i ++){
        tab2[i] = ivec[i];
    }
    cout << endl;
    for(int i : tab2)
        cout << i << endl;
    return 0;
}
