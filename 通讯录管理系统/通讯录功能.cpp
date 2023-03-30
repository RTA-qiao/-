#include <iostream>
#include <stdbool.h>
#include "通讯录头文件.h"
#include <locale.h>
#include <iomanip>
using namespace std;

/* 创建一个通讯录链表 */
bool Creat_mail(Mail  *mail) {
	(*mail).phead = new Mail_node();
	(*mail).phead = NULL;
	(*mail).size = 0;
	return true;
}



/*1、申请并且初始化一个节点 */
static Mail_list_node  Init_mial_node();

/* 获取字符串的函数*/
static void get_String(wstring *s );

/* 得到名字的函数 */
static void get_name(wstring *s);

/* 得到性别函数*/
static void get_sex(string* s);

/* 删除联系人功能函数 */
static bool delet_mail_node(Mail_list_node* mail , wstring ws);

/* 2、输出通讯录的功能函数*/
void vist_mail(Mail_list_node mail);

/* 查找通讯录某个项目的功能函数*/
bool find_node(Mail_list_node mail,wstring ws,Mail_list_node * temp );

/* 修改联系人的功能函数 */
static bool change(Mail_list_node *mail);

/* 得到年龄 */
static void get_age(int *age);

/* 修改联系人的选项*/
char chang_meun();


/*1、申请并且初始化一个节点 */
static Mail_list_node  Init_mial_node(){
	Mail_list_node mal = new Mail_node();
	mal->next = NULL;
	//get_name(&mal->name);
	cout << "请输入名字" << endl;
	get_String(&(mal->name));
	cout << "请输入性别" << endl;
	get_sex(&(mal->sex));
	wcout << "请输入年龄" << endl;
	get_age(&(mal->age));
	wcout << "请输入电话" << endl;
	get_String(&(mal->number_phone));
	wcout << "请输入地址" << endl;
	get_String(&(mal->address));
	return mal;
}

/* 修改联系人的选项*/
char chang_meun() {
	int ch;
	cout << "1、姓名:  " << "2、性别: " << "3、年龄:  " << "4、电话:  " << "5、地址:  " << "6、返回" << endl;
	cout << "请选择1-6" << endl;
	while (((ch) = getchar()) != EOF)
	{
		if (getchar() == '\n') {
			if (ch >= '1' && ch <= '6') {
				break;
			}
			cout << "请输入1-6" << endl;
		}
		else {
			cout << "请输入1-6" << endl;
			while (getchar() != '\n')
				continue;
		}
	}
	return ch;
}

/* 得到名字的函数 */
static void get_name(wstring *s) {
	
	get_String(s);
	return;
}

/* 得到性别的函数 */
static void get_sex(string* s) {
	string man = "男";
	string women = "女";
	string sex ;
	getline(cin, sex);
	//get_String(&sex);
	while  (sex != man && sex != women ) {
		cout << "错误,重新输入!" << endl;
		getline(cin, sex); 
	}
	*s = sex;
}

/* 获取字符串的函数*/
static void get_String(wstring *S){
	//setlocale(LC_ALL, "chs");
	wstring space = L"";
	getline(wcin, *S);
	while (*S == space)
	{
		cout << "输入错误继续输入" << endl;
		getline(wcin, *S);
	}
	return;
}

/* 得到年龄的函数 */
static void get_age(int* age) {
	int a = 0;
	while (!(cin >> a) || a < 0 || a > 130)
	{
		cout << "输入错误重新输入:" << endl;
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

/* 修改联系人的功能函数 */
static bool change(Mail_list_node *mail) {
	int ch;
	while ((ch = chang_meun()) != '6'  )
	{
		switch (ch) {
		case '1':
			cout << "请输入名字:" << endl;
			get_String(&(*mail)->name);
			cout << "****************************************" << endl;
			cout << "修改成功" << endl;
			break;
		case '2':
			cout << "请输入性别:" << endl;
			get_sex(&(*mail)->sex);
			cout << "****************************************" << endl;
			cout << "修改成功" << endl;
			break;
		case '3':
			cout << "请输入年龄:" << endl;
			get_age(&(*mail)->age);
			cout << "****************************************" << endl;
			cout << "修改成功" << endl;
			break;
		case '4':
			cout << "请输入电话:" << endl;
			get_String(&(*mail)->number_phone);
			cout << "****************************************" << endl;
			cout << "修改成功" << endl;
			break;
		case '5':
			cout << "请输入地址:" << endl;
			get_String(&(*mail)->address);
			cout << "****************************************" << endl;
			cout << "修改成功" << endl;
			break;
		}
	}
	if (ch == EOF ) {
		exit(-1);
	}
	if (ch == '6') {
		cout << "返回" << endl;
	}
	return true;
}

/* 删除联系人的功能函数 */
static bool delet_mail_node(Mail_list_node* mail , wstring ws) {
	Mail_list_node p = *mail  ;
	Mail_list_node temp;
	if (!p || !find_node(*mail , ws , &temp)) {
		//cout << "删除失败，空的通讯录!" << endl;
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

/* 输出通讯录的功能函数*/
void vist_mail(Mail_list_node mail) {
	cout << "*****************************************************" << endl;
	wcout << "姓名:---" << setw(11) << mail->name << " ";
	cout << "性别:---" << setw(3) << mail->sex << " ";
	wcout << "年龄:---" << setw(4) << mail->age << " ";
	wcout << "电话:---" << setw(11) << mail->number_phone << " ";
	wcout << "住址:---" << setw(15) << mail->address << endl;
	cout << "*****************************************************\n" << endl;
}

/* 查找通讯录某个项目的功能函数*/
bool find_node(Mail_list_node mail , wstring ws , Mail_list_node* temp) {
	Mail_list_node p = mail;
	if (p == NULL) {
		cout << "空的通讯录" << endl;
		return false;
	}
	while (p)
	{
		if (p->name == ws) {
			//wcout << "找到了" << ws <<  endl;
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


/* 1、add 联系人 */
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

/* 2、输出通讯录 */
void show_mail(Mail mail) {
	int i = 1;
	if (mail.size == 0) {
		cout << "空的通讯录" << endl;
	}
	else {
		Mail_list_node pm = mail.phead;
		while (pm)
		{
			cout << i << "、" << endl;
			vist_mail(pm);
			pm = pm->next;
			i++;
		}
	}
}

/* 3、删除联系人 */
bool delete_mail(Mail *mail){
	wstring delde_name;
	cout << "请输入你要删除人的名字:" << endl;
	get_String(&delde_name);
	if (delet_mail_node(&((*mail).phead),delde_name)) {
		cout << "删除成功" << endl;
		(*mail).size--;
	}
	else
	{
		wcout << "删除失败,通讯录不存在" << delde_name << "的名字！" << endl;
		return false;
	}
	//niuap
	return true;
}

/* 4、查找联系人*/
/* 前置条件: 通讯录存在，不为空*/
/* 后置条件: 找到返回true，否则返回false*/
bool find_mail_node(Mail  mail){
	if (mail.phead == NULL) {
		cout << "空的通讯录!" << endl;
		return false;
	}
	wstring find_name;
	Mail_list_node temp;
	cout << "请输入你要查找的名字：" << endl;
	get_name(&find_name);
	if (find_node(mail.phead, find_name,&temp) == true) {
		//cout << "找到了" << endl;
		cout << "****************************************" << endl;
		vist_mail(temp);
	}
	else {
		cout << "没找到" << endl;
		return false;
	}
	return true; 
}

/* 5、修改联系人 */
/* 前置条件: 通讯录存在，不为空 */
/* 后期条件：更改联系人返回true*/
bool change_mail(Mail mail){
	wstring find_name;
	Mail_list_node temp;
	cout << "请输入你要修改的人的名字：" << endl;
	get_name(&find_name);
	if (find_node(mail.phead, find_name, &temp) == true) {
		//cout << "找到了" << endl;
		change(&temp);
	}
	else {
		wcout << "没有联系人:" << find_name <<  endl;
		return false;
	}
	return  true;
}



/* 6、清空通讯录 */
/* 前置条件：通讯录存在，不为空*/
/* 后置条件：清空通讯录*/
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
