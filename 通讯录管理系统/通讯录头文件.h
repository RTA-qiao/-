#pragma once
/*
	2023��3��26��
	21��44��
	���ܣ��򵥵�ͨѶ¼
	1�������ϵ��
	2����ʾ��ϵ��
	3��ɾ����ϵ��
	4��������ϵ��
	5���޸���ϵ��
	6�������ϵ��
	7���˳�ͨѶ¼
*/
#include <string>
#include <iostream>
#include <stdbool.h>
using namespace std;
typedef struct M_Node {
	wstring name;					//����
	string sex;						//�Ա�
	int  age;						//����
	wstring number_phone;			//�绰
	wstring address;					//��ַ
	struct M_Node* next = NULL;			//��һ���ڵ��λ��
} Mail_node, * Mail_list_node;
typedef struct Mail_list {
	Mail_list_node phead;			//���Ա��ͷ
	int size;						//���Ա�Ĵ�С
}Mail;

/* 1��add ��ϵ�� */
/* ���������һ����Ա*/
/* ǰ�����������Ա���� */
/* ���������������Ա������һ�����ݣ�����ɹ�����true�����򷵻�false*/
bool add_Mail_list(Mail *mail);

/* 2����ʼ��һ���յ�ͨѶ¼���� */
/* �����ɹ�����true */
bool Creat_mail(Mail  *mail);

/* 3����ʾ��ϵ��*/
/* ǰ��������ͨѶ¼����*/
/* �������������ͨѶ¼*/
void show_mail(Mail  mail);

/* 4��ɾ����ϵ�� */
/* ǰ��������ͨѶ¼���� */
/* ����������ɾ��ͨѶ¼�е�ĳ����Ŀ���ɹ�����true�����򷵻�false*/
bool delete_mail(Mail *mail);

/* 5��������ϵ��*/
/* ǰ������: ͨѶ¼���ڣ���Ϊ��*/
/* ��������: �ҵ�����true�����򷵻�false*/
bool find_mail_node(Mail  mail);

/* 5���޸���ϵ�� */
/* ǰ������: ͨѶ¼���ڣ���Ϊ�� */
/* ����������������ϵ�˷���true*/
bool change_mail(Mail nail);

/* 6�����ͨѶ¼ */
/* ǰ��������ͨѶ¼���ڣ���Ϊ��*/
/* �������������ͨѶ¼*/
bool Clear_mail(Mail *mail);
