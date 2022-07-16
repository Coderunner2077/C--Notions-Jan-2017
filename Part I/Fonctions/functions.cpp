#include "functions.h"

int f()
{
    static int i = 0;
    return i++;
}

int fact(int n)
{
    int res = 1;
    while(n > 1)
        res *= n--;
    return res;
}


unsigned abs(int n)
{
    if(n < 0)
        n = -n;
    unsigned m = n;
    return m;
}

void swapF(int *val, int *val2)
{
    if(*val == *val2)
        return;

    int temp = *val;
    *val = *val2;
    *val2 = temp;
}

void swapF(int &val, int &val2)
{
    if(val == val2)
        return;
    int temp = val;
    val = val2;
    val2 = temp;
}

void doesNothing(int nombre)
{
    nombre *= 500;
}

string :: size_type find_char(const string &s, char c, string :: size_type &occurs)
{
    string :: size_type pos = s.size();
    occurs = 0;
    for(decltype(pos) i = 0; i != s.size(); ++i){
        if(s[i] == c){
            if(pos == s.size())
                pos = i;
            ++occurs;
        }
    }
    return pos;
}

int compare(const int nb1, const int* nb2)
{
    return (nb1 > *nb2) ? nb1 : *nb2;
}

void print(const int tab[], size_t taille)
{
    for(size_t i = 0; i != taille; ++i)
        cout << tab[i] << " ";
    cout << endl;
}

void print(const int *beg, const int *fin)
{
    while(beg != fin)
        cout << *beg++ << " ";
    cout << endl;
}

void print(const int (&arr)[10])
{
    for(auto elem : arr)
        cout << elem << " ";
    cout << endl;
}


int (*return_pointer_to_array(int (&tab)[10]))[10]
{
    int (*pt)[10] = &tab;
    for(size_t i = 0; i != 10; ++i)
        (*pt)[i] = i;
    return pt;
}

void print(const int (*pArr)[10])
{
    for(size_t i = 0; i != 10; ++i)
        cout << (*pArr)[i] << " ";
    cout << endl;
}

void print(initializer_list<int> li)
{
    for(auto i = li.begin(); i != li.end(); ++i)
        cout << *i << " ";
    cout << endl;
}

void print(vector<int> vec)
{

    cout << vec[0] << " ";
    vector<int> v;
    for(auto i = vec.begin() + 1; i != vec.end(); ++ i)
        v.push_back(*i);
    if(v.size() > 1)
        print(v);
    else
        cout << v[0] << endl;
}
int sum(initializer_list<int> liste)
{
    int sum = 0;
    for(auto i = liste.begin(); i != liste.end(); ++i)
        sum += *i;
    return sum;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

int divide(int nb, int nb2)
{
    int result = 0;
    try{
        if(!nb2)
            throw runtime_error("Division par zero !");
        result = nb / nb2;
    }catch(runtime_error err){
        result = 0;
    }
    return result;
}







