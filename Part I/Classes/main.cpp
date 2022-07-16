#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"
#include "Person.h"
#include "Screen.h"

using std::string; using std::vector; using std::cin; using std::cout; using std::endl;
int main()
{
    /*
    cout << "Enter a transaction (isbn, quantity, price)" << endl;
    Sales_data total;
    if(read(cin, total))
    {
        Sales_data trans;
        cout << "Entrez la transaction suivante" << endl;
        while(read(cin, trans))
        {
            if(total.isbn() == trans.isbn())
            {
                total.combine(trans);
                cout << "Entrez la transaction suivante" << endl;
            }
            else
            {
                print(cout, total) << endl
                                   << "Entrez la transaction suivante" << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        std::cerr << "No data?!" << endl;
        return -1;
    }
    */

    /*
    Person pers, pers2;
    if(read(read(cin, pers), pers2))
        cout << "ok" << endl;
    print(cout, pers) << endl;
    */

    /*
    Sales_data item(cin);
    print(cout, item) << endl;
    Sales_data item2("voila");
    print(cout, item2) << endl;
    Sales_data item3;
    print(cout, item3) << endl;
    Sales_data item4("isbn", 5, 100);
    print(cout, item4) << endl;
    Sales_data item5 = {"pp", 10, 200}; //implicit conversion
    print(cout, item5);
    */

    /*

    cout << "Enter a transaction (isbn, quantity, price)" << endl;
    Sales_data total(cin);
    if(cin)
    {
        cout << "Entrez la transaction suivante" << endl;
        do
        {
            Sales_data trans(cin);
            if(total.isbn() == trans.isbn())
            {
                total.combine(trans);
                cout << "Entrez la transaction suivante" << endl;
            }
            else
            {
                print(cout, total) << endl
                                   << "Entrez la transaction suivante" << endl;
                total = trans;
            }
        }while(cin);

        print(cout, total) << endl;
    }
    else
    {
        std::cerr << "No data?!" << endl;
        return -1;
    }

    */

    /*
    Person pers(cin);
    print(cout, pers) << endl << "ok" << endl;
    */

    Screen ecran(10, 20, 'c');

    cout << ecran.get() << "ok" << endl;
    Screen ec = ecran;
    cout << ec.get() << "ok" << endl;
    class Screen ec2 = {9, 10}; // same shit : inherited from C
    cout << ec2.get() << "ok" << endl;
    ec.move(5, 10).set('d');
    ec.display(cout).move(5, 11).set('f');
    cout << endl;
    ec.display(cout);
    const Screen ecr = ec;
    cout << endl;
    //ecr.display(cout).move(10, 4); // ==> ERREUR car display est la version const
    ecr.display(cout);
    cout << endl << endl;
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << "\n";

    return 0;
}
