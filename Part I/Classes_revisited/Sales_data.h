#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED
//ATTENTION, LES DEFINITIONS DE FONCTIONS NON-INLINE ET AINSI QUE CELLES DES MEMBRES STATIQUES NORMALEMENT SE FONT DANS DES
//FICHIERS .c (ou .cc, .ccp, etc.)

class Sales_data {
     //friend declarations for non-member Sales_data operations added
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream& read(std::istream&, Sales_data&);
    friend std::ostream& print(std::ostream&, const Sales_data&);
    public:
    //constructors
    //Sales_data() = default;
    Sales_data(const std::string s) : bookNo(s) {} //constructor initializer list (autres : in-class initializers or default init...)
    //Sales_data(const std::string s) : bookNo(s), units_sold(0), revenue(0) {} // if the compiler doesn't support in-class init.
    //Sales_data(const std::string s = "") : bookNo(s) {} // 2 in 1
    Sales_data(const std::string s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(u*p) {}
    explicit Sales_data(std::istream &is = std::cin) { read(is, *this); }
    //new members : operations on Sales_data
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    private:
    double avg_price() const { return units_sold ? revenue / units_sold : 0; }
    //data members
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
/*
//Constructeur défini en dehors de la classe
Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}
*/

//declarations of non-member functions
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
std::istream& read(std::istream &is, Sales_data &lhs);
std::ostream& print(std::ostream &os, const Sales_data &lhs);

//definition of member functions
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
/*
double Sales_data::avg_price() const
{
    if(units_sold)
        return revenue / units_sold;
    else
        return 0;
}
*/

//definition of non-member functions
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &lhs)
{
    double price = 0;
    is >> lhs.bookNo >> lhs.units_sold >> price;
    lhs.revenue = lhs.units_sold * price;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &lhs)
{
    os << lhs.isbn() << " " << lhs.units_sold << " "
       << lhs.revenue << " " << lhs.avg_price();
    return os;
}


#endif // SALES_DATA_H_INCLUDED
