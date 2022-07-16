#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

using std :: cout; using std :: cin; using std :: endl; using std :: string; using std :: end; using std :: runtime_error;

int main()
{
    //STATEMENTS

    /*
    string mot = "Abricot";


    goto end;
    while(cin >> mot && mot != "stop");
    //dangling else
    if(mot.size() < 30)
        if(mot[0] == 'a')
            cout << "primo alpha" << endl;
        else
            cout << "primo altra" << endl;
    mot = "";
    while(getline(cin, mot) && mot != "stop"){
        int cnt = 0, spc = 0, sqn = 0;
        bool f = false;
        if(mot[0] != 's')
            continue;
        for(auto i = mot.begin(); i != mot.end(); ++i){
            if(isupper(*i))
                *i = tolower(*i);
            else if(isspace(*i))
                ++spc;
            switch(*i){
                case 'a': case 'e' :  case 'o' : case 'y' : case 'u' :
                    int ival; //ERROR IF ival INITIALISED
                    ++cnt;
                    f = false;
                    break;
                case 'f' :
                    if((*(i - 1) == 'f' && *(i - 2) != 'f') || (*(i - 1) == 'f' && *(i - 2) == 'f' && *(i - 3) == 'f' && *(i - 4) != 'f')
                       ||(*(i - 1) == 'f' && *(i - 2) == 'f' && *(i - 3) == 'f' && *(i - 4) == 'f' && *(i-5) == 'f')){
                        ++sqn;
                    }
                    else
                        f = true;
                    break;
                case 'l' :
                    if(f)
                        ++sqn;
                    f = false;
                    break;
                case 'i' :
                    ++cnt;
                    if(f)
                        ++sqn;
                    f = false;
                    break;
                default :
                    f = false;
                    break;
            }
        }

        cout << cnt << " vowels" << endl;
        cout << spc << " white-space caracters" << endl;
        cout << sqn << " sequences ff, fl ou fi" << endl;
    }

    end :
    string word;

    while(cin >> mot >> word){
        cout << "Entrer deux mots identiques" << endl;
        if(mot == word && isupper(mot[0])){
            cout << "Mot repete : "  << mot << endl;
            break;
        }
        else
            cout << "Mots pas identiques";

    }

    //goto begin;
    */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // EXCEPTIONS
    double ival = 0, ival2 = 0;
    while(cin >> ival >> ival2){
        begin :
        double result;

        try{
            if(!ival2)
                throw runtime_error("Attention, vous tentez une division par zero !");
            result = ival / ival2;
            cout << "resultat : " << result << endl;
        }catch(runtime_error err){
            cout << err.what();
            cout << "Entrer une autre valeur pour le second nombre ?" << endl;
            string rep;
            cin >> rep;
            rep[0] = toupper(rep[0]);
            if(rep[0] != 'N' && rep[0] == 'O'){
                cin >> ival2;
                goto begin;
            }
            else
                break;

        }
    }
    return 0;
}
