#include <stdio.h>

typedef struct node{
	int data;
	struct node * next;
}node;

void del_from_end(node * head,int n ){
	
	if (NULL==head) return;

	node * p1 = head;
	node * p2 = head;
	int i = n;
	while(i--){
		p1=p1->next;
	}

	while(p1->next!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
	}
// del logic .
	node * tmp = p2->next;
	if(n==1){
		p2->next = NULL;
	}else{
		p2->next = p2->next->next;
	}
return;
}
