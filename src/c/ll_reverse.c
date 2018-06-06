#include <stdio.h>

void reverse_ll(node * head){
	if(head == NULL) return;
	node * pcurr = head;
	node * pnext = NULL;
	node * pprev = NULL;

	while(pcurr != NULL){
		pnext = pcurr->next;
		pcurr->next =pprev;
		pprev = pcurr;
		pcurr = next;
	}
	head = pprev;
	return head;
}


void print_rev_ll(node * head){
	if(head == NULL) return;
	print_rev_ll(head->next);
	printf("Reverse of linked list is:\n");
	printf("%d->",head->data);
}

void display_ll(node * head){
	if(head == NULL) return;
	printf("Reverse of linked list is:\n");
	while(head != NULL){
		printf("%d->",head->data);
		head = head->data;
	}
}

