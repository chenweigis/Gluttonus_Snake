#pragma once
typedef struct Snake
{
	//�����ݴ洢
	char m_snake;//��ʽ
	int x;int y;//����
	Snake* pNext;
}SNAKE;
class snake_list
{
public:
	snake_list(void);
	~snake_list(void);



	SNAKE* pNode;
	SNAKE* pHead;

	char snake_head;//��ͷ
	char snake_body;//����

	//������ز���
	bool CreatList();
	void AddNode(int x,int y);
	//bool DelNode();
	int* MoveNode(int _dir);
};

