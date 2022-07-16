#include <iostream>
#include <string>
#include <cctype>

using std :: cin; using std :: cout; using std :: endl; using std :: string;

int main()
{
    //Initialisation

    string s1; // initialisation par défaut (un string vide)
    string s2 = s1; // initialisation - copie
    string s3(s2); // direct initialization
    string s4 = "un string";
    string s5("2e string");
    string s6(10, 'c'); // initialisation directe
    string s7 = string(8, 'd'); // initialisation - copie

    cout << s4 << endl << s5 << endl;
    cout << s6 << endl << s7 << endl;

    cin >> s1 >> s2;
    cout << s1 << s2 << endl;
    int nb = 9;
    if(!s1.empty()){
        string phrase = s1 + ", which is a string, plus a literal : " + " litt. " + "9";
        cout << phrase << endl;
    }

  // string phrase2 = "une expression littérale, plus une autre " + ": " + phrase;
   // string s8 = "bonjour " + "toi" ;
    string mot = "Lettres";
    cout << "Longueur du mot " << mot << " : " << mot.size() << endl;
    decltype(mot[0]) L = mot[0]; // mot[0] renvoie une référence du 1er caractère
    L = 'p';
    cout << mot << endl;
    string mot1 = "abricot", mot2 = "apricot", mot3 = "bouc";
    if(mot1 < mot2)
        cout << mot1 << " est plus petit que " << mot2 << endl;
    if(mot3 > mot1 && mot3 > mot2)
        cout << mot3 << " est plus grand que " << mot1 << " et " << mot2 << endl;
    string :: size_type longueur = mot3.size();
    auto length = mot3.size();
    decltype(mot3.size()) length2 = mot2.size();
    //string :: size_type est un unsigned spécial (pour donner la longueur d'un string)
    /*
    string phrase2;
    while(getline(cin, phrase2)) // lit une ligne (y compris les espaces)
        cout << phrase2 << endl;
    string premier;

    while(cin >> premier){ // EXERCICE 3.5
        cin >> mot;
        premier += " " + mot;
        cout << premier << endl;
    }
    */

    char c = 'd';
    if(isalnum(c))
        cout << c << " est alphanumerique" << endl;
    if(isalpha(c))
        cout << c << " est une lettre" << endl;
    if(!isdigit(c))
        cout << c << " n\'est pas un nombre" << endl;
    if(!isspace(c))
        cout << c << " n\'est ni un espace, ni un caractere d\'echappement" << endl;
    if(isprint(c))
        cout << c << " est un caractere imprimable (un espace ou un caractere visualisable)" << endl;
    if(isgraph(c))
        cout << c << " n\'est pas un espace, mais un caractere imprimable" << endl;
    if(!ispunct(c))
        cout << c << " n\'est pas un point de ponctuation" << endl;
    if(isxdigit(c))
        cout << c << " est aussi un nombre hexadecimal" << endl;
    if(!iscntrl(c))
        cout << c << " n\'est pas un caractere d\'echappement" << endl;
    if(islower(c)){
        cout << c << " est un caractere minuscule" << endl;
        toupper(c);
    }
    else
        tolower(c);

    string word("Hello word !");
    for(char &r : word) //a range for
        if(isalpha(r))
            r = toupper(r);
    cout << word << endl;
    for(decltype(word.size()) index = 0; index != word.size() && !isspace(word[index]); index++)
        word[index] = tolower(word[index]);
    cout << word << endl;
    for(auto &c : word)
        c = 'X';
    cout << word << endl;
    decltype(word.size()) index = 0;
    while(index != word.size()){
        word[index++] = 'Y';
    }
    cout << word << endl;
    for(decltype(word.size()) i = 0; i != word.size(); i++)
        word[i] = 'Z';
    cout << word << endl;
    string vide;
    cout << vide[0] << endl; // JAMAIS CA, CAR OUT-OF-RANGE
    word = "Point.Virgule,Point-virgule;0";
    index = 0;
    string newWord;
    for(auto &c : word){
        if(!ispunct(c)){
            newWord += c;
        }
        index++;
    }
    word = newWord;
    cout << word << endl;
    const string unMot = "Keep out!";
    for(auto &c : unMot){
        /*
        ...
        */
    }
    return 0;
}
