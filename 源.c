#define _CRT_SECURE_NO_WARNINGS
/*
//数组实现队列
#include<stdio.h>
#define Maxsize 10
int A[Maxsize];
int front = -1;
int rear = -1;
void EnQueue(int x) {
	if (front ==(rear + 1) % Maxsize) {
		printf("The queue is full");
		return;
	}
	else if (front == -1 && rear == -1) {
		rear = 0;
		front = 0;
	}
	else{
		rear = (rear+1) % Maxsize; 
	}
	A[rear] = x;
}
void DeQueue(){
	if (front == -1 && rear == -1) {
		printf("No element to dequeue");
	}
	else if (front == 0 && rear == 0) {
		front = -1;
		rear = -1;
	}
	else {
		front = (front + 1) % Maxsize;
	}
}
int isEmpty() {
	return (front == -1 && rear == -1);
}
void Print() {
	int length = (rear - front + Maxsize) % Maxsize + 1;
	for (int i = 0; i < length; i++) {
		printf("%d", A[(front + i) % Maxsize]);
	}
	printf("\n");
}
int main() {
	EnQueue(1);
	EnQueue(2);
	EnQueue(3);
	EnQueue(4);
	DeQueue();
	Print();
	printf("the queue is empty? %d", isEmpty());
}
*/

//链表实现队列
#include<stdio.h>
#include<stdlib.h>
typedef struct queue {
	int data;
	struct Queue* next;
}queue;
void EnQueue(int x, queue** front, queue** rear) {
	queue* temp = (queue*)malloc(sizeof(queue));
	temp->data = x;
	temp->next = NULL;
	if (*front == NULL && *rear == NULL) {
		*front = temp;
		*rear = temp;
		return;
	}
	(*rear)->next = temp;
	*rear = temp;
}
void DeQueue(queue** front,queue** rear) {
	queue* temp = *front;
	if (*front == NULL &&*rear == NULL){
		printf("queue is empty\n");
		return;
	}
	else if (*front == *rear) {
		*front = NULL;
		*rear = NULL;
	}
	else {
		*front = ((*front)->next);
	}
	free(temp);
}
void Print(queue* front) {
	printf("The queue is:");
	while (front != NULL) {
		printf("%d", front->data);
		front = front->next;
	}
	printf("\n");
}
int isEmpty(queue* front, queue* rear) {
	return (front == NULL && rear==NULL);
}
int main() {
	queue* front = NULL;
	queue* rear = NULL;
	EnQueue(1, &front, &rear);
	DeQueue(&front, &rear);
	Print(front);
	printf("The queue is empty?%d", isEmpty(front,rear));
}
