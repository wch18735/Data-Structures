// �� ��带 ���� ������ �˻��ϴ� ��ȸ��
// ���ݱ��� ��ȸ ���� ������ ����ߴ� �Ϳ� ���� ���� ��ȸ�� ť�� ����ϴ� ��ȸ��

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

// ==== ����ť �ڵ� ���� ====
// rear: �����Ͱ� �ִ� ���� ��
// front:�����Ͱ� ���� ���� ó��
// ���� Dequeue������ Max_Size�� ���� ���� �����ִ� ����� ����� �迭 ������ ����� ��츦 �����Ѵ�
// ���� Queue�� �⺻������ �ð�������� ȸ���Ѵ�

#define MAX_QUEUE_SIZE 100
typedef TreeNode *element;
typedef struct { // ť Ÿ��
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// �����Լ�
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ������ �Լ�
void init_queue(QueueType *q) {
	q->front = q->rear = 0;
}

// ������� ���� �Լ�
int is_empty(QueueType * q) {
	return (q->front == q->rear); // ó�� ���ۻ��¿� ������ empty
}

int is_full(QueueType * q) {
	return((q->rear+1)% MAX_QUEUE_SIZE == q->front);
}


// �迭�� ������ �ο��ϰ� ���� ���� �迭�� struct �ȿ� ����ְ�, �̸� ���δ� struct�� �ڷᱸ���� �����ָ� �ȴ� (����� circular_queue)
void enqueue(QueueType *q, element item) {		// ����, ������ ��带 ���� ������ �迭�� ����ִµ�, �̶� �̴� ť�� ���¸� ������ �迭 ��������
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front+1) % MAX_QUEUE_SIZE;
	/*(q->front + MAX_QUEUE_SIZE - 1) �̰Ŵ� front_delete �� ��*/
	return q->data[q->front];
}

void level_order(TreeNode *ptr) {
	QueueType q;	// TreeNode�� ������ �� �ִ� Circle_Que Ÿ��
	init_queue(&q);	// q�� front�� rear�� �ʱ�ȭ	// struct�� ���� ���������Ƿ� ���۷����� �޸� ���� ��� ����~!!

	if (ptr == NULL)/* ��尡 ������ */ return; /* �� */
	enqueue(&q, ptr); /* ��尡 �����ϸ� �������� �߰� */
	while (!is_empty(&q)) { // �������� �� ������ �Ʒ� ������ �����Ѵ�
		ptr = dequeue(&q);	// ���� ���߿� ���� Node Ȯ��
		printf("[%d]", ptr->data);
		if (ptr->left) /* ptr�� ���� ��尡 �����ϸ� */
			enqueue(&q, ptr->left); // �ش� ����� ������ �߰��Ѵ�
		if (ptr->right) /* ptr�� ������ ��尡 �����ϸ� */
			enqueue(&q, ptr->right); // �ش� ����� �������� �߰��Ѵ�
	}
	/* ��, dequeue�� ������ ���� ��, �ڱ� �ڽ��� left, right�� �ϳ��� �������� ����ְ� ������ */
	/* �� ������ζ�� �Ȱ��� �� �ٿ��� �� �� -> ���� �� ������ ����ȴ�  */
	/* �ٽ��� 1.�����鼭 2.�� �� �߰� 3. ������� ���� */
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;
int main(void)
{
	printf("���� ��ȸ=");
	level_order(root);
	printf("\n");
	return 0;
}