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



//1.创建单链表
List CreatList(List& L, int num)
{
	for (int i = 0; i < num; i++)
	{
		LNode* p = (LNode*)malloc(sizeof(LNode));//新建结点
		scanf_s("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
	return L;
}


//2.在第pos个位置插入int类型元素ele
void ListInsert(List& L, int pos, int ele)
{
	if (pos < 1)
	{
		cout << "插入不合法" << endl;
		system("pause");
	}
	List p = L;
	int j = 0;
	while (p && j < pos - 1)//寻找第pos-1个结点
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


//3.删除第pos个结点并返回
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


//4.查找第pos个元素，并返回
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
		printf_s("第%d个元素不存在", pos);
		return NULL;
	}
	return p->data;
}


//5.输出单链表
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


//6.通讯录
#include<string>
#define book_max 100//通讯录最大储存数量

//联系人结构体
struct Person
{
	string p_name;//联系人姓名
	string p_sex;//联系人性别
	string p_phone;//联系人电话号码
};

//通讯录结构体
struct PhoneBooks
{

	struct Person personArray[book_max];//通讯录保存联系人数组
	int pb_size;//通讯录中当前记录的联系人个数
};

//通讯录菜单
void PhoneBook_showMenu()
{
	printf("**************通讯录的基本操作及应用*********************\n");
	printf("* 1  添加联系人                                         *\n");
	printf("* 2  显示联系人                                         *\n");
	printf("* 3  删除联系人                                         *\n");
	printf("* 4  查找联系人                                         *\n");
	printf("* 5  修改联系人                                         *\n");
	printf("* 6  清空通讯录                                         *\n");
	printf("* 7  退出通讯录                                         *\n");
	printf("*********************************************************\n");
}

//1.添加联系人
void addPerson(PhoneBooks* pbs)
{
	//判断通讯录是否已满
	if (pbs->pb_size == book_max)
	{
		cout << "通讯录已满！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		pbs->personArray[pbs->pb_size].p_name = name;

		//性别
		string sex;
		cout << "请输入性别（“男”或者“女”）：" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == "男" || sex == "女")
			{
				pbs->personArray[pbs->pb_size].p_sex = sex;
				break;
			}
			cout << "输入性别有误，请输入“男”或“女”！！！" << endl;
		}

		//电话号码
		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		pbs->personArray[pbs->pb_size].p_phone = phone;

		//添加信息输入完成
		//更新通讯录人数
		pbs->pb_size++;
		cout << "添加完成！" << endl;
	}
}


//2.显示联系人
void showPerson(PhoneBooks* pbs)
{
	//判断通讯录是否为空
	if (pbs->pb_size == 0)
	{
		cout << "通讯录为空！" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < pbs->pb_size; i++)
		{
			cout << "姓名：" << pbs->personArray[i].p_name << endl;
			cout << "性别：" << pbs->personArray[i].p_sex << endl;
			cout << "电话号码：" << pbs->personArray[i].p_phone << endl;
		}
	}
}


//3.删除联系人
  //首先需要一个通过姓名查询是否存在于通讯录的方法，若存在让其返回具体位置，否则返回-1
int isExit(PhoneBooks* pbs, string name)
{
	for (int i = 0; i < pbs->pb_size; i++)
	{
		if (pbs->personArray[i].p_name == name)
			return i;
	}
	return -1;
}
//删除联系人方法
void deletePerson(PhoneBooks* pbs)
{
	cout << "请输入需要删除的联系人的姓名：" << endl;
	string name;
	cin >> name;
	int pos = isExit(pbs, name);
	if (pos != -1)
	{
		for (int i = pos; i < pbs->pb_size; i++)
		{
			//pos位置之后的数据前移
			pbs->personArray[i] = pbs->personArray[i + 1];
		}
		pbs->pb_size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "没有名为：" << name << " 的联系人" << endl;
	}
}


//4.查找联系人
void findPerson(PhoneBooks* pbs)
{
	string name;
	cout << "请输入需要查找的联系人的姓名：" << endl;
	cin >> name;
	int pos = isExit(pbs, name);
	if (pos != -1)
	{
		cout << "姓名：" << pbs->personArray[pos].p_name << endl;
		cout << "性别：" << pbs->personArray[pos].p_sex << endl;
		cout << "电话号码：" << pbs->personArray[pos].p_phone << endl;
	}
	else
	{
		cout << "没有名为：" << name << " 的联系人" << endl;
	}
}


//5.修改联系人
void modifyPerson(PhoneBooks* pbs)
{
	string name, sex, phone;
	int pos;
	cout << "请输入需要修改的联系人的姓名：" << endl;
	cin >> name;
	//判断联系人是否存在
	pos = isExit(pbs, name);
	if (pos != -1)
	{
		cout << "请输入修改后的姓名：";
		cin >> name;
		pbs->personArray[pos].p_name = name;
		cout << "请输入修改后的性别：";
		cin >> sex;
		pbs->personArray[pos].p_sex = sex;
		cout << "请输入修改后的号码：";
		cin >> phone;
		pbs->personArray[pos].p_phone = phone;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "没有名为：" << name << " 的联系人" << endl;
	}
}


//6.清空通讯录
void emptyPhoneBook(PhoneBooks* pbs)
{
	pbs->pb_size = 0;
	cout << "通讯录清空成功！" << endl;
}


int PhoneBook()
{
	//创建通讯录的结构体变量
	PhoneBooks pbs;
	//初始化通讯录中联系人个数
	pbs.pb_size = 0;
	//选择序号变量 
	int select = 0;
	//菜单调用
	while (true)
	{
		PhoneBook_showMenu();
		cout << "请选择：" << endl;
		cin >> select;
		switch (select)
		{
		case 1://1.添加联系人
			addPerson(&pbs);
			break;
		case 2://2.显示联系人
			showPerson(&pbs);
			break;
		case 3://3.删除联系人
			deletePerson(&pbs);
			break;
		case 4://4.查找联系人
			findPerson(&pbs);
			break;
		case 5://5.修改联系人
			modifyPerson(&pbs);
			break;
		case 6://6.清空通讯录
			emptyPhoneBook(&pbs);
			break;
		case 7://7.退出通讯录
			return 0;
			break;
		default:
			printf("选择序号错误!");

			break;
		}
	}
	return 0;
}