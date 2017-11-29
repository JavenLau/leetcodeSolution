
//
//8.2 运算符重载
//运算符重载为成员函数
complex operator + (complex c2);	//运算符+重载成员函数
void operator ++(int);	//后置单目运算符重载
//运算符重载为友元函数
friend complex operator + (complex c1,complex c2);	//运算符+重载友元函数


//
//8.3 虚函数
//虚函数：通过使用基类的指针，调用派生类的同名成员函数。virtual void display() {};
//8_4.cpp
#include <iostream>
using namespace std;
class B0	//基类B0声明
{
public:	//
	//void display()
	virtual void display()
	{
		cout<<"B0::display()"<<endl;   //虚成员函数
	}
};
class B1: public B0	//公有派生
{
public:
	void display()
	{
		cout<<"B1::display()"<<endl;   //虚成员函数
	}
};
class D1: public B1	//公有派生
{
public:
	void display()
	{
		cout<<"D1::display()"<<endl;   //虚成员函数
	}
};
void fun(B0 *ptr)	//
{
	ptr->display();
}
int main()	//
{
	B0 b0,*p;	//声明基类对象和指针
	B1 b1;	//声明派生类对象
	D1 d1;	//声明派生类对象

	p=&b0;
	fun(p);	//调用基类B0函数成员

	p=&b1;
	fun(p);	//调用派生类B1函数成员

	p=&d1;
	fun(p);	//调用派生类D1函数成员
}

//虚析构函数8_5.cpp
#include <iostream>
using namespace std;

class Base
{
public:
	~Base(){ cout<< "Base destructor\n";}//基类析构函数声明
};

class Derived: public Base
{
public:
	Derived();//派生类构造函数声明
	~Derived();//派生类析构函数声明
private:
	int *i_pointer;
};

Derived::Derived()//派生类构造函数定义
{	i_pointer=new int(0); }

Derived::~Derived()//派生类析构函数定义
{ 
	cout<< "Derived destructor\n";
	delete i_pointer;
}

void fun(Base* b)
{ delete b; }

int main()
{
	Base *b=new Derived();
	fun(b);
}



//
//8.4 纯虚函数与抽象类
//抽象类（带有纯虚函数）：自身无法实例化，其派生类可以实例化，定义对象。virtual void display()=0;
//8_6.cpp
#include <iostream>
using namespace std;


class B0	//抽象类/基类B0声明
{
public:	//
	virtual void display()=0;	//纯虚函数成员
};

class B1: public B0	//公有派生类
{
public:
	void display()
	{
		cout<<"B1::display()"<<endl;   //虚成员函数
	}
};

class D1: public B1	//公有派生类
{
public:
	void display()
	{
		cout<<"D1::display()"<<endl;   //虚成员函数
	}
};
void fun(B0 *ptr)	//普通函数
{
	ptr->display();
}
int main()	//主函数
{
	B0 *p;	//
	B1 b1;	//
	D1 d1;	//

	p=&b1;
	fun(p);	//调用派生类B1函数成员

	p=&d1;
	fun(p);	//调用派生类D1函数成员
}
