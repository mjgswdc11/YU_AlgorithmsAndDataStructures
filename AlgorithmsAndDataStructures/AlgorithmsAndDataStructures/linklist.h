#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;


typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * List;



//1.����������
List CreatList(List& L, int num)
{
	for (int i = 0; i < num; i++)
	{
		LNode* p = (LNode*)malloc(sizeof(LNode));//�½����
		scanf_s("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
	return L;
}


//2.�ڵ�pos��λ�ò���int����Ԫ��ele
void ListInsert(List& L, int pos, int ele)
{
	if (pos < 1)
	{
		cout << "���벻�Ϸ�" << endl;
		system("pause");
	}
	List p = L;
	int j = 0;
	while (p && j < pos - 1)//Ѱ�ҵ�pos-1�����
	{
		p = p->next;
		++j;
	}
	if (!p || j > pos - 1)
	{
		system("pause");
	}
	List s = (List)malloc(sizeof(LNode));
	s->data = ele;
	s->next = p->next;
	p->next = s;
	return;
}


//3.ɾ����pos����㲢����
int ListDelete(List L, int pos)
{
	int e;
	LNode* p = L;
	int j = 0;
	while (p->next && j < pos - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > pos - 1)
	{
		system("pause");
	}
	LNode* q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return e;
}


//4.���ҵ�pos��Ԫ�أ�������
int GetElem(List L, int pos)
{
	int j = 1;
	LNode* p = L->next;
	while (p != NULL && j < pos)
	{
		p = p->next;
		++j;
	}
	if (!p || j > pos)
	{
		printf_s("��%d��Ԫ�ز�����", pos);
		return NULL;
	}
	return p->data;
}


//5.���������
void PrintList(List L)
{
	LNode* p = L->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}


//6.ͨѶ¼
#include<string>
#define book_max 100//ͨѶ¼��󴢴�����

//��ϵ�˽ṹ��
struct Person
{
	string p_name;//��ϵ������
	string p_sex;//��ϵ���Ա�
	string p_phone;//��ϵ�˵绰����
};

//ͨѶ¼�ṹ��
struct PhoneBooks
{

	struct Person personArray[book_max];//ͨѶ¼������ϵ������
	int pb_size;//ͨѶ¼�е�ǰ��¼����ϵ�˸���
};

//ͨѶ¼�˵�
void PhoneBook_showMenu()
{
	printf("**************ͨѶ¼�Ļ���������Ӧ��*********************\n");
	printf("* 1  �����ϵ��                                         *\n");
	printf("* 2  ��ʾ��ϵ��                                         *\n");
	printf("* 3  ɾ����ϵ��                                         *\n");
	printf("* 4  ������ϵ��                                         *\n");
	printf("* 5  �޸���ϵ��                                         *\n");
	printf("* 6  ���ͨѶ¼                                         *\n");
	printf("* 7  �˳�ͨѶ¼                                         *\n");
	printf("*********************************************************\n");
}

//1.�����ϵ��
void addPerson(PhoneBooks* pbs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (pbs->pb_size == book_max)
	{
		cout << "ͨѶ¼������" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		pbs->personArray[pbs->pb_size].p_name = name;

		//�Ա�
		string sex;
		cout << "�������Ա𣨡��С����ߡ�Ů������" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == "��" || sex == "Ů")
			{
				pbs->personArray[pbs->pb_size].p_sex = sex;
				break;
			}
			cout << "�����Ա����������롰�С���Ů��������" << endl;
		}

		//�绰����
		string phone;
		cout << "������绰���룺" << endl;
		cin >> phone;
		pbs->personArray[pbs->pb_size].p_phone = phone;

		//�����Ϣ�������
		//����ͨѶ¼����
		pbs->pb_size++;
		cout << "�����ɣ�" << endl;
	}
}


//2.��ʾ��ϵ��
void showPerson(PhoneBooks* pbs)
{
	//�ж�ͨѶ¼�Ƿ�Ϊ��
	if (pbs->pb_size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < pbs->pb_size; i++)
		{
			cout << "������" << pbs->personArray[i].p_name << endl;
			cout << "�Ա�" << pbs->personArray[i].p_sex << endl;
			cout << "�绰���룺" << pbs->personArray[i].p_phone << endl;
		}
	}
}


//3.ɾ����ϵ��
  //������Ҫһ��ͨ��������ѯ�Ƿ������ͨѶ¼�ķ��������������䷵�ؾ���λ�ã����򷵻�-1
int isExit(PhoneBooks* pbs, string name)
{
	for (int i = 0; i < pbs->pb_size; i++)
	{
		if (pbs->personArray[i].p_name == name)
			return i;
	}
	return -1;
}
//ɾ����ϵ�˷���
void deletePerson(PhoneBooks* pbs)
{
	cout << "��������Ҫɾ������ϵ�˵�������" << endl;
	string name;
	cin >> name;
	int pos = isExit(pbs, name);
	if (pos != -1)
	{
		for (int i = pos; i < pbs->pb_size; i++)
		{
			//posλ��֮�������ǰ��
			pbs->personArray[i] = pbs->personArray[i + 1];
		}
		pbs->pb_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "û����Ϊ��" << name << " ����ϵ��" << endl;
	}
}


//4.������ϵ��
void findPerson(PhoneBooks* pbs)
{
	string name;
	cout << "��������Ҫ���ҵ���ϵ�˵�������" << endl;
	cin >> name;
	int pos = isExit(pbs, name);
	if (pos != -1)
	{
		cout << "������" << pbs->personArray[pos].p_name << endl;
		cout << "�Ա�" << pbs->personArray[pos].p_sex << endl;
		cout << "�绰���룺" << pbs->personArray[pos].p_phone << endl;
	}
	else
	{
		cout << "û����Ϊ��" << name << " ����ϵ��" << endl;
	}
}


//5.�޸���ϵ��
void modifyPerson(PhoneBooks* pbs)
{
	string name, sex, phone;
	int pos;
	cout << "��������Ҫ�޸ĵ���ϵ�˵�������" << endl;
	cin >> name;
	//�ж���ϵ���Ƿ����
	pos = isExit(pbs, name);
	if (pos != -1)
	{
		cout << "�������޸ĺ��������";
		cin >> name;
		pbs->personArray[pos].p_name = name;
		cout << "�������޸ĺ���Ա�";
		cin >> sex;
		pbs->personArray[pos].p_sex = sex;
		cout << "�������޸ĺ�ĺ��룺";
		cin >> phone;
		pbs->personArray[pos].p_phone = phone;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "û����Ϊ��" << name << " ����ϵ��" << endl;
	}
}


//6.���ͨѶ¼
void emptyPhoneBook(PhoneBooks* pbs)
{
	pbs->pb_size = 0;
	cout << "ͨѶ¼��ճɹ���" << endl;
}


int PhoneBook()
{
	//����ͨѶ¼�Ľṹ�����
	PhoneBooks pbs;
	//��ʼ��ͨѶ¼����ϵ�˸���
	pbs.pb_size = 0;
	//ѡ����ű��� 
	int select = 0;
	//�˵�����
	while (true)
	{
		PhoneBook_showMenu();
		cout << "��ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 1://1.�����ϵ��
			addPerson(&pbs);
			break;
		case 2://2.��ʾ��ϵ��
			showPerson(&pbs);
			break;
		case 3://3.ɾ����ϵ��
			deletePerson(&pbs);
			break;
		case 4://4.������ϵ��
			findPerson(&pbs);
			break;
		case 5://5.�޸���ϵ��
			modifyPerson(&pbs);
			break;
		case 6://6.���ͨѶ¼
			emptyPhoneBook(&pbs);
			break;
		case 7://7.�˳�ͨѶ¼
			return 0;
			break;
		default:
			printf("ѡ����Ŵ���!");

			break;
		}
	}
	return 0;
}