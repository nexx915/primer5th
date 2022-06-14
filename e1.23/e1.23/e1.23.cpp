#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item sum, item1;
    int trans_amount = 0;

    while (std::cin >> item1) {
        trans_amount++;
        sum += item1;
        std::cout << "sum: " << sum << std::endl;
        std::cout << "trans_amount: " << trans_amount << std::endl;
    }
        return 0;
}
