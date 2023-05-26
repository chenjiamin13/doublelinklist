#include "doublelinklist.h"

//1.创建一个空的双向链表
double_list_t createEmptyDoubleLinkList()
{
	//1.申请存放头尾指针的结构体
	double_list_t p = (double_list_t)malloc(sizeof(double_node_t));
	if (p == NULL) {
		printf("error\n");
		return NULL;
	}
	//2.初始化,头尾分别指向开辟头节点
	p->len = 0;
	p->head = p->tail = (link_list_t)malloc(sizeof(link_node_t));
	if (p->head == NULL) {
		printf("error\n");
		return NULL;
	}
	//3.初始化头节点
	p->head->prior = NULL;
	p->head->next = NULL;
	return p;
}
//2.向双向链表的指定位置插入数据 post位置， data数据
int insertIntoDoubleLinkList(double_list_t p, int post, datatype data)
{
	int i;
	link_list_t temp = NULL;
	//1.容错判断
	if (post<0 || post>p->len) {
		printf("error\n");
		return -1;
	}
	//2.创建新节点
	link_list_t pnew = (link_list_t)malloc(sizeof(link_node_t));
	if (pnew == NULL) {
		printf("error\n");
		return -1;
	}
	//初始化
	pnew->data = data;
	pnew->prior = NULL;
	pnew->next = NULL;
	//3.插入链表
	//尾插还是插入中间
	//插入尾巴
	if (post == p->len) {
		p->tail->next = pnew;
		pnew->prior = p->tail;
		p->tail = pnew;
	}
	//中间插（前半段？后半段）
	else {
		if (post < p->len / 2) {//前半段
			temp = p->head;
			for (i = 0; i <= post; i++) {
				temp = temp->next;//往后走
			}
		}
		else {//后半段
			temp = p->tail;//向前移动尾指针
			for (i = 0; i < p->len - post - 1; i++) {
				temp = temp->prior;//往前走
			}
		}
		//插入操作（先连前面，后连后面）
		pnew->prior = temp->prior;
		temp->prior->next = pnew;
		pnew->next = temp;
		temp->prior = pnew;
	}
	p->len++;
	return 0;
}
//3.遍历双向链表
void showDoubleLinkList(double_list_t p)
{
	link_list_t temp=NULL;
	printf("正向遍历：\n");
	temp = p->head;
	while (temp->next != NULL) {
		temp = temp->next;
		printf("%d ", temp->data);
	}
	printf("\n");
	printf("反向遍历：\n");
	temp = p->tail;
	while (temp != p->head) {
		printf("%d ", temp->data);
		temp = temp->prior;
	}
	printf("\n");
}
//4.删除双向链表指定位置的数据
int deletePostDoubleLinkList(double_list_t p, int post)
{
	int i;
	link_list_t temp = NULL;
	//1.容错判断
	if (post < 0 || post >= p->len) {
		printf("error\n");
		return -1;
	}
	//2.分析删除位置
	//（1）尾端
	if (post == p->len - 1) {
		//(1)尾指针往前移动一个
		p->tail = p->tail->prior;
		//(2)释放被删除节点
		free(p->tail->next);
		//（3）最后一个节点和链表断开
		p->tail->next = NULL;
	}
	else {//中间删除
		if (post < p->len / 2) {//前半段
			temp = p->head;
			for (i = 0; i < post + 1; i++) {
				temp = temp->next;
			}
		}
		else {//后半段
			temp = p->tail;
			for (i = 0; i < p->len - 1 - post; i++) {
				temp = temp->prior;
			}
		}
		//删除
		temp->prior->next = temp->next;
		temp->next->prior = temp->prior;
		free(temp);
		temp = NULL;
	}
	//长度-1
	p->len--;
	return 0;
}
//5.判断双向链表是否为空
int isEmptyDoubleLinkList(double_list_t p)
{
	return p->len == 0;
}
//6.求双向链表的长度
int lengthDoubleLinkList(double_list_t p)
{
	return p->len;
}
//7.查找指定数据出现的位置 data被查找的数据
int searchPostDoubleLinkList(double_list_t p, datatype data)
{
	link_list_t temp = p->head;
	//从头遍历,比较数据
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
//8.修改指定位置的数据,post修改的位置 data被修改的数据
int changeDataDoubleLinkList(double_list_t p, int post, datatype data)
{
	int i;
	link_list_t temp = NULL;
	//1.容错判断
	if (post < 0 || post >= p->len) {
		printf("error\n");
		return -1;
	}
	//移动到修改位置上去
	if (post < p->len / 2) {//头
		temp = p->head;
		for (i = 0; i < post + 1; i++) {
			temp = temp->next;
		}
	}
	else {//尾
		temp = p->tail;
		for (i = 0; i < p->len - 1 - post; i++) {
			temp = temp->prior;
		}
	}
	//3.修改数据
	temp->data = data;
	return 0;
}
//9.删除双向链表中的指定数据 data代表删除所有出现的data数据
int deleteDataDoubleLinkList(double_list_t p, datatype data)
{
	link_list_t pdel = NULL;
	link_list_t h = p->head->next;
	while (h != NULL) {
		if (h->data == data) {
			if (h==p->tail) {//尾
				p->tail = p->tail->prior;
				free(p->tail->next);
				p->tail->next = NULL;
			}
			else {//中间
				h->prior->next = h->next;
				h->next->prior = h->prior;
				pdel = h;
				h = h->next;
				free(pdel);
				pdel = NULL;
			}
			p->len--;
		}
		else {//不相等
			h = h->next;
		}
	}
}