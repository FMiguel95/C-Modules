#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <cstring>

template <typename T>
class Array
{
public:
	Array() : _size(0), _list(new T[0])
	{
		std::memset(_list, 0, sizeof(T));
	}

	Array(unsigned int n) : _size(n), _list(new T[n])
	{
		std::memset(_list, n, sizeof(T));
	}

	Array(const Array<T>& src) : _size(src.size()), _list(new T[src.size()])
	{
		for (size_t i = 0; i < src.size(); i++)
		{
			_list[i] = src[i];
		}
	}

	Array<T>& operator =(const Array<T>& src)
	{
		if (this != &src)
		{
			if (_list)
				delete[] _list;
			_size = src.size();
			_list = new T[src.size()];
			for (size_t i = 0; i < src.size(); i++)
			{
				_list[i] = src[i];
			}
		}
		return *this;
	}

	~Array()
	{
		if (_list)
			delete[] _list;
		_list = NULL;
	}

	unsigned int size() const
	{
		return _size;
	}

	T& operator [](unsigned int index) const
	{
		if (index >= _size)
			throw std::out_of_range("Index out of range");
		return _list[index];
	}

private:
	unsigned int _size;
	T* _list;
};

#endif
