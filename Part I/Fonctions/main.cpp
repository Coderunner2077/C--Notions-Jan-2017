#include <iostream>
#include <string>
#include <vector>
#include "functions.h"
#include <cctype>
#include <assert.h>

using std :: cin; using std :: cout; using std :: endl; using std :: string; using std :: vector;
using std :: begin; using std :: end;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) &rfToTab(int i)
{
    return (i % 2) ? odd : even;
}

decltype(odd) *ptToTab(int i)
{
    //decltype does not automatically convert a pointer to its corresponding pointer type (hence &)
    return (i % 2) ? &odd : &even;
}



int main(int argc, char **argv)
{
    string word = "condition sinequanon";
    assert(word.size() < 30); // if the arguments yields false, prog shuts down
    int result = fact(5);
    cout << result << endl;
    cout << abs(-123) << endl;
    while((result = f()) < 5)
        cout << result << endl;
    int ival = 2, ival2 = 5;
    swapF(&ival, &ival2);
    cout << ival << " " << ival2 << endl;
    int &r = ival, &r2 = ival2;
    swapF(ival, ival2); //version of references
    cout << r << " " << r2 << endl;
    doesNothing(ival);
    cout << ival << endl;
    string :: size_type occur = 0;
    auto pos = find_char("Aujourd'hui", 'u', occur);
    cout << "position : " << pos << endl;
    cout << "occurence : " << occur << endl;
    bool b = is_empty("");
    cout << b << endl;
    int *p = &ival;
    cout << compare(7, p) << endl;
    int tab[10] = {2, 4, 9, 8, 7, 44, 33};
    print(tab);
    print(begin(tab), end(tab));
    print(&ival, 1);
    int j[2] = {0, 1};
    print(j, 2);


    /*
    cout << "main : " << endl;
    for(int i = 0; i != 2; ++i)
        cout << argv[i] << endl;
    */


    int (*pArr)[10] = return_pointer_to_array(tab);
    cout << **pArr << endl;
    cout << *(*pArr + 4) << endl;
    for(int i = 0; i != 10; ++i)
        cout << (*pArr)[i] << " ";
    cout << endl;

    print(pArr);
    print(return_pointer_to_array(tab));

    cout << sum({1, 2, 3, 4, 5, 6}) << endl;
    initializer_list<int> liste;
    liste = {1, 3, 8};
    liste = {9, 3, 3, 9, 3};
    initializer_list<int> li(liste);



    /*

    for(auto &elem : li)
        elem = 9; // ERROR
    elements in initializer_list are const

    */

    print(li);
    li = {ival};
    print(li);
    print(liste);
    //liste = {li.size()};
    ival = 9;
    print(li);
    cout << __func__ << endl; //renvoie le nom de la fonction principale (main)
    get(tab, 8) = 10; // OK BECAUSE get returns a reference (an lvalue)
    cout << get(tab, 8) << endl;
    vector<int> ivec(10, 3);
    ivec[0] = 1;
    print(ivec);

    int (&tb)[5] = rfToTab(133);
    for(auto elem : tb)
        cout << elem << " ";
    cout << make_plural(2, "pomme") << endl;
    int &rf = ival, &rf2 = ival2;
    constexpr bool touroute = isShorter(4, 9);
    // a constexpr function may return a nonconst expression ... if the context allows it
    #ifndef NDEBUG
    cout << __func__ << endl;
    cout << __FILE__ << endl;
    cout << __LINE__ << endl;
    cout << __TIME__ << endl;
    cout << __DATE__ << endl;
    #endif // NDEBUG

    //pointers to functions

    FuncP ptr = divide;
    //FuncP ptr = &divide; // pareil
    Func* ptr2 = multiply; // idem
    cout << ptr(8, 4) << endl;
    cout << ptr2(3, 89) << endl;

     vector<int(*)(int, int)> pfvec;
    pfvec.push_back(add);
    pfvec.push_back(substract);
    pfvec.push_back(multiply);
    pfvec.push_back(divide);
    int res = pfvec[0](1, 4);
    cout << res << endl;
    cout << pfvec[3](36, 0) << endl;

    return 0;
}
