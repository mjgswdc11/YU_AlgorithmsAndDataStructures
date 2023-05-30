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
//二叉树
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BinTree;

//1.创建二叉树
void CreateBinTree(BinTree* T)
{
	//按先序次序输入二叉树的结点的值（字符），空格字符表示空树
	//构建二叉链表表示的二叉树
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


//2.遍历二叉树

//先序遍历
void Preorder(BinTree T)
{
	if (T)
	{
		printf_s("%c", T->data);
		Preorder(T->lchild);
		Preorder(T->rchild);
	}
}

//中序遍历
void Inorder(BinTree T)
{
	if (T)
	{
		Inorder(T->lchild);
		printf_s("%c", T->data);
		Inorder(T->rchild);
	}
}

//后序遍历
void Postorder(BinTree T)
{
	if (T)
	{
		Postorder(T->lchild);
		Postorder(T->rchild);
		printf_s("%c", T->data);
	}
}



//3.计算树的深度

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

//4.计算叶子结点的个数
int LeafNodeNum(BinTree T)
{
	if (!T)return 0;
	if (T->lchild == NULL && T->rchild == NULL)return 1;
	return (LeafNodeNum(T->lchild) + LeafNodeNum(T->rchild));
}


//5.寻找父结点（DFS思想）
char FindFatherNode(BinTree T,char x)
{
	if (!T)return NULL;
	if ((T->lchild != NULL && T->lchild->data == x) || (T->rchild != NULL && T->rchild->data == x))//要优先判断左右孩子是否为空，否则会内存溢出
		return T->data;
	char temp = FindFatherNode(T->lchild, x);
	if (temp != NULL)return temp;
	return FindFatherNode(T->rchild, x);

}



//6.寻找兄弟结点（参考寻找父节点方法）
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


//7.Huffman编码(应用)

// 赫夫曼树节点
struct HuffmanNode {
	char ch; // 字符
	int freq; // 权值
	HuffmanNode* left, * right; // 左右子树指针

	HuffmanNode(char ch, int freq) {
		this->ch = ch;
		this->freq = freq;
		this->left = this->right = nullptr;
	}

	// 比较函数，用于优先队列中的排序
	bool operator<(const HuffmanNode& other) const {
		return freq > other.freq; // 按照权值从小到大排序
	}
};

// 构建赫夫曼树
HuffmanNode* buildHuffmanTree(const vector<pair<char, int>>& freq) {
	// 将输入转换为赫夫曼树的叶子节点
	vector<HuffmanNode*> leaves;
	for (const auto& p : freq) {
		leaves.push_back(new HuffmanNode(p.first, p.second));
	}

	// 构建赫夫曼树
	priority_queue<HuffmanNode*> pq(leaves.begin(), leaves.end());
	while (pq.size() > 1) {
		// 取出权值最小的两个节点
		HuffmanNode* left = pq.top();
		pq.pop();
		HuffmanNode* right = pq.top();
		pq.pop();

		// 构建新节点，作为左右子树的父节点
		HuffmanNode* parent = new HuffmanNode('\0', left->freq + right->freq);
		parent->left = left;
		parent->right = right;

		// 将新节点加入优先队列中
		pq.push(parent);
	}

	// 返回赫夫曼树的根节点
	return pq.top();
}

// 生成赫夫曼编码表
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