#include <iostream>
#include "Sales_item.h"



int main()
{
    /*
    Sales_item book;
    Sales_item books[100];

    int index = 0;

    while(std :: cin >> book)
    {
        books[index] = book;
        std :: cout << books[index] << std :: endl;
        index++;
    }


    Sales_item book1, book2;
    std :: cin >> book1 >> book2;
    if(book1.isbn() == book2.isbn())
        std :: cout << book1 + book2 << std :: endl;
    else
        std :: cout << "On n'ajoute pas des pommes et des poires" << std :: endl;
    */
    bool continuer = true;
    Sales_item item, item2, result;
    std :: cout << "Entrez le numero ISBN, la quantite ainsi que le prix unitaire" << std :: endl;
    std :: cin >> item >> item2;
    result = item + item2;
    std :: cout << "resultat : " << result << std :: endl;
    while(continuer){
        std :: cout << "Entrez le meme numero ISBN (" << item.isbn() << "), ainsi qu'une quantite donnee et le prix unitaire" << std :: endl;
        std :: cin >> item2;
        if(item.isbn() != item2.isbn()){
            continuer = false;
            std :: cout << "Vous tentez d'entrer un produit différent" << std :: endl;
        }
        else
        {
            item += item2;
            std :: cout << "La somme des transactions : " << item << std :: endl;
        }
    }



    return 0;
}
