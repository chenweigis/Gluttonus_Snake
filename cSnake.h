#ifndef SNAKE_H
#define SNAKE_H
#include "snake_list.h"

class cSnake
{
public:
	cSnake(void);
	~cSnake(void);
	//��Ϸ��ͼ
	void m_showmap();
	bool m_showsnake();
	//sanke ��Ϊ
	void m_snakefood();
	


	
	bool IsSnake(int x,int y);//�ж�food�ڲ���������
	snake_list snake;
	bool gameover;//��Ϸ������ʶ
	int operate;//��¼snake���ƶ�����Ĭ������
	char sanke_food;
	bool eat_flag;//�Ƿ�Ե��ı�ʶ 


};
#endif
