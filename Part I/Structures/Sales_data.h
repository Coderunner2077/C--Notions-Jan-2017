#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED
struct Sales_data{
    std :: string bookNo;
    unsigned units_sold = 0; // C++11 (initialisation par défaut d'une classe)
    double revenue = 0;
}var1, var2;
//item et item2 sont deux objets de type Sales_data... A EVITER (car on combine la définition d'une classe et de variables...)

#endif // SALES_DATA_H_INCLUDED
