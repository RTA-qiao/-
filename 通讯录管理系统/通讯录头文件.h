#pragma once
/*
	2023年3月26日
	21点44分
	功能：简单的通讯录
	1、添加联系人
	2、显示联系人
	3、删除联系人
	4、查找联系人
	5、修改联系人
	6、清空联系人
	7、退出通讯录
*/
#include <string>
#include <iostream>
#include <stdbool.h>
using namespace std;
typedef struct M_Node {
	wstring name;					//名字
	string sex;						//性别
	int  age;						//年龄
	wstring number_phone;			//电话
	wstring address;					//地址
	struct M_Node* next = NULL;			//下一个节点的位置
} Mail_node, * Mail_list_node;
typedef struct Mail_list {
	Mail_list_node phead;			//线性表的头
	int size;						//线性表的大小
}Mail;

/* 1、add 联系人 */
/* 操作：添加一个成员*/
/* 前置条件：线性表存在 */
/* 后置条件：向线性表中添加一个数据，如果成功返回true，否则返回false*/
bool add_Mail_list(Mail *mail);

/* 2、初始化一个空的通讯录链表 */
/* 创建成功返回true */
bool Creat_mail(Mail  *mail);

/* 3、显示联系人*/
/* 前置条件：通讯录存在*/
/* 后置条件：输出通讯录*/
void show_mail(Mail  mail);

/* 4、删除联系人 */
/* 前置条件：通讯录存在 */
/* 后置条件：删除通讯录中的某个项目，成功返回true，否则返回false*/
bool delete_mail(Mail *mail);

/* 5、查找联系人*/
/* 前置条件: 通讯录存在，不为空*/
/* 后置条件: 找到返回true，否则返回false*/
bool find_mail_node(Mail  mail);

/* 5、修改联系人 */
/* 前置条件: 通讯录存在，不为空 */
/* 后期条件：更改联系人返回true*/
bool change_mail(Mail nail);

/* 6、清空通讯录 */
/* 前置条件：通讯录存在，不为空*/
/* 后置条件：清空通讯录*/
bool Clear_mail(Mail *mail);
