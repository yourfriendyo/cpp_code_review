#pragma once
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

    const_iterator cbegin() const { return _str; }
    const_iterator cend() const { return _str + _size; }

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
        _str  = nullptr;
        _size = _capacity = 0;
    }

    const char* c_str() const { return _str; }

    size_t size() const { return _size; }

    char&       operator[](size_t pos) { return _str[pos]; }
    const char& operator[](size_t pos) const { return _str[pos]; }

    void resize(size_t n, char c = '\0')
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
            memset(_str + _size, c, n - _size);
            _size       = n;
            _str[_size] = '\0';
        }
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

    void push_back(char c)
    {
        if (_size + 1 > _capacity)
            reserve(_capacity == 0 ? 4 : _capacity * 2);

        _str[_size++] = c;
        _str[_size]   = '\0';
    }

    void append(const char* str)
    {
        size_t len = strlen(str);
        if (_size + len > _capacity)
            reserve(_size + len);

        strcpy(_str + _size, str);
        _size += len;
    }

    string& operator+=(char c)
    {
        push_back(c);
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

    void pop_back()
    {
        assert(_size > 0);
        _size--;
    }

    bool operator<(const string& s) { return strcmp(_str, s._str) < 0; }
    bool operator==(const string& s) { return strcmp(_str, s._str) == 0; }
    bool operator<=(const string& s) { return *this < s || *this == s; }
    bool operator>(const string& s) { return !(*this <= s); }
    bool operator>=(const string& s) { return !(*this < s); }
    bool operator!=(const string& s) { return !(*this == s); }

    string& insert(size_t pos, char c)
    {
        assert(pos <= _size);

        if (_size + 1 > _capacity)
            reserve(_capacity == 0 ? 4 : 2 * _capacity);

        for (size_t i = _size + 1; i > pos; i--)
            _str[i] = _str[i - 1];

        _str[pos] = c;
        _size++;
        return *this;
    }

    string& insert(size_t pos, const char* str)
    {
        assert(pos <= _size);

        size_t len = strlen(str);
        if (_size + len > _capacity)
            reserve(_size + len);

        for (size_t i = _size + 1; i > pos; i--)
            _str[i + len - 1] = _str[i - 1];

        strncpy(_str + pos, str, len);
        _size += len;
        return *this;
    }

    string& insert(size_t pos, const string& s)
    {
        assert(pos <= _size);
        return insert(pos, s._str);
    }

    string& erase(size_t pos = 0, size_t len = npos)
    {
        assert(pos <= _size);
        if (len == npos || pos + len > _size)
        {
            _size       = pos;
            _str[_size] = '\0';
        }
        else
        {
            for (int i = pos + len; i <= _size; i++)
                _str[i - len] = _str[i];
        }
        return *this;
    }

    iterator erase(iterator first, iterator last)
    {
        erase(first - begin(), last - first);
        return first;
    }

public:
    char*  _str;
    size_t _size;
    size_t _capacity;

    static const size_t npos = -1;
};

inline void test_string1()
{
    string s1("hello world");
    string s2 = "hello world";
    string s3;
    s3 = s1;

    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    cout << s3.c_str() << endl;

    string::iterator it = s1.begin();
    while (it != s1.end())
    {
        (*it)++;
        (*it)--;
        cout << *it << ' ';
        it++;
    }
    cout << endl;

    const string&          s4  = s1;
    string::const_iterator cit = s4.cbegin();
    while (cit != s4.cend())
    {
        // (*cit)++;
        // (*cit)--;
        cout << *cit << ' ';
        cit++;
    }
    cout << endl;
}

inline void test_string2()
{
    string s1("hello world");
    string s2("hello string");
    // s1 += s2;
    s1.insert(0, 'x');
    cout << s1.c_str() << endl;
    s1.insert(1, s2);
    cout << s1.c_str() << endl;
    s1.erase(1, 2);
    cout << s1.c_str() << endl;


    string s3("hello world");
    string s4("hello string");

    cout << (s3 < s4) << endl;
    cout << (s3 > s4) << endl;
    cout << (s3 == s4) << endl;

    s3.resize(13, 'x');
    cout << s3.c_str() << endl;
    s3.resize(3);
    cout << s3.c_str() << endl;
}

} // namespace test