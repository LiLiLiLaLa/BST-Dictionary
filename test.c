#include "BST-Dictionary.h"

void InitMyDict(BSTreeNode **pdict)
{
	assert(pdict);
	BSTreeInsert(pdict, "China", "中国");//字符串存入文字常量区
	BSTreeInsert(pdict, "USA", "美国");
	BSTreeInsert(pdict, "UK", "英国");
	BSTreeInsert(pdict, "Russia", "俄罗斯");
}

InitMyDict_zh(BSTreeNode **pdict_zh)
{
	assert(pdict_zh);
	BSTreeInsert(pdict_zh, "中国", "China");
	BSTreeInsert(pdict_zh, "美国", "USA");
	BSTreeInsert(pdict_zh, "英国", "UK");
	BSTreeInsert(pdict_zh, "俄罗斯", "Russia");
}

int main()
{
	int i = 0;
	//建立数组存放自己要查询的词
	char buf[20] = { 0 };
	BSTreeNode *mydict = NULL;
	BSTreeNode *mydict_zh = NULL;
	BSTreeNode *ret = NULL;
	//往词典插入内容
	InitMyDict(&mydict);
	InitMyDict_zh(&mydict_zh);
	//中序遍历词典
	BSTreeInOrder(&mydict);
	//输入要查询的词汇
	printf("请输入要查询的单词(Please input what's your find word)>\n");
	//要查询的词汇存入buf
	scanf("%s", buf);
	//选择你输入的语言类型
	printf("请输入语言(中文:0  英文:1)\n");
	scanf("%d", &i);
	if (i == 0)
	{
		ret = BSTreeFind(&mydict_zh, buf);
		if (ret != NULL)
			printf("%s\n", ret->_value);
		else
			printf("词库中没有这个词!\n");
	}
	else
	{
		ret = BSTreeFind(&mydict, buf);
		if (ret != NULL)
			printf("%s\n", ret->_value);
		else
			printf("词库中没有这个词!\n");
	}
	system("pause");
}