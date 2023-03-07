#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void test_vector1()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    vector<int> v1(v);

    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

void test_vector2()
{
    vector<int> v(10, 1);
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    vector<int> v1(v.begin(), v.end());
    for (auto e : v1)
    {
        cout << e << " ";
    }
    cout << endl;

    string       s("hello world");
    vector<char> v3(s.begin(), s.end());
    for (auto e : v3)
    {
        cout << e << " ";
    }
    cout << endl;

    vector<char>::reverse_iterator rit = v3.rbegin();
    // auto rit = v.rbegin();
    while (rit != v3.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
}

void test_vector3()
{
    vector<int> v({1, 2, 3, 4, 5});
    cout << v.size() << endl;
    cout << v.max_size() << endl;
    cout << v.capacity() << endl;

    vector<int> v1(10, 0);
    v1.resize(5, 0);

    vector<int> v2(10);
    v2.resize(10);
}

void test_vector_expand()
{
    vector<int> v;
    size_t      sz    = v.capacity();
    size_t      n     = 1000000;
    size_t      begin = clock();
    v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        v.push_back(i);
        if (sz != v.capacity())
        {
            sz = v.capacity();
            cout << sz << endl;
        }
    }
    size_t end = clock();
    cout << "count time: " << end - begin << endl;
}


//int main()
//{
//    // test_vector1();
//    // test_vector2();
//    test_vector3();
//    // test_vector_expand();
//    return 0;

class Solution {
    vector<string> num2str
        = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    // 23
    //
    // a b c
    // d e f
public:
    void combine(string& digits, int i, string combine_str, vector<string>& sv) {
        if (i == digits.size()) {
            sv.push_back(combine_str);
            cout << combine_str << endl;
            return;
        }

        string str = num2str[digits[i] - '0'];
        for (auto ch : str) {
            combine(digits, i + 1, combine_str + ch, sv);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> sv;
        if (digits.size() == 0) {
            return sv;
        }
        combine(digits, 0, "", sv);
        return sv;
    }
};

// int main()
// {
//     Solution().letterCombinations("23");
// }