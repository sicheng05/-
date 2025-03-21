#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Contact.h"

//����˳���ṹ
//#define N 100;
//��̬˳���
//struct SepList
//{
//	int arr[N];
//	int size;
//};

typedef  peoInfo SLDataType;

//��̬˳���

typedef struct SepList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//˳���ĳ�ʼ��
void SLInit(SL* ps);

//˳��������
void SLDestroy(SL* ps);

//��ӡ����
//void SLPrint(SL s);

//β������
void SLPushBack(SL* ps, SLDataType x);
//ͷ������
void SLPushFront(SL* ps, SLDataType x);
//βɾ
void SLPopBack(SL* ps);
//ͷɾ
void SLPopFront(SL* ps);
//��ָ��λ��֮ǰ��������
void SLInsert(SL* ps, int pos, SLDataType x);
//ɾ��ָ��λ�õ�����
void SLErase(SL* ps, int pos);
//˳������ݵĲ���
//int SLFind(SL s, SLDataType x);
