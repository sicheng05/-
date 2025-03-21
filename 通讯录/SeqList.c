#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//˳���ĳ�ʼ��
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//˳��������
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//����ռ亯��
void SLcheckrapacity(SL* ps)
{
	//�ռ䲻������
	if (ps->capacity == ps->size)//assert��Ҫ�������ﲻ��Ϊ��
	{
		//����ռ�
		//malloc calloc realloc int arr[100]--->����reallo
		//��Ŀ���ʽ
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* stp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));//����ռ�
		if (stp == NULL)
		{
			perror("realloc");//ֱ���˳����򣬲��ټ���ִ��
			exit(1);
		}
		ps->arr = stp;//����ɹ�
		ps->capacity = newCapacity;
	}
}
//β������
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);//ps�����ǿ�ָ�� ��Ϊ���ǲ��ܶԿ�ָ����н����ò���
	//�ռ䲻������
	SLcheckrapacity(ps);
	//β��ʵ��
	ps->arr[ps->size] = x;
	ps->size++;//�������ݸ�����1
}
//ͷ������
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLcheckrapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];//��Ԫ�������ƶ�1λ  arr[1] arr[0]
	}
	ps->arr[0] = x;
	ps->size++;//�洢���ݸ���+1
}
//��ӡ����
//void SLPrint(SL s)
//{
//	for (int i = 0; i < s.size; i++)//��Ϊ����Ҫ�ı�sl�е��������Բ���Ҫ����sl��ָ��
//	{
//		printf("%d ", s.arr[i]);
//	}
//	printf("\n");
//}

//βɾ
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);

	ps->size--;//ֱ��size��1Ҳ���� ��Ϊ ֻ��size��Ԫ�� �������ǲ�����±�λsize��Ԫ�ز���
	//sl->arr[sl->size--] = -1;
}
//ͷɾ
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
//��ָ��λ��֮ǰ��������
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	//��������:�ռ乻����
	SLcheckrapacity(ps);
	for (int i = ps->size; i > pos; i--)//��pos֮������� �������ƶ�һλ
	{
		ps->arr[i] = ps->arr[i - 1];//arr[ pos + 1 ] = arr[ pos ] 
	}
	ps->arr[pos] = x;
	ps->size++;
}
//ɾ��ָ��λ�õ�����
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	//for (int i = ps->size;i >= pos;i--)//���ԴӺ���ǰŲ������arr[pos]
	//}
	//{
	//	ps->arr[i] = ps->arr[i - 1];//arr[pos ] = arr[pos+1]   
	for (int i = pos; i < ps->size - 1; i++)//���ԴӺ�ǰ�� һ��ʼ�Ͱ�arr[pos]���ǵ�
	{
		ps->arr[i] = ps->arr[i + 1];//arr[size-2] = arr[size - 1]  i = siz
	}
	ps->size--;
}
//˳������ݵĲ���
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