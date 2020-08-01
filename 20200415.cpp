#include <stdio.h>

#include <iostream>
using namespace std;


#if 0
int a = 10;

// 命名空间的定义
// {}表示一个范围(作用域)---命名空间实际：就是一个有名字的作用域
namespace N1
{
	int a = 20;
	int b = 20;


	int Add(int left, int right)
	{
		return left + right;
	}
}


// 命名空间可以嵌套---命名空间中可以定义命名空间
// 学校
//   院系
//     专业
//       班级
//         宿舍
namespace N2
{
	int a = 30;
	int b = 30;

	int Sub(int left, int right)
	{
		return left - right;
	}

	namespace N3
	{
		int a = 40;
		int b = 40;

		int Mul(int left, int right)
		{
			return left*right;
		}
	}
}


int main()
{
	int a = 50;
	printf("%d\n", a);   // main局部变量a
	printf("%d\n", ::a);   // 全局作用域中的a, ::作用域限定符

	printf("%d\n", N1::a);   // N1命名空间中的a
	printf("%d\n", N2::a);   // N2命名空间中的a
	printf("%d\n", N2::N3::a);   // N3命名空间中的a
	return 0;
}
#endif

#if 0
// int a = 10;

// 命名空间中成员的使用
namespace N1
{
	int a = 20;
	int b = 20;


	int Add(int left, int right)
	{
		return left + right;
	}
}


// 1. 在命名空间成员前增加N1::(命名空间名字以及作用域限定符)
// 2. using N1::成员名字;
using N1::b;  // b相当于是该文件的全局变量(实际b是N1命名空间中的成员)
//using N1::a;


// 3. using namespace N1;
using namespace N1;   // 优点：命名空间中的成员可以直接在当前文件中直接使用
                      // 缺陷：产生冲突的概率比较大

int main()
{
	printf("%d\n", N1::a);
	printf("%d\n", N1::b);
	printf("%d\n", N1::b);
	printf("%d\n", N1::b);
	printf("%d\n", N1::b);
	printf("%d\n", N1::b);
	printf("%d\n", b);

	Add(10, 20);
	return 0;
}
#endif

#if 0
// 定义了两个同名的命名空间
// 可以在一个工程中定义相同名称的命名空间,编译器会将相同名称命名空间中的内容合并成一个

namespace N
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}

namespace N
{
	int c = 30;
	int d = 40;
	int Sub(int left, int right)
	{
		return left - right;
	}
}


int main()
{
	
	return 0;
}
#endif



// #include <iostream.h>   旧的编译器支持---比如vs6.0
//#include <iostream>
//using namespace std;


#if 0
// 输入和输出
int main()
{
	int a;
	int b;
	int c;
	cin >> a;
	cin >> b >> c;

	scanf("%d", &a);
	scanf("%d", a);

	cout << 1 << " " << 1.23 << endl;

	cout << "hello world!!!" << endl;
	return 0;
}
#endif

#if 0
// 函数原型：返回值类型   函数名字(参数列表){}
// C语言编译器对函数原型检测要求不是非常严格
// C++编译器与函数原型检测更加的严格
void Test1()
{
	printf("Test1()\n");
}


int main()
{
	Test1();
	//int ret = Test1();
	Test1(10);
	//Test1(10,20);
	//Test1(10,20,30);

	return 0;
}
#endif


#if 0
// 备胎
// 能否给参数带上默认值
// 缺省参数
void Test1(int a = 0)
{
	printf("%d\n", a);
}

int main()
{
	Test1();
	Test1(10);
	return 0;
}
#endif


#if 0
// 缺省参数分类：
// 1. 全缺省参数---所有参数都带有默认值
void TestFunc(int a = 10, int b = 20, int c = 30)
{
	cout << a << " " << b << " " << c << endl;
}


// 函数传参规则：从右往左一次来传递参数
// 缺省参数匹配规则：从左往右来进行匹配---？
int main()
{
	TestFunc();    //10 20 30
	TestFunc(1);       // ?--->1  20  30
	TestFunc(1, 2);    // ?--->1  2   30
	TestFunc(1, 2, 3); // 1 2 3
	return 0;
}
#endif

#if 0
// 2. 半缺省参数：部分参数带有默认值---默认值只能从右往左依次给出，不能隔着给
void TestFunc(int a, int b , int c = 30)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc(10,20);
	TestFunc(10, 20, 300);
	return 0;
}
#endif

#if 0
int g_a = 100;
// 默认值不能在函数声明和定义位置同时给出
void TestFunc(int a = g_a/*10*/);

void TestFunc(int a)
{
	cout << a << endl;
}


// 1. 为什么不能同时在两个位置给出：一不小心，声明和定义位置给出的默认值可能不一致，在调用时候应该用哪一个就会存在问题
// 2. 那个位置给出比较好：声明的位置

int main()
{
	return 0;
}
#endif


#if 0
// 在C语言中，函数名字必须唯一
int Addii(int left, int right)
{
	return left + right;
}

int Addiii(int left, int mid, int right)
{
	return left + mid + right;
}
#endif


#if 0
namespace N
{
	int Add(int left, int right)
	{
		return left + right;
	}
}


double Add(double left, double right)
{
	return left + right;
}

int main()
{
	Add(10,20);
	Add(1.2, 2.3);
	return 0;
}
#endif

#if 0
// 1
void Test1()
{}

// 2
void Test1(int)
{}

// 3
void Test1(double)
{}

// 4
void Test1(int, double)
{}

// 5
void Test1(double, int)
{}


// 6
int Test1(int)
{
	return 0;
}
// 参数列表不同
// 1和2函数：参数个数不同
// 2和3函数：参数的类型
// 4和5函数：类型次序不同

// 函数6不能和其他2个函数形成重载----因为这两个函数仅仅是返回值类型不同
// 结论：两个函数如果仅仅只是因为返回值类型不同，是不能构成重载的
// 为什么？
#endif

#if 0
// 函数重载的调用原理
int Add(int left, int right)
{
	return left + right;
}

// char Add(char left, char right)
// {
// 	return left + right;
// }

double Add(double left, double right)
{
	return left + right;
}


// 函数重载在调用时到底应该调用那个函数？是编译器在编译阶段确定的
// 在编译阶段，编译器会对传递的实参类型进行推演，根据推演的结果选择合适的函数进行调用
// 注意：如果推演出来后没有合适的结果可用，编译器会尝试进行参数隐式类型转化
//     转化完成成有合适的函数可供调用，则编译成功
//     转换完成后没有合适函数可供调用，或者说不能进行转化，则会编译失败
int main()
{
	Add(1, 2);     // int,int--->Add(int,int)
	Add(1.0, 2.0); // double, double--->Add(double, double)
	Add('1', '2'); // 没有提供字符类型的加法函数，char和int可以发生隐式类型转化--->char,char-->隐式类型转化-->int,int
	               // 

	// Add(1, 2.0);   // int double  转化：int  int或者double double，编译器不知道该如何转化---直接报错
	Add(1, (int)2.0);
	return 0;
}
#endif

#if 0
// C语言
// 函数名字被修饰：_Add
int Add(int left, int right);

// _Add
double Add(double left, double right);

// 结论：C语言编译器对函数名字修饰规则：仅仅只是在函数名字前增加了一个下划线
int main()
{
	//Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}
#endif

#if 0
// C++
// ?Add@@YAHHH@Z
int Add(int left, int right);

// ?Add@@YANNN@Z
double Add(double left, double right);

// ?Add@@YAHNH@Z---?Add@@YAHNH@Z
int Add(double left, int right);

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	Add(1.0, 2);
	return 0;
}
#endif

#if 0
// 函数重载为什么和返回值没有关系？
int Add(int left, int right)
{
	return left + right;
}

double Add(int left, int right)
{
	return left + right;
}

// 假设仅仅只是返回值类型不同可以形成重载

int main()
{
	int ret1 = Add(1, 2);
	double ret2 = Add(1, 2);

	// 调用那个？
	Add(1,2);
	return 0;
}
#endif

#if 0
// C语言和C++编译器对函数名字修饰的规则不一样

// C++给的名字?Add@@YANHH@Z
extern "C" double Add(int left, int right)
{
	return left + right;
}

// 拿到C语言中调用--->C语言编译器_Add

int main()
{
	Add(1, 2);
	return 0;
}
#endif


#if 0
void TestFunc()
{}

void TestFunc(int a = 10)
{}

int main()
{
	TestFunc();
	TestFunc(190);
	return 0;
}
#endif

#if 0
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}

void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

int main()
{
	int a = 10, b = 20;
	Swap(a, b);
	cout << a << " " << b << endl;

	Swap(&a, &b);
	cout << a << " " << b << endl;
	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;

	// 引用变量的类型必须要与实体的类型一致
	int& ra = a;

	ra = 100;

	a = 200;
	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;

	// int& ra;  编译失败

	int& ra = a;

	int& rra = a;

	ra = 100;
	rra = 200;

	// 引用只能和一个实体对应：引用一旦引用一个实体，再不能引用其他实体
	int b = 10;
	int& rb = b;

	rb = a;   // 注意：该条语句不是让rb引用a，而是将a的值赋值给rb
	// &rb = a;  编译失败--->&rb是对rb取地址

	rb = 20;

	// 实体--->引用变量 那个的生命周期长？
	if (true)
	{
		int& rrb = b;
	}
	return 0;
}
#endif


#if 0
int main()
{
	// 1. 
	const int a = 10;
	// a = 100;

	const int& ra = a;
	// ra = 100;


	// 2. 
	const int& rb = 10;

	// 3.
	double d = 12.34;
	const int& rd = d;
	cout << rd << endl;

	d = 34.56;
	cout << d << endl;
	cout << rd << endl;
	return 0;
}
#endif

/*
struct A
{
	int a;
	int b;
	struct B
	{
		int c;
		int d;
	};
	B stub;
};

int main()
{
	// 1. 为了写代码简单，在函数中给实体取别名
	int a = 10;
	int& ra = a;

	A stuA;
	stuA.a = 10;
	stuA.b = 20;
	stuA.stub.c = 30;
	stuA.stub.d = 40;

	int& r = stuA.stub.c;
	r = 50;
	return 0;
}*/

// 引用的应用场景：
// 1. 为了写代码简单，在函数中给实体取别名
// 2. 作为函数的参数--->将传地址和传值的优点结合起来---按值传递以及操作，但是可以体到指针的效果
//                    注意：如果不想通过形参改变实参，可以将形参设置为const类型的

#if 0
void Swap(int& left, int& right)
{
	cout << &left << endl;
	cout << &right << endl;

	int temp = left;
	left = right;
	right = temp;
}


int main()
{
	int a = 10;
	int b = 20;
	cout << &a << endl;
	cout << &b << endl;
	Swap(a, b);
	return 0;
}
#endif

#if 0
// 3. 作为函数的返回值类型
// 注意：不能返回函数栈上的空间，因为函数运行结束后，栈空间被回收
//      如果在调用位置以引用的方式接收函数的返回值，将来该引用引用的就是一块非法的空间

// 如果引用作为函数的返回值，到底应该怎么返回？
// 只要返回的变量的生命周期不受函数控制(不随函数结束而销毁)即可
// 返回值：全局变量、被static修饰的变量、引用类型的参数
int g_a = 0;
int& Add(int left, int right)
{
	//int tmp = left + right;
	//cout << &tmp << endl;
	//return tmp;
	g_a = left + right;
	return g_a;
}


int main()
{
	int& ret = Add(1, 2);
	printf("%p\n", ret);
	Add(3, 4);
	return 0;
}
#endif

#if 0
// 验证：传值、传地址、传引用

#include <time.h>

struct A
{
	int array[10000];
};


void TestRefParam(A& a)
{}

void TestValueParam(A a)
{}

void TestPtrParam(A* a)
{}

void Test1()
{
	A a;

	// 测试传值---A拷贝一份
	size_t begin = clock();
	for (int i = 0; i < 1000000; ++i)
		TestValueParam(a);
	size_t end = clock();
	cout << end - begin << endl;

	// 传引用---别名
	begin = clock();
	for (int i = 0; i < 1000000; ++i)
		TestRefParam(a);
	end = clock();
	cout << end - begin << endl;
}

void Test2()
{
	A a;

	// 测试传地址
	size_t begin = clock();
	for (int i = 0; i < 1000000; ++i)
		TestPtrParam(&a);
	size_t end = clock();
	cout << end - begin << endl;

	// 传引用---别名
	begin = clock();
	for (int i = 0; i < 1000000; ++i)
		TestRefParam(a);
	end = clock();
	cout << end - begin << endl;
}

// 结论：传值的效率最低--->传值每次都需要进行一份拷贝
//      传地址和传引用：效率几乎一样
int main()
{
	//Test1();
	for (int i = 0; i < 10; ++i)
		Test2();
	return 0;
}
#endif

// 指针和引用有什么区别？ *****
// 指针和引用到底没有区别--->到底：底层实现

// 概念以及使用

int main()
{
	int*** p;

	int a = 10;
	const int&&rra = 10;

	int* pa = &a;
	*pa = 100;

	int b = 100;
	pa = &b;

	int& ra = a;
	ra = 100;
	ra = b;


	char ch = 'a';
	char& rch = ch;
	char* pch = &ch;

	cout << sizeof(rch) << endl;
	cout << sizeof(pch) << endl;
	return 0;
}