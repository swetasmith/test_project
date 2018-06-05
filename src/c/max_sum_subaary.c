#include <stdio.h>

#define MAX(A,B) ((A>B)?A:B)
#define DEBUG 1
#define debug_print(fmt,...) \
				do{ if(DEBUG) \
						printf("%s:%d:%s(): " fmt,__FILE__,__LINE__,__func__,__VA_ARGS__);}while(0);

int max_sum_subarray(int a [], int size){
	int i=0,ans=a[0],sum=0;

	for(i=1;i<size;i++){
			ans=MAX(ans,a[i]);
	}
	if(ans <0){
		return ans;
	}

	for(i=1;i<size;i++){
		if((sum + a[i])>0){
			sum=sum+a[i];
		}else{
			sum =0;
		}
	}
		ans=MAX(ans,sum);
	return ans;
}

int find_loop_ll(node * head){
	node * slow = head;
	node * fast = head;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			return true;
		}
	}
return false;
}

void  find_loop_remove_ll(node * head){
	node * slow = head;
	node * fast = head;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			break;
		}
	}
	if(slow == fast){
		slow = head;
		while(show->next != fast->Next){
			slow = slow->next;
			fast= fast->next;
		}
		fast->next = NULL;
	}
}
int length (node * head) {
	int len = 0;
	while(head !=NULL){
		len++;
		head = head->next;
	}
	return len;
}

node * find_merge_point(node * a , node * b ){
	int m= length(a);
	int n= lrngth(b);
	int d = n - m;
	if(m>n){
		node * temp = a;
		b=a;
		a=temp;
		d= m-n;
	}
	int i;
	for(i=0;i<d;i++){
		b =b->next;
	}
	while(a!=NULL && b!=NULL){
		if(a==b){
			return a;
			}
			a=a->next;
			b=b->next;
	}
return NULL;
}




int main(){
	int arr[] = {3,-2,5,-1};
	int n = sizeof(arr)/sizeof(arr[0]);
	debug_print("size : %d ,sum %d \n",n,max_sum_subarray(arr,n));
	return 0;
}
