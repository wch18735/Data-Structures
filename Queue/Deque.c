#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}DEQUE;


/* ���� ������� */

// error()
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// init(dq)
void init(DEQUE *q) {
	q->front = 0;
	q->rear = 0;
}

// is_empty(dq)
int is_empty(DEQUE *q) {
	return (q->front == q->rear);
}

// is_full(dq)
int is_full(DEQUE *q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

// add_front(dq,e)
void add_front(DEQUE *q, element e) {
	if (is_full(q)) error("��ȭ ����");
	q->data[q->front] = e;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

// add_rear(dq,e)
void add_rear(DEQUE *q, element e) {
	if (is_full) error("��ȭ ����");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = e;
}

// delete_front(dq)
int delete_front(DEQUE *q) {
	if (is_empty(q)) error("���� ����");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// delete_rear(dq)
int delete_rear(DEQUE *q) {
	if (is_empty(q)) error("���� ����");
	int e;
	e = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return e;
}

// get_front(q)
int get_front(DEQUE *q) {
	if (is_empty(q)) error("���� ����");
	return q->data[(q->front + 1)%MAX_QUEUE_SIZE];
} // get������ %MAX�� ��������Ѵ�

// get_rear(q)
int get_rear(DEQUE *q) {
	if (is_empty(q)) error("���� ����");
	return q->data[q->rear];
}



int main() {
	DEQUE q;
	init(&q);

	for (int i = 0; i < 3; i++) {
		add_front(&q,i);
		printf("%d\n", get_front(&q));
	}
	for (int i = 0; i < 3; i++) {
		printf("%d\n",delete_rear(&q));
	}
	return 0;
}


/*
double-ended queue �� ���ڷ� ���ʿ��� ����� �����ϴ�
������ front�� rear �� ������ �ǽ��ϸ� ���´� �����̴�.
����ť�� ���� ���� ���� �Լ�: add_front, delete_rear
����ť�� ���� ���� �ִ� �Լ�: add_rear == enqueue, delete_front == dequeue
�Լ��� ����� �� ������ �����ϸ�
delete_rear ������ ������Ʈ�� rear = (rear-1+MAX) % MAX �� �����Ѵ�.
add_front ������ ���� ������Ʈ�� front = (front-1+MAX) % MAX �� �����Ѵ�.
���ð� ť�� ������ ��� ������ �ִ�.
*/