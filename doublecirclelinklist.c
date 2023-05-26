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
	
	//1.����˫��ѭ������
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
	//�����½ڵ����ӵ���β
	for(i=2;i<=all_num;i++){
		link_list_t pnew=(link_list_t)malloc(sizeof(link_node_t));
		if(pnew==NULL){
			printf("error\n");
		 	return -1;
		}
		pnew->data=i;
		pnew->prior=NULL;
		pnew->next=NULL;
		//(1)���½ڵ����ӵ�����β
		p->tail->next=pnew;
		pnew->prior=p->tail; 
		//(2)βָ������ƶ�
		p->tail=pnew; 
	} 
	//(3)�γ�˫��ѭ������
	p->tail->next=p->head;
	p->head->prior=p->tail; 
	//�������� 
	#if 0
	while(1){
		printf("%d\n",p->head->data);
		p->head=p->head->next;
		sleep(1);
	}
	#endif
	//2.ѭ��ɱ������
	h=p->head; 
	//(1)�ƶ�����ʼ���� 
	for(i=0;i<start_num-1;i++){
		h=h->next;
	} 
	while(h->next!=h){//ֻʣһ���ڵ��˳� 
		//(2)�Ƚ�h�ƶ�����Ҫ��ɱ���ĺ��Ӵ�
		for(i=0;i<kill_num-1;i++){
			h=h->next;
		} 
		//h�Ѿ�ָ��Ҫɱ�����Ӵ���ɱ��
		h->prior->next=h->next;
		h->next->prior=h->prior; 
		pdel=h;
		printf("kill is %d\n",pdel->data);
		h=h->next;//����ƶ�
		free(pdel);
		pdel=NULL; 
	}
	printf("king is %d\n",h->data);
	return 0;
}









