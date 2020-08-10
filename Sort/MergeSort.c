#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10
int sorted[MAX_SIZE];
// i�� ���ĵ� ���� ����Ʈ�� ���� �ε���
// j�� ���ĵ� ������ ����Ʈ�� ���� �ε���
// k�� ���ĵ� ����Ʈ�� ���� �ε���

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// ���� ���ĵ� list�� �պ�
	while (i<=mid && j <= right){
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid)	// ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	//�迭 sorted[]�� ����Ʈ�� �迭 list[]�� ����
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;			// ����Ʈ�� �յ����
		merge_sort(list, left, mid);		// �κ� ����Ʈ ����
		merge_sort(list, mid + 1, right);	// �κ� ����Ʈ ����
		merge(list, left, mid, right);		// �պ�
	}
}

/* �պ� ���� ���⵵ �м� */
// �� Ƚ��: ũ�� n�� ����Ʈ�� ��Ȯ�� �յ�й��ϹǷ� log(n) ���� �н�
// �� �н����� ����Ʈ�� ��� ���ڵ� n���� ���ϹǷ� n���� �� ����

/* �̵� Ƚ�� */
// ���ڵ��� �̵��� �� �н����� 2n�� �߻��ϹǷ� ��ü ���ڵ��� �̵��� 2n*log(n)�� �߻�
// ���ڵ��� ũ�Ⱑ ū ��쿡�� �ſ� ū �ð��� ���� �ʷ�
// ���ڵ带 ���� ����Ʈ�� �����Ͽ� �պ� ������ ���, �ſ� ȿ����
// ����, ���, �־��� ��� ū ���� ���� O(n*log(n)) �� ���⵵
// �������̸� �������� �ʱ� �л� ������ ������ �� �޴´�




// 1. ����Ʈ�� �� ���� �յ��� ũ��� �����ϰ� ���ҵ� ����Ʈ�� ����
// 2. ���ĵ� �� ���� �κ� ����Ʈ�� ���Ͽ� ��ü ����Ʈ�� �����Ѵ�

// ����, ����, ���� �˰����� ����Ѵ�.
// 1. ����(divide): �迭�� ���� ũ���� 2���� �κ� �迭�� ����
// 2. ����(conquer): �κ� �迭�� �����ϴµ�, �κ� �迭�� ũ�Ⱑ ����� ���� ������ ���ȣ���� �̿��Ͽ� �ٽ� ������������� �����Ѵ�
// 3. ����(Combine): ���ĵ� �κй迭�� �ϳ��� �迭�� �����Ѵ�

/* �պ����� �˰��� */
/*
	if left<right
		mid = (left+right)/2;
		merge_sort(list, left, mid);
		merge_sort(list, mid+1, right);
		merge(list, left, mid, right);
*/

/* �պ� �˰��� */
/*
	i <- left;
	j <- mid+1
	k <- left;
	while i < mid and j <right do
		if(list[i] < mid[j])
				then
					sorted[k] <- list[i];
					k++;
					i++;
				else
					sorted[k] <- mid[j];
					k++;
					j++;
	��Ұ� ���� �κ� �迭�� sorted �� �����Ѵ�;
	sorted�� list�� �����Ѵ�
*/

