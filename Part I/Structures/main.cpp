#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    Sales_data total, trans;
    double price = 0, t_price = 0;
    if(std :: cin >> total.bookNo >> total.units_sold >> price){
        total.revenue = total.units_sold * price;
        std :: cout << "Enrez le numero ISBN, la quantite et le prix" << std :: endl;
        while(std :: cin >> trans.bookNo >> trans.units_sold >> t_price)
        {
            trans.revenue = trans.units_sold * t_price;
            if(total.bookNo == trans.bookNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
                price = total.revenue / total.units_sold;
            }
            else
            {
                std :: cout << "total : " << total.bookNo << " " << total.units_sold << " " << total.revenue
                        << " " << price << std :: endl;
                        total = trans;
            }
            std :: cout << "Enrez le numero ISBN, la quantite et le prix" << std :: endl;
        }
         std :: cout << "total : " << total.bookNo << " " << total.units_sold << " " << total.revenue
                        << " " << price << std :: endl;
    }
    else
    {
        std :: cerr << "Entree invalide ! " << std :: endl;
        return -1;
    }

    return 0;
}
