#include <stdio.h>

int ll_length(node * head){
	int len = 0;
	while(head!=NULL){
		len++;
		head=head->next;
	}
	return len;
}

node * find_merge_point(node * a,node *b){
	if(NULL == a ||NULL == b) return;
	int m = ll_length(a);
	int n = ll_length(b);
	int d = n-m;
	int i = 0;

	if (m>n){
		node * tmp = b;
		b=a;
		a=tmp;
		d = m -n;
	}

	for(i=0;i<d;i++){
		b = b->next;
	}

	while(a != NULL && b != NULL){
		if (a == b ) retun a;
		a = a->next;
		b = b->next;
	}
	return NULL;
}
