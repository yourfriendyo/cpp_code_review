#include <iostream>
using namespace std;

class A
{
public:
    A(int) { cout << "A(int)" << endl; }
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }

private:
    int a;
};

// int main()
// {
//     A* pA = (A*)operator new(sizeof(A));
//     new (pA) A;
//     new (pA) A(1);
//     return 0;
// }

// int main()
// {
//     A* p = new A[2];
// 	delete[] p;
//     // delete p;
// 	// free(p);
// }
//
// int main()
// {
//     A* p = new A;
// 	delete[] p; // 死循环调用析构
//     delete p;
// 	free(p);
// }
//
// int main()
// {
//     A* p = (A*)malloc(sizeof(A) * 4);
//     delete[] p; // 死循环调用析构
//     delete p;
//     free(p);
// }

// int main()
// {
//     int num = 4;
//
//     A*   p1 = (A*)malloc(sizeof(A));
//     A* p2 = new A;
//
//     if (num == 1)
//     {
//         free(p1);
//         delete p2;
//     }
//     else if (num == 2)
//     {
//         delete p1;
//         free(p2);
//     }
//     else if (num == 3)
//     {
//         free(p1);
//         free(p2);
//     }
//     else if (num == 4)
//     {
//         delete p1;
//         delete p2;
//     }
//
//     return 0;
// }