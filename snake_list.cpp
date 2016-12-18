#include "StdAfx.h"
#include "snake_list.h"


#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

snake_list::snake_list(void)
{
	snake_head = '>';
	snake_body = '@';
	pHead=NULL;
	CreatList();
	pNode =new SNAKE;
	pHead->pNext=pNode;
	pNode->m_snake=snake_head;
	pNode->x=1;
	pNode->y=2;
	pNode->pNext=NULL;

}


snake_list::~snake_list(void)
{
	SNAKE* pSnake=pHead;
	while (pSnake)
	{
		pHead=pSnake;
		pSnake=pSnake->pNext;
		delete pHead;
	}
}


bool snake_list::CreatList()
{
	pHead = new SNAKE;
	if (pHead == NULL)
	{
		return false;
	}
	else
	{
		pHead->m_snake=snake_body;
		pHead->x = 1;
		pHead->y = 1;
		pHead->pNext = NULL;
		return true;
	}
}/*
bool snake_list::AddNode()
{

}*/
int coord[5]={0,0,0,0,1};//定义为局部变量的话，跳出这个函数之后数据将被破坏
//调用返回值的函数中如果包含其他函数，其他函数执行之后数据就被破坏了
int* snake_list::MoveNode(int _dir)
{
	SNAKE* pSnake=pHead;
	coord[0]=pHead->x;
	coord[1]=pHead->y;
	switch(_dir)
	{
	case UP:
		snake_head='^';
		while(pSnake->pNext->pNext)//找到尾节点pNext==NULL;
		{
			pSnake=pSnake->pNext;
		}
		if (pSnake->x==pSnake->pNext->x-1 && pSnake->y==pSnake->pNext->y)
		{
			coord[4]=0;
			return coord;
		}
		else
		{
			pSnake=pSnake->pNext;
		}
		pSnake->pNext=pHead;
		pHead=pHead->pNext;
		pSnake->pNext->pNext=NULL;
		pSnake->m_snake=snake_body;
		pSnake->pNext->x=pSnake->x;
		pSnake->pNext->y=pSnake->y;
		pSnake->pNext->x--;
		pSnake=pSnake->pNext;
		pSnake->m_snake=snake_head;
		break;
	case DOWN:
		snake_head='V';
		while(pSnake->pNext->pNext)//找到尾节点pNext==NULL;
		{
			pSnake=pSnake->pNext;
		}
		if (pSnake->x==pSnake->pNext->x+1 && pSnake->y==pSnake->pNext->y)
		{
			coord[4]=0;
			return coord;
		}
		else
		{
			pSnake=pSnake->pNext;
		}
		pSnake->pNext=pHead;
		pHead=pHead->pNext;
		pSnake->pNext->pNext=NULL;
		pSnake->m_snake=snake_body;
		pSnake->pNext->x=pSnake->x;
		pSnake->pNext->y=pSnake->y;
		pSnake->pNext->x++;
		pSnake=pSnake->pNext;
		pSnake->m_snake=snake_head;
		break;
	case LEFT:
		snake_head='<';
		while(pSnake->pNext->pNext)//找到尾节点pNext==NULL;
		{
			pSnake=pSnake->pNext;
		}
		if (pSnake->x==pSnake->pNext->x && pSnake->y==pSnake->pNext->y-1)
		{
			coord[4]=0;
			return coord;
		}
		else
		{
			pSnake=pSnake->pNext;
		}
		pSnake->pNext=pHead;
		pHead=pHead->pNext;
		pSnake->pNext->pNext=NULL;
		pSnake->m_snake=snake_body;
		pSnake->pNext->x=pSnake->x;
		pSnake->pNext->y=pSnake->y;
		pSnake->pNext->y--;
		pSnake=pSnake->pNext;
		pSnake->m_snake=snake_head;
		break;
	case RIGHT:
		snake_head='>';
		while(pSnake->pNext->pNext)//找到尾节点pNext==NULL;
		{
			pSnake=pSnake->pNext;
		}
		if (pSnake->x==pSnake->pNext->x && pSnake->y==pSnake->pNext->y+1)
		{
			coord[4]=0;
			return coord;
		}
		else
		{
			pSnake=pSnake->pNext;
		}
		pSnake->pNext=pHead;//尾节点指向头节点，把蛇的尾部拿到蛇的头部来
		pHead=pHead->pNext;//头指针指向下一个节点
		pSnake->pNext->pNext=NULL;
		pSnake->m_snake=snake_body;//修改原来蛇头的样式为蛇身
		pSnake->pNext->x=pSnake->x;
		pSnake->pNext->y=pSnake->y;
		pSnake->pNext->y++;//修改坐标
		pSnake=pSnake->pNext;
		pSnake->m_snake=snake_head;//修改现在蛇头样式
		break;
	default:
		break;
	}
	coord[2]=pSnake->x;
	coord[3]=pSnake->y;
	coord[4]=1;
	return coord;
}

void snake_list::AddNode(int x,int y)//传进来移动之前的蛇尾位置
{
	SNAKE* pAddNode=new SNAKE;
	pAddNode->m_snake=snake_body;
	pAddNode->x=x;
	pAddNode->y=y;
	pAddNode->pNext=pHead;
	pHead=pAddNode;

}