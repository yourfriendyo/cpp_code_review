#include <iostream>

using namespace std;

int main()
{
    extern char** environ;

    for (int i = 0; environ[i]; i++) 
    {
        std::cout << environ[i] << std::endl;
    }

    std::cout << "hello other proccess" << std::endl;
}

