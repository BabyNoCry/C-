#pragma once
#define  _CRT_SECURE_NO_WARNINGS


// ´«Í³
//namespace bit
//{
//	class String
//	{
//	public:
//	/*	String()
//			:_str(new char[1])
//		{
//			_str[0] = '\0';
//		}
//
//		String(char* str)
//			:_str(new char[strlen(str)+1])
//		{
//			strcpy(_str, str);
//		}*/
//
//		String(char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//
//		// copy(s1)
//		String(const String& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		// copy = s2
//		String& operator=(const String& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//
//			return *this;
//		}
//
//		~String()
//		{
//			if (_str)
//				delete[] _str;
//		}
//
//		char* c_str()
//		{
//			return _str;
//		}
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//		size_t Size()
//		{
//			return strlen(_str);
//		}
//
//	private:
//		char* _str;
//	};
//
//	void TestString1()
//	{
//		String s1(nullptr);
//		String s2("hello");
//		s2[0] = 'x';
//
//		for (size_t i = 0; i < s2.Size(); ++i)
//		{
//			cout << s2[i] << " ";
//		}
//		cout << endl;
//
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//	}
//
//	// Éî¿½±´
//	// Ç³¿½±´
//	void TestString2()
//	{
//		String s1("hello");
//		String copy(s1);
//		String s2("world");
//
//		cout << s1.c_str() << endl;
//		cout << copy.c_str() << endl;
//
//		copy = s2;
//		cout << copy.c_str() << endl;
//	}
//}

// ÏÖ´úÐ´·¨
//namespace bit
//{
//	class String
//	{
//	public:
//		String(char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			strcpy(_str, str);
//		}
//
//		// copy(s1)
//		String(const String& s)
//			:_str(nullptr)
//		{
//			String tmp(s._str);
//			swap(_str, tmp._str);
//		}
//		
//		// copy = s2
//	/*	String& operator=(const String& s)
//		{
//			if (this != &s)
//			{
//				String tmp(s._str);
//				swap(_str, tmp._str);
//			}
//
//			return *this;
//		}*/
//
//		// copy = s2;
//		String& operator=(String s)
//		{
//			swap(_str, s._str);
//			return *this;
//		}
//	
//
//		~String()
//		{
//			if (_str)
//				delete[] _str;
//		}
//
//		char* c_str()
//		{
//			return _str;
//		}
//
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//
//		size_t Size()
//		{
//			return strlen(_str);
//		}
//
//	private:
//		char* _str;
//	};
//
//	void TestString1()
//	{
//		String s1(nullptr);
//		String s2("hello");
//		s2[0] = 'x';
//
//		for (size_t i = 0; i < s2.Size(); ++i)
//		{
//			cout << s2[i] << " ";
//		}
//		cout << endl;
//
//		cout << s1.c_str() << endl;
//		cout << s2.c_str() << endl;
//	}
//
//	// Éî¿½±´
//	// Ç³¿½±´
//	void TestString2()
//	{
//		String s1("hello");
//		String copy(s1);
//		String s2("world");
//
//		cout << s1.c_str() << endl;
//		cout << copy.c_str() << endl;
//
//		copy = s2;
//		cout << copy.c_str() << endl;
//	}
//}

#include<iostream>
#include<string.h>
using namespace std;
	class String
	{
	public:
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		String(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		// copy(s1)
		String(const String& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s._str);
			this->Swap(tmp);
		}
		// copy = s2;
		String& operator=(String s)
		{
			this->Swap(s);
			return *this;
		}

		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}


		~String()
		{
			if (_str)
			{
				delete[] _str;
				_size = 0;
				_capacity = 0;
			}
		}
		//------------------------------------------------------------------------------
		
		bool operator<(const String& s)
		{
			return !(_str > s._str) && !(_str == s._str);
		}

		//---------------------------------------------------------------------------------
		bool operator>(const String& s)
		{
			int begin = 0;
			int end1 = _size;
			int end2 = s._size;
			while (begin < end1&&begin < end2)
			{
				if (_str[begin] > s._str[begin])
					return true;
				else if (_str[begin] == s._str[begin])
				{
					begin++;
				}
				else
					return false;
			}
			if (begin == end1 && begin == end2)
			{
				return false;
			}
			else if (begin == end1)
				return false;
			else
				return true;

		}

		//------------------------------------------------------------------------------

		bool operator<=(const String& s)
		{
			return !(_str > s._str);
		}

		//------------------------------------------------------------------------------

		bool operator>=(const String& s)
		{
			return !(_str < s._str);
		}

		//------------------------------------------------------------------------------

		bool operator==(const String& s)
		{
			int begin = 0;

			int end1 = _size;
			int end2 = s._size;
			if (end1 != end2)
				return false;
			else
			{
				while (begin < end1)
				{
					if (_str[begin] == s._str[begin])
						begin++;

					else
						return false;
				}
				if (begin == end1)
					return true;
			}
		}

		//------------------------------------------------------------------------------

		bool operator!=(const String& s)
		{
			return !(_str == s._str);
		}


		//------------------------------------------------------------------------------

		void Reserve(size_t n)
		{
			_capacity = n;
		}


		//------------------------------------------------------------------------------

		void PushBack(char ch)
		{
			if(_size==_capacity)
			_capacity *=2;
			
			_str[_size++] = ch;
			_str[_size] = '\0';
			
		}
		//------------------------------------------------------------------------------


		// "hello"  "xxxxxxxxxxxxxxxxxxxxxxxxxx"
		void Append(const char* str)
		{
			Reserve(_capacity + strlen(str)+1);
			strcpy(_str + _size, str);
			_size += strlen(str);
		}
		//------------------------------------------------------------------------------

		String& operator+=(char ch)
		{
			PushBack(ch);
			return (*this);
		}



		//------------------------------------------------------------------------------

		String& operator+=(const char* str)
		{
			Append(str);
			
			return (*this);
		}


		//------------------------------------------------------------------------------

		void Insert(size_t pos, char ch)
		{
			if (_size == _capacity)
				_capacity *= 2;
			char* arr = _str + pos;
			_str[pos] = ch;
			strcpy(_str + pos + 1, arr);
			_size++;
			
		}

		//------------------------------------------------------------------------------

		void Insert(size_t pos, const char* str)
		{
			if (_size == _capacity)
				_capacity *= 2;
			int len = strlen(str);
			char* arr = _str + pos;
			strcpy(_str + pos, str);
			strcpy(_str + pos + len + 1, arr);
			_size++;
		}
		//------------------------------------------------------------------------------

		void Erase(size_t pos, size_t len)
		{
			char* arr = _str + pos;
			char* s = arr + len;
			strcpy(_str + pos, s);
			_size -= len;
		}

		//------------------------------------------------------------------------------

		size_t Find(char ch, size_t pos = 0)
		{
			size_t begin = pos;
			while (begin < _size)
			{
				if (_str[begin] == ch)
					return begin;
			}
			return npos;

		}

		//------------------------------------------------------------------------------

		size_t Find(const char* str, size_t pos = 0)
		{
			size_t begin = pos;
			int len = strlen(str);
			while (begin < _size)
			{
				char* arr = _str + begin;
				int j = 0;
				while (j < len)
				{
					if (arr[j] == str[j])
					{
						j++;
					}
					break;
				}
				if (j == len)
					return begin;
				begin++;		
			}
			return npos;
		}

		//------------------------------------------------------------------------------

		char* c_str()
		{
			return _str;
		}

		//------------------------------------------------------------------------------

		char& operator[](size_t pos)
		{
			//assert(pos < _size);

			return _str[pos];
		}
		//------------------------------------------------------------------------------

		size_t Size()
		{
			return _size;
		}
		//------------------------------------------------------------------------------

		size_t Capacity()
		{
			return _capacity;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};


	void TestString2()
	{
		String s1("haha");
		s1.PushBack('c');
		cout << s1.c_str() << endl;
		//s1 += "hehe";
		cout << 5 << endl;

	}
	void TestString1()
	{
		String s1("hello");
		String s2("world");
		String copy(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << copy.c_str() << endl;

		copy = s1 = s2;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << copy.c_str() << endl;

		String::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : s1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

size_t String::npos = -1;
int main()
{
	TestString2();
	system("pause");
	return 0;

}