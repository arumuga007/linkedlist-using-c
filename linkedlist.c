#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist{ 	//creation linkedlist using structure
	int data; //value gonna store in a node
	struct linkedlist* next; //To store address of the next node
}linkedlist; // data and address of next node together is called as a node
linkedlist* root = NULL; // root node is a global variable which can be accessable anywhere in a program and it always store the address of the first node
void insert() {		//To insert new element to linkedlist in the begining O(1)
	printf("\n How many elements do you want to add to linked list?"); 
int size, data;
scanf("\n%d",&size);
for(int i = 1; i <= size ; i++ ) {
	printf("\nEnter the value of %d element:",i);
	scanf("\n%d",&data);
	linkedlist* temp;
	temp =(linkedlist*) malloc(sizeof(linkedlist)); //malloc function is used to allocate memory for our node in given size in heap memory
	temp->data = data;
	temp->next = root;
	root = temp;
	}
	}
void display() {	//To display all the data of all node in the linked list
	linkedlist* temp = root;
	if(root == NULL) {
		printf("\nNo element to display");
		return;
	}
	while(1) {
		printf("\n%d",temp->data);
		if(temp->next == NULL)
			break;
		temp = temp->next;
	}
}
void element_in_position() { //To remove element in particular position
	printf("\nEnter the position of node which you want to see?");
	int position;
	linkedlist* temp = root;
	scanf("\n%d",&position);
	while(--position > 0) {
		temp = temp->next;
	}
	printf("\nThe element in position %d is %d",position,temp->data);
}
void removeElement() { //To remove element you want ,where element value is equals to data of any node
	int Element;
	linkedlist* temp = root;
	linkedlist* temp2 = NULL;
	if(temp == NULL) {
		printf("No element available in the list");
		return;
	}
	printf("\nEnter the element you want to remove:");
	scanf("\n%d",&Element);
	while(temp->next != NULL && temp->data != Element) {
		temp2 = temp;
		temp = temp->next;

	}
	if(temp2 != NULL) {
	temp2->next = temp->next;
	free(temp);
	printf("\nElement removed");
	}
	else if(temp-> data == Element) {
		root = temp->next;
		free(temp);
	}
	else
		printf("\nNo such element found");
}
void calls() {
	printf("\n1.To add element to linkedlist");
	printf("\n2.To view all element in linkedlist" );
	printf("\n3.To remove particular element from linkedlist");
	printf("\n4.To view element in particular position");
	printf("\n5.To exit");
	int exit = 0;
	while(1) {
	printf("\nEnter your choice: ");
	int choice;
	scanf("\n%d",&choice);
	switch(choice) {
		case 1:
			insert();
			break;
		case 2:
			display();
			break;
		case 3:
			removeElement();
			break;
		case 4:
			element_in_position();
			break;
		case 5:
			exit = 1;
			printf("\nExited from program successfully");
			break;
		default:
			printf("\nInvalid choice");
			break;
	}
	if(exit == 1) //Used to break out of the outer loop easily
		break;
			}
}
void main() {
	printf("\nWelcome to linkedlist code");
	calls();
}
