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
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = e;
	p->link = head;	// p�� head�� ����Ű�� ��
	head = p;		// head �� p�� ����Ų��
	return head;
}

// ����� �߰��� �߰� (���Կ���)
ListNode* insert(ListNode *head, ListNode *pre, element e) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode*));
	p->data = e;
	p->link = pre->link;
	pre->link = p;
	return head;
} // pre ������ �߰�

// ����� ���ۺκ� ����
ListNode* delete_first(ListNode* head) {
	ListNode *removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// ����� �߰��κ� ����
ListNode* delete_mid(ListNode* head, ListNode *pre) {
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

// ����� ����Ʈ ��� ����Ʈ
void print_list(ListNode *head) {
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

// Ư�� �� ã�Ƴ��� �Լ�
ListNode* search_list(ListNode* head, element e) {
	ListNode *p = head;
	while (p != NULL)
	{
		if (p->data == e) return p;	// ������ �ش� ��� ��ȯ
		p = p->link;				// �ƴϸ� ��� ����
	}
	return NULL;
}

// �� ���� ����Ʈ�� ��ġ�� �Լ�
ListNode* concat_list(ListNode *head1, ListNode *head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode *p;
		p = head1;
		while (p->link !=NULL)		// ������ ����
			p = p->link;
		p->link = head2;
		return head1;
	}
}

// �������� �����ϴ� �Լ�
ListNode *reverse(ListNode *head) {
	ListNode *r, *q, *p;
	p = head;	// p�� �������� ���� ����Ʈ
	q = NULL;	// q�� �������� ���� ���
	while (p != NULL){
		r = q;
		q = p;
		p = p->link;	// ����

		q->link = r;	// �������� ��ȯ
	}
	return q;			// ���� ������ ����̴�!!!
						// ���⼭ head = q; ���� head ��ȯ�ص� ����
}

// Test
int main() {
	ListNode *head = NULL;
/*  ����1
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	return 0; 
*/

}