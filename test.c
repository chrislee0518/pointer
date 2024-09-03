#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//void test1(int arr[][5])//数组接收
//{
//
//}
//void test2(int(*arr)[5])//指针接收
//{
//
//}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test1(arr);//函数传参传过去的是二维数组的首地址，实质上是指向第一行的指针
//	test2(arr);
//	return 0;
//}

//二级指针传参
//void test(char** p)
//{
//
//}
//
//int main()
//{
//	char c = 'b';
//	char* pc = &c;
//	char** ppc = &pc;//二级指针=一级指针的地址
//	char* arr[10];//指针数组，里面元素都是地址
//	test1(&pc);//一级指针的地址
//	test2(ppc);//二级指针本身
//	test3(arr);//一级指针的地址
//
//	return 0;
//}

//函数指针 指向函数的指针
//int add1(int x,int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int a = 3;
//	int b = 4;
//	int ret = add1(a, b);
//	printf("%d\n", ret);
//	//&函数名 和 函数 都是函数的地址
//	printf("%p\n", add1);
//	printf("%p\n", &add1);
//	//函数指针 
//	//int (*pa)(int,int)=add1;"()"表示是函数，里面要确定参数类型int，函数返回类型int
//	int (*pa)(int, int) = add1;//根据地址找到函数，可以调用(函数名就表示函数地址)
//	int ret2 = (pa)(4, 4);//add1的地址就存在pa里 add1==pa
//	int ret1=(*pa)(4, 5);//解引用函数地址，找到函数
//	printf("%d", ret2);
//	return 0;
//}

//void Print(char* str)
//{
//	printf("%s", str);
//}
//
//int main()
//{
//	
//	void (*pa)(char*) = Print;
//	(*pa)("qwer");
//	return 0;
//}

//(*(void(*)()0)()//void(*)()函数指针类型，对0进行强制类型转换，此时0是地址，*解引用找到函数
//调用该函数 无参数



//void (*signal(int,void(*)(int)))(int)
//void(*p)(int)表示函数指针类型，p->函数，//void(* )（int）表示函数返回类型//（例如int表示整数类型），是函数指针
//形如int add1（int，int），后面表示函数名和参数，前面的int表示返回类型

//解释：signal是一个函数声明
//signal函数有两个参数，一个int，一个是函数指针，该函数指针指向的函数参数是int，返回类型是void
//signal函数的返回类型也是一个函数指针：该函数指针指向的函数参数是int，返回类型是void

//简化
//typedef void(* pfun)(int);//把函数指针类型void(* )（int）重新定义为pfun
//pfun signal(int ,pfun);

//函数指针数组
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int main()
{
	int i = 0;
	int (*pa[4])(int, int) = {Add,Sub,Mul,Div};//pa先和[]结合，表示数组，
	//int (*  )(int,int),表示函数指针，数组内存的是函数指针-函数指针数组
	for (i = 0; i < 4; i++)
	{
		int ret = (*pa[i])(8, 4);//访问数组元素即调用里面的函数
		printf("%d ", ret);
	}
}