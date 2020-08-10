// ������ 2 �Ǵ� 3�� ��带 ������ Ʈ��

/* 2-��� */
// ����Ž��Ʈ��ó�� �ϳ��� ������ k1�� �� ���� �ڽ� ��带 ������

/* 3-��� */
// 2���� ������ k1,k2�� 3���� �ڽĳ�带 ������

// ���� ���� Ʈ���� �ִ� �����͵��� ��� k1���� ���� ���̴�
// �߰� ���� Ʈ���� �ִ� ������ ��� k1���� ũ�� k2���� �۴�
// �����ʿ� �ִ� �����͵��� ��� k2���� ũ��

Tree23Node *tree23_search(Tree23Node* root, int key)
{
	if (root == NULL)			// Ʈ���� ��� ������
		return FALSE;
	else if (key == root->data)// ��Ʈ�� Ű==Ž��Ű 
		return TRUE;
	else if (root->type == TWO_NODE) {  // 2-���
		if (key < root->key)
			return tree23_search(root->left, key);
		else
			return tree23_search(root->right, key);
	}
	else {										// 3-���
		if (key < root->key1)
			return tree23_search(root->left, key);
		else if (key > root->key2)
			return tree23_search(root->right, key);
		else
			return tree23_search(root->middle, key);
	}
}