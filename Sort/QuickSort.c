#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

/* �� ���� */
// ��������� ���� ���� ���� ���
// ���������� ���
// ����Ʈ�� 2���� �κ� ����Ʈ�� ��յ� �����ϰ�, ������ �κ� ����Ʈ�� �ٽ� ��������(���ȣ��)

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do 
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);	// ���� ������ Swqp ����
	} while (low < high);	// ��� �˻� �Ϸ�

	SWAP(list[left], list[high], temp);
	return high;	// High�� Pivot�� ��ġ
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {	// q = �� �ǹ��� ��ġ
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++) // ���� ���� �� ���
		list[i] = rand() % 100;
	quick_sort(list, 0, n - 1); // ������ ȣ��
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}

/* ��  ���� ���⵵ �м� */
// �ּ��� ���: ���� �յ��� ����Ʈ�� ���ҵǴ� ���
// �н� ��: log(n)
// �� �н� �ȿ����� �� Ƚ��: n
// �� ��Ƚ��: n*log(n)

// �־��� ���: �ص��� �ұյ��� ����Ʈ�� ���ҵǴ� ���
// �н� ��: n
// �� �н� �ȿ��� ��Ƚ��: n
// �� ��Ƚ��: n**2
// �߰� ���� �ǹ����� �����ϸ� �ұյ� ���� ��ȭ ����

