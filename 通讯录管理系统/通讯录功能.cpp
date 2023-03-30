#include <iostream>
#include <stdbool.h>
#include "ͨѶ¼ͷ�ļ�.h"
#include <locale.h>
#include <iomanip>
using namespace std;

/* ����һ��ͨѶ¼���� */
bool Creat_mail(Mail  *mail) {
	(*mail).phead = new Mail_node();
	(*mail).phead = NULL;
	(*mail).size = 0;
	return true;
}



/*1�����벢�ҳ�ʼ��һ���ڵ� */
static Mail_list_node  Init_mial_node();

/* ��ȡ�ַ����ĺ���*/
static void get_String(wstring *s );

/* �õ����ֵĺ��� */
static void get_name(wstring *s);

/* �õ��Ա���*/
static void get_sex(string* s);

/* ɾ����ϵ�˹��ܺ��� */
static bool delet_mail_node(Mail_list_node* mail , wstring ws);

/* 2�����ͨѶ¼�Ĺ��ܺ���*/
void vist_mail(Mail_list_node mail);

/* ����ͨѶ¼ĳ����Ŀ�Ĺ��ܺ���*/
bool find_node(Mail_list_node mail,wstring ws,Mail_list_node * temp );

/* �޸���ϵ�˵Ĺ��ܺ��� */
static bool change(Mail_list_node *mail);

/* �õ����� */
static void get_age(int *age);

/* �޸���ϵ�˵�ѡ��*/
char chang_meun();


/*1�����벢�ҳ�ʼ��һ���ڵ� */
static Mail_list_node  Init_mial_node(){
	Mail_list_node mal = new Mail_node();
	mal->next = NULL;
	//get_name(&mal->name);
	cout << "����������" << endl;
	get_String(&(mal->name));
	cout << "�������Ա�" << endl;
	get_sex(&(mal->sex));
	wcout << "����������" << endl;
	get_age(&(mal->age));
	wcout << "������绰" << endl;
	get_String(&(mal->number_phone));
	wcout << "�������ַ" << endl;
	get_String(&(mal->address));
	return mal;
}

/* �޸���ϵ�˵�ѡ��*/
char chang_meun() {
	int ch;
	cout << "1������:  " << "2���Ա�: " << "3������:  " << "4���绰:  " << "5����ַ:  " << "6������" << endl;
	cout << "��ѡ��1-6" << endl;
	while (((ch) = getchar()) != EOF)
	{
		if (getchar() == '\n') {
			if (ch >= '1' && ch <= '6') {
				break;
			}
			cout << "������1-6" << endl;
		}
		else {
			cout << "������1-6" << endl;
			while (getchar() != '\n')
				continue;
		}
	}
	return ch;
}

/* �õ����ֵĺ��� */
static void get_name(wstring *s) {
	
	get_String(s);
	return;
}

/* �õ��Ա�ĺ��� */
static void get_sex(string* s) {
	string man = "��";
	string women = "Ů";
	string sex ;
	getline(cin, sex);
	//get_String(&sex);
	while  (sex != man && sex != women ) {
		cout << "����,��������!" << endl;
		getline(cin, sex); 
	}
	*s = sex;
}

/* ��ȡ�ַ����ĺ���*/
static void get_String(wstring *S){
	//setlocale(LC_ALL, "chs");
	wstring space = L"";
	getline(wcin, *S);
	while (*S == space)
	{
		cout << "��������������" << endl;
		getline(wcin, *S);
	}
	return;
}

/* �õ�����ĺ��� */
static void get_age(int* age) {
	int a = 0;
	while (!(cin >> a) || a < 0 || a > 130)
	{
		cout << "���������������:" << endl;
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}
	}
	*age = a;
	while (cin.get() != '\n')
		continue;
}

/* �޸���ϵ�˵Ĺ��ܺ��� */
static bool change(Mail_list_node *mail) {
	int ch;
	while ((ch = chang_meun()) != '6'  )
	{
		switch (ch) {
		case '1':
			cout << "����������:" << endl;
			get_String(&(*mail)->name);
			cout << "****************************************" << endl;
			cout << "�޸ĳɹ�" << endl;
			break;
		case '2':
			cout << "�������Ա�:" << endl;
			get_sex(&(*mail)->sex);
			cout << "****************************************" << endl;
			cout << "�޸ĳɹ�" << endl;
			break;
		case '3':
			cout << "����������:" << endl;
			get_age(&(*mail)->age);
			cout << "****************************************" << endl;
			cout << "�޸ĳɹ�" << endl;
			break;
		case '4':
			cout << "������绰:" << endl;
			get_String(&(*mail)->number_phone);
			cout << "****************************************" << endl;
			cout << "�޸ĳɹ�" << endl;
			break;
		case '5':
			cout << "�������ַ:" << endl;
			get_String(&(*mail)->address);
			cout << "****************************************" << endl;
			cout << "�޸ĳɹ�" << endl;
			break;
		}
	}
	if (ch == EOF ) {
		exit(-1);
	}
	if (ch == '6') {
		cout << "����" << endl;
	}
	return true;
}

/* ɾ����ϵ�˵Ĺ��ܺ��� */
static bool delet_mail_node(Mail_list_node* mail , wstring ws) {
	Mail_list_node p = *mail  ;
	Mail_list_node temp;
	if (!p || !find_node(*mail , ws , &temp)) {
		//cout << "ɾ��ʧ�ܣ��յ�ͨѶ¼!" << endl;
		return false;
	}
	if ((*mail) == temp) {
		(*mail) = temp->next;
		return true;
	}
	while (p->next  && p->next != temp )
	{
		p = p->next;
	}
	if (!p) {
		return false;
	}
	p->next = temp->next;
	free(temp);
	return true;
}

/* ���ͨѶ¼�Ĺ��ܺ���*/
void vist_mail(Mail_list_node mail) {
	cout << "*****************************************************" << endl;
	wcout << "����:---" << setw(11) << mail->name << " ";
	cout << "�Ա�:---" << setw(3) << mail->sex << " ";
	wcout << "����:---" << setw(4) << mail->age << " ";
	wcout << "�绰:---" << setw(11) << mail->number_phone << " ";
	wcout << "סַ:---" << setw(15) << mail->address << endl;
	cout << "*****************************************************\n" << endl;
}

/* ����ͨѶ¼ĳ����Ŀ�Ĺ��ܺ���*/
bool find_node(Mail_list_node mail , wstring ws , Mail_list_node* temp) {
	Mail_list_node p = mail;
	if (p == NULL) {
		cout << "�յ�ͨѶ¼" << endl;
		return false;
	}
	while (p)
	{
		if (p->name == ws) {
			//wcout << "�ҵ���" << ws <<  endl;
			*temp = p;
			break;
		}
		p = p->next;
	}
	if (!p) {
		return false;
	}
	return true;
}


/* 1��add ��ϵ�� */
bool add_Mail_list(Mail* mail) {
	Mail_node* node = Init_mial_node();
	//cout << node << endl;
	if (mail->phead == NULL) {
		mail->phead = node;
	}
	Mail_list_node p;
	p = mail->phead;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = node;
	mail->size++;
	node->next = NULL;
	cout << "-----------------" << endl;
	return true;
}

/* 2�����ͨѶ¼ */
void show_mail(Mail mail) {
	int i = 1;
	if (mail.size == 0) {
		cout << "�յ�ͨѶ¼" << endl;
	}
	else {
		Mail_list_node pm = mail.phead;
		while (pm)
		{
			cout << i << "��" << endl;
			vist_mail(pm);
			pm = pm->next;
			i++;
		}
	}
}

/* 3��ɾ����ϵ�� */
bool delete_mail(Mail *mail){
	wstring delde_name;
	cout << "��������Ҫɾ���˵�����:" << endl;
	get_String(&delde_name);
	if (delet_mail_node(&((*mail).phead),delde_name)) {
		cout << "ɾ���ɹ�" << endl;
		(*mail).size--;
	}
	else
	{
		wcout << "ɾ��ʧ��,ͨѶ¼������" << delde_name << "�����֣�" << endl;
		return false;
	}
	//niuap
	return true;
}

/* 4��������ϵ��*/
/* ǰ������: ͨѶ¼���ڣ���Ϊ��*/
/* ��������: �ҵ�����true�����򷵻�false*/
bool find_mail_node(Mail  mail){
	if (mail.phead == NULL) {
		cout << "�յ�ͨѶ¼!" << endl;
		return false;
	}
	wstring find_name;
	Mail_list_node temp;
	cout << "��������Ҫ���ҵ����֣�" << endl;
	get_name(&find_name);
	if (find_node(mail.phead, find_name,&temp) == true) {
		//cout << "�ҵ���" << endl;
		cout << "****************************************" << endl;
		vist_mail(temp);
	}
	else {
		cout << "û�ҵ�" << endl;
		return false;
	}
	return true; 
}

/* 5���޸���ϵ�� */
/* ǰ������: ͨѶ¼���ڣ���Ϊ�� */
/* ����������������ϵ�˷���true*/
bool change_mail(Mail mail){
	wstring find_name;
	Mail_list_node temp;
	cout << "��������Ҫ�޸ĵ��˵����֣�" << endl;
	get_name(&find_name);
	if (find_node(mail.phead, find_name, &temp) == true) {
		//cout << "�ҵ���" << endl;
		change(&temp);
	}
	else {
		wcout << "û����ϵ��:" << find_name <<  endl;
		return false;
	}
	return  true;
}



/* 6�����ͨѶ¼ */
/* ǰ��������ͨѶ¼���ڣ���Ϊ��*/
/* �������������ͨѶ¼*/
bool Clear_mail(Mail *mail) {
	if ((*mail).phead == NULL) {
		return true;
	}
	Mail_list_node p , q ;
	p = (*mail).phead;
	while (p)
	{
		q = p;
		p = p->next;
		delete(q);
	}
	(*mail).size = 0;
	return true;
}
