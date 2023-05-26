#include "doublelinklist.h"

//1.����һ���յ�˫������
double_list_t createEmptyDoubleLinkList()
{
	//1.������ͷβָ��Ľṹ��
	double_list_t p = (double_list_t)malloc(sizeof(double_node_t));
	if (p == NULL) {
		printf("error\n");
		return NULL;
	}
	//2.��ʼ��,ͷβ�ֱ�ָ�򿪱�ͷ�ڵ�
	p->len = 0;
	p->head = p->tail = (link_list_t)malloc(sizeof(link_node_t));
	if (p->head == NULL) {
		printf("error\n");
		return NULL;
	}
	//3.��ʼ��ͷ�ڵ�
	p->head->prior = NULL;
	p->head->next = NULL;
	return p;
}
//2.��˫�������ָ��λ�ò������� postλ�ã� data����
int insertIntoDoubleLinkList(double_list_t p, int post, datatype data)
{
	int i;
	link_list_t temp = NULL;
	//1.�ݴ��ж�
	if (post<0 || post>p->len) {
		printf("error\n");
		return -1;
	}
	//2.�����½ڵ�
	link_list_t pnew = (link_list_t)malloc(sizeof(link_node_t));
	if (pnew == NULL) {
		printf("error\n");
		return -1;
	}
	//��ʼ��
	pnew->data = data;
	pnew->prior = NULL;
	pnew->next = NULL;
	//3.��������
	//β�廹�ǲ����м�
	//����β��
	if (post == p->len) {
		p->tail->next = pnew;
		pnew->prior = p->tail;
		p->tail = pnew;
	}
	//�м�壨ǰ��Σ����Σ�
	else {
		if (post < p->len / 2) {//ǰ���
			temp = p->head;
			for (i = 0; i <= post; i++) {
				temp = temp->next;//������
			}
		}
		else {//����
			temp = p->tail;//��ǰ�ƶ�βָ��
			for (i = 0; i < p->len - post - 1; i++) {
				temp = temp->prior;//��ǰ��
			}
		}
		//�������������ǰ�棬�������棩
		pnew->prior = temp->prior;
		temp->prior->next = pnew;
		pnew->next = temp;
		temp->prior = pnew;
	}
	p->len++;
	return 0;
}
//3.����˫������
void showDoubleLinkList(double_list_t p)
{
	link_list_t temp=NULL;
	printf("���������\n");
	temp = p->head;
	while (temp->next != NULL) {
		temp = temp->next;
		printf("%d ", temp->data);
	}
	printf("\n");
	printf("���������\n");
	temp = p->tail;
	while (temp != p->head) {
		printf("%d ", temp->data);
		temp = temp->prior;
	}
	printf("\n");
}
//4.ɾ��˫������ָ��λ�õ�����
int deletePostDoubleLinkList(double_list_t p, int post)
{
	int i;
	link_list_t temp = NULL;
	//1.�ݴ��ж�
	if (post < 0 || post >= p->len) {
		printf("error\n");
		return -1;
	}
	//2.����ɾ��λ��
	//��1��β��
	if (post == p->len - 1) {
		//(1)βָ����ǰ�ƶ�һ��
		p->tail = p->tail->prior;
		//(2)�ͷű�ɾ���ڵ�
		free(p->tail->next);
		//��3�����һ���ڵ������Ͽ�
		p->tail->next = NULL;
	}
	else {//�м�ɾ��
		if (post < p->len / 2) {//ǰ���
			temp = p->head;
			for (i = 0; i < post + 1; i++) {
				temp = temp->next;
			}
		}
		else {//����
			temp = p->tail;
			for (i = 0; i < p->len - 1 - post; i++) {
				temp = temp->prior;
			}
		}
		//ɾ��
		temp->prior->next = temp->next;
		temp->next->prior = temp->prior;
		free(temp);
		temp = NULL;
	}
	//����-1
	p->len--;
	return 0;
}
//5.�ж�˫�������Ƿ�Ϊ��
int isEmptyDoubleLinkList(double_list_t p)
{
	return p->len == 0;
}
//6.��˫������ĳ���
int lengthDoubleLinkList(double_list_t p)
{
	return p->len;
}
//7.����ָ�����ݳ��ֵ�λ�� data�����ҵ�����
int searchPostDoubleLinkList(double_list_t p, datatype data)
{
	link_list_t temp = p->head;
	//��ͷ����,�Ƚ�����
	int post = 0;
	while (temp->next != NULL) {
		temp = temp->next;
		if (temp->data == data) {
			return post;
		}
		post++;
	}
	return -1;
}
//8.�޸�ָ��λ�õ�����,post�޸ĵ�λ�� data���޸ĵ�����
int changeDataDoubleLinkList(double_list_t p, int post, datatype data)
{
	int i;
	link_list_t temp = NULL;
	//1.�ݴ��ж�
	if (post < 0 || post >= p->len) {
		printf("error\n");
		return -1;
	}
	//�ƶ����޸�λ����ȥ
	if (post < p->len / 2) {//ͷ
		temp = p->head;
		for (i = 0; i < post + 1; i++) {
			temp = temp->next;
		}
	}
	else {//β
		temp = p->tail;
		for (i = 0; i < p->len - 1 - post; i++) {
			temp = temp->prior;
		}
	}
	//3.�޸�����
	temp->data = data;
	return 0;
}
//9.ɾ��˫�������е�ָ������ data����ɾ�����г��ֵ�data����
int deleteDataDoubleLinkList(double_list_t p, datatype data)
{
	link_list_t pdel = NULL;
	link_list_t h = p->head->next;
	while (h != NULL) {
		if (h->data == data) {
			if (h==p->tail) {//β
				p->tail = p->tail->prior;
				free(p->tail->next);
				p->tail->next = NULL;
			}
			else {//�м�
				h->prior->next = h->next;
				h->next->prior = h->prior;
				pdel = h;
				h = h->next;
				free(pdel);
				pdel = NULL;
			}
			p->len--;
		}
		else {//�����
			h = h->next;
		}
	}
}