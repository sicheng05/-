#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include"SeqList.h"



//通讯录的初始化 
void contactInit(Contact* con)
{
	//对通讯录的操作就是对顺序表的操作
	SLInit(con);
}
//通讯录的销毁
void ContactDesTroy(Contact* con)
{
	SLDestroy(con);
}
//通讯录新数据的添加
void ContactAdd(Contact* con)
{
	//获取用户输入的内容:姓名+性别+年龄+电话+地址
	peoInfo info;
	printf("请输入新用户的姓名\n");
	scanf("%s", info.name);

	printf("请输入新用户的性别\n");
	scanf("%s",info.gender);

	printf("请输入新用户的年龄\n");
	scanf("%d", &info.age);

	printf("请输入新用户的电话\n");
	scanf("%s", info.tel);

	printf("请输入新用户的地址\n");
	scanf("%s", info.addr);

	//将新用户的数据通过顺序表的尾查填入顺序表中
	SLPushBack(con, info);
}
//查找通讯录是否存在次联系人的函数
int FindByName(Contact*con,char name[NAME_MAX])
{
	for (int i = 0;; i++)
	{
		if (0 == strcmp(con->arr[i].name, name))
		{
			printf("通讯录中存在%s此人\n", name);
			return i;
		}
	}
	printf("通讯录中未存储%s的信息", name);
	return -1;
}
//通讯录删除数据
void ContactDel(Contact* con)
{
	// 要删除的数据必须要存在，才能执行删除操作
	//查找
	char name[NAME_MAX];
	printf("请输入你想要删除的联系人\n");
	scanf("%s",name);
	int find = FindByName(con, name);
	if (find >=0)
	{
		SLErase(con, find);
		printf("删除成功\n");
	}
	else
	{
		printf("删除失败\n");
	}
}
//展示通讯录的联系人数据
void ContactShow(Contact* con)
{
	printf(" 姓名     性别 年龄    电话        地址\n");
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
//修改通讯录数据
void ContactModify(Contact* con)
{
	// 要修改的数据必须要存在，才能执行修改操作
	//查找
	char name[NAME_MAX];
	printf("请输入你想要修改的联系人的姓名\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find >= 0)
	{
		printf("请输入修改后的用户的姓名\n");
		scanf("%s",con->arr[find].name);

		printf("请输入修改后的用户的性别\n");
		scanf("%s", con->arr[find].gender);

		printf("请输入修改后的用户的年龄\n");
		scanf("%d", &con->arr[find].age);

		printf("请输入修改后的用户的电话\n");
		scanf("%s", con->arr[find].tel);

		printf("请输入修改后的用户的地址\n");
		scanf("%s", con->arr[find].addr);
	}
}
//通讯录数据的查找
void ContactFind(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要查找的联系人的姓名\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find >= 0)
	{
		printf("%s的信息为:\n", con->arr[find].name);
		printf("姓名:%s\n", con->arr[find].name);
		printf("性别:%s\n", con->arr[find].gender);
		printf("年龄:%d\n", con->arr[find].age);
		printf("电话:%s\n", con->arr[find].tel);
		printf("地址:%s\n", con->arr[find].addr);
	}

}
//保存通讯录到文件中
void Savecontact(Contact* con)
{
	FILE* pf = fopen("contact.txt","wb"); 
	if (pf == NULL)
	{
		perror("fopen error!\n");
		return;
	}
	      //将通讯录数据写人文件
	for (int i = 0; i < con->size; i++)
	{
			fwrite(con->arr+i, sizeof(peoInfo), 1, pf);
	}
		printf("通讯录数据保存成功!\n");


}
//历史数据导入通讯录
void LoadContact(Contact* con)
{
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("fopen error!\n");
		return;
	}

	//循环读取文件数据
	peoInfo info;
	while (fread(&info, sizeof(peoInfo), 1, pf))
	{

		SLPushBack(con, info);
	}
			printf("历史数据导入通讯录成功!\n");
}