#include <stdio.h>

#include <iostream>
using namespace std;


#if 0
int a = 10;

// �����ռ�Ķ���
// {}��ʾһ����Χ(������)---�����ռ�ʵ�ʣ�����һ�������ֵ�������
namespace N1
{
	int a = 20;
	int b = 20;


	int Add(int left, int right)
	{
		return left + right;
	}
}


// �����ռ����Ƕ��---�����ռ��п��Զ��������ռ�
// ѧУ
//   Ժϵ
//     רҵ
//       �༶
//         ����
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
	printf("%d\n", a);   // main�ֲ�����a
	printf("%d\n", ::a);   // ȫ���������е�a, ::�������޶���

	printf("%d\n", N1::a);   // N1�����ռ��е�a
	printf("%d\n", N2::a);   // N2�����ռ��е�a
	printf("%d\n", N2::N3::a);   // N3�����ռ��е�a
	return 0;
}
#endif

#if 0
// int a = 10;

// �����ռ��г�Ա��ʹ��
namespace N1
{
	int a = 20;
	int b = 20;


	int Add(int left, int right)
	{
		return left + right;
	}
}


// 1. �������ռ��Աǰ����N1::(�����ռ������Լ��������޶���)
// 2. using N1::��Ա����;
using N1::b;  // b�൱���Ǹ��ļ���ȫ�ֱ���(ʵ��b��N1�����ռ��еĳ�Ա)
//using N1::a;


// 3. using namespace N1;
using namespace N1;   // �ŵ㣺�����ռ��еĳ�Ա����ֱ���ڵ�ǰ�ļ���ֱ��ʹ��
                      // ȱ�ݣ�������ͻ�ĸ��ʱȽϴ�

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
// ����������ͬ���������ռ�
// ������һ�������ж�����ͬ���Ƶ������ռ�,�������Ὣ��ͬ���������ռ��е����ݺϲ���һ��

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



// #include <iostream.h>   �ɵı�����֧��---����vs6.0
//#include <iostream>
//using namespace std;


#if 0
// ��������
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
// ����ԭ�ͣ�����ֵ����   ��������(�����б�){}
// C���Ա������Ժ���ԭ�ͼ��Ҫ���Ƿǳ��ϸ�
// C++�������뺯��ԭ�ͼ����ӵ��ϸ�
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
// ��̥
// �ܷ����������Ĭ��ֵ
// ȱʡ����
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
// ȱʡ�������ࣺ
// 1. ȫȱʡ����---���в���������Ĭ��ֵ
void TestFunc(int a = 10, int b = 20, int c = 30)
{
	cout << a << " " << b << " " << c << endl;
}


// �������ι��򣺴�������һ�������ݲ���
// ȱʡ����ƥ����򣺴�������������ƥ��---��
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
// 2. ��ȱʡ���������ֲ�������Ĭ��ֵ---Ĭ��ֵֻ�ܴ����������θ��������ܸ��Ÿ�
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
// Ĭ��ֵ�����ں��������Ͷ���λ��ͬʱ����
void TestFunc(int a = g_a/*10*/);

void TestFunc(int a)
{
	cout << a << endl;
}


// 1. Ϊʲô����ͬʱ������λ�ø�����һ��С�ģ������Ͷ���λ�ø�����Ĭ��ֵ���ܲ�һ�£��ڵ���ʱ��Ӧ������һ���ͻ��������
// 2. �Ǹ�λ�ø����ȽϺã�������λ��

int main()
{
	return 0;
}
#endif


#if 0
// ��C�����У��������ֱ���Ψһ
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
// �����б�ͬ
// 1��2����������������ͬ
// 2��3����������������
// 4��5���������ʹ���ͬ

// ����6���ܺ�����2�������γ�����----��Ϊ���������������Ƿ���ֵ���Ͳ�ͬ
// ���ۣ����������������ֻ����Ϊ����ֵ���Ͳ�ͬ���ǲ��ܹ������ص�
// Ϊʲô��
#endif

#if 0
// �������صĵ���ԭ��
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


// ���������ڵ���ʱ����Ӧ�õ����Ǹ��������Ǳ������ڱ���׶�ȷ����
// �ڱ���׶Σ���������Դ��ݵ�ʵ�����ͽ������ݣ��������ݵĽ��ѡ����ʵĺ������е���
// ע�⣺������ݳ�����û�к��ʵĽ�����ã��������᳢�Խ��в�����ʽ����ת��
//     ת����ɳ��к��ʵĺ����ɹ����ã������ɹ�
//     ת����ɺ�û�к��ʺ����ɹ����ã�����˵���ܽ���ת����������ʧ��
int main()
{
	Add(1, 2);     // int,int--->Add(int,int)
	Add(1.0, 2.0); // double, double--->Add(double, double)
	Add('1', '2'); // û���ṩ�ַ����͵ļӷ�������char��int���Է�����ʽ����ת��--->char,char-->��ʽ����ת��-->int,int
	               // 

	// Add(1, 2.0);   // int double  ת����int  int����double double����������֪�������ת��---ֱ�ӱ���
	Add(1, (int)2.0);
	return 0;
}
#endif

#if 0
// C����
// �������ֱ����Σ�_Add
int Add(int left, int right);

// _Add
double Add(double left, double right);

// ���ۣ�C���Ա������Ժ����������ι��򣺽���ֻ���ں�������ǰ������һ���»���
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
// ��������Ϊʲô�ͷ���ֵû�й�ϵ��
int Add(int left, int right)
{
	return left + right;
}

double Add(int left, int right)
{
	return left + right;
}

// �������ֻ�Ƿ���ֵ���Ͳ�ͬ�����γ�����

int main()
{
	int ret1 = Add(1, 2);
	double ret2 = Add(1, 2);

	// �����Ǹ���
	Add(1,2);
	return 0;
}
#endif

#if 0
// C���Ժ�C++�������Ժ����������εĹ���һ��

// C++��������?Add@@YANHH@Z
extern "C" double Add(int left, int right)
{
	return left + right;
}

// �õ�C�����е���--->C���Ա�����_Add

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

	// ���ñ��������ͱ���Ҫ��ʵ�������һ��
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

	// int& ra;  ����ʧ��

	int& ra = a;

	int& rra = a;

	ra = 100;
	rra = 200;

	// ����ֻ�ܺ�һ��ʵ���Ӧ������һ������һ��ʵ�壬�ٲ�����������ʵ��
	int b = 10;
	int& rb = b;

	rb = a;   // ע�⣺������䲻����rb����a�����ǽ�a��ֵ��ֵ��rb
	// &rb = a;  ����ʧ��--->&rb�Ƕ�rbȡ��ַ

	rb = 20;

	// ʵ��--->���ñ��� �Ǹ����������ڳ���
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
	// 1. Ϊ��д����򵥣��ں����и�ʵ��ȡ����
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

// ���õ�Ӧ�ó�����
// 1. Ϊ��д����򵥣��ں����и�ʵ��ȡ����
// 2. ��Ϊ�����Ĳ���--->������ַ�ʹ�ֵ���ŵ�������---��ֵ�����Լ����������ǿ����嵽ָ���Ч��
//                    ע�⣺�������ͨ���βθı�ʵ�Σ����Խ��β�����Ϊconst���͵�

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
// 3. ��Ϊ�����ķ���ֵ����
// ע�⣺���ܷ��غ���ջ�ϵĿռ䣬��Ϊ�������н�����ջ�ռ䱻����
//      ����ڵ���λ�������õķ�ʽ���պ����ķ���ֵ���������������õľ���һ��Ƿ��Ŀռ�

// ���������Ϊ�����ķ���ֵ������Ӧ����ô���أ�
// ֻҪ���صı������������ڲ��ܺ�������(���溯������������)����
// ����ֵ��ȫ�ֱ�������static���εı������������͵Ĳ���
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
// ��֤����ֵ������ַ��������

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

	// ���Դ�ֵ---A����һ��
	size_t begin = clock();
	for (int i = 0; i < 1000000; ++i)
		TestValueParam(a);
	size_t end = clock();
	cout << end - begin << endl;

	// ������---����
	begin = clock();
	for (int i = 0; i < 1000000; ++i)
		TestRefParam(a);
	end = clock();
	cout << end - begin << endl;
}

void Test2()
{
	A a;

	// ���Դ���ַ
	size_t begin = clock();
	for (int i = 0; i < 1000000; ++i)
		TestPtrParam(&a);
	size_t end = clock();
	cout << end - begin << endl;

	// ������---����
	begin = clock();
	for (int i = 0; i < 1000000; ++i)
		TestRefParam(a);
	end = clock();
	cout << end - begin << endl;
}

// ���ۣ���ֵ��Ч�����--->��ֵÿ�ζ���Ҫ����һ�ݿ���
//      ����ַ�ʹ����ã�Ч�ʼ���һ��
int main()
{
	//Test1();
	for (int i = 0; i < 10; ++i)
		Test2();
	return 0;
}
#endif

// ָ���������ʲô���� *****
// ָ������õ���û������--->���ף��ײ�ʵ��

// �����Լ�ʹ��

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