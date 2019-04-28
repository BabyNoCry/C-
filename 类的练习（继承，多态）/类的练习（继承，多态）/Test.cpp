
#include<iostream>
using namespace std;
#include<windows.h>
//虚表
class A
{
public:
	virtual void print()
	{
		cout << "ha ha" << endl;
	}

};
class B :public A
{
public:
	virtual void print()
	{
		cout << "he he" << endl;
	}
};

void Func(A* p)	//调用对象的引用
{
	p->print();	//调用的是虚函数
}
int main()
{
	A a;
	B b;
	Func(&a);
	Func(&b);
	system("pause");
	return 0;
}

//
//class A
//{
//public:
//	virtual void print() = 0;
//};
//class B :public A
//{
//public:
//	virtual void print()
//	{
//		cout << "I am B" << endl;
//	}
//};
//class C :public A
//{
//public:
//	virtual void print()
//	{
//		cout << "I am C" << endl;
//	}
//};
//void Test()
//{
//	A* PB = new B;
//	PB->print();
//	A* PC = new C;
//	PC->print();
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

//关键字final 验证
//class A
//{
//public:
//	virtual void print() final
//	{
//		cout << "haha" << endl;
//	}
//};
//class B :public A
//{
//public:
//	virtual void print()
//	{
//		cout << "hehe" << endl;
//	}
//};
//int main()
//{
//	A a;
//	B b;
//	a.print();
//	b.print();
//	system("pause");
//	return 0;
//}

//关键字overirrde 验证
//class A
//{
//public:
//	virtual void print()
//	{
//		cout << "haha" << endl;
//	}
//};
//
////overirrde 修饰派生类虚函数强制完成重写，如果没有重写会编译报错。
//class B: public  A
//{
//public:
//	virtual void pp() override
//	{
//		cout << "haha" << endl;
//	}
//};
//int main()
//{
//	A a;
//	B b;
//	a.print();
//	b.print();
//	system("pause");
//}

//虚函数表
//class Base
//{
//public:
//		virtual void Func1()
//		{
//		cout << "Base::Func1()" << endl;
//		}
//
//		virtual void Func2()
//		{
//			cout << "Base::Func2()" << endl;
//		}
//		
//		void Func3()
//		{
//			cout << "Base::Func3()" << endl;
//		}
//
//private:
//	int _b = 1;
//};
//
//class Derive :public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//
//	system("pause");
//	return 0;
//}
