#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//void test1(int arr[][5])//�������
//{
//
//}
//void test2(int(*arr)[5])//ָ�����
//{
//
//}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test1(arr);//�������δ���ȥ���Ƕ�ά������׵�ַ��ʵ������ָ���һ�е�ָ��
//	test2(arr);
//	return 0;
//}

//����ָ�봫��
//void test(char** p)
//{
//
//}
//
//int main()
//{
//	char c = 'b';
//	char* pc = &c;
//	char** ppc = &pc;//����ָ��=һ��ָ��ĵ�ַ
//	char* arr[10];//ָ�����飬����Ԫ�ض��ǵ�ַ
//	test1(&pc);//һ��ָ��ĵ�ַ
//	test2(ppc);//����ָ�뱾��
//	test3(arr);//һ��ָ��ĵ�ַ
//
//	return 0;
//}

//����ָ�� ָ������ָ��
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
//	//&������ �� ���� ���Ǻ����ĵ�ַ
//	printf("%p\n", add1);
//	printf("%p\n", &add1);
//	//����ָ�� 
//	//int (*pa)(int,int)=add1;"()"��ʾ�Ǻ���������Ҫȷ����������int��������������int
//	int (*pa)(int, int) = add1;//���ݵ�ַ�ҵ����������Ե���(�������ͱ�ʾ������ַ)
//	int ret2 = (pa)(4, 4);//add1�ĵ�ַ�ʹ���pa�� add1==pa
//	int ret1=(*pa)(4, 5);//�����ú�����ַ���ҵ�����
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

//(*(void(*)()0)()//void(*)()����ָ�����ͣ���0����ǿ������ת������ʱ0�ǵ�ַ��*�������ҵ�����
//���øú��� �޲���



//void (*signal(int,void(*)(int)))(int)
//void(*p)(int)��ʾ����ָ�����ͣ�p->������//void(* )��int����ʾ������������//������int��ʾ�������ͣ����Ǻ���ָ��
//����int add1��int��int���������ʾ�������Ͳ�����ǰ���int��ʾ��������

//���ͣ�signal��һ����������
//signal����������������һ��int��һ���Ǻ���ָ�룬�ú���ָ��ָ��ĺ���������int������������void
//signal�����ķ�������Ҳ��һ������ָ�룺�ú���ָ��ָ��ĺ���������int������������void

//��
//typedef void(* pfun)(int);//�Ѻ���ָ������void(* )��int�����¶���Ϊpfun
//pfun signal(int ,pfun);

//����ָ������
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
	int (*pa[4])(int, int) = {Add,Sub,Mul,Div};//pa�Ⱥ�[]��ϣ���ʾ���飬
	//int (*  )(int,int),��ʾ����ָ�룬�����ڴ���Ǻ���ָ��-����ָ������
	for (i = 0; i < 4; i++)
	{
		int ret = (*pa[i])(8, 4);//��������Ԫ�ؼ���������ĺ���
		printf("%d ", ret);
	}
}