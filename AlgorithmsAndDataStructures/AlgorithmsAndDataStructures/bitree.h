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
	char ch;
	int weight;
	HuffmanNode* left, * right;

	HuffmanNode(char _ch, int _weight) : ch(_ch), weight(_weight), left(nullptr), right(nullptr) {}
	bool operator<(const HuffmanNode& other) const {
		return weight > other.weight; // 按照权重从小到大排序
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