#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p) {
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode* pop() {		// Q.���� ���ڰ� ��� �ɱ�?
						// A.��� �ȴ�. ���� ������ �����߱� ����!!
	TreeNode *p = NULL;
	if (top >= 0) p = stack[top--];	// stack �� ��������
	return p;
}

void inorder_iter(TreeNode *root) {
	while (1) {
		for (; root; root = root->left)				// �� ���� Node�� ã�ư���!!
			push(root);								// stack�� �߰��Ѵ�					
		root = pop();								// root�� NULL ������ �ϳ� ���� ���� ����Ű�� ��
		if (!root) break;	// root -> NULL �̸�!!
		printf("[%d]", root->data);					// �ش� �ڸ����� printf ����
		root = root->right;							// ������ ������ root�� ���� (������ null)
													// null �̸� left �˻���� �״�� �ϳ� ���� �ö�
													// ������ stack�� ����

		/* ��, ���� ���� ���� ã��, �߰��� ��ġ��, ���� ���������� �̵��ϴ� ������ȸ�� ������*/
	}
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;

int main(void) {
	printf("���� ��ȸ=");
	inorder_iter(root);
	printf("\n");
}