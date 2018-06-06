#include <stdio.h>

void find_loop_n_remove(node * head){

	if (head == NULL) return;

	node * slow = head;
	node * fast = head;
	// Find loop logic.
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast){
			printf("Linked List loop detected.\n");
			break;
		}
	}
	// remove loop logic.
	if ( slow == fast){
		slow = head;
		while(fast->next != slow->next){
			slow = slow->next;
			fast = fast->next;
		}
		fast->next = NULL;
	}
	return;
}
