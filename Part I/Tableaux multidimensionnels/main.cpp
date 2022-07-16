#include <iostream>
#include <vector>

using std :: cin; using std :: cout; using std :: endl; using std :: vector;
using std :: begin; using std :: end;

int main()
{
    //Initialisation
    int tab[3][4] = {{2}, {9}, {7}}; // chaque ligne commence par ces nombres, les autres = 0
    int tab2[3][4] = {1, 2, 3, 4}; // ==> première ligne, les autres = 0
    int tab3[4][10][35] = {0};
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
        };
    for(int (&row)[4] : ia){
        for(const int &i : row)
            cout << i << " ";
        cout << endl;
    }

    for(int (&row)[4] : tab){
        for(const int &i : row)
            cout << i << " ";
        cout << endl;
    }

    for(int (&row)[4] : tab2){
        for(const int &i : row)
            cout << i << " ";
        cout << endl;
    }
    cout << endl << endl;

    for(int (&z)[10][35] : tab3){
        for(int (&row)[35] : z){
            for(int &i : row)
                cout << i << " ";
            cout << endl;
        }
        cout << ",";
    }
    cout << endl << endl;

    for(size_t row = 0; row != 3; row++){
        for(size_t col = 0; col != 4; col++){
            cout << ia[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Avec les pointeurs : " << endl;
    for(int (*row)[4] = ia; row != ia + 3; ++row){
        for(int *i = *row; i != *row + 4; ++i)
            cout << *i << " ";
        cout << endl;
    }

    //Using alias
    cout << endl << endl;
    using int_array = int[4];
    for(int_array *row = ia; row != ia + 3; ++row){
        for(int *col = *row; col != *row + 4; ++col){
            cout << *col << " ";
        }
        cout << endl;
    }

    return 0;
}
