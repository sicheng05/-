#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Contact.h"

//定义顺序表结构
//#define N 100;
//静态顺序表
//struct SepList
//{
//	int arr[N];
//	int size;
//};

typedef  peoInfo SLDataType;

//动态顺序表

typedef struct SepList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//顺序表的初始化
void SLInit(SL* ps);

//顺序表的销毁
void SLDestroy(SL* ps);

//打印数据
//void SLPrint(SL s);

//尾部插入
void SLPushBack(SL* ps, SLDataType x);
//头部插入
void SLPushFront(SL* ps, SLDataType x);
//尾删
void SLPopBack(SL* ps);
//头删
void SLPopFront(SL* ps);
//在指定位置之前插入数据
void SLInsert(SL* ps, int pos, SLDataType x);
//删除指定位置的数据
void SLErase(SL* ps, int pos);
//顺序表数据的查找
//int SLFind(SL s, SLDataType x);
