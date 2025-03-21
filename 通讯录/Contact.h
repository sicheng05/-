#pragma once

#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR 100

//������ϵ�����ݽṹ
// ���� �Ա� ���� �绰 ��ַ

typedef struct personlnfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR];
} peoInfo;
//��˳����һ������ ����ͨѶ¼
typedef struct SepList Contact;
//ͨѶ¼��صķ���

//ͨѶ¼�ĳ�ʼ�� 
void contactInit(Contact * con);

//ͨѶ¼������ 
void ContactDesTroy(Contact*con);
//ͨѶ¼������� 
void ContactAdd(Contact* con);
//ͨѶ¼ɾ������
void ContactDel(Contact* con);
//չʾͨѶ¼����ϵ������
void ContactShow(Contact* con);
//�޸�ͨѶ¼����
void ContactModify(Contact* con);
//ͨѶ¼���ݵĲ���
void ContactFind(Contact* con);
//����ͨѶ¼���ļ���
void Savecontact(Contact* con);
//��ʷ���ݵ���ͨѶ¼
void LoadContact(Contact* con);