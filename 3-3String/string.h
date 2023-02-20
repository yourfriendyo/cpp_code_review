#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cassert>
using std::cout;
using std::endl;

namespace test
{
class string
{
public:
    typedef char*       iterator;
    typedef const char* const_iterator;

    iterator begin()
    {
        return _str;
    }

    iterator end()
    {
        return _str + _size;
    }

    const_iterator begin() const
    {
        return _str;
    }

    const_iterator end() const
    {
        return _str + _size;
    }

public:
    string(const char* str = "")
        : _size(strlen(str))
        , _capacity(_size)
    {
        _str = new char[_capacity + 1];
        strcpy(_str, str);
    }

    string(const string& s)
        : _size(s._size)
        , _capacity(s._capacity)
    {
        _str = new char[_capacity + 1];
        strcpy(_str, s._str);
    }

    string& operator=(const string& s)
    {
        if (this != &s)
        {
            char* tmp = new char[s._capacity + 1];
            strcpy(tmp, s._str);
            delete[] _str;
            _str = tmp;

            _size     = s._size;
            _capacity = s._capacity;
        }
        return *this;
    }

    ~string()
    {
        delete[] _str;
    }

    const char* c_str() const
    {
        return _str;
    }

    char& operator[](size_t pos)
    {
        assert(pos < _size);
        return _str[pos];
    }

    const char& operator[](size_t pos) const
    {
        assert(pos < _size);
        return _str[pos];
    }

    size_t size() const
    {
        return _size;
    }

    bool operator<(const string& s) const
    {
        return strcmp(_str, s._str) < 0;
    }

    bool operator==(const string& s) const
    {
        return strcmp(_str, s._str) == 0;
    }

    bool operator!=(const string& s) const
    {
        return !(*this != s);
    }

    bool operator<=(const string& s) const
    {
        return *this < s || *this == s;
    }

    bool operator>(const string& s) const
    {
        return !(*this <= s);
    }

    bool operator>=(const string& s) const
    {
        return !(*this < s);
    }

    void resize()
    {

    }

    void reserve(size_t n)
    {
        if (n <= _capacity)
            return;

        char* tmp = new char[n + 1];
        strcpy(tmp, _str);
        delete[] _str;
        _str = tmp;

        _capacity = n;
    }

    void push_back(char ch)
    {
        if (_size + 1 > _capacity)
            reserve(2 * _capacity);

        _str[_size++] = ch;
        _str[_size] = '\0';
    }

    void append(const char* str)
    {
        size_t len = strlen(str);
        if (_size + len > _capacity)
            reserve(_size + len);

        strcpy(_str + _size, str);
        _size += len;

        _str[_size] = '\0';
    }

    string& operator+=(char ch)
    {
        push_back(ch);
        return *this;
    }

    string& operator+=(const char* str)
    {
        append(str);
        return *this;
    }

    string& operator+=(const string& s)
    {
        append(s._str);
        return *this;
    }

private:
    char*  _str;
    size_t _size;
    size_t _capacity;
};

inline void test_string()
{
    string s;
    string s1("hello world");
    cout << s1.c_str() << endl;

    string s2(s1);
    cout << s2.c_str() << endl;

    string s3;
    s3 = s1;
    cout << s3.c_str() << endl;

    for (size_t i = 0; i < s1.size(); ++i)
    {
        s3[i]++;
        cout << s3[i] << " ";
        s3[i]--;
        cout << s3[i] << " ";
    }
    cout << endl;

    string::iterator it = s3.begin();
    while (it != s3.end())
    {
        (*it)++;
        cout << *it << ' ';
        ++it;
    }
    cout << endl;

    it = s3.begin();
    while (it != s3.end())
    {
        (*it)--;
        cout << *it << ' ';
        ++it;
    }
    cout << endl;

    for (auto ch : s3)
    {
        cout << ch << ' ';
    }
    cout << endl;

    const string s4 = "hello world";
    for (auto ch : s4)
    {
        cout << ch << ' ';
    }
    cout << endl;

    cout << (s1 < s2) << endl;
    cout << (s1 >= s2) << endl;
    cout << (s1 == s2) << endl;

    string s5 = "hello";
    s5 += ' ';
    s5 += "world";
    cout << s5.c_str() << endl;
}
} // namespace test
