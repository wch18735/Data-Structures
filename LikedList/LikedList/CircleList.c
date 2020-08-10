#include<stdio.h>
#include<stdlib.h>

// ��� ����
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

/* ��� ���� */
// ����� ���ۺκп� �߰�
ListNode* insert_first(ListNode *head, element e) {
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	if (head == NULL) {		// ���� ����
		head = node;
		node->link = head;
	}
	else {					// �ƴ� ���
		node->link = head->link;
		head->link = node;
	}
	return head;
}

// ����� ���� ����
ListNode* insert_last(ListNode* head, element e) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	if (head == NULL) {		// head�� ���۷����� �����ϴ��� �ƴϸ� ��ü�� ���� �����ϴ��� Ȯ��
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;		// �� ���� ��带 head�� �Ѵ�
	}
	return head;
}

// ����� ó�� ����
ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	removed = head->link;
	head->link = removed->link;
	free(removed);
	return head;
}

// ����� ������ ����
ListNode* delete_last(ListNode* head) {
	ListNode* removed;
	removed = head;
	while (removed->link != head)	// head �ٷ� ������
		removed = removed->link;
	head = removed;
	removed = removed->link;
	head->link = removed->link;
	free(removed);
	return head;
}

// ����Ʈ�� �׸� ���
void print_list(ListNode* head)
{
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // ������ ��� ���
}


int main(void)
{
	ListNode *head = NULL;
	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	head = delete_first(head);
	head = delete_last(head);
	print_list(head);
	return 0;
}