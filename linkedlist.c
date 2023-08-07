#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h" 

cll_node *cll_head(cll_node *list){	
	if(list == NULL){		//reutnrs null if list is empty
		return NULL;
	}
	else if (list->is_head == 1){		//if it is already the list
		return list;
	}
	else {
		return cll_head(list->prev); 	//recursive loop
	} 
  
}

cll_node *cll_tail(cll_node *list) {

	if(list == NULL){
		return NULL;
	}
	else if (list->next->is_head == 1){
		return list;
	}
	else {
		return cll_tail(list->next); 		// recursive loop that keeps going until it finds the tail
   	}
}

unsigned long cll_length(cll_node *list) {

	int i = 1;
	cll_node *node = list;	
	if (list == NULL){    
		return 0;
	}
	while (list->next != node){ //for loop finds length
		i++;
		list = list->next;
	}
	return i;		 
}

cll_node *cll_find(cll_node *list, int value) {

	int tempval = list->value; 
	if(list == NULL){    
		return NULL;
	}
	else if (tempval == value){
		return list;
	}
	list = list->next;
	while (list->value != tempval){    //goes through all cases until it hits itself again
		if (list->value == value){
			return list;
		}
		else{
			list = list->next;
		}
	}
 	return NULL;
}

cll_node *cll_remove(cll_node *list) {

	if (list == NULL){
		return NULL; 
	}
	else if (list->is_head ==1 && cll_length(list) == 1){
		free(list);
		return NULL;
	}
	else if (list->is_head == 1){
		cll_node *temp = list->prev;
                cll_node *temp1 = list->next;
                temp->next = temp1;
                temp1->prev = temp;
		temp1->is_head = 1;
                free(list);
                return temp1;
	}
	else{
		cll_node *temp = list->prev;
		cll_node *temp1 = list->next;
		temp->next = temp1;
		temp1->prev = temp;
		free(list);
		return temp1;
	}
}

cll_node *cll_insert(int value, cll_node *list, int before) {  
 
	if(list == NULL){
		cll_node *node = malloc(sizeof(cll_node));
		node->next = node;
		node->prev = node;
		node->is_head = 1;
		node->value = value;
		return node;
	}
	else if (before == 0){
		cll_node *node = malloc(sizeof(cll_node));
                cll_node *tempnode = list->next;
                tempnode->prev = node;
                node->next = tempnode;
                list->next = node;
                node->prev = list;
                node->value = value;
		return node;
	}
	else{
		cll_node *node = malloc(sizeof(cll_node));
                cll_node *tempnode = list->prev;
                tempnode->next = node;
                node->prev = tempnode;
                list->prev = node;
                node->next = list;
                node->value = value;
                return node;		
	}

}

void cll_show(cll_node *list) {
    // Find the head of the linked list
    cll_node *head = cll_head(list);
    cll_node *ptr = head;
    // Print opening [
    putchar('[');
    // Loop through list printing values
    if (ptr) {
        do {
            if (!ptr->is_head) 
                printf(", "); // include a comma if not the first element
            if (ptr == list) 
                putchar('*'); // include * surrounding parameter element
            printf("%d", ptr->value);
            if (ptr == list) 
                putchar('*');
            ptr = ptr->next; // next pointer
        } while (ptr != head);
    }
    // Print closing ]
    puts("]");
}

/*int main(int argc, const char *argv[]) { 

cll_node *x = NULL;
    putchar('A'); cll_show(x);
    x = cll_insert(25, x, 1);
    putchar('B'); cll_show(x);
    x = cll_insert(1, x, 0);
    putchar('C'); cll_show(x);
    x = cll_insert(98, cll_head(x), 1);
    putchar('D'); cll_show(x);
    x = cll_insert(0, x, 1);
    putchar('E'); cll_show(x);
    x = cll_insert(-8, cll_tail(x), 0);
    putchar('F'); cll_show(x);
    cll_node *y = cll_head(x);
    putchar('G'); cll_show(y);
    printf("Length: %lu (or %lu)\n", cll_length(y), cll_length(x));
    x = cll_remove(x);
    putchar('H'); cll_show(x);
    putchar('I'); cll_show(y);
    x = cll_remove(cll_find(y, 98));
    putchar('J'); cll_show(x);
    putchar('K'); cll_show(y);
    
    return 0;
}
*/