#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<time.h>

// ���ĵ� ���� ����Ʈ�� ���ĵ��� ���� ������ ����Ʈ�� ����
// �ʱ⿡ ���� ����Ʈ�� ����ְ�, ������ ���ڵ��� ��� ������ ����Ʈ�� ����
// ������ ����Ʈ�� ���� ���� ����(�Ǵ� ū) ���� �����ؼ� ���� ����Ʈ�� �����´�
// �� ������ ����Ʈ�� �� �� ������� �ʰ� �� ���� ó���ϴ� ��

// �˰���
// for i <- 0 to n-2 do
//		least <- A[i], A[i+1], ... , A[n-1] �߿��� ���� ���� ���� �ε���;
//		A[i]�� A[least] �� ��ȯ;
//		i++;
//		������ n-2 ������ ������ ������ �� ���� ���� ���� �ʿ� ����

#define MAX_SIZE 10
#define SWAP(x,y,t)((t) = (x), (x) = (y), (y) = (t))
int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n) {
	int i, j, least, temp;
	for (int i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)			// �ּҰ� Ž��
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
	}
	// i => ������ ���� ��ġ�� index�� 1�� ����
	// least => ���鼭 �ּ��� �� ã��
	// j => i�� ���� index
	// �� j < n ����?
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i<n; i++) // ���� ���� �� ���
		list[i] = rand() % 100; // ���� �߻� ���� 0~99
	selection_sort(list, n); // �������� ȣ��
	for (i = 0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}

// �������� ���⵵ �м�
// ��Ƚ��: O(n**2)
// �̵�Ƚ��: 3(n-1)
// ��ü �ð��� ���⵵: O(n**2)
// �������� �������� ����

