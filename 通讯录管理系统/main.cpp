#include <iostream>
#include "ͨѶ¼ͷ�ļ�.h"
/* �˵�111ȥ */
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
			cout << "��ӳɹ�" << endl;
			break;
		case '2':
			cout << "****************************************" << endl;
			cout << "����ͨѶ¼��¼��---" << mail.size << "��!\n" << endl;
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
			cout << "�������!" << endl; ;
			break;*/
		}
	}
	cout << "bye!" << endl;
	return 0;
}




/* �˵� */
static char  menu() {
	int ch;
	cout << "			   ͨѶ¼ϵͳ                          " << endl;
	cout << "**********************************************************" << endl;
	cout << "			1�������ϵ��\n"
		"			2����ʾ��ϵ��\n"
		"			3��ɾ����ϵ��\n"
		"			4��������ϵ��\n"
		"			5���޸���ϵ��\n"
		"			6�������ϵ��\n"
		"			7���˳�ͨѶ¼\n"
		"**********************************************************" << endl;
	cout << "��ѡ��1-7" << endl;
	while (((ch) = getchar()) != EOF)
	{
		if (ch == '\n') {
			cout << "������1-7" << endl;
			continue;
		}
		
		if (getchar() == '\n' ) {
			if  (ch >= '1'  && ch <= '7') {
				break;
			}
			cout << "������1-7" << endl;
		}
		else {
			cout << "������1-7" << endl;
			while (getchar() != '\n')
				continue;
		}
	}
	if (ch == EOF ) {
		ch = '7';
	}
	return ch; 
}
