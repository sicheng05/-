#pragma once

#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR 100

//定义联系人数据结构
// 姓名 性别 年龄 电话 地址

typedef struct personlnfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR];
} peoInfo;
//给顺序表改一个名字 叫做通讯录
typedef struct SepList Contact;
//通讯录相关的方法

//通讯录的初始化 
void contactInit(Contact * con);

//通讯录的销毁 
void ContactDesTroy(Contact*con);
//通讯录添加数据 
void ContactAdd(Contact* con);
//通讯录删除数据
void ContactDel(Contact* con);
//展示通讯录的联系人数据
void ContactShow(Contact* con);
//修改通讯录数据
void ContactModify(Contact* con);
//通讯录数据的查找
void ContactFind(Contact* con);
//保存通讯录到文件中
void Savecontact(Contact* con);
//历史数据导入通讯录
void LoadContact(Contact* con);