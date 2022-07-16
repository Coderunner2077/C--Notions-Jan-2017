#include <iostream>
#include <vector>
#include <string>

using std :: cin; using std :: cout; using std :: endl; using std :: vector; using std :: string;
int* getPtr(){
    int nb = 9;
    return &nb;
}
int main()
{
    int ival = 5 + 10 * 20 / 2;
    cout << ival << endl;
    vector<int> ivec(10, 1);
    ivec[2] = 9;
    cout << *(ivec.begin() + 2) << endl; // function has a higher precedence than dereference pointer
    // L'ordre d'évaluation :
    /*
     Soit :
    int nb = fct1() + fct2() + fct3();
    L'ordre d'évaluation de ces fonctions est indéfinie. C'est pas grave, sauf si de plus elles sont interdépendantes, car le
    résultat sera alors indéfini.

    */


    // Unary plus and unary minus
    //unary plus peut aussi s'appliquer aux pointeurs
    ival = -ival;
    cout << ival; // unary minus returns the result of negating a (possibly promoted) copy of the value of its operand

    // MODULOS
    int mod = 1 % 2;
    cout << " 1 % 2 = " <<  mod << endl;
    int number = ((12 / 3) * 4) + (5 * 15) + ((24 % 4) /2); // même résultat sans les parenthèses
    cout << number << endl;
    cout << (-30 * 3 + 21 / 5) << endl;
    cout << (-30 + 3 * 21 / 5) << endl;
    cout << (30 / 3 * 21 % 5) << endl;
    cout << (-30 / 3 * 21 % 4) << endl;
    number = (-3) % 2; // = - 1
    number = -(3 % 2); // équivalent à (-3) % 2
    number =  3 % (-2); // = 1; pas -1
    cout << number << endl;
    /*
    while(cin >> number){
        if(number % 2)
            cout << number << " est impair" << endl;
        else
            cout << number << " est pair" << endl;
    }
    */


    number = -1;
    bool tourou = false;
    tourou = number; // number is a non - zero, so it yields 1
    if(tourou)
        cout << number << endl;
    if(number == true); // vrai seulement si number est égal à 1 (car true converti en 1)

    const char* cp = "Hello world !";
    if(cp && *cp)
        cout << "cp est un pointeur non null pointant sur une valeur non-nulle" << endl;

    while(cin >> number && number != 42);

    int a = 10, b = 8, c = 4, d = 2;
    if(a > b && b > c && c > d)
        cout << "a + grand que b, b + gd que c, c + gd que d" << endl;

    // <, >, <=, >= havent a little bit higher precedence that == and !=
    if(d != b < a)
        cout << d << " est different de " << (b < a) << endl;
    double dval;
    number = dval = 3.354; //ASSIGNMENT IS RIGHT ASSOCIATIVE (i.e. from right to left)
    cout << number << endl;

    //With += sort of operator, a number is evaluated once (not two)
    if(number = 45) // 45 est assigné à number, cond ==> si number est différent de 0
        cout << "ne pas confondre assignment et equality" << endl;
    //if(45 = number); // ERREUR CAR l'opérande de gauche doit être une lvalue, pas une rvalue
    int *p = &number, nb;

    dval = nb = *p = 8.43;
    cout << dval << endl;
    p = nullptr;
    if((p = getPtr()) != 0)
        cout << "assignement has very low precedence (lower than equality and inequality)" << endl;
    int i = 0, j = 0, tablo[3] = {1, 2, 3}, *ptr = tablo;
    int k1 = ++i;
    int k = j++;
    cout << "postfix increment : " << k << endl; //higher precedence thant prefix increment, but return an rvalue
    cout << "prefix increment : " << k1 << endl; // return an lvalue

    while(ptr && *ptr++ && (ptr - tablo) < 3)
        cout << *ptr << endl;
    if(i++ && i)
        cout << "Dans une expression avec &&, la deuxième condition n'est evaluee que si la premiere condition est verifiee"
             << endl;
    vector<string> svec(10, "Hello");
    svec[3] = "Bye";
    vector<string> :: iterator it = svec.begin();
    while((it != svec.end()) && !(it++->empty()))
        cout << *(it - 1) << endl;
    /*
    //EXO
    while(cin >> i)
        ivec.push_back(i);
    for(vector<int> :: iterator iter = ivec.begin(); iter != ivec.end(); ++iter){
        if(!(*iter % 2))
            *iter *= 2;
        cout << *iter << endl;
    }
    */
    /*

    unsigned int grade;
    cin >> grade;
    string note;
    if(grade <= 100)
        note = (grade >= 90) ? "High pass" : (grade >= 60 && grade <= 75) ? "Low pass" : (grade >=50) ? "Pass" : "Fail";
    if(grade <= 100){
        if(grade >= 90)
            note = "high pass";
        else if(grade >= 60 && grade <= 75)
            note = "low pass";
        else if(grade < 50)
            note = "fail";
        else
            note = "pass";
    }
    cout << note << endl;
    string word = "word";
    string s = word + (word[word.size() - 1] == 's' ? "" : "s"); // + (addition) has higher precedence than ==
    cout << s << endl;
    */
    // bitwise operators : &, |, ~, ^

    char car = 0b01110001;
    cout << car << endl;
    car = ~car << 6; // ~ HAS A HIGHER PRECEDENCE THAN <<
    cout << car << endl;
    char c2 = 0b10001110000000; // = car (après ~car << 6)
    cout << c2 << endl;
    unsigned long ul1 = 3, ul2 = 7, ul3 = ul1 & ul2, ul4 = ul1 | ul2;
    cout << ul3 << " " << ul4 << endl;
    unsigned long quiz1 = 0b000000000000000;
    quiz1 |= 1UL << 2;
    quiz1 |= 1UL << 6;
    quiz1 |= 1UL << 10;
    quiz1 |= 0UL << 12;
    cout << quiz1 << endl;
    quiz1 &= ~(1UL << 2);
    cout << quiz1 << endl;
    bool pass = quiz1 & (1UL << 2);
    cout << "student 2 : " << pass << endl;
    pass = quiz1 & (1UL << 6);
    cout << "student 6 : " << pass << endl;
    pass = quiz1 & (1UL << 10);
    cout << "student 10 : " << pass << endl;
    pass = quiz1 & (1UL << 12);
    cout << "student 12 : " << pass << endl;
    pass = quiz1 & (1UL << 5);
    cout << "student 5 : " << pass << endl;

    // sizeof
    int x[10], *p2 = x;
    cout << "taille du tableau : " << sizeof(x) / sizeof(*x) << endl; //for sizeof, x is not a pointer, but an array
    cout << "irrelevant : " << sizeof(p) / sizeof(*p) << endl << endl << endl << endl;

    vector<int> ivec2(10, 1);
    vector<int> :: size_type cnt = ivec2.size();
    for(vector<int> :: size_type ix = 0; ix != ivec2.size(); ++ix, --cnt){
        ivec2[ix] = cnt;
        cout << ivec2[ix] << " ";
    }
    cout << endl;

    vector<int> ivec3(10, 1);
     cnt = ivec3.size();
    for(vector<int> :: size_type ix = 0; ix != ivec3.size(); ix++, cnt--){
        ivec3[ix] = cnt;
        cout << ivec3[ix] << " ";
    }
    cout << endl;

    int iv = 0, iv2 = 0;
    bool tourout = true;
    tourout ? (++iv, ++iv2) : --iv2, --iv; // --iv executed anyways
    cout << iv << " " << iv2;
    // COMMA HAS THE LOWEST PRECEDENCE

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //CONVERSIONS
    float fval = - 3.34F;
    dval = fval + ival;
    unsigned int ui = 80;
    cout << endl << dval << endl;
    fval = ui + ival * 1.0;
    cout << fval << endl;
    fval = 1.206;
    dval = ui * fval;
    cout << dval << endl;
    char cval = 'a' + 3;
    ival = fval = dval = 2.5;
    cval = ival + fval + dval;
    cout << cval << endl;
    ival = cval;
    cout << ival << endl;

    //static_cast<type> change le type
    //const_cast<type> change le constness
    //reinterpret_cast<type> performs a low-level reinterpretation of the bit pattern of its operands (à utiliser avec les
            //pointeurs ??)
    ival = dval = 2.5;
    ival *= static_cast<int>(dval);

    cout << ival << endl;

    const string word = "mot", *ps = &word;
    char *pc = "wesch", *pc2 = "dOREMI";
    void *pv = nullptr;
    string word2 = static_cast<string>(pc);
    cout << word2 << endl;
    //pv = static_cast<void*>(const_cast<string*>(ps));
    pv = reinterpret_cast<void*>(const_cast<string*>(ps)); // équivalent à pv = (void*)ps;
    cout << pv << " " << ps << endl;
    ival = static_cast<int>(*pc); // équivalent à ival = int(*pc);
    cout << ival << endl;
    pv = reinterpret_cast<double*>(&dval); // équivalent à pv = &dval
    cout << pv << " " << &dval << endl;
    double *pd = reinterpret_cast<double*>(pv);
    cout << *pd << endl;
    pc = reinterpret_cast<char*>(pv); // pc = (char*)pv;    ...enfin, je pense
    dval = static_cast<double>(5/2); // = 4
    cout << dval << endl;

    return 0;
}
