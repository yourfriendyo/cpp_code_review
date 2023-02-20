#include <iostream>
#include <string>
using namespace std;

void test4()
{
    string s1 = "hello";
    string::iterator it = s1.begin();
    while (it != s1.end())
    {
        cout << *it << " ";
		++it;
	}
	cout << endl;

    for (auto& ch : s1)
    {
        cout << ch << " ";
	}
	cout << endl;

    string s2 = "hello world";
    string::iterator it2 = s2.begin();
    while (it2 != s2.end())
    {
        cout << *it2;
        ++it2;
	}
	cout << endl;
}


void test3()
{
    string s1 = "hello";
	cout << s1 << endl;
	cout << s1.capacity() <<endl;

    s1.reserve(20);
	cout << s1 << endl;
	cout << s1.capacity() <<endl;

    s1.resize(50, 'x');
	cout << s1 << endl;
	cout << s1.capacity() <<endl;

    s1.resize(5);
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() <<endl;
}

void test2()
{
    string s1 = "hello";
    s1.push_back('*');
    cout << s1 << endl;

    s1.append("world");
    cout << s1 << endl;

    s1 += " my name is yy";
    cout << s1 << endl;

    s1 += 'o';
    cout << s1 << endl;
}

void test1()
{
    string s1;
    string s2("hello string");
    string s3 = "hello string";
    string s4(s3, 0, 5);
    string s5(s3, 0);
    string s6(s3, 0, 25);
    string s7(10, '*');

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    cout << s7 << endl;

    cout << string::npos << endl;

    cout << s2.size() << endl;
    cout << s2.length() << endl;
    cout << s2.max_size() << endl;
    cout << s2.capacity() << endl;
}


int main()
{
    // test1();
    // test2();
	// test3();
	test4();


    return 0;
}
