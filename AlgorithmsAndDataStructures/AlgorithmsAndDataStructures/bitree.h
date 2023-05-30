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
	char ch;
	int weight;
	HuffmanNode* left, * right;

	HuffmanNode(char _ch, int _weight) : ch(_ch), weight(_weight), left(nullptr), right(nullptr) {}
	bool operator<(const HuffmanNode& other) const {
		return weight > other.weight; // ����Ȩ�ش�С��������
	}
};

HuffmanNode* buildHuffmanTree(const vector<pair<char, int>>& freq) {
	priority_queue<HuffmanNode*> pq;

	for (auto& p : freq) {
		pq.push(new HuffmanNode(p.first, p.second));
	}

	while (pq.size() > 1) {
		auto left = pq.top(); pq.pop();
		auto right = pq.top(); pq.pop();

		auto parent = new HuffmanNode('\0', left->weight + right->weight);
		parent->left = left;
		parent->right = right;
		pq.push(parent);
	}
	return pq.top();
}

void generateHuffmanCode(HuffmanNode* root, unordered_map<char, string>& code) {
	if (!root) return;

	function<void(HuffmanNode*, string)> dfs = [&](HuffmanNode* node, string s) {
		if (node->left == nullptr && node->right == nullptr) {
			code[node->ch] = s;
			return;
		}

		if (node->left != nullptr) dfs(node->left, s + '0');
		if (node->right != nullptr) dfs(node->right, s + '1');
	};

	dfs(root, "");
}