#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include"SeqList.h"



//ͨѶ¼�ĳ�ʼ�� 
void contactInit(Contact* con)
{
	//��ͨѶ¼�Ĳ������Ƕ�˳���Ĳ���
	SLInit(con);
}
//ͨѶ¼������
void ContactDesTroy(Contact* con)
{
	SLDestroy(con);
}
//ͨѶ¼�����ݵ����
void ContactAdd(Contact* con)
{
	//��ȡ�û����������:����+�Ա�+����+�绰+��ַ
	peoInfo info;
	printf("���������û�������\n");
	scanf("%s", info.name);

	printf("���������û����Ա�\n");
	scanf("%s",info.gender);

	printf("���������û�������\n");
	scanf("%d", &info.age);

	printf("���������û��ĵ绰\n");
	scanf("%s", info.tel);

	printf("���������û��ĵ�ַ\n");
	scanf("%s", info.addr);

	//�����û�������ͨ��˳����β������˳�����
	SLPushBack(con, info);
}
//����ͨѶ¼�Ƿ���ڴ���ϵ�˵ĺ���
int FindByName(Contact*con,char name[NAME_MAX])
{
	for (int i = 0;; i++)
	{
		if (0 == strcmp(con->arr[i].name, name))
		{
			printf("ͨѶ¼�д���%s����\n", name);
			return i;
		}
	}
	printf("ͨѶ¼��δ�洢%s����Ϣ", name);
	return -1;
}
//ͨѶ¼ɾ������
void ContactDel(Contact* con)
{
	// Ҫɾ�������ݱ���Ҫ���ڣ�����ִ��ɾ������
	//����
	char name[NAME_MAX];
	printf("����������Ҫɾ������ϵ��\n");
	scanf("%s",name);
	int find = FindByName(con, name);
	if (find >=0)
	{
		SLErase(con, find);
		printf("ɾ���ɹ�\n");
	}
	else
	{
		printf("ɾ��ʧ��\n");
	}
}
//չʾͨѶ¼����ϵ������
void ContactShow(Contact* con)
{
	printf(" ����     �Ա� ����    �绰        ��ַ\n");
	for (int i = 0; i < con->size; i++)
	{
		printf("%2s %7s %3d %7s %s\0",
			con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].addr
			    );
        printf("\n");
		
	}
	printf("\n");
}
//�޸�ͨѶ¼����
void ContactModify(Contact* con)
{
	// Ҫ�޸ĵ����ݱ���Ҫ���ڣ�����ִ���޸Ĳ���
	//����
	char name[NAME_MAX];
	printf("����������Ҫ�޸ĵ���ϵ�˵�����\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find >= 0)
	{
		printf("�������޸ĺ���û�������\n");
		scanf("%s",con->arr[find].name);

		printf("�������޸ĺ���û����Ա�\n");
		scanf("%s", con->arr[find].gender);

		printf("�������޸ĺ���û�������\n");
		scanf("%d", &con->arr[find].age);

		printf("�������޸ĺ���û��ĵ绰\n");
		scanf("%s", con->arr[find].tel);

		printf("�������޸ĺ���û��ĵ�ַ\n");
		scanf("%s", con->arr[find].addr);
	}
}
//ͨѶ¼���ݵĲ���
void ContactFind(Contact* con)
{
	char name[NAME_MAX];
	printf("������Ҫ���ҵ���ϵ�˵�����\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find >= 0)
	{
		printf("%s����ϢΪ:\n", con->arr[find].name);
		printf("����:%s\n", con->arr[find].name);
		printf("�Ա�:%s\n", con->arr[find].gender);
		printf("����:%d\n", con->arr[find].age);
		printf("�绰:%s\n", con->arr[find].tel);
		printf("��ַ:%s\n", con->arr[find].addr);
	}

}
//����ͨѶ¼���ļ���
void Savecontact(Contact* con)
{
	FILE* pf = fopen("contact.txt","wb"); 
	if (pf == NULL)
	{
		perror("fopen error!\n");
		return;
	}
	      //��ͨѶ¼����д���ļ�
	for (int i = 0; i < con->size; i++)
	{
			fwrite(con->arr+i, sizeof(peoInfo), 1, pf);
	}
		printf("ͨѶ¼���ݱ���ɹ�!\n");


}
//��ʷ���ݵ���ͨѶ¼
void LoadContact(Contact* con)
{
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("fopen error!\n");
		return;
	}

	//ѭ����ȡ�ļ�����
	peoInfo info;
	while (fread(&info, sizeof(peoInfo), 1, pf))
	{

		SLPushBack(con, info);
	}
			printf("��ʷ���ݵ���ͨѶ¼�ɹ�!\n");
}