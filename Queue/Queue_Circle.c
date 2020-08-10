#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	int rear, front;
	element data[MAX_QUEUE_SIZE];
} QueCircle;

// QueCircle �� �Լ���
// init_QueCircle(&q)			: ����
void init_QueCircle(QueCircle *q) {
	q->front = 0;
	q->rear = 0;
}

// is_full(&q)					: ���� ���ִ��� Ȯ��
int is_full(QueCircle *q) {
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

// is_empty(&q)					: ������� Ȯ��
int is_empty(QueCircle *q) {
	return q->front == q->rear;
}

// Error �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// element dequeue(&q)			: �� �տ��� �̰� ����
element dequeue(QueCircle *q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->data[q->front] = '\0';					// �ʱ�ȭ ��Ű��
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // front�� �� ĭ ������ �ű��
	return q->data[q->front];
}

// void enque(&q, element item)	: �� �ڿ� �߰�
void enqueue(QueCircle *q, element item) {
	if (is_full(q)) error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// element peek(&q)				: �̾Ƴ��⸸ ��
element peek(QueCircle *q) {
	if (is_empty(q)) error("���鿡���Դϴ�");
	return q->data[q->front + 1];
}

// ����ť ��� �Լ�
void queue_print(QueCircle *q) {
	printf("QUEUE(fornt=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);				//  i = i + 1 ���� i = (i + 1) % MAX_QUEUE_SIZE �� ����
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}


int main() {
	QueCircle q;
	int element;

	init_QueCircle(&q);
	printf("---- ������ �߰� �ܰ� -----\n");
	while (!is_full(&q))
	{
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &element);
		enqueue(&q, element);
		queue_print(&q);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");

	printf("---- ������ ���� �ܰ� ----\n");
	while (!is_empty(&q))
	{
		element = dequeue(&q);
		printf("������ ����: %d\n", element);
		queue_print(&q);
	}
	printf("ť�� ��������Դϴ�");
	return 0;
}