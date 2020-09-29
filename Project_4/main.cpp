#include <iostream>
#include <vector>
#include "counthsw.h"

int main()
{
    std::vector<int> parameters = {4, 2, 1, 0, 0, 0, 3, 1};
    int result = countHSW( parameters[0], parameters[1], 1, 0, 0, 0, 3, 1);
    std::cout << result << "\n";
    return result;
}