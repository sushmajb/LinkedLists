#include<iostream>
#include "ListNode.h"
using namespace std;

class Solution{
	public:
		ListNode* reverse(ListNode* head){
			ListNode* prev = NULL, *next=NULL;
			while(head){
				next = head->next;
				head->next = prev;
				prev = head;
				head =next;
			}
			return prev;
		}

		ListNode* reverseRec(ListNode* head){
			if(!head)
				return head;
			if(head->next)
				return head;
			ListNode* rest = head->next;
			ListNode* newHead = reverseRec(rest);
			head->next->next = head;
			head->next = NULL;
			return  newHead;
		}

		int ListLength(ListNode* head){
			ListNode* cur = head;
			int count = 0;
			while(cur != NULL){
				count++;
				cur = cur->next;
			}
			return count;
		}
	};

		

int main(){
	int A[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(A)/sizeof(int);
	Solution sl;
	
	ListNode* list= buildList(A,size);

	cout<<"Number of nodes in linkedlist\n";
	int count = sl.ListLength(list);
	cout<<count;

	cout<<"\nBefore : ";
	printList(list);
	list = sl.reverseRec(list);
	//list = sl.reverse(list);
	cout<<"\nAfter : ";
	printList(list);
	cout<<"\n";
	deleteList(list);
	return 0;
}