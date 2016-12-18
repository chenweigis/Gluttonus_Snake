#include "StdAfx.h"
#include "cSnake.h"
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <iostream>
using namespace std;

#define MAX_COLUNM 50
#define MAX_ROW 20

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

char m_mapdata[MAX_ROW][MAX_COLUNM+1]={
	{"**************************************************"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"*                                                *"},
	{"**************************************************"}
};

cSnake::cSnake(void)
{
	operate=RIGHT;
	gameover=false;
    eat_flag=false;
	sanke_food='$';
	m_snakefood();
}

cSnake::~cSnake(void)
{
}

bool cSnake::m_showsnake()
{
    //判断是否符合改变方向的规则
	int temp_operate=operate;
	if (_kbhit())
	{
		//键盘记录的是双字节，需要获取两次才能获取真正的键盘值
		operate=_getch();
		operate=_getch();
	}
	int* coord=snake.MoveNode(operate);//记录头节点和尾节点的坐标
	while (coord[4]==0)
	{
		operate=temp_operate;
		coord=snake.MoveNode(operate);
	}
	if (coord[2]<=0 || coord[2]>=MAX_ROW-1 || coord[3]<=0 || coord[3]>=MAX_COLUNM-1)
	{
		gameover=true;
	} 
	
	if (gameover)
	{
		return false;
	}
	else
	{
		if (eat_flag)
		{
			m_snakefood();
			eat_flag=false;
		}
		if (m_mapdata[coord[2]][coord[3]]==' ')
		{
			m_mapdata[coord[0]][coord[1]]=' ';//清空地图中的尾节点
		}
		else if (m_mapdata[coord[2]][coord[3]]==snake.snake_body)
		{
			return false;
		}
		else
		{
			snake.AddNode(coord[0],coord[1]);
		    eat_flag=true;
		}
		SNAKE* pSnake;
		pSnake=snake.pHead;
		while (pSnake)
		{
			m_mapdata[pSnake->x][pSnake->y]=pSnake->m_snake;
			pSnake=pSnake->pNext;
		}
		return true;
	}
	
	
	
}


void cSnake::m_showmap()
{
	while (1)
	{
		for (int i=0;i<MAX_ROW;i++)
		{
			for (int j=0;j<MAX_COLUNM;j++)
			{
				cout<<m_mapdata[i][j];
			}
			cout<<endl;
		}
		if (m_showsnake())
		{
			system("cls");
			Sleep(1);
		}
		else
		{
			cout<<"游戏结束！"<<endl;
			break;
		}
	}
}
void cSnake::m_snakefood()
{
	srand(time(NULL));
	int x=0,y=0;
	do{
		x=rand()%(MAX_ROW-2)+1;
		y=rand()%(MAX_COLUNM-2)+1;
	  } while (IsSnake(x,y));
	m_mapdata[x][y]=sanke_food;
}
bool cSnake::IsSnake(int x,int y)
{
	SNAKE* pSnake;
	pSnake=snake.pHead;
	while (pSnake)
	{
		
		if (pSnake->x==x && pSnake->y==y)
		{
			return true;
		}
		else
		{
			pSnake=pSnake->pNext;
		}
	}
	return false;
}

