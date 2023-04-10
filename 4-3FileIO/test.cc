#include <iostream>

int main()
{
    printf("hello printf\n");
    fprintf(stdout, "hello fprintf->stdout\n");
    fprintf(stderr, "hello fprintf->stderr\n");

    std::cout << "hello cout" << std::endl;
    std::cerr << "hello cerr" << std::endl;


    return 0;
}
