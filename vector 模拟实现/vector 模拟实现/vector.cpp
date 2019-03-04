//#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<assert.h>
using namespace std;


	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		/*Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstroage(nullptr)
		{}*/
		Vector() = default;

		// v2(v1)
	/*	Vector(const Vector<T>& v)
		{
			_start = new T[v.Size()];
			memcpy(_start, v._start, sizeof(T)*v.Size());
			_finish = _start + v.Size();
			_endofstroage = _start + v.Size();
		}*/
		Vector(const Vector<T>& v)
		{
			_start = new T[v.Capacity()];
			//memcpy(_start, v._start, sizeof(T)*v.Size());
			for (size_t i = 0; i < v.Size(); ++i)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.Size();
			_endofstroage = _start + v.Capacity();
		}

		// v2 = v1
		/*Vector<T>& operator=(const Vector<T>& v)
		{
			if (this != &v)
			{
				delete[] _start;
				_start = new T[v.Capacity()];
				memcpy(_start, v._start, sizeof(T)*v.Size());
				_finish = _start + v.Size();
				_endofstroage = _start + v.Capacity();
			}

			return *this;
		}*/

		//copy = v2;
		Vector<T>& operator=(Vector<T> v)
		{
			this->Swap(v);
			return *this;
		}

		void Swap(Vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstroage, v._endofstroage);
		}

		~Vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstroage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}

		const_iterator cend() const
		{
			return _finish;
		}

		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T)*size);
					for (size_t i = 0; i < size; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + size;
				_endofstroage = _start + n;
			}
		}

		void Resize(size_t n, const T& value = T())
		{
			if (n <= Size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > Capacity())
					Reserve(n);

				while (_finish != _start + n)
				{
					*_finish = value;
					++_finish;
				}
			}
		}

		void PushBack(const T& x)
		{
			/*	if (_finish == _endofstroage)
				{
					size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;
					Reserve(newcapacity);
				}

				*_finish = x;
				++_finish;*/

			Insert(end(), x);
		}

		void PopBack()
		{
			/*assert(Size() > 0);

			--_finish;*/
			Erase(--end());
		}

		void Insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			size_t posindex = pos - _start;
			if (_finish == _endofstroage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				Reserve(newcapacity);
				pos = _start + posindex;
			}

			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}

			*pos = x;
			++_finish;
		}

		iterator Erase(iterator pos)
		{
			assert(pos < _finish);
			iterator next = pos;
			while (pos < _finish - 1)
			{
				*pos = *(pos + 1);
				++pos;
			}
			--_finish;

			return next;
		}

		T& operator[](size_t pos)
		{
			assert(pos < Size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < Size());
			return _start[pos];
		}

		size_t Size() const
		{
			return _finish - _start;
		}

		size_t Capacity() const
		{
			return _endofstroage - _start;
		}
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstroage = nullptr;
	};

	void TestVector1()
	{
		Vector<int> v1;
		v1.PushBack(1);
		v1.PushBack(2);
		v1.PushBack(3);
		v1.PushBack(4);
		v1.PushBack(5);

		for (size_t i = 0; i < v1.Size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		v1.Resize(3);
		Vector<int>::iterator it1 = v1.begin();
		while (it1 != v1.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;

		v1.Resize(10, 5);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void TestVector2()
	{
		Vector<int> v1;
		v1.PushBack(1);
		v1.PushBack(2);
		v1.PushBack(3);
		v1.PushBack(4);
		v1.PushBack(5);

		auto pos = std::find(v1.begin(), v1.end(), 3);
		if (pos != v1.end())
		{
			v1.Insert(pos, 30);
		}
		pos = std::find(v1.begin(), v1.end(), 3);
		v1.Erase(pos);

		for (size_t i = 0; i < v1.Size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;
	}

	void TestVector3()
	{
		Vector<int> v1;
		v1.PushBack(1);
		v1.PushBack(2);
		v1.PushBack(3);
		v1.PushBack(4);
		v1.PushBack(5);

		Vector<int> copy = v1; // copy(v1)
		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;

		Vector<int> v2;
		v2.PushBack(10);
		v2.PushBack(20);

		copy = v2;
		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void TestVector4()
	{
		Vector<std::string> v;
		v.PushBack("111");
		v.PushBack("222");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");



		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

int main()
{
	Vector<int>v;
	v.PushBack(1);
	v.PushBack(2);
	Vector<int>v2;
	v2 = v;
	for (auto e : v2)
	{
		cout << e << endl;
	}
	cout << endl;
	for (auto e : v)
	{
		cout << e;
	}

	system("pause");
	return 0;
}

