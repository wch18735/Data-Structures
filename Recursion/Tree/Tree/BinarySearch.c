// ����Ž��Ʈ�� => Ž���۾��� ȿ�������� �ϱ� ���� �ڷᱸ��
// key(���� ���� Ʈ��) < key(��Ʈ���) < key(������ ���� Ʈ��)
// ����Ž���� ������ȸ(LVR)�ϸ� ������������ ���ĵ� ���� ���� �� �ִ�

// ������ ��Ʈ���� ���� ��, �������� ��Ʈ���� ū ��
// ����Ž��Ʈ������ ����: �־��� Ű ���� ��Ʈ��� Ű ������ ������ ����, ũ�� ���������� ��ġ ��Ų��

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
} TreeNode;

/* ��ȯ���� ������� ����Ž�� */
TreeNode *search_iter(TreeNode *node, int key) {
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search_iter(node->left, key);
	else
		return search_iter(node->right, key);
}

TreeNode *search_recur(TreeNode *node, int key) {
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}	// �� ���� while �������� node ������Ʈ
	return NULL;		// Ž���� �������� ��� NULL ��ȯ
}
TreeNode *new_node(int item) {	// key(==item) ���� ������ ���ο� ��� ����
	TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// ����Ž��Ʈ�������� ���Կ��� => Ž���� ������ ��ġ�� ���ο� ��带 �����ϴ� ��ġ
TreeNode *insert_node(TreeNode *node, int key) {
	// Ʈ���� �����̸� ���ο� ��� ��ȯ
	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ�� ������
	if (key < node->key)	// key���� ����� key������ ������
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	// key���� ���� ��,�� �Ǵ��ϰ� �װ��� NULL�̸� �� ��ġ�� �����ϰ� ������Ʈ
	// �ƴϸ� �ٽ� �� �� key���� �־��� key�� ��

	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�
	return node;
}

void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);		// ���� ����Ʈ�� ��ȸ
		printf("[%d] ", root->key);	// ��� �湮 (print�� �����Ϳ� �����Ѵٴ� ��)
		inorder(root->right);		// ������ ����Ʈ�� ��ȸ
	}
}

// ����Ž��Ʈ�������� ���� ����
// 1. �����Ϸ��� ��尡 �ܸ� ����� ���
// 2. �����Ϸ��� ��尡 �ϳ��� �����̳� ������ ���� Ʈ�� �� �ϳ��� ������ �ִ� ���
// 3. �����Ϸ��� ��尡 �� ���� ���� Ʈ�� ��� ������ �ִ� ���

// CASE1: �����Ϸ��� ��尡 �ܸ� ����� ���
// �����ϰ� ���� ���� (�θ� ��忡�� NULL ������ �����ָ� �ȴ�)

// CASE2: �����Ϸ��� ��尡 �ϳ��� ����Ʈ���� ���� �ִ� ���
// ���� �ش� ��带 �����ϰ�, �ش����� �θ����, �ش����� �ڽĳ�带 �ٿ��ش�

// CASE3: �����Ϸ��� ��尡 �ΰ��� ����Ʈ���� ���� �ִ� ���
// �������� ���� ����� ���� ���� ��带 ���� ��� ��ġ�� �����´�
// �׷��ٸ� ���� ����� ���� ���?
// ���� ����Ʈ������ ���� ū �� or ������ ����Ʈ������ ���� ���� �� �� �ϳ�!!
// ����: ����Ž��Ʈ���� ��� ����� ����Ż ����
// ���� ����Ʈ���� ���� ������ȸ�� ������������ ���� ����
// ��� ���� �ش� ����� �� ���� ���� �� ������

TreeNode *min_value_node(TreeNode *node) {
	TreeNode *current = node;
	//�� ���� �ܸ� ��带 ã���� ��������
	while (current->left != NULL)
		current = current->left;

	return current;
}

TreeNode *delete_node(TreeNode *root, int key) {
	if (root == NULL) return root;

	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (key > root->key)
		root->right = delete_node(root->left, key);

	// Ű�� ��Ʈ�� ���� �� �� ��带 ����
	else{
		if (root->left == NULL) {	// ������ ���� ��
			TreeNode *temp = root->right; // �ݴ��� ��ȯ
			free(root);
			return temp;
		}
		else if (root->right == NULL) {	// �������� ���� ��
			TreeNode *temp = root->left;	// �ݴ��� ��ȯ
			free(root);
			return temp;
		}

		// �� ��° ���

		TreeNode *temp = min_value_node(root->right);

		// ���� ��ȸ�� �İ� ��带 �����Ѵ�
		root->key = temp->key;

		// ���� ��ȸ�� �İ� ��带 �����Ѵ�
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

TreeNode *search(TreeNode *node, int key) {
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;
}

int main(void)
{
	TreeNode * root = NULL;
	TreeNode * tmp = NULL;
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("���� Ž�� Ʈ������ 30�� �߰��� \n");
	else
		printf("���� Ž�� Ʈ������ 30�� �߰߸��� \n");
	return 0;
}