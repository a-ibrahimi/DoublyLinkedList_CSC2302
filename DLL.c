#include <stdio.h>
#include<stdlib.h>

typedef struct Node{ 
    	char name; 
   	struct Node* next; 
	struct Node* previous;
}Node; 

Node* create_and_fill(char c){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->previous = NULL;
	newNode->name = c;
	return newNode;
}

Node* add_node(char c, Node* head){
	Node* newNode = create_and_fill(c);
	Node* walker;
	if(c <= head->name){
		newNode->next = head;
		head->previous = newNode;
		head = newNode;
	}
	else{
		walker = head; // used just to traverse the linked list
		while(walker->next != NULL && c > walker->next->name){
			walker = walker->next;
		}
		if(walker->next == NULL){ //insert at the end
			newNode->previous = walker;
			walker->next = newNode;
		}
		else{
			newNode->next = walker->next;
			newNode->previous = walker;
			walker->next = newNode;
			newNode->next->previous = newNode;
		}
	}
	return head;
}

Node* delete_node(char c, Node* head){
	Node* todelete = NULL, *walker, *temp;
	if(c == head->name){
		todelete = head;
		head = head->next;
		head->previous = NULL;
	}
	else{
		walker = head; // used just to traverse the linked list
		while(walker->next != NULL && c != walker->name){
			walker = walker->next;
		}
		if(walker->next == NULL && walker->name == c){ //delete at the end
			todelete = walker;
			walker->previous->next = NULL;
		}
		else if(walker->next != NULL){
			todelete = walker;
			todelete->previous->next = todelete->next;
      todelete->next->previous = todelete->previous;
		}
	}
	free(todelete);
	return head;
}

int main(){
	Node* head = create_and_fill('b');
	head->next = create_and_fill('d');
	head = add_node('c', head); // do not forget to update head
	Node* walker = head; // used just to traverse the linked list
	while(walker != NULL){
		printf("%c ", walker->name);
		walker = walker->next;
	}
	printf("\n");
	head = delete_node('d', head);
	walker = head;
	while(walker != NULL){
		printf("%c ", walker->name);
		walker = walker->next;
	}

}
