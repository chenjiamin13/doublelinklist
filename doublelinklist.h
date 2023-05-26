#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node_t
{
	datatype data;//������ 
	struct node_t* next;//ָ����һ���ڵ��ָ�� next ��һ��
	struct node_t* prior;//ָ��ǰһ���ڵ��ָ�� prior ǰһ��
}link_node_t, * link_list_t;
//��˫�������ͷָ���βָ���װ��һ���ṹ���� 
//˼�����е���ѧ����ʽ����
typedef struct doublelinklist
{
	link_list_t head; //ָ��˫�������ͷָ��
	link_list_t tail; //ָ��˫�������βָ��
	int len;
}double_node_t, * double_list_t;
//1.����һ���յ�˫������
double_list_t createEmptyDoubleLinkList();
//2.��˫�������ָ��λ�ò������� postλ�ã� data����
int insertIntoDoubleLinkList(double_list_t p, int post, datatype data);
//3.����˫������
void showDoubleLinkList(double_list_t p);
//4.ɾ��˫������ָ��λ�õ�����
int deletePostDoubleLinkList(double_list_t p, int post);
//5.�ж�˫�������Ƿ�Ϊ��
int isEmptyDoubleLinkList(double_list_t p);
//6.��˫������ĳ���
int lengthDoubleLinkList(double_list_t p);
//7.����ָ�����ݳ��ֵ�λ�� data�����ҵ�����
int searchPostDoubleLinkList(double_list_t p, datatype data);
//8.�޸�ָ��λ�õ�����,post�޸ĵ�λ�� data���޸ĵ�����
int changeDataDoubleLinkList(double_list_t p, int post, datatype data);
//9.ɾ��˫�������е�ָ������ data����ɾ�����г��ֵ�data����
int deleteDataDoubleLinkList(double_list_t p, datatype data);