#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include"SeqList.h"



//void test()
//{
//	Contact con;
//	contactInit(&con);
//	ContactAdd(&con);
//	ContactAdd(&con);
//	ContactFind(&con);
//	ContactShow(&con);
//	ContactModify(&con);
//	ContactShow(&con);
//	ContactDel(&con);
//	ContactShow(&con);
//	ContactDesTroy(&con);
//	
//}
void menu()
{
	printf("****************ͨѶ¼****************\n");
	printf("**************************************\n");
	printf("******1.�����ϵ�� 2.ɾ����ϵ��*******\n");
	printf("******3.�޸���ϵ�� 4.������ϵ��*******\n");
	printf("******5.չʾͨѶ¼ 0.�˳�ͨѶ¼	******\n");
	printf("**************************************\n");
	printf("**************************************\n");
	printf("\n");
	printf("��ѡ��\n");

}
void test()
{


}
enum contact
{
    Exit,
	ADD,
	DEL,
	Modify,
	Find,
	Show
};
int main()
{
	Contact con;
	contactInit(&con);
	LoadContact(&con);
	int op = 0;
	
	do
	{
		
		menu();
		scanf("%d", &op);
		switch (op)
		{
		case ADD:
			ContactAdd(&con);
			break;
		case DEL:
			ContactDel(&con);
			break;
		case Modify:
			ContactModify(&con);
			break;
		case Find:
			ContactFind(&con);
			break;
		case Show:
			ContactShow(&con);
			break;
		case Exit:
				break;
		default:
			break;
		}
	} while (op);
	Savecontact(&con);
    ContactDesTroy(&con);
	return 0;
}

