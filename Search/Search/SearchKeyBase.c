// Ž��Ű (search key)
// �׸�� �׸��� �������ִ� Ű(key)
// Ž���� ���Ͽ� ���Ǵ� �ڷ� ����
// �迭, ���Ḯ��Ʈ, Ʈ��, �׷��� ��
// Ž��: ��� �ڷ� �������� ���ϴ� ���� ã�Ƴ��� ����

// ���� Ž�� (Sequential search)
// Ž�� ��� �߿��� ���� �����ϰ� �������� Ž�� ���
// ���ĵ��� ���� �迭�� ó������ ���������� �ϳ��� �˻��ϴ� ���
// ��� �� Ƚ��
// Ž������: (n+1)/2 �� ��
// Ž������: n�� ��
// �ð����⵵: O(n)

int seq_search(int key, int low, int high) {
	int i;
	for (i = low; i <= high; i++)
		if (list[i] == key)
			return i;	// Ž�� ����
	return -1;			// Ž�� ����
}

int seq_search2(int key, int low, int high) {
	int i;
	list[high + 1] = key;			// Ű ���� ã���� ����
	for (i = low; list[i] != key; i++)
		;
	if (i == (high + 1)) return -1;	// Ž�� ����
	else return i;					// Ž�� ����
} // Ż�⹮ �� 1��, i�� key ���̶� �񱳿��µ� i�� key�� index�� ���ϸ鼭 �� ���� ����

