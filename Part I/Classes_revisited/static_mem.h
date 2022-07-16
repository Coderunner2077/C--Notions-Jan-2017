#ifndef STATIC_MEM_H_INCLUDED
#define STATIC_MEM_H_INCLUDED
//ATTENTION, LES DEFINITIONS DE FONCTIONS NON-INLINE ET AINSI QUE CELLES DES MEMBRES STATIQUES NORMALEMENT SE FONT DANS DES
//FICHIERS .c (ou .cc, .ccp, etc.)
class Account {
public:
    Account(double amnt = val2) : amount(amnt) { }
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    //static double interestRate = 0; ==> ERREUR !
    static const unsigned period;
    static const unsigned val = 0;
    //static const double val2 = 0.0; //==> ERROR BCZ const, IN-CLASS INITIALIZED AND NOT INTEGRAL TYPE
    static const double val2;
    static constexpr unsigned deux = 2;
    static constexpr int stat_nb = 5; // Used only in contexts where the compiler may substitute the member's value
    static double initRate();
    int tableau[deux]; // OK CAR deux EST UNE EXPRESSION CONSTANTE
    static Account acc;
    //Account acc2; // ==> ERREUR (incomplete type)
};

void Account::rate(double newRate)
{
    interestRate = newRate;
}

double Account::initRate()
{
    interestRate = 1.5;
    return interestRate;
}

//double Account::interestRate = initRate(); //OK
double Account::interestRate = 0; //must be defined outside any function
unsigned const Account::val;
double const Account::val2 = 5.0;
constexpr unsigned Account::deux; //DEFINED SO THAT IT MAY BE USED NOT ONLY IN CONTEXTS WHERE THE COMPILER CAN SUBSTITUTE THE
                                // MEMBER'S VALUE

#endif // STATIC_MEM_H_INCLUDED
