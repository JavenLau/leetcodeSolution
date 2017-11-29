
//继承的定义
class son: virtual public class father1, father 2 

//构造函数

//拷贝构造函数

//虚基类，标识符定义域


//8.4 纯虚函数与抽象类
//抽象类（带有纯虚函数）：自身无法实例化，其派生类可以实例化，定义对象。
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
