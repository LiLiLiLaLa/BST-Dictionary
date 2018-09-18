#include "BST-Dictionary.h"

static BSTreeNode* BuyNode(BSTKeyType key, BSTKeyType value)
{
	BSTreeNode* newNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (newNode == NULL)
	{
		printf("开辟新结点失败");
		return NULL;
	}
	//newNode->_key = (BSTKeyType)malloc(strlen(key) + 1);
	//因为传参使用""将内容存放在文字常量区，顾不在重新申请内存存放指针key和value指向的内容
	newNode->_key = key;
	newNode->_value = value;
	newNode->_left = NULL;
	newNode->_right = NULL;
	return newNode;
}

int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType key, BSTValueType value)
{
	BSTreeNode* cur = *ppTree;
	BSTreeNode* parent = NULL;
	//插入的结点为第一个结点
	if (*ppTree == NULL)
	{
		*ppTree = BuyNode(key, value);
		return 1;
	}
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)
		{
			parent = cur; 
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)
		{
			parent = cur;
			cur = cur->_right;
		}
		//待插入元素已存在
		else
		{
			return 0;
		}
	}
	if (strcmp(parent->_key, key) < 0)
	{
		parent->_right = BuyNode(key, value);
	}
	else
	{
		parent->_left = BuyNode(key, value);
	}
	return 1;
}

BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTKeyType key)
{
	BSTreeNode* cur = *ppTree;
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)
		{
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)
		{
			cur = cur->_right;
		}
		else
		{
			return cur;
		}
	}
	//没找到
	return NULL;
}

void BSTreeInOrder(BSTreeNode** ppTree)
{
	BSTreeNode* root = *ppTree;
	if (*ppTree == NULL)
	{
		return;
	}
	BSTreeInOrder(&root->_left);
	printf("%s:%s\n", root->_key, root->_value);
	BSTreeInOrder(&root->_right);
}