#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

/*
			<���� Ʈ��>
				n1
			��		��
		  n2		  n3
*/


int main() {
	// ���� ���� (���۷��� ����)
	TreeNode *n1, *n2, *n3;

	// �޸� �Ҵ�
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));

	n1->data = 10;
	n1->left = n2;
	n1->right = n3;

	n2->data = 20;
	n2->left = NULL;
	n2->right = NULL;

	n3->data = 30;
	n1->left = NULL;
	n1->right = NULL;
}






/* ����Ʈ���� ǥ�� */
/* 
	1. �迭���̿��� ǥ��
	��� ����Ʈ���� ��ȭ ���� Ʈ����� �����ϰ� �� ��忡 ��ȣ�� �ٿ����� ��ȣ�� �迭�� �ε����� ��� ����� �����͸� �迭�� �����ϴ� ���
	��� i�� �θ� ��� �ε��� = i/2
	��� i�� ���� �ڽ� ��� �ε��� = 2i
	��� i�� ������ �ڽ� ��� �ε��� = 2i + 1
*/


/*
	2. ��ũ ǥ����
	�����͸� �̿��Ͽ� �θ��尡 �ڽĳ�带 ����Ű�� �ϴ� ���
*/