#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

// ����� ���� DataType
typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
	// TreeNode�� ������ ������ �����Ѵ�
} TreeNode;

// ����� ���� �Լ� (��ȸ)
// ���� ��ȸ
void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);		// ���� ����Ʈ�� ��ȸ
		printf("[%d] ", root->data);	// ��� �湮 (print�� �����Ϳ� �����Ѵٴ� ��)
		inorder(root->right);		// ������ ����Ʈ�� ��ȸ
	}
}

// ���� ��ȸ
void preorder(TreeNode *root) {
	if (root) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// �Ŀ� ��ȸ
void postorder(TreeNode *root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main() {
	TreeNode n1 = { 1, NULL, NULL };
	TreeNode n2 = { 4, &n1, NULL };
	TreeNode n3 = { 16, NULL, NULL };
	TreeNode n4 = { 25, NULL, NULL };
	TreeNode n5 = { 20, &n3, &n4 };
	TreeNode n6 = { 15, &n2, &n5 };
	TreeNode *root = &n6;

	printf("���� ��ȸ=");
	inorder(root);
	printf("\n");
	printf("���� ��ȸ=");
	preorder(root);
	printf("\n");
	printf("���� ��ȸ=");
	postorder(root);
	printf("\n");
	return 0;
}





/* BinaryTree�� ��ȸ */
/*
	1. ������ȸ (preorder traersal)
	: �ڼճ�庸�� ��Ʈ��带 ���� �湮�Ѵ�

	2. ������ȸ (inorder traversal)
	: ���� �ڼ�, ��Ʈ, ������ �ڼ� ������ �湮�Ѵ�

	3. ������ȸ (postorder traveral)
	: ��Ʈ��庸�� �ڼ��� ���� �湮�Ѵ�

	�� ��ȯȣ���� �̿��Ѵ�
*/
