#include <iostream>
#include "通讯录头文件.h"
/* 菜单111去 */
static char   menu();
int main() {
	Mail mail;
	Creat_mail(&mail);
	char choice;
	while ((choice = menu ()) != '7')
	{
		switch (choice)
		{
		case '1':
			add_Mail_list(&mail);
			cout << "添加成功" << endl;
			break;
		case '2':
			cout << "****************************************" << endl;
			cout << "现在通讯录记录了---" << mail.size << "条!\n" << endl;
			show_mail(mail);
			break;
		case '3':
			cout << "****************************************" << endl;
			delete_mail(&mail);
			break;
		case '4':
			cout << "****************************************" << endl;
			(find_mail_node(mail));
			break;
		case '5':
			cout << "****************************************" << endl;
			change_mail(mail);
			break;
		case '6':
			Clear_mail(&mail);
			break;
	/*	default :
			cout << "输入错误!" << endl; ;
			break;*/
		}
	}
	cout << "bye!" << endl;
	return 0;
}




/* 菜单 */
static char  menu() {
	int ch;
	cout << "			   通讯录系统                          " << endl;
	cout << "**********************************************************" << endl;
	cout << "			1、添加联系人\n"
		"			2、显示联系人\n"
		"			3、删除联系人\n"
		"			4、查找联系人\n"
		"			5、修改联系人\n"
		"			6、清空联系人\n"
		"			7、退出通讯录\n"
		"**********************************************************" << endl;
	cout << "请选择1-7" << endl;
	while (((ch) = getchar()) != EOF)
	{
		if (ch == '\n') {
			cout << "请输入1-7" << endl;
			continue;
		}
		
		if (getchar() == '\n' ) {
			if  (ch >= '1'  && ch <= '7') {
				break;
			}
			cout << "请输入1-7" << endl;
		}
		else {
			cout << "请输入1-7" << endl;
			while (getchar() != '\n')
				continue;
		}
	}
	if (ch == EOF ) {
		ch = '7';
	}
	return ch; 
}
