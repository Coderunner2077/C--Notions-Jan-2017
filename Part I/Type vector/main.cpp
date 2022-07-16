#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std :: vector; using std :: cin; using std :: cout; using std :: endl; using std :: string;

int main()
{
    vector<int> ivec;
    vector<vector<int>> file; //vector dont les elements sont des vectors
    //ancienne notation : vector<vector<int> > file; (avec un espace...)
    //Initialisation
    vector<string> svec; //default initialization with no elements;
    //apres avoir ajouté des éléments à svec :
    vector<string> svec2(svec); //copie les éléments de svec dans svec2
    vector<int> ivec2 = ivec; //copie les éléments d'ivec dans ivec2
    //vector<string> svec3(ivec); ==> ERROR (types...)
    vector<string> svec3 = {"un", "deux", "trois"}; // LISTE-INITIALISATION
    for(string mot : svec3)
        cout << mot << endl;
        vector<string> svec4{"quatre", "cinq"}; //LISTE-INITIALISATION
    vector<int> ivec3(10, -1); // dix integers avec pour valeur -1
    vector<int> ivec4(10); //dix integers initialisés par défaut (0)
    for(int i : ivec4)
        cout << i;
    cout << endl;
    vector<string> svec5(5, "Hi"); //CINQ strings contenant "Hi"

    //si le compilateur n'arrive pas à faire une liste-initialisation avec les valeurs données, il se tourne vers d'autres
    //moyens d'initialisations :
    vector<string> svec6{6}; // équivalent à vector<string> svec6(6)
    vector<string> svec7{10, "Curly braces and yet not list-initialization !"};
    vector<string> svec8{svec7};
    for(string mot : svec8)
        cout << mot << endl;

    // EXERCICES

    /*
    while(cin >> number)
        ivec.push_back(number);
    for(auto nb : ivec)
        cout << nb << " ";
    cout << endl;
    */
    /*
    string mot;
    while(cin >> mot)
        svec.push_back(mot);

    for(string &word : svec)
        for(auto &c : word)
            c = toupper(c);
    */
    /*
    for(vector<string> :: size_type i = 0; i < svec.size(); i++)
        for(auto &c : svec[i])
            c = toupper(c);
    for(vector<string> :: size_type i = 0; i != svec.size(); ++i){
        if(i != (svec.size() - 1))
            cout << svec[i] << ", ";
        else
            cout << svec[i] << ".";
        if(i != 0 && (i % 8) == 0)
            cout << endl;
    }
    */
    int number = 0;
    while(cin >> number)
        ivec.push_back(number);
    int print = 0;
    /*
    for(decltype(ivec.size()) i = 0; i != ivec.size(); ++i){
        print += ivec[i];
        if(i && !((i + 1) % 2)){
            cout << print << endl;
            print = 0;
        }
    }
    */
    /*
    for(decltype(ivec.size()) i = 0; i <= (ivec.size() - 1 - i) && i != ivec.size(); ++i){
        if(i != (ivec.size() - 1 - i))
            print = ivec[i] + ivec[ivec.size() - 1- i];
        else
            print = ivec[i];
        cout << print << endl;
        print = 0;
    }
    */
    return 0;
}
