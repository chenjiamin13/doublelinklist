#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node_t
{
	datatype data;//数据域 
	struct node_t* next;//指向下一个节点的指针 next 下一个
	struct node_t* prior;//指向前一个节点的指针 prior 前一个
}link_node_t, * link_list_t;
//将双向链表的头指针和尾指针封装到一个结构体里 
//思想上有点像学的链式队列
typedef struct doublelinklist
{
	link_list_t head; //指向双向链表的头指针
	link_list_t tail; //指向双向链表的尾指针
	int len;
}double_node_t, * double_list_t;
//1.创建一个空的双向链表
double_list_t createEmptyDoubleLinkList();
//2.向双向链表的指定位置插入数据 post位置， data数据
int insertIntoDoubleLinkList(double_list_t p, int post, datatype data);
//3.遍历双向链表
void showDoubleLinkList(double_list_t p);
//4.删除双向链表指定位置的数据
int deletePostDoubleLinkList(double_list_t p, int post);
//5.判断双向链表是否为空
int isEmptyDoubleLinkList(double_list_t p);
//6.求双向链表的长度
int lengthDoubleLinkList(double_list_t p);
//7.查找指定数据出现的位置 data被查找的数据
int searchPostDoubleLinkList(double_list_t p, datatype data);
//8.修改指定位置的数据,post修改的位置 data被修改的数据
int changeDataDoubleLinkList(double_list_t p, int post, datatype data);
//9.删除双向链表中的指定数据 data代表删除所有出现的data数据
int deleteDataDoubleLinkList(double_list_t p, datatype data);