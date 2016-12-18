#ifndef T_ARRAY
#define T_ARRAY
#include "StdAfx.h"
#include <iostream>
using namespace std;


template <class T>
class t_Array
{

public:
	int m_size;//数组的个数
	T* m_data;//保存数组

public:
	t_Array()
	{
		m_data=NULL;
		m_size=0;
	}
	t_Array(T* _data)
	{	
		m_size=1;
		m_data=new T[m_size];
		m_data[m_size-1]=*_data;
	}
	~t_Array()
	{
		delete []m_data;
	}

	//数组头部插入数据
	void m_AddHead(T& _data)
	{
		T* temp=m_data;
			m_data=new T[m_size+1];
			for (int i=0;i<m_size;i++)
			{
				m_data[i+1]=temp[i];
			}
			m_data[0]=_data;
			m_size++;
			delete []temp;

		
	}
	//数组尾部插入数据
	void m_AddFoot(T& _data)
	{
		T* temp=m_data;
		m_data=new T[m_size+1];
		for (int i=0;i<m_size;i++)
		{
			m_data[i]=temp[i];
		}
		m_data[m_size]=_data;
		m_size++;
		delete []temp;
	}
	//数组指定部位插入数据
	bool m_Insert(T& _data,unsigned int pos)
	{
		if (pos>(m_size-1)||m_size==0)
		{
			return false;
		}
		T* temp=m_data;
		m_data=new T[m_size+1];
		for(int i=0;i<pos;i++)
		{
			m_data[i]=temp[i];		
		}
		for (int i=pos;i<m_size;i++)
		{
			m_data[i+1]=temp[i];
		}
		m_data[pos]=_data;
		m_size++;
		delete []temp;
		return true;
	}
	//数组制定位置数据修改
	bool m_Modifi(T& _data,int pos)
	{
		if (pos>m_size-1||m_size==0)
		{
			return false;
		}
		T* temp=m_data;
		m_data=new T[m_size];
		for(int i=0;i<pos;i++)
		{
			m_data[i]=temp[i];		
		}
		for (int i=pos;i<m_size;i++)
		{
			m_data[i]=temp[i];
		}
		m_data[pos]=_data;
		delete []temp;
		return true;
	}
	//数组制定位置数据删除
	bool m_Del(unsigned int pos)
	{
		if (pos>m_size-1||m_size==0)
		{
			return false;
		}
		T* temp=m_data;
		m_data=new T[m_size-1];
		for(int i=0;i<pos;i++)
		{
			m_data[i]=temp[i];		
		}
		for (int i=pos;i<m_size-1;i++)
		{
			m_data[i]=temp[i+1];
		}
		m_size--;
		delete []temp;
		return true;
	}
	//重载下角标操作符[]
	T& operator [](unsigned int pos)
	{
		if (pos>m_size-1)
		{
			pos=m_size-1;
		}
		return m_data[pos];
	}
	//对数组进行排序
	void m_Sort()
	{
		T temp_data;
		for (int j=0;j<m_size-1;j++)
		{
			for (int i=0;i<m_size-1-j;i++)
			{			
				if (m_data[i]>m_data[i+1])
				{
					temp_data=m_data[i];
					m_data[i]=m_data[i+1];
					m_data[i+1]=temp_data;
				}

			}
		}
	}
	//打印数组
	void m_Print()
	{
		cout<<"m_size:"<<m_size<<endl;
		for (int i=0;i<m_size;i++)
		{
			cout<<i<<":"<<m_data[i]<<endl;
		}

	}

};


#endif

