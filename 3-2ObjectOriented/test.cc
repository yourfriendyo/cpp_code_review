#include <iostream>
using namespace std;

int main()
{
  int a = 0;
  int &b = a;
  int &c = b;

  cout << &a << endl;
  cout << &b << endl;
  cout << &c << endl;

  return 0;
}
