#include "common.h"

//将换两个节点(必须）
//先交换prev的next
//在交换prev的next的next
struct node{
	int d;
	node* next;
};
//prev指针
void swapmy(node* p1, node* p2){
	swap(p1->next, p2->next);
	swap(p1->next->next, p2->next->next);
}

node* reverselist2(node* head){
	stack<node*> s;
	while (head != nullptr){
		s.push(head); 
		head = head->next;
	}
	node* pre = nullptr;
	while (!s.empty()){
		node* c = s.top(); s.pop();
		if (pre == nullptr){
			pre = c;
			head = c;
		}
		else{
			pre->next = c;
			pre = c;
		}
	}
	pre->next = nullptr;
	return head;
}
node* reverselist(node* cur, node* prev){
	if (cur == nullptr){
		return prev;
	}
	node* temp = cur->next;
	cur->next = prev;
	return reverselist(temp, cur);
}



typedef struct _DoubleList{
	int value;
	struct _DoubleList* prev;
	struct _DoubleList* next;
}DoubleList;

DoubleList* getmid(DoubleList* start, DoubleList* end){
	DoubleList* slow = start;
	DoubleList* fast = start;
	while (fast->next != end && fast->next->next != end){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->next;
}

DoubleList* doublelist_to_tree(DoubleList* start, DoubleList* end){
	if (start == end){
		start->prev = nullptr;
		start->next = nullptr;
		return start;
	}
	else{
		DoubleList* retnode = getmid(start, end);
		retnode->prev = doublelist_to_tree(start, retnode->prev);
		retnode->next = doublelist_to_tree(retnode->next, end);
		return retnode;
	}
}