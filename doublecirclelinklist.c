#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node_t
{
	datatype data;
	struct node_t *prior;
	struct node_t *next;
 } link_node_t,*link_list_t;
 
typedef struct doublinklist
{
	link_list_t head;
	link_list_t tail;
}double_node_t,*double_list_t;

int main()
{
	int i;
	int all_num=8;
	int start_num=3;
	int kill_num=3;
	link_list_t h=NULL;
	link_list_t pdel=NULL;
	scanf("%d%d%d",&all_num,&start_num,&kill_num);
	
	//1.创建双向循环链表
	 double_list_t p=(double_list_t)malloc(sizeof(double_node_t));
	 if(p==NULL){
	 	printf("error\n");
	 	return -1;
	 }
	p->head=p->tail=(link_list_t)malloc(sizeof(link_node_t));
	if(p->tail==NULL){
		printf("error\n");
	 	return -1;
	}
	p->head->data=1;
	p->head->prior=NULL;
	p->head->next=NULL;
	//创建新节点链接到表尾
	for(i=2;i<=all_num;i++){
		link_list_t pnew=(link_list_t)malloc(sizeof(link_node_t));
		if(pnew==NULL){
			printf("error\n");
		 	return -1;
		}
		pnew->data=i;
		pnew->prior=NULL;
		pnew->next=NULL;
		//(1)将新节点链接到链表尾
		p->tail->next=pnew;
		pnew->prior=p->tail; 
		//(2)尾指针向后移动
		p->tail=pnew; 
	} 
	//(3)形成双向循环链表
	p->tail->next=p->head;
	p->head->prior=p->tail; 
	//调试数据 
	#if 0
	while(1){
		printf("%d\n",p->head->data);
		p->head=p->head->next;
		sleep(1);
	}
	#endif
	//2.循环杀死猴子
	h=p->head; 
	//(1)移动到开始猴子 
	for(i=0;i<start_num-1;i++){
		h=h->next;
	} 
	while(h->next!=h){//只剩一个节点退出 
		//(2)先将h移动到将要被杀死的猴子处
		for(i=0;i<kill_num-1;i++){
			h=h->next;
		} 
		//h已经指向要杀死猴子处，杀死
		h->prior->next=h->next;
		h->next->prior=h->prior; 
		pdel=h;
		printf("kill is %d\n",pdel->data);
		h=h->next;//向后移动
		free(pdel);
		pdel=NULL; 
	}
	printf("king is %d\n",h->data);
	return 0;
}









