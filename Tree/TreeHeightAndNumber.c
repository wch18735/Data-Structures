/* ���� Ʈ�� ����: ��� ������ ���� */
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

int get_node_count(TreeNode *node) {
	int count = 0;
	if (node != NULL) {
		count = 1 /* ���� '���� ����' ��ȯ */ + get_node_count(node->left) /* ���� ���� �Ʒ� ��� ���� ��ȯ */ + get_node_count(node->right) /* ���� ������ �Ʒ� ��� ���� ��ȯ */;
	}
	return count;
}

int get_height(TreeNode *node) { // �� �غ��� ������� ���� ��ȯ
	int height = 0;
	if (node != NULL) //��尡 NULL�� �ƴϸ�!!
		height = 1 + max(get_height(node->left), get_height(node->right));
	// max �Լ��� stdlib.h���� ����ϴ� ��
	// height�� ���� 1��ȯ (null �̸� �Լ����� 0��ȯ�ϹǷ�)
	return height; // �б��� �߰������� ������ ������� height�� �Ѱ��ش�
}

int get_leaf_count(TreeNode *node) {
	/*���� § �ڵ�*/
	// int count = 0;
	// if (node == NULL) return 1;
	// return count + get_leaf_count(node->left) + get_leaf_count(node->right);

	// if(node == NULL) return 1; �� �ϸ� �ܸ���忡�� 2�� ���� �ö���� �ȴ�. (�� �ʿ��� 1�� ����)

	int count = 0;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
	} return count;
}

/* 
����Լ��� �ٹ� ������ ���� �ۼ��ϰ��ִ�, 
���ڷ� ���� ���°� �߰��б����̶�� �����Ѵ�. 
���⿡ ���� �� �������� ��ȯ�Ǵ� ���� �����غ���.
example�� null ���� �� 0 or 1�̳� � ���� ��ȯ�Ǵ����� Ȯ��
*/