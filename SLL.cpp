#include<iostream>
using namespace std;

typedef struct listnode{
	int data;
	struct listnode *next;
}node;

node* createnode(int data) {
	node* newnode = new node;
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

void insertfront(node **head,int data) {
	node *newnode = createnode(data);

	if(!newnode) {
		cout<<"Memory Error"<<"\n";
		return;
	}

	if(*head == NULL)
		*head = newnode;

	else{

		newnode->next = *head;
		*head = newnode;
	}

}

void insertRear(node **head, int data) {
	node *newnode = createnode(data);

	if(*head == NULL)
		*head = newnode;
	else{
		node *temp = *head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}

}

void insertAtPos(node **head, int data, int pos) {
	node *p,*q;
	int k=1;
	node *newnode = createnode(data);
	
	if(!newnode) {
		cout<<"Memory Error"<<"\n";
		return;
	}

	p = *head;

	if(pos == 1){
		newnode->next = *head;
		*head = newnode;
	}
	else{
		while(p != NULL && k<pos){
			k++;
			q = p;
			p = p->next;
		}
		q->next = newnode;
		newnode->next = p;
	}
}

void displayList(node *head){
	node *temp;
	temp = head;
	cout<<"\n";
	while(temp != NULL){
		cout<< temp->data<<" ";
		temp =temp->next;
	}
	cout<<"\n";
}

void countNode(node *head) {
	int count = 0;
	node *temp = head;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	cout<<"\n"<<"number of nodes in list :"<<count<<"\n";
}

void deletefront(node **head){
	node *temp = *head;
	if(*head == NULL) {
		cout << "List Empty" <<"\n";
		return;
	}
	else {
		*head = (*head)->next;
		cout<<"\n"<<"Element deleted in front is :"<<temp->data<<"\n";
		delete temp;
		return;
	}
	
}

void deleterear(node **head) {
	node *temp = *head,*p;
	if(*head == NULL) {
		cout << "List Empty" <<"\n";
		return;
	}
	else{
		while(temp->next != NULL){
			p =temp;
			temp =temp->next;
		}
		p->next = NULL;
		cout<<"\n"<< "element del at rear is : "<<temp->data;
		delete temp;
	}
		

}

void deletePos(node **head, int pos) {
	int k = 1;
	node *temp = *head, *q;
	if(*head == NULL) {
		cout << "List Empty" <<"\n";
		return;
	}
	if(pos == 1){
		*head = (*head)->next;
		delete temp;
		return;
	}
	else{
		while(temp != NULL && k < pos) {
			k++;
			q = temp;
			temp = temp->next;
		}
		if(temp == NULL)
			cout<<"\n"<<"position "<< pos <<" doesnot exit"<<"\n";
		else{
			q->next = temp->next;
			cout<<"\n"<<"element deleted at positon "<<pos<<" is :"<<temp->data;
			delete temp;
		}
		
	}
}

int main() {
	node *head = NULL;
	insertfront(&head , 10);
	insertRear(&head,12);
	insertAtPos(&head,15,2);
	insertRear(&head,20);
	insertfront(&head , 30);

	displayList(head);
	countNode(head);
	
	deletefront(&head);
	displayList(head);
	
	deleterear(&head);
	displayList(head);
	
	deletePos(&head, 3 );
	displayList(head);
	countNode(head);
	displayList(head);
	
	deletePos(&head,6);
	return 0;
}