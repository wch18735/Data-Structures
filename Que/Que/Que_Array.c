#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {								// Quetype�� Abstract Data Type ���� �����
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;
// front: ���� ����ִ� ���� ó��
// rear: ���� data�� ���ִ� ��


// ���� �Լ�
void error(const char *message) {						// ���� ����� �Լ�
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q) {					// ť�� �ʱ�ȭ: front�� rear�� ��� -1�� �ʱ�ȭ��Ų��
	q->front = -1;
	q->rear = -1; 
}

void queue_print(QueueType *q) {				// ť�� ����Ʈ�ϱ�
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || q->rear < i)		// ������ �ٱ����̸� (front => �� ������ �� ��, reat => Data�� ���ִ� �� �κ�)
			printf("  |");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int is_full(QueueType *q) {						// Full ���� Ȯ���ϴ� ���ִ� �Լ� (rear == MAX_QUEUE_SIZE - 1 �̸�)
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else return 0;
}

int is_empty(QueueType *q) {					// Empty ���� Ȯ���ϴ� �Լ� (front == rear �̸� �� ��)
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}
	
void enqueue(QueueType *q, int item) {			// ����ִ� �� 
	if (is_full(q))								// is_full �ȿ� is_full(q) �� �� ������ֱ�
		error("��ȭ ����");
	else q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q) {						// �̾Ƴ��� �� (�ʱ�ȭ ��Ű�鼭 �̵��Ѵ�)
	if (is_empty(q)) {							// is_empty �ȿ� is_empty(q) �� �� ������ֱ�
		error("���� ����");
		return -1;
	}
	// q->data[q->front] = NULL;				Why �ʱ�ȭ ������ ����X ??r
	return q->data[++(q->front)];
}

int main(void) {
	int item = 0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
}