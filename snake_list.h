#pragma once
typedef struct Snake
{
	//蛇数据存储
	char m_snake;//样式
	int x;int y;//坐标
	Snake* pNext;
}SNAKE;
class snake_list
{
public:
	snake_list(void);
	~snake_list(void);



	SNAKE* pNode;
	SNAKE* pHead;

	char snake_head;//蛇头
	char snake_body;//蛇身

	//链表相关操作
	bool CreatList();
	void AddNode(int x,int y);
	//bool DelNode();
	int* MoveNode(int _dir);
};

