#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

// ����Ʈ���� NULL ��ũ�� �̿��Ͽ� ��ȯ ȣ�� ���̵� Ʈ���� ������ ��ȸ
// NULL ��ũ�� ���� ��ȸ�ÿ� �ļ� ����� ���� �ļ��� (inorder successor)�� ������� ���� Ʈ���� ������ ���� Ʈ��(threaded binary tree)
#define true 1

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
	int is_thread; // ���� ������ ��ũ�� �������̸� True
} TreeNode;
// �ܸ� ���� ��ܸ������ ������ ���Ͽ� is_thread �ʵ� �ʿ�

TreeNode *find_successor(TreeNode *p) {
	TreeNode *q = p->right;		// p �� ������ ��带 q�� ����
	if (q == NULL || p->is_thread == true) return q;	// q�� NULL�̰ų�, p�� ���� �ļ��ڰ� q��� (is_thread == true) q����
	while (q->left != NULL) q = q->left;				// ������ �ڽĳ�尡 NULL��, ���� �ļ��ڵ� �ƴ϶�� �װ��� ���� ���� ���� �̵�
	return q;											// ���� �Ʒ� ���� ��� ����
}

void thread_inorder(TreeNode *t) {
	TreeNode *q;
	q = t;
	while (q->left) q = q->left;	// ���� ���� ���� �̵�
	do {
		printf("c", q->data);	// ������ ���
		q = find_successor(q);	// �ļ��� �Լ� ȣ��
	} while (q);				// NULL�� �ƴϸ�
}

