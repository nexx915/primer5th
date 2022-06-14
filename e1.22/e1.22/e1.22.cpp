#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item sum, item1;

    while (std::cin >> item1) {
        std::cout << item1 << std::endl;
        sum += item1;
        std::cout << "sum: " << sum << std::endl;
    }
    return 0;
}
