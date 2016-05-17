#include<iostream>
using namespace std;


typedef struct ListNode
{
	int data;
	struct ListNode *next;
}node;

node *getnewnode(int data){
	
		node *newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		return newNode;
}

void addLast(node **head, int data) {
	node *ptr = *head;
	if(*head == NULL)
		*head = getnewnode(data);
	else{
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = getnewnode(data);
	}
}


node *createList() {
	node *head = NULL;
	addLast(&head , 12);
	addLast(&head , 13);
	addLast(&head , 14);
	addLast(&head , 15);
	return head;
}

void printList(node *head){
	node *ptr = head;
	while(ptr != NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
}

int main() {
	node *head = NULL;
	head = createList();
	printList(head);
	return 0;
}

 	


