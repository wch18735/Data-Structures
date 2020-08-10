// �����̳� ��ȭ��ȣ�θ� Ž���ϴ� ���
// Ž��Ű�� ������ ��ġ�� �����Ͽ� Ž���ϴ� ���: O(log(n))
// ����Ž���� ���� Ž���� �����ϳ� ����Ʈ�� �ұյ� �����Ͽ� Ž��
// ��ʽ��� �̿��� ã�´�: ã������ key ���� ó��, ���� key ���� ������ index�� ������ ����־� ã��

int interpol_search(int key, int n)
{
	int low, high, j;
	low = 0;
	high = n - 1;
	while ((list[high] >= key) && (key > list[low])) {
		j = ((float)(key - list[low]) / (list[high] - list[low])		// ����ȯ �ʿ�
			*(high - low)) + low;
		if (key > list[j]) low = j + 1;
		else if (key < list[j]) high = j - 1;
		else low = j;
	}
	if (list[low] == key) return(low); // Ž������
	else return -1; // Ž������
}
