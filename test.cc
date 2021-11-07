#include <iostream>

int main()
{
    bool p{true};
    int x = 0;

    while(p)
    {
        std::cout << "Hello: ";
        std::cin >> x;

        std::cout << x;
    }
}