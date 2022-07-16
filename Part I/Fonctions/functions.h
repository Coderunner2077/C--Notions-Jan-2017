#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <initializer_list>
#include <stdexcept>

using std :: string; using std :: vector; using std :: cout; using std :: endl;
using std :: begin; using std :: end; using std :: initializer_list;
using std :: runtime_error;

int f();
int fact(int n);
unsigned abs(int n);
void swapF(int *val, int *val2);
void swapF(int &val, int &val2);
void doesNothing(int nombre);
string :: size_type find_char(const string &s, char c, string :: size_type &occurs);
inline bool is_empty(const string& s){ return s.empty(); }
vector<int> :: iterator change_val(const int newValue, vector<int> :: iterator it);
int compare(const int nb1, const int* nb2);
void print(const int tab[], size_t taille);
void print(const int *beg, const int *fin);
void print(const int (&arr)[10]);
void print(const int *nb);
void print(const int (*pArr)[10]);
void print(initializer_list<int> li);
void print(vector<int> vec);
auto return_pointer_to_array(int (&tab)[10]) -> int (*)[10];
int sum(initializer_list<int> liste);
inline int &get(int *arr, size_t index){ return arr[index]; }
int *reset(int *);
double *reset(double *);
string screen(unsigned, unsigned = 80, char = ' ');
string make_plural(size_t ctr, const string &word, const string &ending = "s");
constexpr bool isShorter(int val,  int val2) { return val < val2; }

int calc(char*, char*);
int calc(const char*, const char*);

inline int multiply(int nb, int nb2) { return nb * nb2; }
inline int add(int nb, int nb2){ return nb + nb2; }
inline int substract(int nb, int nb2){ return nb - nb2; }
int divide(int, int);
int divide(int, int);


typedef int Func(int, int);
typedef int (*FuncP)(int, int);


int compute(string param, FuncP pt);
int compute(string param, Func pt); // idem : functions automatically converted in pointers (only for parameters)
int compute(string param, int(*pt)(int, int)); //idem

FuncP return_function_pointer(string arg);
Func *return_function_pointer(string arg); //idem : for compiler, function in return type is a function
auto return_function_pointer(string arg) -> int(*)(int, int); // idem
decltype(divide) *return_function_pointer(string args);// idem (decltype doesnt convert function to pointer
int (*return_function_pointer(string args))(int, int); //idem

#endif // FUNCTIONS_H_INCLUDED
