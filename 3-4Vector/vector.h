#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

namespace test
{
template<class T>
class vector
{
public:
    typedef T*       iterator;
    typedef const T* const_iterator;

    iterator       begin() { return _start; };
    iterator       end() { return _finish; };
    const_iterator begin() const { return _start; };
    const_iterator end() const { return _finish; };

public:
    vector()
        : _start(nullptr)
        , _finish(nullptr)
        , _end_of_storage(nullptr)
    {}

    vector(const vector& v)
        : _start(nullptr)
        , _finish(nullptr)
        , _end_of_storage(nullptr)
    {
        _start = new T[v.capacity()];
        for (int i = 0; i < v.size(); i++)
        {
            _start[i] = v._start[i];
        }
        _finish         = _start + v.size();
        _end_of_storage = _start + v.capacity();
    }

    vector& operator=(const vector& v)
    {
        if (this != &v)
        {
            _start = new T[v.capacity()];
            for (int i = 0; i < v.size(); i++)
            {
                _start[i] = v._start[i];
            }
            _finish         = _start + v.size();
            _end_of_storage = _start + v.capacity();
        }
        return *this;
    }

    ~vector()
    {
        delete[] _start;
        _start = _finish = _end_of_storage = nullptr;
    }

    size_t size() const { return _finish - _start; }
    size_t capacity() const { return _end_of_storage - _start; }

    void reserve(size_t n)
    {
        if (n > capacity())
        {
            T*     tmp = new T[n];
            size_t sz  = size();
            for (int i = 0; i < sz; i++)
            {
                tmp[i] = _start[i];
            }
            delete[] _start;
            _start = tmp;

            _finish         = _start + sz;
            _end_of_storage = _start + n;
        }
    }

    void resize(size_t n, T val = T())
    {
        if (n <= size())
        {
            _finish = _start + n;
        }
        else
        {
            if (n > capacity())
            {
                reserve(n);
            }
            while (_finish != _start + n)
            {
                *_finish = val;
                _finish++;
            }
        }
    }

    T& operator[](size_t pos)
    {
        return _start[pos];
    }

    const T& operator[](size_t pos) const
    {
        return _start[pos];
    }

    void push_back(T x)
    {
        if (size() == capacity())
        {
            reserve(capacity() == 0 ? 4 : 2 * capacity());
        }

        *_finish = x;
        ++_finish;
    }

    void pop_back()
    {
        assert(size());
        --_finish;
    }

    iterator insert(iterator pos, const T& val)
    {
        assert(_start <= pos && pos <= _finish);

        if (size() == capacity())
        {
            size_t step = pos - _start;
            reserve(capacity() == 0 ? 4 : capacity() * 2);
            pos = _start + step;
        }

        for (iterator end = _finish; end >= pos; --end)
        {
            *end = *(end - 1);
        }

        *pos = val;
        ++_finish;
        return pos;
    }

    iterator erase(iterator pos)
    {
        assert(_start <= pos && pos < _finish);

        for (iterator begin = pos; begin < _finish - 1; ++begin)
        {
            *begin = *(begin + 1);
        }

        --_finish;
        return pos;
    }

    void print()
    {
        for (auto e : *this)
        {
            cout << e << " ";
        }
        cout << endl;
    }


private:
    iterator _start;
    iterator _finish;
    iterator _end_of_storage;
};

inline void test_vector_1()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.print();

    vector<int> v1(v);
    v1.print();

    vector<int> v2;
    v2 = v1;
    v2.print();

    v.resize(10, 8);
    v.print();
    cout << v.size() << endl;
    v.resize(3);
    v.print();
    cout << v.size() << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "------------------------" << endl;
    v.print();
    v.pop_back();
    v.print();
    v.pop_back();
    v.print();
    v.pop_back();
    v.print();
    // v.pop_back();
    // v.print();

    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.print();

    v.insert(v.begin(), 0);
    v.insert(v.begin() + 3, 3);
    v.insert(v.end(), 9);
    v.print();


    vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        if (*it % 2 == 0)
        {
            it = v.erase(it);
        }
        else
        {
            ++it;
        }
    }

    v.print();
}

} // namespace test