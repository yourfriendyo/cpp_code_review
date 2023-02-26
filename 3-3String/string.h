#pragma once
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
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

    iterator begin() { return _str; }
    iterator end() { return _str + _size; }

    const_iterator begin() const { return _str; }
    const_iterator end() const { return _str + _size; }

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

    ~string()
    {
        delete[] _str;
        _size = _capacity = 0;
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

    const char* c_str() const
    {
        return _str;
    }

    size_t size() const
    {
        return _size;
    }

    size_t capacity() const
    {
        return _capacity;
    }

    char& operator[](size_t pos)
    {
        return _str[pos];
    }

    const char& operator[](size_t pos) const
    {
        return _str[pos];
    }

    void reserve(size_t n)
    {
        if (n > _capacity)
        {
            char* tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;

            _capacity = n;
        }
    }

    void resize(size_t n, char ch = '\0')
    {
        if (n <= _size)
        {
            _size       = n;
            _str[_size] = '\0';
        }
        else
        {
            if (n > _capacity)
                reserve(n);

            memset(_str + _size, ch, n - _size);
            _size       = n;
            _str[_size] = '\0';
        }
    }

    void clear()
    {
        _size       = 0;
        _str[_size] = '\0';
    }

    void push_back(char ch)
    {
        if (_size + 1 >= _capacity)
            reserve(_capacity == 0 ? 4 : _capacity * 2);

        _str[_size++] = ch;
        _str[_size]   = '\0';
    }

    void append(const char* str)
    {
        size_t len = strlen(str);
        if (_size + len >= _capacity)
            reserve(_size + len);

        strcpy(_str + _size, str);
        _size += len;
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

    string& insert(size_t pos, char ch)
    {
        assert(pos <= _size);

        if (_size + 1 >= _capacity)
            reserve(_capacity == 0 ? 4 : _capacity * 2);

        for (size_t i = _size + 1; i > pos; i--)
            _str[i] = _str[i - 1];

        _str[pos] = ch;
        _size++;
        return *this;
    }

    string& insert(size_t pos, const char* str)
    {
        assert(pos <= _size);

        size_t len = strlen(str);
        if (_size + len >= _capacity)
            reserve(_size + len);

        for (size_t i = _size + 1; i > pos; i--)
            _str[i + len - 1] = _str[i - 1];

        strncpy(_str + pos, str, len);
        _size += len;
        return *this;
    }

    string& erase(size_t pos = 0, size_t len = npos)
    {
        assert(pos < _size);

        if (len == npos || pos + len >= _size)
        {
            _size       = pos;
            _str[_size] = '\0';
        }
        else
        {
            strcpy(_str + pos, _str + pos + len);
            _size -= len;
        }
        return *this;
    }

private:
    char*  _str;
    size_t _size;
    size_t _capacity;

    static const size_t npos = -1;
};

std::ostream& operator<<(std::ostream& out, const string& s)
{
    for (auto ch : s) out << ch;
    return out;
}

std::istream& operator>>(std::istream& in, string& s)
{
    s.clear();

    char ch = in.get();
    while (ch != ' ' && ch != '\n')
    {
        s += ch;
        ch = in.get();
    }

    return in;
}

void test_string1()
{
    string s1;
    string s2("x");
    string s3("hello world");
    string s4(s3);
    string s5 = s4;
    string s6;
    s6 = s5;

    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    cout << s3.c_str() << endl;
    cout << s4.c_str() << endl;
    cout << s5.c_str() << endl;
    cout << s6.c_str() << endl;

    string::iterator it = s6.begin();
    while (it != s6.end())
    {
        (*it)++;
        ++it;
    }

    for (auto& ch : s6)
    {
        ch--;
        cout << ch;
    }
    cout << endl;

    s6.reserve(10);
    cout << s6.capacity() << endl;
    s6.reserve(30);
    cout << s6.capacity() << endl;

    s6.resize(10);
    cout << s6.c_str() << endl;
    cout << s6.size() << endl;
    s6.resize(50, 'x');
    cout << s6.c_str() << endl;
    cout << s6.size() << endl;
}

void test_string2()
{
    string s1("hello world");

    cout << s1[0] << endl;

    s1.push_back('s');
    s1 += "ello";
    cout << s1.c_str() << endl;

    s1.insert(0, "xxxx");
    s1.insert(5, "xxxx");
    cout << s1.c_str() << endl;

    s1.erase(5, 4);
    cout << s1.c_str() << endl;

    cout << s1 << endl;
    std::cin >> s1;
    cout << s1 << endl;
}

} // namespace test