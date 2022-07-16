#include <iostream>



int main()
{
    int sum = 0;
    for(int val = 1; val <= 10; ++val){
        sum += val;
    }

    std :: cout << "La valeur de \"sum\" est egale a : " << sum << std :: endl;
    sum = 55;
    int sum2 = 55;
    if(++sum != sum2++)
        std :: cout << "En C++, il y a bien une difference entre \"++nombre\" et \"nombre++\", mais laquelle? " << std :: endl;

    int nb1 = 0, nb2 = 0;
    while(nb1++ < 5)
        std :: cout << "Valeur de nb++ : " << nb1 << std :: endl;
    while(++nb2 < 5 )
        std :: cout << "Valeur de ++nb : " << nb2 << std :: endl;
    std :: cout << "La même qu'en Java apparemment..." << std :: endl;


    return 0;
}
