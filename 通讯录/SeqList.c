#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//顺序表的初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//顺序表的销毁
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//申请空间函数
void SLcheckrapacity(SL* ps)
{
	//空间不足扩容
	if (ps->capacity == ps->size)//assert主要断言这里不能为空
	{
		//申请空间
		//malloc calloc realloc int arr[100]--->增容reallo
		//三目表达式
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* stp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));//申请空间
		if (stp == NULL)
		{
			perror("realloc");//直接退出程序，不再继续执行
			exit(1);
		}
		ps->arr = stp;//申请成功
		ps->capacity = newCapacity;
	}
}
//尾部插入
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);//ps不能是空指针 因为我们不能对空指针进行解引用操作
	//空间不足扩容
	SLcheckrapacity(ps);
	//尾插实现
	ps->arr[ps->size] = x;
	ps->size++;//储存数据个数＋1
}
//头部插入
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLcheckrapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];//把元素往后移动1位  arr[1] arr[0]
	}
	ps->arr[0] = x;
	ps->size++;//存储数据个数+1
}
//打印数据
//void SLPrint(SL s)
//{
//	for (int i = 0; i < s.size; i++)//因为不需要改变sl中的数据所以不需要传递sl的指针
//	{
//		printf("%d ", s.arr[i]);
//	}
//	printf("\n");
//}

//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);

	ps->size--;//直接size减1也可以 因为 只有size个元素 所以我们不会对下标位size的元素操作
	//sl->arr[sl->size--] = -1;
}
//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1]; //arr[size-2] = arr[size-1]
	}
	ps->size--;
}
//在指定位置之前插入数据
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	//插入数据:空间够不够
	SLcheckrapacity(ps);
	for (int i = ps->size; i > pos; i--)//把pos之后的数据 都往后移动一位
	{
		ps->arr[i] = ps->arr[i - 1];//arr[ pos + 1 ] = arr[ pos ] 
	}
	ps->arr[pos] = x;
	ps->size++;
}
//删除指定位置的数据
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	//for (int i = ps->size;i >= pos;i--)//可以从后往前挪动覆盖arr[pos]
	//}
	//{
	//	ps->arr[i] = ps->arr[i - 1];//arr[pos ] = arr[pos+1]   
	for (int i = pos; i < ps->size - 1; i++)//可以从后前往 一开始就把arr[pos]覆盖掉
	{
		ps->arr[i] = ps->arr[i + 1];//arr[size-2] = arr[size - 1]  i = siz
	}
	ps->size--;
}
//顺序表数据的查找
//int SLFind(SL s, SLDataType x)
//{
//	for (int i = 0; i < s.size; i++)
//	{
//		if (x == s.arr[i])
//		{
//			return i;
//		}
//	}
//	return -1;
//}