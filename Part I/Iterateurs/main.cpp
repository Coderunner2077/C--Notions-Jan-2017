#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std :: cout; using std :: cin; using std :: endl; using std :: string; using std :: vector;

int main()
{
    string word = "Abricot";
    /*
    for(auto c = word.begin(); c != word.end(); c++)
        *c = toupper(*c);
    */
     for(string :: iterator c = word.begin(); c != word.end(); c++)
        *c = toupper(*c);
    cout << word << endl;
    vector<int> ivec(10, 4);
    for(vector<int> :: iterator i = ivec.begin(); i != ivec.end(); ++i)
        cout << *i << endl;
    vector<string> svec(10, "Hello !");
    /*
    for(vector<string> :: iterator s = svec.begin(); s!= svec.end(); ++s){
        for(string :: iterator c = s->begin(); c != s->end(); ++c)
            *c = toupper(*c);
        cout << *s << endl;
    }
    */

    /*
    for(vector<string> :: iterator s = svec.begin(); s!= svec.end(); ++s){
        for(string :: iterator c = (*s).begin(); c != (*s).end(); ++c)
            *c = toupper(*c);
        cout << *s << endl;
    }
    auto s = svec.end();
    s--;
    *s = "Good bye !";
    auto str = svec.begin();
    while(str != svec.end()){
         cout << *str << endl;
         str++;
    }
    */

    /*
    string phrase;
    vector<string> svec2;
    while(phrase.size() < 40){
        getline(cin, phrase);
        svec2.push_back(phrase);
    }
    for(auto s = svec2.begin(); s != svec2.end() && !s->empty(); ++s)
        for(auto c = s->begin(); c != s->end(); ++c)
            *c = toupper(*c);
    for(auto  s = svec2.begin(); s != svec2.end(); ++s)
        cout << *s << endl;

    */

    /*
    vector<int> intvec;
    int nb;
    while(intvec.size() != 9)
    {
        cin >> nb;
        intvec.push_back(nb);
    }
    for(auto i = intvec.begin(); i != intvec.end(); ++i)
    {
        *i *= *i;
        cout << *i << endl;
    }
    */
    /*
    vector<int> intvec;
    int nb;
    while(intvec.size() != 9)
    {
        cin >> nb;
        intvec.push_back(nb);
    }
    int print = 0, decrem = 0;
    auto deb = intvec.begin();
    auto fin = intvec.end();
    for(auto i = deb; i != fin; ++i)
    {
        print = *i + *(intvec.end() - 1 - decrem);
        cout << print << endl;
        print = 0;
        decrem++;
    }
    */

    /*
    vector<unsigned> unvec(11, 0);
    unsigned grade = 0;
    while( cin >> grade){
        if(grade <= 100){
            auto i = unvec.begin();
            i += (grade / 10);
            (*i)++;
        }
    }
    for(auto i = unvec.begin(); i != unvec.end(); ++i)
        cout << *i << endl;

    */

    /*
    // Binary search
    vector<string> text(10000);
    string mot = "";
    for(auto i = text.begin(); i != text.end(); ++i){
          mot += 'a';
          *i = mot;
    }

    string sought = "a";
    auto beg =  text.begin();
    auto fin = text.end();
    auto mid = beg + (fin - beg) / 2;
    while(mid != fin && *mid != sought){
        if(sought < *mid)
            fin = mid;
        else
            beg = mid + 1;
        mid = beg + (fin - beg)/2;
        cout << *mid << endl;
    }
    cout << *mid << endl;
    */

    vector<int> :: difference_type diff = ivec.end() - ivec.begin();
    cout << diff << endl;
    //vector<int> :: difference_type n'est pas un unsigned, il peut prendre des valeurs négatives

    return 0;
}
