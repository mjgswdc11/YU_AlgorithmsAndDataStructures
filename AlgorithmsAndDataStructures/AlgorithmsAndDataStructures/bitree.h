#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
#include<functional>

using namespace std;
//������
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BinTree;

//1.����������
void CreateBinTree(BinTree* T)
{
	//�������������������Ľ���ֵ���ַ������ո��ַ���ʾ����
	//�������������ʾ�Ķ�����
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')*T = NULL;
	else
	{
		*T = (BinTree)malloc(sizeof(BinTree));
		(*T)->data = ch;
		CreateBinTree(&(*T)->lchild);
		CreateBinTree(&(*T)->rchild);
	}

}


//2.����������

//�������
void Preorder(BinTree T)
{
	if (T)
	{
		printf_s("%c", T->data);
		Preorder(T->lchild);
		Preorder(T->rchild);
	}
}

//�������
void Inorder(BinTree T)
{
	if (T)
	{
		Inorder(T->lchild);
		printf_s("%c", T->data);
		Inorder(T->rchild);
	}
}

//�������
void Postorder(BinTree T)
{
	if (T)
	{
		Postorder(T->lchild);
		Postorder(T->rchild);
		printf_s("%c", T->data);
	}
}



//3.�����������

int PostOrderGetHeight(BinTree T)
{
	int HL, HR, MaxH;
	if (T) {
		HL = PostOrderGetHeight(T->lchild);
		HR = PostOrderGetHeight(T->rchild);
		MaxH = HL > HR ? HL : HR;
		return (MaxH + 1);
	}
	else {
		return 0;
	}
}

//4.����Ҷ�ӽ��ĸ���
int LeafNodeNum(BinTree T)
{
	if (!T)return 0;
	if (T->lchild == NULL && T->rchild == NULL)return 1;
	return (LeafNodeNum(T->lchild) + LeafNodeNum(T->rchild));
}


//5.Ѱ�Ҹ���㣨DFS˼�룩
char FindFatherNode(BinTree T,char x)
{
	if (!T)return NULL;
	if ((T->lchild != NULL && T->lchild->data == x) || (T->rchild != NULL && T->rchild->data == x))//Ҫ�����ж����Һ����Ƿ�Ϊ�գ�������ڴ����
		return T->data;
	char temp = FindFatherNode(T->lchild, x);
	if (temp != NULL)return temp;
	return FindFatherNode(T->rchild, x);

}



//6.Ѱ���ֵܽ�㣨�ο�Ѱ�Ҹ��ڵ㷽����
char FindBrotherNode(BinTree T, char x)
{
	if (!T)return NULL;
	if (T->lchild != NULL && T->lchild->data == x)
	{
		if (T->rchild != NULL)
			return T->rchild->data;
		else
			return NULL;
	}
	if (T->rchild != NULL && T->rchild->data == x)
	{
		if (T->lchild != NULL)
			return T->lchild->data;
		else
			return NULL;
	}
	char temp =FindBrotherNode(T->lchild, x);
	if (temp != NULL)return temp;
	return FindBrotherNode(T->rchild, x);
}


//7.Huffman����(Ӧ��)

// �շ������ڵ�
struct HuffmanNode {
	char ch; // �ַ�
	int freq; // Ȩֵ
	HuffmanNode* left, * right; // ��������ָ��

	HuffmanNode(char ch, int freq) {
		this->ch = ch;
		this->freq = freq;
		this->left = this->right = nullptr;
	}

	// �ȽϺ������������ȶ����е�����
	bool operator<(const HuffmanNode& other) const {
		return freq > other.freq; // ����Ȩֵ��С��������
	}
};

// �����շ�����
HuffmanNode* buildHuffmanTree(const vector<pair<char, int>>& freq) {
	// ������ת��Ϊ�շ�������Ҷ�ӽڵ�
	vector<HuffmanNode*> leaves;
	for (const auto& p : freq) {
		leaves.push_back(new HuffmanNode(p.first, p.second));
	}

	// �����շ�����
	priority_queue<HuffmanNode*> pq(leaves.begin(), leaves.end());
	while (pq.size() > 1) {
		// ȡ��Ȩֵ��С�������ڵ�
		HuffmanNode* left = pq.top();
		pq.pop();
		HuffmanNode* right = pq.top();
		pq.pop();

		// �����½ڵ㣬��Ϊ���������ĸ��ڵ�
		HuffmanNode* parent = new HuffmanNode('\0', left->freq + right->freq);
		parent->left = left;
		parent->right = right;

		// ���½ڵ�������ȶ�����
		pq.push(parent);
	}

	// ���غշ������ĸ��ڵ�
	return pq.top();
}

// ���ɺշ��������
unordered_map<char, string> generateHuffmanTable(HuffmanNode* root) {
	unordered_map<char, string> table;
	string code;
	function<void(HuffmanNode*, string)> traverse = [&](HuffmanNode* node, string code) {
		if (!node) {
			return;
		}
		if (node->ch != '\0') {
			table[node->ch] = code;
		}
		traverse(node->left, code + "0");
		traverse(node->right, code + "1");
	};
	traverse(root, code);
	return table;
}