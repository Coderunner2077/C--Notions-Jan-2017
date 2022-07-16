#include <iostream>
#include <string>
#include <vector>
#include "Screen.h"
#include "Name_lookup.h"
#include "Exos.h"
#include "Sales_data.h"
#include "static_mem.h"

using namespace std;

int main()
{
    /*
    Exercice nb;
    nb.setVal(3);
    cout << nb.getVal() << endl;
    Screen ecran(3, 5, 'A'), ecran2(4, 6, 'B'), ecran3(5, 6, 'C');
    ecran.display(cout).set(3, 8, 'B');
    cout << endl;
    Window_mng mng;
    mng.addScreen(ecran);
    mng.addScreen(ecran2);
    mng.addScreen(ecran3);
    Window_mng::ScreenIndex i = 0;
    for(std::vector<Screen>::const_iterator it = mng.getBegin(); it!= mng.getEnd(); ++it)
    {
        it->display(cout);
        cout << endl;
        mng.clear(i++);
    }

    for(std::vector<Screen>::const_iterator it = mng.getBegin(); it!= mng.getEnd(); ++it)
    {
        it->display(cout);
        cout << endl;
    }

    X x = X(2, 3);
    cout << x.base << " " << x.rem << endl;

    */

    /*
    //Sales_data impl_conversion = cin; Interdit par le mot clé explicit
    Sales_data impl_conversion = Sales_data(cin);
    //Sales_data impl_conversion2 = "Seulement une seule conversion automatique";
    string isbn = "Seulement une seule conversion automatique";
    Sales_data impl_conversion2 = isbn;
    //impl_conversion.combine(cin); conversion interdite par le mot clé explicit
    //impl_conversion.combine("Seulement une seule conversion automatique"); ==> INTERDIT CAR CA FERAIT 2 CONVERSIONS IMPLICITES
    impl_conversion.combine(static_cast<string>("La, on peut")); //A TEMPORARY IS CREATED
    impl_conversion.combine(isbn); //IDEM
    impl_conversion.combine({"appel au construc avec 3 arguments", 4, 5}); //AND AGAIN, A TEMPORARY
    print(cout, impl_conversion) << endl;
    print(cout, impl_conversion2) << endl;
    Sales_data def_arg_cin;
    print(cout, def_arg_cin) << endl;
    */

    /*
    Book livre;
    print(cout, livre) << endl;

    Book libre(cin); //the constructor delegates to Book() which delegates to Book(t, a, g)
    //and the bodies of every constructor is executed (here 3 bodies are executed!)
    print(cout, libre) << endl;
    Book livre2("livre2");
    */

    //C str_c; // ==> ERREUR
    //cout << str_c.getMembre().getNombre() << endl; // => ERREUR
    //vector<NoDefault> vec(10); // => ERREUR
    // vector<C> vec(10); // => ERREUR

    Book pook = {"t", "a", "g"};
    print(cout, pook) << endl;
    Account account, *pAcc;
    double taux = Account::rate();
    double t = account.rate();
    double t2 = pAcc->rate();
    cout << taux << " " << t << " " << t2 << endl;

    return 0;
}
