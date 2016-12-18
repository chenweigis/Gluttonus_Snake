// Gluttonus_Snake.cpp : 定义控制台应用程序的入口点。
//

/************************************************************************/
/* 贪吃蛇游戏：
游戏规则：
1.snake只能在一个固定的map中运动
2.通过上下左右键来控制sanke上下左右走，碰到墙壁就gameover，碰到自己也会gameover(v2.0可以穿过去)
3.map中会随机产生food,吃到就可以变长,map中没有空位后游戏获胜

1.使用封装好的cArray模板类来存储snake;
☆2.使用链表来存储snake;
*/
/************************************************************************/

#include "stdafx.h"
#include "cSnake.h"
#include "t_Array.h"


int _tmain(int argc, _TCHAR* argv[])
{
	cSnake snake;
	snake.m_showmap();

	system("pause");
	return 0;
	
}

