



#include <iostream>
using namespace std;
struct node{
int data;
struct node* next;
};
void Push(struct node** headRef, int data){
struct node* newNode = new struct node;
newNode->data = data;
newNode->next = *headRef;
*headRef = newNode;
}
void Print(struct node* head){
struct node* current = head;
while(current != NULL){
cout << current->data << endl;
current = current->next;
}
}
int Length(struct node* head){
struct node* current = head;
int counter = 0;
while(current != NULL){
current = current->next;
counter++;
}
return counter;
}
void AddToEnd(struct node** headRef, int data){
struct node* current = *headRef;
if(current == NULL){
Push(headRef, data);
}else{
while(current->next != NULL){
current = current->next;
}
Push( &(current->next), data);
}
}
struct node* FindFromTheEnd(struct node* head, int k){
struct node* current = head;
struct node* runner = head;
for(int i=0; (i<k); i++){
if(runner == NULL){
return NULL;
}
runner = runner->next;
}
while(runner != NULL){
current = current->next;
runner = runner->next;
}
return current;
}
void InsertSorted(struct node** headRef, int data){
struct node* newNode = new struct node;
newNode->data = data;
struct node* current = *headRef;
if(current == NULL || (*headRef)->data >= data){
newNode->next = *headRef;
*headRef = newNode;
}else{
while( (current->next != NULL) && ((current->next)->data < data) ){
current = current->next;
}
newNode->next = current->next;
current->next = newNode;
}
}
void RemoveNode(struct node** headRef, int data){
struct node* current = *headRef;
struct node* prev = NULL;
if((*headRef)->data == data){ // removing the first node
prev = *headRef;
*headRef = (*headRef)->next;
delete prev;
return;
}else{
while(current != NULL){
if(current->data > data){ // faster remove IF the list is sorted
return;
}
if(current->data == data){ // located the node
prev->next = current->next;
delete current;
return;
}
prev = current;
current = current->next;
}
}
}
bool RemoveDuplicatesSorted(struct node* head){
bool removed = false;
struct node* current = head;
while(current && current->next){ //current != NULL && current->next != NULL
if (current->data == current->next->data){
struct node* temp = current->next;
current->next = temp->next;
delete temp;
removed = true;
}else{
current = current->next;
}
}
return removed;
}


struct node* Reverse(struct node* head) {
	node* prev = NULL;
	node* current = head;
	while (current != NULL) {
		node* nextNode = current->next;
		current->next = prev;
		prev = current;
		current = nextNode;
	}
	return prev;
}


bool isPalindrome(struct node* head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}

	int length = Length(head);
	int mid = length / 2;


	node* slow = head;
	node* fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	node* firstHalf = head;
	node* secondHalf = Reverse(slow);

	node* secondHalfCopy = secondHalf;
	bool isPalin = true;

	for (int i = 0; i < mid; i++) {
		if (firstHalf->data != secondHalf->data) {
			isPalin = false;
			break;
		}
		firstHalf = firstHalf->next;
		secondHalf = secondHalf->next;
	}

	Reverse(secondHalfCopy);

	return isPalin;




}

struct node* Merge(node* head1, node* head2) {
	node* temp = new struct node;
	node* current = temp;

	while (head1 != NULL && head2 != NULL) {
		if (head1->data <= head2->data) {
			current->next = head1;
			head1 = head1->next;
		} else {
			current-> next = head2;
			head2 = head2->next;
		}
		current = current->next;
	}

	if (head1 != NULL) {
		current->next = head1;
	} else {
		current->next = head2;
	}

	node* mergedHead = temp->next;

	delete temp;

	return mergedHead;
}



