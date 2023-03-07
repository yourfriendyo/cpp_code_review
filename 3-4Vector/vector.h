#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
using std::cout;
using std::endl;

namespace test
{
template<class T>
class vector
{
public:
    typedef T*       iterator;
    typedef const T* const_iterator;
    iterator         begin() { return _start; };
    iterator         end() { return _finish; };

    const_iterator begin() const { return _start; };
    const_iterator end() const { return _finish; };

public:
    vector()
        : _start(nullptr)
        , _finish(nullptr)
        , _end_of_storage(nullptr)
    {}
    void push_back(const T& x)
    {
        if (_finish == _end_of_storage)
        {
            reserve(capacity() == 0 ? 4 : 2 * capacity());
        }
        *_finish = x;
        ++_finish;
    }

    size_t size() const
    {
        return _finish - _start;
    }

    size_t capacity() const
    {
        return _end_of_storage - _start;
    }

    void reserve(size_t n)
    {
        if (n > capacity())
        {
            T* tmp = new T[n];
            if (_start)
            {
                memcpy(tmp, _start, sizeof(T) * size());
                delete[] _start;
            }
            size_t sz = size();
            _start          = tmp;
            _finish         = tmp + sz;
            _end_of_storage = tmp + n;
        }
    }

    T& operator[](size_t pos)
    {
        assert(pos < size());
        return _start[pos];
    }


private:
    iterator _start;
    iterator _finish;
    iterator _end_of_storage;
};

inline void test_vector1()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    vector<int>::iterator it = v1.begin();
    while (it != v1.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for (auto e : v1)
    {
        cout << e << " ";
    }
    cout << endl;
}

} // namespace test